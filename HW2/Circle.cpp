#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Circle.h"
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
    }
}
//constructor
Circle::Circle(const double &radius){
    if(testValue(radius)) {
        r = radius;
        cx = radius;
        cy = radius;
    }
}
//no parameter constructor
Circle::Circle(void){
    r = 100;
    cx = 100;
    cy = 100;
}
// setter functions
void Circle::setRadius(const double &radius ) {
    if(testValue(radius))
      r = radius;
    if(cx<r)
        cx = r;
    if(cy<r)
        cy = r;
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