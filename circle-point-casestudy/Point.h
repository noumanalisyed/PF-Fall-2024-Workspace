//
// Created by Syed Nouman Ali Shah on 31/10/2024.
//

#ifndef CIRCLE_POINT_CASESTUDY_POINT_H
#define CIRCLE_POINT_CASESTUDY_POINT_H

#include <iostream>
using namespace std;

class Point {
public:
    Point();

    Point(float x, float y);

    void setX(float x);

    void setY(float y);

    float getX();

    float getY();

    void print();

private:
    float x, y;
};



#endif //CIRCLE_POINT_CASESTUDY_POINT_H
