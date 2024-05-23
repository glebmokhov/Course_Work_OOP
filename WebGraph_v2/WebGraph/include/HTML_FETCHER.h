//
//  HTML_FETCHER.h
//  WebGraph
//
//  Created by Глеб on 22/05/2024.
//

#ifndef HTML_FETCHER_h
#define HTML_FETCHER_h



#include <vector>
#include "PageNode.h"
#include <string>

std::vector<PageNode*> fetchNestedLinks(const std::vector<std::string>& urls, int depth);





#endif // HTML_FETCHER_h

