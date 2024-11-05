//
// Created by Syed Nouman Ali Shah on 31/10/2024.
//

#ifndef CIRCLE_POINT_CASESTUDY_RECTANGLE_H
#define CIRCLE_POINT_CASESTUDY_RECTANGLE_H

#include "Point.h"
class Rectangle {
public:
    Rectangle();
    Rectangle(float length,float width, float x,float y);
    void print();
    void setLength(float length);
    void setWidth(float width);
    float getLength();
    float getWidth();
    float area();
    float perimeter();
private:
    Point center;
    float length;
    float width;
};


#endif //CIRCLE_POINT_CASESTUDY_RECTANGLE_H
