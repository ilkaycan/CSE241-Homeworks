#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Circle.h"

#define PI 3.1415926535897
double Circle::totalArea = 0;
double Circle::totalPerimeter = 0;

//checks the input value
bool Circle::testValue(const double &num)const{
    if(num>=0){
        return true;
    }else{
        cerr << "You have entered wrong number!!" << endl ;
        exit(EXIT_FAILURE);
    }
}
//constructor
Circle::Circle(const double &radius, const double &centerx, const double &centery){
    if(testValue(radius) && testValue(centerx) && testValue(centery)){
        r = radius;
        cx = centerx;
        cy = centery;
        perimeterlength = 2*PI*r;
        area = PI*r*r;
        totalArea += area;
        totalPerimeter += perimeterlength;
    }
}
//constructor
Circle::Circle(const double &radius){
    if(testValue(radius)) {
        r = radius;
        cx = radius;
        cy = radius;
        perimeterlength = 2*PI*r;
        area = PI*r*r;
        totalArea += area;
        totalPerimeter += perimeterlength;
    }
}
//no parameter constructor
Circle::Circle(void){
    r = 100;
    cx = 100;
    cy = 100;
    perimeterlength = 2*PI*r;
    area = PI*r*r;
    totalArea += area;
    totalPerimeter += perimeterlength;
}
// setter functions
void Circle::setRadius(const double &radius ) {
    if(testValue(radius))
      r = radius;
    if(cx<r)
        cx = r;
    if(cy<r)
        cy = r;
    perimeterlength = 2*PI*r;
    area = PI*r*r;
}
void Circle::setX(const double &centerx ){
    if(testValue(centerx))
    cx = centerx;
}
void Circle::setY(const double &centery ){
    if(testValue(centery))
    cy = centery;
}
//draws given circle to svg file
void Circle::draw(ofstream &myfile) {

    myfile << "<svg version=\"1.1\" " << endl << "baseProfile=\"full\"" << endl;
    myfile << "width=" << "\"" << r*2 << "\"" ;
    myfile << " height=" << "\"" << r*2 << "\""  << endl;
    myfile << "xmlns=\"http://www.w3.org/2000/svg\">" << endl;
    myfile << "<circle cx=\"" << cx << "\"";
    myfile << " cy=\"" << cy <<"\"";
    myfile << " r=\""<< r << "\" stroke=\"black\" stroke-width=\"1\" fill=\"blue\" />" << endl;
    myfile << "</svg>" << endl;
}
//this function sends outputstream to << overloading function in main
ostream& Circle::output(ostream &outputStream)const{
    outputStream << "Radius:" << r << " cx:" << cx << " cy:" << cy ;
    outputStream << " area:" << area <<  " perimeter length:" << perimeterlength << endl;

    return outputStream;
}
//this function overloads + for Circle Class
const Circle Circle::operator +(double& change){
    Circle newShape(r+change);

    return newShape;
}
//this function overloads - for Circle Class
const Circle Circle::operator -(double& change){
    Circle newShape(r-change);

    return newShape;
}
//this function overloads postfix ++ for Circle Class
Circle Circle::operator ++(int){
    double x = cx;
    double y = cy;
    cx++;
    cy++;

    return Circle(r, x, y);
}
//this function overloads prefix ++ for Circle Class
Circle Circle::operator ++(){
    cx++;
    cy++;

    return Circle(r, cx, cy);
}
//this function overloads postfix -- for Circle Class
Circle Circle::operator --(int){
    double x = cx;
    double y = cy;
    cx--;
    cy--;

    return Circle(r, x, y);
}
//this function overloads prefix -- for Circle Class
Circle Circle::operator --(){
    cx--;
    cy--;

    return Circle(r, cx, cy);
}
//this function overloads < for Circle Class
bool Circle::operator <(const Circle& compare){
    if(area < compare.area) {
        return true;
    } else{
        return false;
    }
}
//this function overloads > for Circle Class
bool Circle::operator >(const Circle& compare){
    if(area > compare.area) {
        return true;
    } else{
        return false;
    }
}
//this function overloads <= for Circle Class
bool Circle::operator <=(const Circle& compare){
    if(area <= compare.area) {
        return true;
    } else{
        return false;
    }
}
//this function overloads >= for Circle Class
bool Circle::operator >=(const Circle& compare){
    if(area >= compare.area) {
        return true;
    } else{
        return false;
    }
}
//this function overloads == for Circle Class
bool Circle::operator ==(const Circle& compare){
    if(area == compare.area) {
        return true;
    } else{
        return false;
    }
}
//this function overloads != for Circle Class
bool Circle::operator !=(const Circle& compare){
    if(area != compare.area) {
        return true;
    } else{
        return false;
    }
}
