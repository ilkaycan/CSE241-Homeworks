#ifndef HW5_POLYGONDYN_H
#define HW5_POLYGONDYN_H
#include "NoParamConstructorException.h"
#include "Polygon.h"
namespace GTU{
class PolygonDyn : public Polygon {
public:
    PolygonDyn(const Polygon::Point2D &Point);
    PolygonDyn(const vector <Polygon::Point2D> PPoints );
    PolygonDyn(const Rectangle &rect);
    PolygonDyn(const Circle &circ);
    PolygonDyn(const Triangle &tri);
    PolygonDyn(void)throw(NoParamConstructorException);

    Polygon::Point2D* getArray(void)const{return Coordinate;};
    int getSize(void)const {return size;};

    void setArray(const int &index, const Polygon::Point2D &newCoord);
    void changeArraySize(const int &Size);
    void setSize(const int &Size);

    void output(ostream &outputStream);
    PolygonDyn *duplicatefunction(void);

    void draw(ofstream &myfile);
    double getArea(void);
    double getPerimeter(void);

    const PolygonDyn &operator ++(int); //postfix
    PolygonDyn &operator ++();
    const PolygonDyn &operator --(int)throw(NegativityException); //postfix
    PolygonDyn &operator --()throw(NegativityException);

    virtual ShapeType getShapetype(void)const{ return ShapeType::Circle;};
    PolygonDyn& operator =(const PolygonDyn& rtSide);
    ~PolygonDyn(void);
    PolygonDyn(const PolygonDyn& copyobj);
private:
    Polygon::Point2D *Coordinate;
    int size;
    double area=0.0, perimeter=0.0;
};
}


#endif //HW5_POLYGONDYN_H
