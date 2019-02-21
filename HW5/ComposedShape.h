#ifndef HW5_COMPOSEDSHAPE_H
#define HW5_COMPOSEDSHAPE_H
#include <iostream>
#include <fstream>
#include <vector>
#include<cmath>
#include "Rectangle.h"
#include "Triangle.h"
#include "Circle.h"
#include "NoParamConstructorException.h"


#define SQRT3 1.73205080757
#define PI 3.1415926535897

using namespace std;
namespace GTU {

    class ComposedShape : public Shape {
    public:
        ComposedShape(const Rectangle &Contain, Rectangle Small);
        ComposedShape(const Rectangle &Contain, Circle Small);
        ComposedShape(const Rectangle &Contain, Triangle Small);
        ComposedShape(const Triangle &Contain, Rectangle Small);
        ComposedShape(const Triangle &Contain, Triangle Small);
        ComposedShape(const Triangle &Contain, Circle Small);
        ComposedShape(const Circle &Contain, Rectangle Small);
        ComposedShape(const Circle &Contain, Circle Small);
        ComposedShape(const Circle &Contain, Triangle Small);
        ComposedShape(void) throw(NoParamConstructorException);

        ShapeType getShapeContain(void) const { return shapeContain; };
        ShapeType getShapeSmall(void) const { return shapeSmall; }
        vector<Shape *> getVector(void) const { return InnerShape; };
        ShapeType getShapetype(void) const { return ShapeType::Circle; };
        double getArea(void);
        double getPerimeter(void);

        void optimalFit();
        void output(ostream &outputStream);
        void draw(ofstream &myfile);

        const ComposedShape &operator++(int); //postfix
        ComposedShape &operator++();
        const ComposedShape &operator--(int); //postfix
        ComposedShape &operator--();

        ComposedShape *duplicatefunction(void);

        ComposedShape(const ComposedShape &copyObject);
        ComposedShape &operator=(const ComposedShape &rtSide);
        ~ComposedShape(void);

    private:
		//ComposedShape *tempCom;	
	
        vector<Shape *> InnerShape;

        Shape *ptr;
        ShapeType shapeContain, shapeSmall;

        Rectangle RContain;
        Rectangle RSmall;
        void RRoptimal();
        void RToptimal();
        void RCoptimal();

        Triangle TContain;
        Triangle TSmall;
        void TRoptimal();
        void TToptimal();
        void TCoptimal();

        Circle CContain;
        Circle CSmall;
        void CRoptimal();
        void CToptimal();
        void CCoptimal();

        bool checkRectInCircle(const double &x, const double &y, const double &SmallA,
                               const double &SmallB, const double &ContainA) const;

        bool checkTriInCircle(const double &x1, const double &y1, const double &x2, const double &y2,
                              const double &x3, const double &y3, const double &ContainA) const;

        bool checkCircleInCircle(const double &cx, const double &cy, const double &SmallA,
                                 const double &ContainA) const;

    };
}

#endif //HW5_COMPOSEDSHAPE_H
