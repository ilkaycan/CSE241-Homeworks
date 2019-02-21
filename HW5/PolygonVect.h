#ifndef HW5_POLYGONVECT_H
#define HW5_POLYGONVECT_H
#include "NoParamConstructorException.h"
#include "Polygon.h"
namespace GTU{
class PolygonVect : public Polygon{
public:
    PolygonVect(const Polygon::Point2D &Point);
    PolygonVect(const vector <Polygon::Point2D> PPoints );
    PolygonVect(const Rectangle &rect);
    PolygonVect(const Circle &circ);
    PolygonVect(const Triangle &tri);
    PolygonVect(void)throw(NoParamConstructorException);

    vector<Polygon::Point2D> getVector(void)const{return Coordinate;};

    void output(ostream &outputStream);
    PolygonVect *duplicatefunction(void);

    void draw(ofstream &myfile);
    double getArea(void);
    double getPerimeter(void);

    const PolygonVect &operator ++(int); //postfix
    PolygonVect &operator ++();
    const PolygonVect &operator --(int)throw(NegativityException); //postfix
    PolygonVect &operator --()throw(NegativityException);
    virtual ShapeType getShapetype(void)const{ return ShapeType::Circle;};

private:
    vector <Polygon::Point2D> Coordinate;
    double area=0.0, perimeter=0.0;

};
}

#endif //HW5_POLYGONVECT_H
