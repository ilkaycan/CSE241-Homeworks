#ifndef HW_TRIANGLE_H
#define HW_TRIANGLE_H
#include <fstream>
using namespace std;

class Triangle {
public:
    Triangle(const double &side, const double &coorx1, const double &coory1,
            const double &coorx2, const double &coory2, const double &coorx3,
            const double &coory3);
    Triangle(const double &side);
    Triangle();
    void setSide(const double &side ) ;
    void setX1(const double &coorx1);
    void setY1(const double &coory1);
    void setX2(const double &coorx2);
    void setY2(const double &coory2);
    void setX3(const double &coorx3);
    void setY3(const double &coory3);

    double getSide(void)const {return Side;};
    double getX1(void)const {return x1;};
    double getY1(void)const {return y1;};
    double getX2(void)const {return x2;};
    double getY2(void)const {return y2;};
    double getX3(void)const {return x3;};
    double getY3(void)const {return y3;};
    double getArea(void)const{return area;};
    double getPerimeter(void)const{return perimeterlength;};

    void draw(ofstream &myfile);

    ostream& output(ostream& outputStream)const;
    const Triangle operator +(double& change);
    const Triangle operator -(double& change);
    Triangle operator ++(int); //postfix
    Triangle operator ++();
    Triangle operator --(int); //postfix
    Triangle operator --();
    bool operator <(const Triangle& compare);
    bool operator >(const Triangle& compare);
    bool operator <=(const Triangle& compare);
    bool operator >=(const Triangle& compare);
    bool operator ==(const Triangle& compare);
    bool operator !=(const Triangle& compare);
    static double totalAreafunc(void){return totalArea;};
    static double totalPerimeterfunc(void){return totalPerimeter;};
private:
    bool testValue(const double &num)const;
    double Side, area, perimeterlength;
    double x1, x2, x3, y1, y2, y3;
    static double totalArea, totalPerimeter;
};


#endif //HW_TRIANGLE_H
