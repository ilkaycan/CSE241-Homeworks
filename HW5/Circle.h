#ifndef HW5_CIRCLE_H
#define HW5_CIRCLE_H

#include "Shape.h"
#include <fstream>
#include "NegativityException.h"

using namespace std;
namespace GTU {
    class Circle : public Shape {
    public:
        const Circle &operator++(int); //postfix
        Circle &operator++();
        const Circle &operator--(int) throw(NegativityException); //postfix
        Circle &operator--()throw(NegativityException);

        void output(ostream &outputStream);
        void draw(ofstream &myfile);

        Circle *duplicatefunction(void);
        Circle(const double &radius, const double &centerx, const double &centery);
        Circle(const double &radius);
        Circle(void);

        void setRadius(const double &radius);
        void setX(const double &centerx);
        void setY(const double &centery);
        double getRadius(void) const { return r; };
        ShapeType getShapetype(void) const { return shapetype; };
        double getCx(void) const { return cx; };
        double getCy(void) const { return cy; };
        double getArea(void);
        double getPerimeter(void);
    private:
        double r, area, perimeterlength;
        double cx, cy;
        ShapeType shapetype;
    };
}

#endif //HW5_CIRCLE_H
