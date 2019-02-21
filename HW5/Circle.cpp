#include "Circle.h"
#define PI 3.1415926535897
#include "NegativityException.h"

namespace GTU {
// Overrriding area and perimeter functions for circle class
    double Circle::getArea(void) {
        return PI * r * r;
    }

    double Circle::getPerimeter(void) {
        return 2 * PI * r;
    }

// Pre and post increment and decrement functions
    const Circle &Circle::operator++(int) {  //postfix

        static Circle temp = *this;
        temp = *this;
        ++(*this);

        return temp;
    }

    Circle &Circle::operator++() {
        cx++;
        cy++;

        return *this;
    }

    const Circle &Circle::operator--(int) throw(NegativityException){  //postfix
        if(cx == 0 || cy == 0){
            throw NegativityException();
        }
        static Circle temp = *this;
        temp = *this;
        --(*this);

        return temp;
    }

    Circle &Circle::operator--()throw(NegativityException) {
        if(cx == 0 || cy == 0){
            throw NegativityException();
        }
        cx--;
        cy--;

        return *this;
    }

    Circle::Circle(const double &radius, const double &centerx, const double &centery) {
        if (testValue(radius) && testValue(centerx) && testValue(centery)) {
            r = radius;
            cx = centerx;
            cy = centery;
            perimeterlength = 2 * PI * r;
            area = PI * r * r;
        }
    }

//constructor
    Circle::Circle(const double &radius) {
        if (testValue(radius)) {
            r = radius;
            cx = radius;
            cy = radius;
            perimeterlength = 2 * PI * r;
            area = PI * r * r;
            shapetype = ShapeType::Circle;
        }
    }

//no parameter constructor
    Circle::Circle(void) {
        r = 100;
        cx = 100;
        cy = 100;
        perimeterlength = 2 * PI * r;
        area = PI * r * r;
        shapetype = ShapeType::Circle;
    }

// setter functions
    void Circle::setRadius(const double &radius) {
        if (testValue(radius))
            r = radius;
        if (cx < r)
            cx = r;
        if (cy < r)
            cy = r;
        perimeterlength = 2 * PI * r;
        area = PI * r * r;
    }

    void Circle::setX(const double &centerx) {
        if (testValue(centerx))
            cx = centerx;
    }

    void Circle::setY(const double &centery) {
        if (testValue(centery))
            cy = centery;
    }

    void Circle::output(ostream &outputStream) {
        outputStream << "<circle cx=\"" << cx << "\"";
        outputStream << " cy=\"" << cy << "\"";
        outputStream << " r=\"" << r << "\" stroke=\"black\" stroke-width=\"1\" fill=\"blue\" />" << endl;
    }

    void Circle::draw(ofstream &myfile) {
        startSVG(myfile, r, r);
        myfile << *this;
        endSVG(myfile);
    }
    //Clone funtion to use in other functions
    Circle *Circle::duplicatefunction(void) {
        return new Circle(*this);
    }
}