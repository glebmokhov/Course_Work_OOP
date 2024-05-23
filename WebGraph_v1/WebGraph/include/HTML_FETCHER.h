//
//  HTML_FETCHER.h
//  WebGraph
//
//  Created by Глеб on 22/05/2024.
//

#ifndef HTML_FETCHER_h
#define HTML_FETCHER_h

#include <string>
#include <vector>
#include <curl/curl.h>
#include "gumbo.h"
#include "link_tracker.h"





// Fetches HTML content from the given URL
std::string fetchHTML(const std::string& url);

// Extracts links from the given HTML content
std::vector<std::string> extractLinks(const std::string& html);

// Recursively fetches and parses links up to the specified depth
std::vector<PageLinks> fetchNestedLinks(const std::vector<std::string>& urls, int depth);






#endif // HTML_FETCHER_h

