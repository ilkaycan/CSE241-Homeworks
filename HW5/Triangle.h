#ifndef HW5_TRIANGLE_H
#define HW5_TRIANGLE_H

#include "Shape.h"
#include "NegativityException.h"

namespace GTU {
    class Triangle : public Shape {
    public:
        Triangle(const double &side);
        Triangle();
        Triangle(const double &side, const double &coorx1, const double &coory1,
                 const double &coorx2, const double &coory2, const double &coorx3,
                 const double &coory3);

        void setSide(const double &side);
        void setX1(const double &coorx1);
        void setY1(const double &coory1);
        void setX2(const double &coorx2);
        void setY2(const double &coory2);
        void setX3(const double &coorx3);
        void setY3(const double &coory3);

        inline double getSide(void) const { return Side; };
        inline ShapeType getShapetype(void) const { return shapetype; };
        inline double getX1(void) const { return x1; };
        inline double getY1(void) const { return y1; };
        inline double getX2(void) const { return x2; };
        inline double getY2(void) const { return y2; };
        inline double getX3(void) const { return x3; };
        inline double getY3(void) const { return y3; };
        double getArea(void);
        double getPerimeter(void);

        const Triangle &operator++(int); //postfix
        Triangle &operator++();
        const Triangle &operator--(int)throw(NegativityException); //postfix
        Triangle &operator--()throw(NegativityException);

        void output(ostream &outputStream);
        void draw(ofstream &myfile);

        Triangle *duplicatefunction(void);

    private:
        double Side, area, perimeterlength;
        double x1, x2, x3, y1, y2, y3;
        ShapeType shapetype;
    };
}

#endif //HW5_TRIANGLE_H
