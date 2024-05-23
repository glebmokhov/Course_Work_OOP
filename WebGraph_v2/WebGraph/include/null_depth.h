//
//  null_depth.h
//  WebGraph
//
//  Created by Глеб on 22/05/2024.
//

#ifndef NULL_DEPTH_H
#define NULL_DEPTH_H

#include "vertex.h"

class null_depth : public vertex {
public:
    null_depth(float div, float divn, const std::string& inlink);

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

#endif // NULL_DEPTH_H
