//
//  vertex.h
//  WebGraph
//
//  Created by Глеб on 21/05/2024.
//

#ifndef VERTEX_H
#define VERTEX_H

#include <string>

class vertex {
public:
    vertex(int district, float div, float divn, const std::string& inlink);

    virtual ~vertex() = default;

    virtual int getDistrict() const = 0;
    virtual float getDiv() const = 0;
    virtual float getDivn() const = 0;
    virtual float getX() const = 0;
    virtual float getY() const = 0;
    virtual int getRadius() const = 0;
    virtual int getRed() const = 0;
    virtual int getGreen() const = 0;
    virtual int getBlue() const = 0;

    std::string getLink() const;

protected:
    int district;
    float div;
    float divn;
    float x;
    float y;
    int radius;
    int red;
    int green;
    int blue;
    std::string link;
};

#endif // VERTEX_H

