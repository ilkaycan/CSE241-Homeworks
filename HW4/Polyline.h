#ifndef POLYLINE_H
#define POLYLINE_H

#include <fstream>
#include <vector>
#include "Polygon.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Circle.h"


namespace HW4_171044053{
    class Polyline {
    public:
        Polyline(const Polygon::Point2D &Point);
        Polyline(const vector <Polygon::Point2D> PPoints );
        Polyline(const Rectangle &rect);
        Polyline(const Circle &circ);
        Polyline(const Triangle &tri);

        Polygon getPolygon(void)const {return Composition;};
        const Polygon::Point2D &operator [](const int &i);
        bool operator ==(const Polyline &compare);
        bool operator !=(const Polyline &compare);
        const Polyline operator +(Polyline &add);
        friend ofstream& operator<<(ofstream& outputStream, const Polyline &P);

        Polyline& operator =(const Polyline& rtSide);
        ~Polyline(void);
        Polyline(const Polyline& pfaObject);
    private:
        Polygon Composition;
    };
}


#endif //POLYLINE_H


