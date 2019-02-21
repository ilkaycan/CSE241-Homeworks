#include "Rectangle.h"
#include "NegativityException.h"
#include <iostream>
using namespace std;
namespace GTU{
    // Overrriding area and perimeter functions for rectangle class
    double Rectangle::getArea(void){
        return Side1*Side2;
    }

    double Rectangle::getPerimeter(void){
        return 2*(Side1+Side2);
    }
    // Pre and post increment and decrement functions
    const Rectangle &Rectangle::operator ++(int){  //postfix
        static Rectangle temp = *this;
        temp = *this;
        ++(*this);

        return temp;
    }
    Rectangle &Rectangle::operator ++(){
        x++;
        y++;
        return *this;
    }
    const Rectangle &Rectangle::operator --(int)throw(NegativityException){  //postfix
        if(x == 0 || y == 0){
            throw NegativityException();
        }
        static Rectangle temp = *this;
        temp = *this;
        --(*this);

        return temp;
    }
    Rectangle &Rectangle::operator --() throw(NegativityException){
        if(x == 0 || y == 0){
            throw NegativityException();
        }
        x--;
        y--;

        return *this;
    }

    //constructor
    Rectangle::Rectangle(const double &width, const double &height, const double &coordinatex, const double &coordinatey){
        if(testValue(width) && testValue(height) && testValue(coordinatex) && testValue(coordinatey)){
            Side1 = width;
            Side2 = height;
            x = coordinatex;
            y = coordinatey;
            perimeterlength = 2 * (Side1 + Side2);
            area = Side1 * Side2;
            shapetype = ShapeType::Rectangle;
        }
    }
    //consructor
    Rectangle::Rectangle(const double &width, const double &height){
        if(testValue(width) && testValue(height)){
            Side1 = width;
            Side2 = height;
            x = 0;
            y = 0;
            perimeterlength = 2 * (Side1 + Side2);
            area = Side1 * Side2;
            shapetype = ShapeType::Rectangle;
        }
    }
    //no parameter constructor
    Rectangle::Rectangle(void) {
        Side1 = 200;
        Side2 = 100;
        x = 0;
        y = 0;
        perimeterlength = 2 * (Side1 + Side2);
        area = Side1 * Side2;
        shapetype = ShapeType::Rectangle;
    }

    //setter fuctions
    void Rectangle::setSide1(const double &width){
        if(testValue(width))
            Side1 = width;
        perimeterlength = 2 * (Side1 + Side2);
        area = Side1 * Side2;
    }
    void Rectangle::setSide2(const double &height ){
        if(testValue(height))
            Side2 = height;
        perimeterlength = 2 * (Side1 + Side2);
        area = Side1 * Side2;
    }
    void Rectangle::setX(const double &coordinatex ){
        if(testValue(coordinatex))
            x = coordinatex;
    }
    void Rectangle::setY(const double &coordinatey ){
        if(testValue(coordinatey))
            y = coordinatey;
    }
    // << overloading helper function
    void Rectangle::output(ostream& outputStream){

        outputStream << "<rect x=\""<< x <<"\" y=\"" << y << "\" width=\"" << Side1;
        outputStream <<"\" height=\""<< Side2 << "\" stroke=\"black\" stroke-width=\"1\" fill=\"purple\" />" << endl;
    }
    //Writes rectangle to SVG file
    void Rectangle::draw(ofstream &myfile){
        int side;
        if(Side2<Side1){
            side = Side1;
        } else {
            side = Side2;
        }
        startSVG(myfile, side, side);
        myfile << (*this);
        endSVG(myfile);
    }
    //Clone function to use in other functions
    Rectangle *Rectangle::duplicatefunction(void){
        return new Rectangle(*this);
    }
}