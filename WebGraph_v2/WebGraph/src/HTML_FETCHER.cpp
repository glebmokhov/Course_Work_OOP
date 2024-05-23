//
//  HTML_FETCHER.cpp
//  WebGraph
//
//  Created by Глеб on 22/05/2024.
//


#include "HTML_FETCHER.h"
#include <curl/curl.h>
#include "gumbo.h"
#include "RootNode.h"
#include "FirstDepthNode.h"
#include "SecondDepthNode.h"
#include "ThirdDepthNode.h"
#include <iostream>
#include <regex>

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
            std::cerr << "cURL error: " << curl_easy_strerror(res) << " for URL: " << url << std::endl;
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

std::vector<std::string> extractLinks(const std::string& base_url, const std::string& html) {
    GumboOutput* output = gumbo_parse(html.c_str());
    std::vector<std::string> links;
    searchForLinks(output->root, links);
    gumbo_destroy_output(&kGumboDefaultOptions, output);

    std::vector<std::string> absolute_links;
    std::regex url_regex("(https?|ftp)://([^\\s/$.?#].[^\\s]*)");
    std::smatch url_match_result;

    for (const std::string& link : links) {
        if (std::regex_match(link, url_match_result, url_regex)) {
            absolute_links.push_back(link);  // It's already an absolute URL
        } else {
            // Assume the link is a relative URL
            std::string absolute_link = base_url + link;
            absolute_links.push_back(absolute_link);
        }
    }
    return absolute_links;
}

PageNode* createNode(const std::string& url, int depth) {
    switch (depth) {
    case 0:
        return new RootNode(url);
    case 1:
        return new FirstDepthNode(url);
    case 2:
        return new SecondDepthNode(url);
    case 3:
        return new ThirdDepthNode(url);
    default:
        return nullptr;
    }
}

std::vector<PageNode*> fetchNestedLinks(const std::vector<std::string>& urls, int depth) {
    std::vector<PageNode*> result;

    if (depth < 0) {
        return result;
    }

    for (const auto& url : urls) {
        if (url.empty()) {
            continue;  // Skip empty URLs
        }
        
        PageNode* node = createNode(url, depth);
        std::string html = fetchHTML(url);
        
        if (html.empty()) {
            continue;  // Skip if failed to fetch HTML
        }

        std::vector<std::string> links = extractLinks(url, html);

        if (depth > 0) {
            std::vector<PageNode*> nestedLinks = fetchNestedLinks(links, depth - 1);
            for (auto nestedNode : nestedLinks) {
                node->addChild(nestedNode);
            }
        }

        result.push_back(node);
    }

    return result;
}
