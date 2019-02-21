#include "PolygonVect.h"
#include <cmath>
#include <iostream>
#include "NegativityException.h"
#include "NoParamConstructorException.h"
#include "NoParamConstructorException.h"

#define PI 3.1415926535897
namespace GTU{
    //Constructors
    PolygonVect::PolygonVect(const Polygon::Point2D &Point){
        Coordinate.push_back(Point);
    }
    PolygonVect::PolygonVect(const vector <Polygon::Point2D> PPoints ){

        for (int i = 0; i < PPoints.size(); i++) {
            Coordinate.push_back(PPoints[i]);
        }
    }
    PolygonVect::PolygonVect(const Rectangle &rect){
        Polygon::Point2D X;

        X.setX(rect.getX());
        X.setY(rect.getY());
        Coordinate.push_back(X);

        X.setX(rect.getX() + rect.getSide1());
        X.setY(rect.getY());
        Coordinate.push_back(X);

        X.setX(rect.getX() + rect.getSide1());
        X.setY(rect.getY() + rect.getSide2());
        Coordinate.push_back(X);

        X.setX(rect.getX());
        X.setY(rect.getY() + rect.getSide2());
        Coordinate.push_back(X);

    }
    PolygonVect::PolygonVect(const Circle &circ){

        double angle = 0;
        double change = 3.6;
        Polygon::Point2D X;

        for (int i = 0; i < 100; i++) {
            X.setX(circ.getCx() + (circ.getRadius() * cos((angle + (i * change)) * PI / 180.0)));
            X.setY(circ.getCy() + (circ.getRadius() * sin((angle + (i * change)) * PI / 180.0)));
            Coordinate.push_back(X);
        }

    }
    PolygonVect::PolygonVect(const Triangle &tri){
        Polygon::Point2D X;

        X.setX(tri.getX1());
        X.setY(tri.getY1());
        Coordinate.push_back(X);

        X.setX(tri.getX2());
        X.setY(tri.getY2());
        Coordinate.push_back(X);

        X.setX(tri.getX3());
        X.setY(tri.getY3());
        Coordinate.push_back(X);

    }

    PolygonVect::PolygonVect(void)throw(NoParamConstructorException){
        throw NoParamConstructorException();
    }
    //clone function to use in other functions
    PolygonVect *PolygonVect::duplicatefunction(void){
        return new PolygonVect(*this);
    }
    // << overloading helper function
    void PolygonVect::output(ostream& outputStream){

        outputStream << "<polygon points=\"";
        for (int i = 0; i < Coordinate.size(); i++) {
            outputStream << Coordinate[i].getX() << "," << Coordinate[i].getY() << " ";
        }
        outputStream << "\"" << endl;
        outputStream << "stroke=\"black\" stroke-width=\"1\" fill=\"purple\" />" << endl;
    }
    // Writes Polygon to SVG file
    void PolygonVect::draw(ofstream &myfile){
        startSVG(myfile, 1000, 1000);
        myfile << (*this);
        endSVG(myfile);
    }
    // Calculates area
    double PolygonVect::getArea(void) {
        int size = Coordinate.size();
        for (int i = 0; i < size; i++) {
            if(i != size-1) {
                area += Coordinate[i].getX() * Coordinate[i + 1].getY();
                area -= Coordinate[i + 1].getX() * Coordinate[i].getY();
            } else {
                area += Coordinate[size-1].getX() * Coordinate[0].getY();
                area -= Coordinate[0].getX() * Coordinate[size-1].getY();
            }
        }

        return abs(area*0.5);

    }

    // Calculates perimeter

    double PolygonVect::getPerimeter(void){
        int size = Coordinate.size();

        for (int i = 0; i < size-1; i++){
            perimeter+= sqrt(pow(Coordinate[i].getX()- Coordinate[i+1].getX(), 2) + pow(Coordinate[i].getY()- Coordinate[i+1].getY(), 2));
        }
        perimeter+= sqrt(pow(Coordinate[0].getX()- Coordinate[size-1].getX(), 2) + pow(Coordinate[0].getY()- Coordinate[size-1].getY(), 2));

        return perimeter;
    }

    //Post and pre ++ and --

    const PolygonVect &PolygonVect::operator ++(int){
        static PolygonVect temp = *this;
        temp = *this;
        ++(*this);

        return temp;
    } //postfix

    PolygonVect &PolygonVect::operator ++(){
        double temp;
        int size = Coordinate.size();

        for (int i = 0; i < size; i++){
            temp = Coordinate[i].getX();
            Coordinate[i].setX(temp+1);
            temp = Coordinate[i].getY();
            Coordinate[i].setY(temp+1);
        }

        return *this;
    }
    const PolygonVect &PolygonVect::operator --(int)throw(NegativityException){
        for(int i =0; i< Coordinate.size(); i++){
            if(Coordinate[i].getX()<0 || Coordinate[i].getY()<0){
                throw NegativityException();
            }
        }
        static PolygonVect temp = *this;
        temp = *this;
        --(*this);

        return temp;
    } //postfix
    PolygonVect &PolygonVect::operator --()throw(NegativityException){
        double temp;
        int size = Coordinate.size();
        for(int i =0; i< Coordinate.size(); i++){
            if(Coordinate[i].getX()<0 || Coordinate[i].getY()<0){
                throw NegativityException();
            }
        }
        for (int i = 0; i < size; i++){
            temp = Coordinate[i].getX();
            Coordinate[i].setX(temp-1);
            temp = Coordinate[i].getY();
            Coordinate[i].setY(temp-1);
        }

        return *this;
    }
}