#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Triangle.h"

#define SQRT3 1.73205080757
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
