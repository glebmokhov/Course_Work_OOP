//
//  second_depth.cpp
//  WebGraph
//
//  Created by Глеб on 22/05/2024.
//

#include "second_depth.h"
#include <cmath>

second_depth::second_depth(int div, int divn, float x_inh, float y_inh, const std::string& inlink)
    : null_depth(div, divn, inlink) {
    district = 80;
    this->div = div;
    this->divn = divn;
    x = x_inh + 80 * cos(2 * 3.14 * (divn / div));
    y = y_inh + 80 * sin(2 * 3.14 * (divn / div));
    radius = 6;
    red = 255;
    green = 40;
    blue = 40;
}

int second_depth::getDistrict() const {
    return district;
}

float second_depth::getDiv() const {
    return div;
}

float second_depth::getDivn() const {
    return divn;
}

float second_depth::getX() const {
    return x;
}

float second_depth::getY() const {
    return y;
}

int second_depth::getRadius() const {
    return radius;
}

int second_depth::getRed() const {
    return red;
}

int second_depth::getGreen() const {
    return green;
}

int second_depth::getBlue() const {
    return blue;
}
