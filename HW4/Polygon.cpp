#include <iostream>
#include <cmath>
#include "Polygon.h"
#define PI 3.1415926535897

namespace HW4_171044053 {
    //Constructors for Point2D class
    Polygon::Polygon(void) {
        Point2D A(0, 0);
        size = 1;
        Coordinate = new Point2D[1];

        Coordinate[0] = A;

    }

    Polygon::Point2D::Point2D(void) {
        x = 0;
        y = 0;
    }

    Polygon::Point2D::Point2D(const double &coordx, const double &coordy) {
        x = coordx;
        y = coordy;
    }

    // Setters of Point2D class
    void Polygon::Point2D::setX(const double &coordx) {
        x = coordx;
    }

    void Polygon::Point2D::setY(const double &coordy) {
        y = coordy;
    }

    //Constructors of Polygon class
    Polygon::Polygon(const Point2D &Point) {
        size = 1;
        Coordinate = new Point2D[1];

        Coordinate[0] = Point;
    }

    Polygon::Polygon(const vector<Point2D> PPoints) {
        size = PPoints.size();
        Coordinate = new Point2D[size];

        for (int i = 0; i < size; i++) {
            Coordinate[i] = PPoints[i];
        }
    }

    Polygon::Polygon(const Rectangle &rect) {
        Coordinate = new Point2D[4];
        size = 4;
        Coordinate[0].setX(rect.getX());
        Coordinate[0].setY(rect.getY());
        Coordinate[1].setX(rect.getX() + rect.getSide1());
        Coordinate[1].setY(rect.getY());
        Coordinate[2].setX(rect.getX() + rect.getSide1());
        Coordinate[2].setY(rect.getY() + rect.getSide2());
        Coordinate[3].setX(rect.getX());
        Coordinate[3].setY(rect.getY() + rect.getSide2());
    }

    Polygon::Polygon(const Triangle &tri) {
        Coordinate = new Point2D[3];
        size = 3;
        Coordinate[0].setX(tri.getX1());
        Coordinate[0].setY(tri.getY1());
        Coordinate[1].setX(tri.getX2());
        Coordinate[1].setY(tri.getY2());
        Coordinate[2].setX(tri.getX3());
        Coordinate[2].setY(tri.getY3());
    }

    Polygon::Polygon(const Circle &circ) {
        Coordinate = new Point2D[100];

        size = 100;

        double angle = 0;
        double change = 3.6;

        for (int i = 0; i < 100; i++) {
            Coordinate[i].setX(circ.getCx() + (circ.getRadius() * cos((angle + (i * change)) * PI / 180.0)));
            Coordinate[i].setY(circ.getCy() + (circ.getRadius() * sin((angle + (i * change)) * PI / 180.0)));
        }
    }

    // This is a helper function to << overload
    ofstream &operator<<(ofstream &outputStream, const Polygon &P) {

        outputStream << "<polygon points=\"";
        for (int i = 0; i < P.getSize(); i++) {
            outputStream << P.getArray()[i].getX() << "," << P.getArray()[i].getY() << " ";

        }
        outputStream << "\"" << endl;
        outputStream << "stroke=\"black\" stroke-width=\"1\" fill=\"purple\" />" << endl;

        return outputStream;
    }

    // [] operator is overloaded for Polygon class
    const Polygon::Point2D &Polygon::operator[](const int &i) {
        if (i > size - 1) {
            cerr << "Index is greater than size of array" << endl;
            exit(EXIT_FAILURE);
        }

        return Coordinate[i];

    }

    //+ operator is overloaded for Polygon class
    const Polygon Polygon::operator+(Polygon &add) {
        vector<Polygon::Point2D> newVector;

        for (int i = 0; i < size; i++) {
            newVector.push_back(Coordinate[i]);
        }
        for (int j = 0; j < add.getSize(); j++) {
            newVector.push_back(add.getArray()[j]);
        }

        return Polygon(newVector);
    }

    //Equality comparison operators overloaded for Polygon class
    bool Polygon::operator==(const Polygon &compare) {
        if (size != compare.getSize()) {
            return false;
        }
        for (int i = 0; i < size; i++) {
            if (Coordinate[i].getX() != compare.getArray()[i].getX()) {
                return false;
            } else if (Coordinate[i].getY() != compare.getArray()[i].getY()) {
                return false;
            }
        }
        return true;
    }

    bool Polygon::operator!=(const Polygon &compare) {
        if (size == compare.getSize()) {
            for (int i = 0; i < size; i++) {
                if (Coordinate[i].getX() != compare.getArray()[i].getX()) {
                    return true;
                } else if (Coordinate[i].getY() != compare.getArray()[i].getY()) {
                    return true;
                }
            }
            return false;
        } else
            return true;
    }

    //Big Three
    //Assignment operator overloading
    Polygon &Polygon::operator=(const Polygon &rtSide) {
        if (size != rtSide.getSize()) {
            delete[] Coordinate;
            Coordinate = new Point2D[rtSide.getSize()];
            size = rtSide.getSize();
        }

        for (int i = 0; i < size; i++) {
            Coordinate[i] = rtSide.getArray()[i];
        }

        return *this;

    }

    //Destructor
    Polygon::~Polygon(void) {
        delete[] Coordinate;
    }

    //Copy constructor
    Polygon::Polygon(const Polygon &pfaObject) : size(pfaObject.getSize()) {
        Coordinate = new Point2D[size];

        for (int i = 0; i < size; i++) {
            Coordinate[i] = pfaObject.getArray()[i];
        }
    }

    void Polygon::setSize(const int &Size) {
        size = Size;
    }

    void Polygon::changeArraySize(const int &Size) {
        delete[] Coordinate;

        Coordinate = new Polygon::Point2D[Size];
    }

    void Polygon::setArray(const int &index, const Polygon::Point2D &newCoord) {
        if (size < index + 1) {
            cerr << "This index doesn't exist" << endl;
            exit(EXIT_FAILURE);
        }
        Coordinate[index] = newCoord;
    }
}
