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
    ComposedShape(const Rectangle &Contain, const Rectangle &Small);
    ComposedShape(const Rectangle &Contain, const Circle &Small);
    ComposedShape(const Rectangle &Contain, const Triangle &Small);
    ComposedShape(const Triangle &Contain, const Rectangle &Small);
    ComposedShape(const Triangle &Contain, const Triangle &Small);
    ComposedShape(const Triangle &Contain, const Circle &Small);
    ComposedShape(const Circle &Contain, const Rectangle &Small);
    ComposedShape(const Circle &Contain, const Circle &Small);
    ComposedShape(const Circle &Contain, const Triangle &Small);
    ComposedShape(void);

    void optimalFit();
    void draw(ofstream &myfile) const;
    Shape getShapeContain(void)const {return shapeContain;} ;
    Shape getShapeSmall(void)const {return shapeSmall;};

    vector<Rectangle> getVectorR(void) const{return vectorR;}
    vector<Triangle> getVectorT(void) const{return vectorT;};
    vector<Circle> getVectorC(void) const{return vectorC;};
private:
    Shape shapeContain, shapeSmall;

    Rectangle RContain, RSmall;
    vector<Rectangle> vectorR;
    inline void RRoptimal();
    inline void RToptimal();
    inline void RCoptimal();

    Triangle TContain, TSmall;
    vector<Triangle> vectorT;
    inline void TRoptimal();
    inline void TToptimal();
    inline void TCoptimal();

    Circle CContain, CSmall;
    vector<Circle> vectorC;
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
