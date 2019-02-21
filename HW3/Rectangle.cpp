#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Rectangle.h"

using namespace std;
double Rectangle::totalArea = 0;
double Rectangle::totalPerimeter = 0;
//constructor
Rectangle::Rectangle(const double &width, const double &height, const double &coordinatex, const double &coordinatey){
    if(testValue(width) && testValue(height) && testValue(coordinatex) && testValue(coordinatey)){
        Side1 = width;
        Side2 = height;
        x = coordinatex;
        y = coordinatey;
        perimeterlength = 2 * (Side1 + Side2);
        area = Side1 * Side2;
        totalArea += area;
        totalPerimeter += perimeterlength;
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
        totalArea += area;
        totalPerimeter += perimeterlength;
    }
}
//no parameter constructor
Rectangle::Rectangle(void){
    Side1 = 200;
    Side2 = 100;
    x = 0;
    y = 0;
    perimeterlength = 2 * (Side1 + Side2);
    area = Side1 * Side2;
    totalArea += area;
    totalPerimeter += perimeterlength;
}
//checks the input value
bool Rectangle::testValue(const double &num)const{
    if(num>=0){
        return true;
    }else{
        cerr << "You have entered wrong number!!" << endl ;
        exit(EXIT_FAILURE);
    }
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
//draws given rectangle to svg file
void Rectangle::draw(ofstream &myfile)  {
    myfile << "<svg version=\"1.1\" " << endl << "baseProfile=\"full\"" << endl;
    myfile << "width=" << "\"" << Side1 << "\"" ;
    myfile << " height=" << "\"" << Side2 << "\""  << endl;
    myfile << "xmlns=\"http://www.w3.org/2000/svg\">" << endl;
    myfile << "<rect x=\""<< x <<"\" y=\"" << y << "\"" << endl;
    myfile << "width=\"100%\" height=\"100%\" stroke=\"black\" stroke-width=\"1\" fill=\"blue\" />" << endl;
    myfile << "</svg>" << endl;

}
//this function sends outputstream to << overloading function in main
ostream& Rectangle::output(ostream& outputStream)const{

    outputStream << "Width:" << Side1 << " Height:" << Side2 ;
    outputStream << " x:" << x << " y:" << y << " area:" << area ;
    outputStream <<  " perimeter length:" << perimeterlength << endl;

    return outputStream;
}
//this function overloads + for Rectangle Class
const Rectangle Rectangle::operator +(double& change ){
    Rectangle newShape(Side1+change, Side2+change);

    return newShape;
}
//this function overloads - for Rectangle Class
const Rectangle Rectangle::operator -(double& change ){
    Rectangle newShape(Side1-change, Side2-change);

    return newShape;
}
//this function overloads postfix ++ for Rectangle Class
Rectangle Rectangle::operator ++(int){
    double coorx = x;
    double coory = y;
    x++;
    y++;

    return Rectangle(Side1, Side2, coorx, coory);
}
//this function overloads prefix++ for Rectangle Class
Rectangle Rectangle::operator ++(){
    x++;
    y++;

    return Rectangle(Side1, Side2, x, y);
}
//this function overloads postfix -- for Rectangle Class
Rectangle Rectangle::operator --(int){
    double coorx = x;
    double coory = y;
    x--;
    y--;

    return Rectangle(Side1, Side2, coorx, coory);
}
//this function overloads prefix -- for Rectangle Class
Rectangle Rectangle::operator --(){
    x--;
    y--;

    return Rectangle(Side1, Side2, x, y);
}
//this function overloads < for Rectangle Class
bool Rectangle::operator <(const Rectangle& compare){
    if(area < compare.area) {
        return true;
    } else{
        return false;
    }
}
//this function overloads > for Rectangle Class
bool Rectangle::operator >(const Rectangle& compare){
    if(area > compare.area) {
        return true;
    } else{
        return false;
    }
}
//this function overloads <= for Rectangle Class
bool Rectangle::operator <=(const Rectangle& compare){
    if(area <= compare.area) {
        return true;
    } else{
        return false;
    }
}
//this function overloads >= for Rectangle Class
bool Rectangle::operator >=(const Rectangle& compare){
    if(area >= compare.area) {
        return true;
    } else{
        return false;
    }
}
//this function overloads == for Rectangle Class
bool Rectangle::operator ==(const Rectangle& compare){
    if(area == compare.area) {
        return true;
    } else{
        return false;
    }
}
//this function overloads != for Rectangle Class
bool Rectangle::operator !=(const Rectangle& compare){
    if(area != compare.area) {
        return true;
    } else{
        return false;
    }
}