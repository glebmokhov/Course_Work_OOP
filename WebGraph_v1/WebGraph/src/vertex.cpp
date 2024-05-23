//
//  vertex.cpp
//  WebGraph
//
//  Created by Глеб on 22/05/2024.
//

#include "vertex.h"

vertex::vertex(int district, float div, float divn, const std::string& inlink)
    : district(district), div(div), divn(divn), x(0), y(0), radius(20), red(255), green(0), blue(0), link(inlink) {}

std::string vertex::getLink() const {
    return link;
}
