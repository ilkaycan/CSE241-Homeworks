
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

    void draw(ofstream &myfile);
private:
    bool testValue(const double &num)const;
    double r;
    double cx, cy;
};


#endif //HW_CIRCLE_H
