//
//  second_depth.h
//  WebGraph
//
//  Created by Глеб on 22/05/2024.
//

#ifndef second_depth_h
#define second_depth_h

#include "null_depth.h"

class second_depth : public null_depth {
public:
    second_depth(int div, int divn, float x_inh, float y_inh, const std::string& inlink);

    int getDistrict() const override;
    float getDiv() const override;
    float getDivn() const override;
    float getX() const override;
    float getY() const override;
    int getRadius() const override;
    int getRed() const override;
    int getGreen() const override;
    int getBlue() const override;
};

#endif /* second_depth_h */
