
#ifndef POLYGON_H
#define POLYGON_H

#include <fstream>
#include <vector>
#include "Rectangle.h"
#include "Triangle.h"
#include "Circle.h"

namespace HW4_171044053{
    class Polygon {
    public:
        class Point2D{
        public:
            Point2D(void);
            Point2D(const double &coordx, const double &coordy);

            double getX(void)const{return x;};
            double getY(void)const{return y;}
            void setX(const double &coordx);
            void setY(const double &coordy);
        private:
            double x, y;
        };
        Polygon(const Point2D &Point);
        Polygon(const vector <Point2D> PPoints );
        Polygon(const Rectangle &rect);
        Polygon(const Circle &circ);
        Polygon(const Triangle &tri);
        Polygon(void);

        Point2D* getArray(void)const{return Coordinate;};
        int getSize(void)const {return size;};

        void setArray(const int &index, const Point2D &newCoord);
        void changeArraySize(const int &Size);
        void setSize(const int &Size);

        const Point2D &operator [](const int &i);
        bool operator ==(const Polygon &compare);
        bool operator !=(const Polygon &compare);
        const Polygon operator +(Polygon &add);
        friend ofstream& operator<<(ofstream& outputStream, const Polygon &P);

        Polygon& operator =(const Polygon& rtSide);
        ~Polygon(void);
        Polygon(const Polygon& pfaObject);
    private:
        Point2D *Coordinate;
        int size;
    };
}
#endif //POLYGON_H


