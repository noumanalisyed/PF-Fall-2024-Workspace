//
// Created by Syed Nouman Ali Shah on 31/10/2024.
//

#include "Point.h"

Point::Point() {
    x = 0;
    y = 0;
    cout << "Point -- Default Constructor called " << endl;
}

Point::Point(float x, float y) {
    Point::x = x;
    Point::y = y;
    cout << "Point -- Overloaded Constructor called " << endl;
}

void Point::setX(float x) {
    Point::x = x;
}

void Point::setY(float y) {
    Point::y = y;
}

float Point::getX() {
    return x;
}

float Point::getY() {
    return y;
}

void Point::print() {
    cout << "Point [ X = " << x << " , Y = " << y << " ] , ";
}
