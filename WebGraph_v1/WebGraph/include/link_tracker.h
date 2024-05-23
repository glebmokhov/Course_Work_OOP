//
//  link_tracker.h
//  WebGraph
//
//  Created by Глеб on 22/05/2024.
//

#ifndef link_tracker_h
#define link_tracker_h

#include <string>
#include <vector>



struct PageLinks {
    std::string pageUrl;
    std::vector<std::string> links;
    std::vector<PageLinks> nestedLinks;
};







#endif // link_tracker_h 
