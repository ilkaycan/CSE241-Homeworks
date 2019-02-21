#include "Polyline.h"
#include <iostream>
#include <cmath>
#define PI 3.1415926535897

namespace HW4_171044053 {
    //Constructors of Polyline class
    Polyline::Polyline(const Polygon::Point2D &Point) {

        Polygon A(Point);
        Composition = A;


    }

    Polyline::Polyline(const vector<Polygon::Point2D> PPoints) {

        Polygon A(PPoints);
        Composition = A;

    }

    Polyline::Polyline(const Rectangle &rect) {

        Polygon A(rect);
        Composition = A;

    }

    Polyline::Polyline(const Triangle &tri) {

        Polygon A(tri);
        Composition = A;

    }

    Polyline::Polyline(const Circle &circ) {

        Polygon A(circ);
        Composition = A;

    }

    // This is << overload
    ofstream &operator<<(ofstream &outputStream, const Polyline &P) {
        outputStream << "<svg version=\"1.1\" " << endl << "baseProfile=\"full\"" << endl;
        outputStream << "width=" << "\"" << 500 << "\"";
        outputStream << " height=" << "\"" << 500 << "\"" << endl;
        outputStream << "xmlns=\"http://www.w3.org/2000/svg\">" << endl;
        outputStream << "<polyline points=\"";
        for (int i = 0; i < P.getPolygon().getSize(); i++) {
            outputStream << P.getPolygon().getArray()[i].getX() << "," << P.getPolygon().getArray()[i].getY() << " ";

        }
        outputStream << "\"" << endl;
        outputStream << "stroke=\"black\" stroke-width=\"3\" fill=\"blue\" />" << endl;
        outputStream << "</svg>" << endl;

        return outputStream;
    }

    // [] operator is overloaded for Polyline class
    const Polygon::Point2D &Polyline::operator[](const int &i) {
        if (i > Composition.getSize() - 1) {
            cerr << "Index is greater than size of array" << endl;
            exit(EXIT_FAILURE);
        }

        return Composition.getArray()[i];

    }

    //+ operator is overloaded for Polyline class
    const Polyline Polyline::operator+(Polyline &add) {
        vector<Polygon::Point2D> newVector;

        for (int i = 0; i < Composition.getSize(); i++) {
            newVector.push_back(Composition.getArray()[i]);
        }
        for (int j = 0; j < add.getPolygon().getSize(); j++) {
            newVector.push_back(add.getPolygon().getArray()[j]);
        }

        return Polyline(newVector);
    }

    //Comparison operators overloaded for Polyline class
    bool Polyline::operator==(const Polyline &compare) {
        if (Composition.getSize() != compare.getPolygon().getSize()) {
            return false;
        }
        for (int i = 0; i < Composition.getSize(); i++) {
            if (Composition.getArray()[i].getX() != compare.getPolygon().getArray()[i].getX()) {
                return false;
            } else if (Composition.getArray()[i].getY() != compare.getPolygon().getArray()[i].getY()) {
                return false;
            }
        }
        return true;
    }

    bool Polyline::operator!=(const Polyline &compare) {
        if (Composition.getSize() == compare.getPolygon().getSize()) {
            return false;
        }
        for (int i = 0; i < Composition.getSize(); i++) {
            if (Composition.getArray()[i].getX() == compare.getPolygon().getArray()[i].getX()) {
                return false;
            } else if (Composition.getArray()[i].getY() == compare.getPolygon().getArray()[i].getY()) {
                return false;
            }
        }
        return true;
    }

    //Big THREE
    Polyline &Polyline::operator=(const Polyline &rtSide) {
        if (Composition.getSize() != rtSide.getPolygon().getSize()) {
            Composition.setSize(rtSide.getPolygon().getSize());
            Composition.changeArraySize(rtSide.getPolygon().getSize());
        }

        for (int i = 0; i < Composition.getSize(); i++) {
            Composition.setArray(i, rtSide.getPolygon().getArray()[i]);
        }

        return *this;

    }

    Polyline::~Polyline(void) {
        //Intentionally empty
        //Don't have a pointer data member
    }

    Polyline::Polyline(const Polyline &pfaObject) {
        Composition.setSize(pfaObject.getPolygon().getSize());
        Composition.changeArraySize(pfaObject.getPolygon().getSize());

        for (int i = 0; i < Composition.getSize(); i++) {
            Composition.setArray(i, pfaObject.getPolygon().getArray()[i]);
        }
    }
}
