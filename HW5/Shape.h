#ifndef HW5_SHAPE_H
#define HW5_SHAPE_H
#include <vector>
#include <fstream>
#include "NegativityException.h"

using namespace std;
namespace GTU{

enum class ShapeType {Rectangle, Triangle, Circle};

class Shape {
public:
    virtual double getArea(void)=0;
    virtual double getPerimeter(void)=0;
    virtual const Shape &operator ++(int)=0; //postfix
    virtual Shape &operator ++()=0;
    virtual const Shape &operator --(int)=0; //postfix
    virtual  Shape &operator --()=0;
    bool operator <( Shape& compare);
    bool operator >( Shape& compare);
    bool operator <=( Shape& compare);
    bool operator >=( Shape& compare);
    bool operator ==( Shape& compare);
    bool operator !=( Shape& compare);
    bool testValue(const double &num)const throw(NegativityException);

    virtual ShapeType getShapetype(void)const=0;
    virtual void output(ostream &outputStream)=0;
    virtual Shape *duplicatefunction(void)=0;
    void startSVG(ofstream &myfile, const double &width, const double &height)const;
    void endSVG(ofstream &myfile);
    virtual void draw(ofstream &myfile)=0;
protected:

};
ostream& operator <<(ostream& outputStream, Shape &S);
}

#endif //HW5_SHAPE_H
