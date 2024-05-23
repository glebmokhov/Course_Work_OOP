//
//  third_depth.h
//  WebGraph
//
//  Created by Глеб on 22/05/2024.
//

#ifndef third_depth_h
#define third_depth_h

#include "null_depth.h"

class third_depth : public null_depth {
public:
    third_depth(int div, int divn, float x_inh, float y_inh, const std::string& inlink);

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


#endif /* third_depth_h */
