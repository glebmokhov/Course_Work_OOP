//
//  HTML_FETCHER.cpp
//  WebGraph
//
//  Created by Глеб on 22/05/2024.
//

#include "HTML_FETCHER.h"
#include <curl/curl.h>
#include "gumbo.h"
#include <iostream>

// Helper callback function for cURL
static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

std::string fetchHTML(const std::string& url) {
    CURL* curl;
    CURLcode res;
    std::string readBuffer;

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            std::cerr << "cURL error: " << curl_easy_strerror(res) << std::endl;
        }
        curl_easy_cleanup(curl);
    }
    return readBuffer;
}

void searchForLinks(GumboNode* node, std::vector<std::string>& links) {
    if (node->type != GUMBO_NODE_ELEMENT) {
        return;
    }

    GumboAttribute* href;
    if (node->v.element.tag == GUMBO_TAG_A &&
        (href = gumbo_get_attribute(&node->v.element.attributes, "href"))) {
        links.push_back(href->value);
    }

    const GumboVector* children = &node->v.element.children;
    for (unsigned int i = 0; i < children->length; ++i) {
        searchForLinks(static_cast<GumboNode*>(children->data[i]), links);
    }
}

std::vector<std::string> extractLinks(const std::string& html) {
    GumboOutput* output = gumbo_parse(html.c_str());
    std::vector<std::string> links;
    searchForLinks(output->root, links);
    gumbo_destroy_output(&kGumboDefaultOptions, output);
    return links;
}

std::vector<PageLinks> fetchNestedLinks(const std::vector<std::string>& urls, int depth) {
    std::vector<PageLinks> result;

    if (depth <= 0) {
        return result;
    }

    for (const auto& url : urls) {
        PageLinks page;
        page.pageUrl = url;
        std::cout << "Fetching: " << url << " at depth: " << depth << std::endl;
        std::string html = fetchHTML(url);
        page.links = extractLinks(html);
        std::cout << "Found " << page.links.size() << " links on page: " << url << std::endl;

        if (depth > 1) {
            page.nestedLinks = fetchNestedLinks(page.links, depth - 1);
        }

        result.push_back(page);
    }

    return result;
}

