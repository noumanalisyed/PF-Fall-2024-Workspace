//
// Created by Syed Nouman Ali Shah on 31/10/2024.
//

#include "Circle.h"
Circle::Circle() : center() {
    radius = 0;
    cout << "Circle -- Default Constructor called " << endl;
}

Circle::Circle(float radius, float x, float y) : center(x, y) {
    Circle::radius = radius;
    cout << "Circle -- Overloaded Constructor called " << endl;
}

float Circle::getRadius() {
    return radius;
}

void Circle::setRadius(float radius) {
    Circle::radius = radius;
}

Point Circle::getCenter() {
    return center;
}

void Circle::setCenter(Point center) {
    Circle::center.setX(center.getX());
    Circle::center.setY(center.getY());
}

float Circle::area() {
    return (float) (22 / 7) * radius * radius;
}

float Circle::circumference() {
    return (float) (22 / 7) * radius * 2;
}

void Circle::print() {
    cout << "Circle [ ";
    center.print();
    cout << " Radius = " << radius << " , Area = " << area()
         << " , Circumference " << circumference() << " ] " << endl;
}
