#ifndef HW_RECTANGLE_H
#define HW_RECTANGLE_H
#include<fstream>

using namespace std;

class Rectangle {
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
    double getArea(void)const {return area;};
    double getPerimeter(void)const{return perimeterlength;};

    void draw(ofstream &myfile);

    ostream& output(ostream& outputStream)const;
    const Rectangle operator +(double& change);
    const Rectangle operator -(double& change);
    Rectangle operator ++(int); //postfix
    Rectangle operator ++();
    Rectangle operator --(int); //postfix
    Rectangle operator --();
    bool operator <(const Rectangle& compare);
    bool operator >(const Rectangle& compare);
    bool operator <=(const Rectangle& compare);
    bool operator >=(const Rectangle& compare);
    bool operator ==(const Rectangle& compare);
    bool operator !=(const Rectangle& compare);
    static double totalAreafunc(void){return totalArea;};
    static double totalPerimeterfunc(void){return totalPerimeter;};
private:
    bool testValue(const double &num)const;
    double Side1, Side2, area, perimeterlength;
    double x, y;
    static double totalArea, totalPerimeter;
};


#endif //HW_RECTANGLE_H
