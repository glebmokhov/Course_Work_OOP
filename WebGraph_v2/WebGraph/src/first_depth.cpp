//
//  first_depth.cpp
//  WebGraph
//
//  Created by Глеб on 22/05/2024.
//

#include "first_depth.h"
#include <cmath>

first_depth::first_depth(int div, int divn, float x_inh, float y_inh, const std::string& inlink)
    : null_depth(div, divn, inlink) {
    district = 175;
    this->div = div;
    this->divn = divn;
    x = x_inh + 175 * cos(2 * 3.14 * (divn / div));
    y = y_inh + 175 * sin(2 * 3.14 * (divn / div));
    radius = 10;
    red = 255;
    green = 20;
    blue = 20;
}

int first_depth::getDistrict() const {
    return district;
}

float first_depth::getDiv() const {
    return div;
}

float first_depth::getDivn() const {
    return divn;
}

float first_depth::getX() const {
    return x;
}

float first_depth::getY() const {
    return y;
}

int first_depth::getRadius() const {
    return radius;
}

int first_depth::getRed() const {
    return red;
}

int first_depth::getGreen() const {
    return green;
}

int first_depth::getBlue() const {
    return blue;
}
