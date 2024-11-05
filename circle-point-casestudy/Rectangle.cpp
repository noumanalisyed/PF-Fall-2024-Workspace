//
// Created by Syed Nouman Ali Shah on 31/10/2024.
//

#include "Rectangle.h"

Rectangle::Rectangle():center(){
    length = 0;
    width = 0;
    cout<<"Rectangle -- Default constructor called "<<endl;
}
Rectangle::Rectangle(float length,float width, float x,float y):center(x,y){
    Rectangle::length = length;
    Rectangle::width = width;
    cout<<"Rectangle -- Overloaded constructor called "<<endl;
}
void Rectangle::print(){
    cout << "Rectangle [ ";
    center.print();
    cout << " Length = " << length
            << " Width = " << width
        << " , Area = " << area()
         << " , Perimeter " << perimeter() << " ] " << endl;
}
void Rectangle::setLength(float length){
    Rectangle::length = length;
}
void Rectangle::setWidth(float width){
    Rectangle::width = width;
}
float Rectangle::getLength(){
    return length;
}
float Rectangle::getWidth(){
    return width;
}
float Rectangle::area(){
    return length * width;
}
float Rectangle::perimeter(){
    return 2 * (length + width);
}