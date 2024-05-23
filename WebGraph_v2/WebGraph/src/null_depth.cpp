//
//  null_depth.cpp
//  WebGraph
//
//  Created by Глеб on 22/05/2024.
//

#include "null_depth.h"

null_depth::null_depth(float div, float divn, const std::string& inlink)
    : vertex(1, div, divn, inlink) {
    x = 400;
    y = 400;
}

int null_depth::getDistrict() const {
    return district;
}

float null_depth::getDiv() const {
    return div;
}

float null_depth::getDivn() const {
    return divn;
}

float null_depth::getX() const {
    return x;
}

float null_depth::getY() const {
    return y;
}

int null_depth::getRadius() const {
    return radius;
}

int null_depth::getRed() const {
    return red;
}

int null_depth::getGreen() const {
    return green;
}

int null_depth::getBlue() const {
    return blue;
}
