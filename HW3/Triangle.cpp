#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Triangle.h"

#define SQRT3 1.73205080757
double Triangle::totalArea = 0;
double Triangle::totalPerimeter = 0;
//checks input value
bool Triangle::testValue(const double &num)const{
    if(num>=0){
        return true;
    }else{
        cerr << "You have entered wrong number!!" << endl ;
        exit(EXIT_FAILURE);
    }
}
//constructor
Triangle::Triangle(const double &side, const double &coorx1, const double &coory1,
         const double &coorx2, const double &coory2, const double &coorx3,
         const double &coory3) {
    if (testValue(side) && testValue(coorx1) && testValue(coory1) && testValue(coorx2)
        && testValue(coory2) && testValue(coorx3) && testValue(coory3)) {
        Side = side;
        x1 = coorx1;
        x2 = coorx2;
        x3 = coorx3;
        y1 = coory1;
        y2 = coory2;
        y3 = coory3;
        perimeterlength = 3 * Side;
        area = Side * Side * SQRT3 / 4;
        totalArea += area;
        totalPerimeter += perimeterlength;
    }
}
//consructor
Triangle::Triangle(const double &side){
    if(testValue(side)){
        Side = side;
    }
    x1 = Side/2;
    y1 = 0;
    x2 = 0;
    y2 = Side*SQRT3/2;
    x3 = Side;
    y3 = y2;
    perimeterlength = 3 * Side;
    area = Side * Side * SQRT3 / 4;
    totalArea += area;
    totalPerimeter += perimeterlength;
}
//no parameter consructor
Triangle::Triangle(){
    Side = 100;
    x1 = Side/2;
    y1 = 0;
    x2 = 0;
    y2 = Side*SQRT3/2;
    x3 = Side;
    y3 = y2;
    perimeterlength = 3 * Side;
    area = Side * Side * SQRT3 / 4;
    totalArea += area;
    totalPerimeter += perimeterlength;
}
//setter functions
void Triangle::setSide(const double &side){
    if(testValue(Side))
        Side = side;
    x1 = Side/2;
    y1 = 0;
    x2 = 0;
    y2 = Side*SQRT3/2;
    x3 = Side;
    y3 = y2;
    perimeterlength = 3 * Side;
    area = Side * Side * SQRT3 / 4;
}
void Triangle::setX1(const double &coorx1){
    if(testValue(coorx1))
    x1 = coorx1;
}
void Triangle::setY1(const double &coory1){
    if(testValue(coory1))
    y1 = coory1;
}
void Triangle::setX2(const double &coorx2){
    if(testValue(coorx2))
    x2 = coorx2;
}
void Triangle::setY2(const double &coory2){
    if(testValue(coory2))
    y2 = coory2;
}
void Triangle::setX3(const double &coorx3){
    if(testValue(coorx3))
    x3 = coorx3;
}
void Triangle::setY3(const double &coory3){
    if(testValue(coory3))
    y3 = coory3;
}
//draws given triangle to svg file
void Triangle::draw(ofstream &myfile) {
    myfile << "<svg version=\"1.1\" " << endl << "baseProfile=\"full\"" << endl;
    myfile << "width=" << "\"" << Side << "\"" ;
    myfile << " height=" << "\"" << Side << "\""  << endl;
    myfile << "xmlns=\"http://www.w3.org/2000/svg\">" << endl;
    myfile << "<polygon points=\"" << x1 << "," << y1 << " " << x2 << "," << y2 << " " << x3 ;
    myfile << "," << y3 << "\""<< endl;
    myfile << "stroke=\"black\" stroke-width=\"1\" fill=\"blue\" />" << endl;

    myfile << "</svg>" << endl;

}
//this function sends outputstream to << overloading function in main
ostream& Triangle::output(ostream& outputStream)const{
    outputStream << "Side:" << Side << " Coordinates:" << x1 <<",";
    outputStream << y1 << " " << x2 << "," << y2 << " " << x3 << "," ;
    outputStream<< y3 << " area:" << area <<  " perimeter length:" << perimeterlength << endl;

    return outputStream;
}
//this function overloads + for Triangle Class
const Triangle Triangle::operator +(double& change){
    Triangle newShape(Side+change);

    return newShape;
}
//this function overloads - for Triangle Class
const Triangle Triangle::operator -(double& change){
    Triangle newShape(Side-change);

    return newShape;
}
//this function overloads postfix ++ for Triangle Class
Triangle Triangle::operator ++(int){
    double a1 = x1;
    double a2 = x2;
    double a3 = x3;
    double b1 = y1;
    double b2 = y2;
    double b3 = y3;
    x1++;
    x2++;
    x3++;
    y1++;
    y2++;
    y3++;
    return Triangle(Side, a1, b1, a2, b2, a3, b3);
}
//this function overloads prefix ++ for Triangle Class
Triangle Triangle::operator ++(){
    x1++;
    x2++;
    x3++;
    y1++;
    y2++;
    y3++;
    return Triangle(Side, x1, y1, x2, y2, x3, y3);
}
//this function overloads postfix -- for Triangle Class
Triangle Triangle::operator --(int){
    double a1 = x1;
    double a2 = x2;
    double a3 = x3;
    double b1 = y1;
    double b2 = y2;
    double b3 = y3;

    x1--;
    x2--;
    x3--;
    y1--;
    y2--;
    y3--;
    return Triangle(Side, a1, b1, a2, b2, a3, b3);
}
//this function overloads prefix -- for Triangle Class
Triangle Triangle::operator --(){
    x1--;
    x2--;
    x3--;
    y1--;
    y2--;
    y3--;
    return Triangle(Side, x1, y1, x2, y2, x3, y3);
}
//this function overloads < for Triangle Class
bool Triangle::operator <(const Triangle& compare){
    if(area < compare.area) {
        return true;
    } else{
        return false;
    }
}
//this function overloads > for Triangle Class
bool Triangle::operator >(const Triangle& compare){
    if(area > compare.area) {
        return true;
    } else{
        return false;
    }
}
//this function overloads <= for Triangle Class
bool Triangle::operator <=(const Triangle& compare){
    if(area <= compare.area) {
        return true;
    } else{
        return false;
    }
}
//this function overloads >= for Triangle Class
bool Triangle::operator >=(const Triangle& compare){
    if(area >= compare.area) {
        return true;
    } else{
        return false;
    }
}
//this function overloads == for Triangle Class
bool Triangle::operator ==(const Triangle& compare){
    if(area == compare.area) {
        return true;
    } else{
        return false;
    }
}
//this function overloads != for Triangle Class
bool Triangle::operator !=(const Triangle& compare){
    if(area != compare.area) {
        return true;
    } else{
        return false;
    }
}