#ifndef HW5_RECTANGLE_H
#define HW5_RECTANGLE_H

#include "Shape.h"
namespace GTU{

class Rectangle : public Shape{
public:
    Rectangle(const double &width, const double &height, const double &coordinatex, const double &coordinatey);
    Rectangle(const double &width, const double &height);
    Rectangle(void);

    void setSide1(const double &width ) ;
    void setSide2(const double &height );
    void setX(const double &coordinatex );
    void setY(const double &coordinatey );

    double getSide1(void)const {return Side1;};
    double getSide2(void)const {return Side2;};
    double getX(void)const {return x;};
    double getY(void)const {return y;};
    double getArea(void);
    double getPerimeter(void);
    ShapeType getShapetype(void)const{return shapetype;};

    const Rectangle &operator ++(int); //postfix
    Rectangle &operator ++();
    const Rectangle &operator --(int)throw(NegativityException); //postfix
    Rectangle &operator --()throw(NegativityException);

    void output(ostream &outputStream);
    void draw(ofstream &myfile);

    Rectangle *duplicatefunction(void);


private:
    double Side1, Side2, area, perimeterlength;
    double x, y;
    ShapeType shapetype;
};
}

#endif //HW5_RECTANGLE_H
