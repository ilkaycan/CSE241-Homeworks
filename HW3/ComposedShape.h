#ifndef HW_COMPOSEDSHAPE_H
#define HW_COMPOSEDSHAPE_H

#include <iostream>
#include <fstream>
#include <vector>
#include<cmath>
#include "Rectangle.h"
#include "Triangle.h"
#include "Circle.h"

#define SQRT3 1.73205080757
#define PI 3.1415926535897

using namespace std;
enum class Shape {Rectangle, Triangle, Circle};
class ComposedShape {
public:
    class ShapeElem{
    public:
        ShapeElem(Rectangle &rect);
        ShapeElem(Triangle &tri);
        ShapeElem(Circle &circ);

        void* SmallShape;
        Shape shape;

        double getareaElem(void);
        double getperimeterElem(void);

        ostream& output(ostream& outputStream)const;
    };
    ComposedShape(const Rectangle &Contain, Rectangle Small);
    ComposedShape(const Rectangle &Contain, Circle Small);
    ComposedShape(const Rectangle &Contain, Triangle Small);
    ComposedShape(const Triangle &Contain, Rectangle Small);
    ComposedShape(const Triangle &Contain, Triangle Small);
    ComposedShape(const Triangle &Contain, Circle Small);
    ComposedShape(const Circle &Contain, Rectangle Small);
    ComposedShape(const Circle &Contain, Circle Small);
    ComposedShape(const Circle &Contain, Triangle Small);
    ComposedShape(void);

    void optimalFit();
    void draw(ofstream &myfile) const;
    Shape getShapeContain(void)const {return shapeContain;} ;
    Shape getShapeSmall(void)const {return shapeSmall; }


    ostream& output(ostream& outputStream)const;
    ComposedShape::ShapeElem operator [](Rectangle &rect);
    ComposedShape::ShapeElem operator [](Triangle &tri);
    ComposedShape::ShapeElem operator [](Circle &circ);

    const ComposedShape operator +=(Rectangle &rect);
    const ComposedShape operator +=(Triangle &tri);
    const ComposedShape operator +=(Circle &circ);

private:
    Shape shapeContain, shapeSmall;

    vector<ShapeElem> InnerShape;

    Rectangle RContain;
    Rectangle RSmall;
    inline void RRoptimal();
    inline void RToptimal();
    inline void RCoptimal();

    Triangle TContain;
    Triangle TSmall;
    inline void TRoptimal();
    inline void TToptimal();
    inline void TCoptimal();

    Circle CContain;
    Circle CSmall;
    inline void CRoptimal();
    inline void CToptimal();
    inline void CCoptimal();

    bool checkRectInCircle(const double &x, const double &y, const double &SmallA,
            const double &SmallB, const double &ContainA)const;
    bool checkTriInCircle(const double &x1, const double &y1,const double &x2,const double &y2,
            const double& x3, const double &y3, const double &ContainA)const;
    bool checkCircleInCircle(const double &cx, const double &cy, const double &SmallA,
                             const double &ContainA)const;

    void startSVG(ofstream &myfile, const double &width, const double &height)const;

};


#endif //HW_COMPOSEDSHAPE_H
