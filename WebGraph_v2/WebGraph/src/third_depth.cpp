//
//  third_depth.cpp
//  WebGraph
//
//  Created by Глеб on 22/05/2024.
//

#include "third_depth.h"
#include <cmath>

third_depth::third_depth(int div, int divn, float x_inh, float y_inh, const std::string& inlink)
    : null_depth(div, divn, inlink) {
    district = 30;
    this->div = div;
    this->divn = divn;
    x = x_inh + 30 * cos(2 * 3.14 * (divn / div));
    y = y_inh + 30 * sin(2 * 3.14 * (divn / div));
    radius = 3;
    red = 255;
    green = 60;
    blue = 60;
}

int third_depth::getDistrict() const {
    return district;
}

float third_depth::getDiv() const {
    return div;
}

float third_depth::getDivn() const {
    return divn;
}

float third_depth::getX() const {
    return x;
}

float third_depth::getY() const {
    return y;
}

int third_depth::getRadius() const {
    return radius;
}

int third_depth::getRed() const {
    return red;
}

int third_depth::getGreen() const {
    return green;
}

int third_depth::getBlue() const {
    return blue;
}
