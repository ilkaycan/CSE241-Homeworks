#ifndef HW5_POLYGON_H
#define HW5_POLYGON_H
#include "Shape.h"
#include <fstream>
#include <vector>
#include "Rectangle.h"
#include "Triangle.h"
#include "Circle.h"
namespace GTU {
    class Polygon : public Shape {
    public:
        class Point2D {
        public:
            Point2D(void);
            Point2D(const double &coordx, const double &coordy);

            double getX(void) const { return x; };
            double getY(void) const { return y; }

            void setX(const double &coordx);
            void setY(const double &coordy);

        private:
            double x, y;
        };
    };
}

#endif //HW5_POLYGON_H
