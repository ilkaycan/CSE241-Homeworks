#include "Triangle.h"
#include "NegativityException.h"

#define SQRT3 1.73205080757
namespace GTU {
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
            shapetype = ShapeType::Triangle;
        }
    }

//consructor
    Triangle::Triangle(const double &side) {
        if (testValue(side)) {
            Side = side;
        }
        x1 = Side / 2;
        y1 = 0;
        x2 = 0;
        y2 = Side * SQRT3 / 2;
        x3 = Side;
        y3 = y2;
        perimeterlength = 3 * Side;
        area = Side * Side * SQRT3 / 4;
        shapetype = ShapeType::Triangle;
    }

//no parameter consructor
    Triangle::Triangle() {
        Side = 100;
        x1 = Side / 2;
        y1 = 0;
        x2 = 0;
        y2 = Side * SQRT3 / 2;
        x3 = Side;
        y3 = y2;
        perimeterlength = 3 * Side;
        area = Side * Side * SQRT3 / 4;
    }

//setter functions
    void Triangle::setSide(const double &side) {
        if (testValue(Side))
            Side = side;
        x1 = Side / 2;
        y1 = 0;
        x2 = 0;
        y2 = Side * SQRT3 / 2;
        x3 = Side;
        y3 = y2;
        perimeterlength = 3 * Side;
        area = Side * Side * SQRT3 / 4;
    }

    void Triangle::setX1(const double &coorx1) {
        if (testValue(coorx1))
            x1 = coorx1;
    }

    void Triangle::setY1(const double &coory1) {
        if (testValue(coory1))
            y1 = coory1;
    }

    void Triangle::setX2(const double &coorx2) {
        if (testValue(coorx2))
            x2 = coorx2;
    }

    void Triangle::setY2(const double &coory2) {
        if (testValue(coory2))
            y2 = coory2;
    }

    void Triangle::setX3(const double &coorx3) {
        if (testValue(coorx3))
            x3 = coorx3;
    }

    void Triangle::setY3(const double &coory3) {
        if (testValue(coory3))
            y3 = coory3;
    }

    // Overrriding area and perimeter functions for triangle class
    double Triangle::getArea(void) {
        return (Side * Side) * SQRT3 / 4;
    }

    double Triangle::getPerimeter(void) {
        return 3 * Side;
    }

// Pre and post increment and decrement functions
    const Triangle &Triangle::operator++(int) {  //postfix
        static Triangle temp = *this;
        temp = *this;
        ++(*this);

        return temp;
    }

    Triangle &Triangle::operator++() {
        x1++;
        x2++;
        x3++;
        y1++;
        y2++;
        y3++;

        return *this;
    }

    const Triangle &Triangle::operator--(int) throw(NegativityException){  //postfix
        if(x1 == 0 || x2 == 0 || x3==0 || y1 == 0 || y2 == 0 || y3 == 0){
            throw NegativityException();
        }
        static Triangle temp = *this;
        temp = *this;
        --(*this);

        return temp;
    }

    Triangle &Triangle::operator--()throw(NegativityException) {
        if(x1 == 0 || x2 == 0 || x3==0 || y1 == 0 || y2 == 0 || y3 == 0){
            throw NegativityException();
        }
        x1--;
        x2--;
        x3--;
        y1--;
        y2--;
        y3--;

        return *this;
    }

    // << overloading helper function
    void Triangle::output(ostream &outputStream) {
        outputStream << "<polygon points=\"" << x1 << "," << y1 << " ";
        outputStream << x2 << "," << y2 << " ";
        outputStream << x3 << "," << y3 << "\"" << endl;
        outputStream << "stroke=\"black\" stroke-width=\"1\" fill=\"purple\" />" << endl;
    }
    //Writes triangle to SVG file
    void Triangle::draw(ofstream &myfile) {
        startSVG(myfile, Side, Side);
        myfile << *this;
        endSVG(myfile);
    }
    //Clone function to use in other functions
    Triangle *Triangle::duplicatefunction(void) {
        return new Triangle(*this);

    }
}
