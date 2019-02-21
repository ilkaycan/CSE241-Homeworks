#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Rectangle.h"

using namespace std;
//constructor
Rectangle::Rectangle(const double &width, const double &height, const double &coordinatex, const double &coordinatey){
    if(testValue(width) && testValue(height) && testValue(coordinatex) && testValue(coordinatey)){
        Side1 = width;
        Side2 = height;
        x = coordinatex;
        y = coordinatey;
    }
}
//consructor
Rectangle::Rectangle(const double &width, const double &height){
    if(testValue(width) && testValue(height)){
        Side1 = width;
        Side2 = height;
        x = 0;
        y = 0;
    }
}
//no parameter constructor
Rectangle::Rectangle(void){
    Side1 = 200;
    Side2 = 100;
    x = 0;
    y = 0;
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
}
void Rectangle::setSide2(const double &height ){
    if(testValue(height))
    Side2 = height;
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