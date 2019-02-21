#ifndef HW_CIRCLE_H
#define HW_CIRCLE_H
#include <fstream>
using namespace std;

class Circle {
public:
    Circle(const double &radius, const double &centerx, const double &centery);
    Circle(const double &radius);
    Circle(void);
    void setRadius(const double &radius) ;
    void setX(const double &centerx );
    void setY(const double &centery );
    double getRadius(void)const {return r;};
    double getCx(void)const {return cx;};
    double getCy(void)const {return cy;};
    double getArea(void)const{return area;};
    double getPerimeter(void)const{return perimeterlength;};

    void draw(ofstream &myfile);

    ostream& output(ostream& outputStream)const;
    const Circle operator +(double& change);
    const Circle operator -(double& change);
    Circle operator ++(int); //postfix
    Circle operator ++();
    Circle operator --(int); //postfix
    Circle operator --();
    bool operator <(const Circle& compare);
    bool operator >(const Circle& compare);
    bool operator <=(const Circle& compare);
    bool operator >=(const Circle& compare);
    bool operator ==(const Circle& compare);
    bool operator !=(const Circle& compare);
    static double totalAreafunc(void){return totalArea;};
    static double totalPerimeterfunc(void){return totalPerimeter;};
private:
    bool testValue(const double &num)const;
    double r, area, perimeterlength;
    double cx, cy;
    static double totalArea, totalPerimeter;
};



#endif //HW_CIRCLE_H
