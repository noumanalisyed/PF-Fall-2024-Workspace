//
// Created by Syed Nouman Ali Shah on 31/10/2024.
//

#ifndef CIRCLE_POINT_CASESTUDY_CIRCLE_H
#define CIRCLE_POINT_CASESTUDY_CIRCLE_H
#include "Point.h"

class Circle {
public:
    Circle();

    Circle(float radius, float x, float y);

    float getRadius();

    void setRadius(float radius);

    Point getCenter();

    void setCenter(Point center);

    float area();

    float circumference();

    void print();

private:
    float radius;
    Point center;
};


#endif //CIRCLE_POINT_CASESTUDY_CIRCLE_H
