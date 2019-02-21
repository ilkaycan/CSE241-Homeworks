#include "ComposedShape.h"
#include <iostream>
#include <fstream>
#include <vector>
#include<cmath>
#include "Rectangle.h"
#include "Triangle.h"
#include "Circle.h"
#define PI 3.1415926535897
#define SQRT3 1.73205080757

using namespace HW4_171044053;
using std::cout;
using std::endl;
using std::exit;
using std::cerr;
//checks if circle rectangle fits in circle by
//If [(x-x0)^2+(y-y0)^2]^0.5 <= R-r
bool ComposedShape::checkCircleInCircle(const double &cx, const double &cy, const double &SmallA,
                                        const double &ContainA)const{
    bool result = false;
    double x, y;

    x = (ContainA - cx) * (ContainA - cx);
    y = (ContainA - cy) * (ContainA - cy);

    if ( (ContainA-SmallA) >= sqrt(x+y) ){
        result = true;
    }

    return result;
}
//checks if given rectangle fits in circle by
//(x-a)^2 + (y-b)^2 = r^2
bool ComposedShape::checkRectInCircle(const double &x, const double &y, const double &SmallA,
                                      const double &SmallB, const double &ContainA)const{
    double xdownleft = x, ydownleft = y+SmallB;
    double xupright = x+SmallA, yupright = y, xdownright = x+SmallA, ydownright = y+SmallB;
    bool result = false;

    if( ( ( ((x-ContainA)*(x-ContainA)) + ((y-ContainA)*(y-ContainA)) ) <= (ContainA*ContainA) ) &&
        ( ( ((xdownleft-ContainA)*(xdownleft-ContainA)) + ((ydownleft-ContainA)*(ydownleft-ContainA)) ) <= (ContainA*ContainA) ) &&
        ( ( ((xupright-ContainA)*(xupright-ContainA)) + ((yupright-ContainA)*(yupright-ContainA)) ) <= (ContainA*ContainA) ) &&
        ( ( ((xdownright-ContainA)*(xdownright-ContainA)) + ((ydownright-ContainA)*(ydownright-ContainA)) ) <= (ContainA*ContainA) ) ){
        result = true;
    }
    return result;
}
//checks if given triangle fits in circle by
//(x-a)^2 + (y-b)^2 = r^2
bool ComposedShape::checkTriInCircle(const double &x1, const double &y1,const double &x2,const double &y2,
                                     const double& x3, const double &y3, const double &ContainA)const{
    bool result = false;

    if( ((((x1-ContainA)*(x1-ContainA)) + ((y1-ContainA)*(y1-ContainA)) ) <= (ContainA*ContainA) ) &&
        ((((x2-ContainA)*(x2-ContainA)) + ((y2-ContainA)*(y2-ContainA)) ) <= (ContainA*ContainA) ) &&
        ((((x3-ContainA)*(x3-ContainA)) + ((y3-ContainA)*(y3-ContainA)) ) <= (ContainA*ContainA) )   ){
        result = true;
    }

    return result;
}
//constructors
ComposedShape::ComposedShape(const Rectangle &Contain, Rectangle Small){
    shapeContain = Shape::Rectangle;
    RContain = Contain;
    shapeSmall = Shape::Rectangle;
    RSmall = Small;

}
ComposedShape::ComposedShape(const Rectangle &Contain, Circle Small){
    shapeContain = Shape::Rectangle;
    RContain = Contain;
    shapeSmall = Shape::Circle;
    CSmall = Small;
}
ComposedShape::ComposedShape(const Rectangle &Contain, Triangle Small){
    shapeContain = Shape::Rectangle;
    RContain = Contain;
    shapeSmall = Shape::Triangle;
    TSmall = Small;
}
ComposedShape::ComposedShape(const Triangle &Contain, Rectangle Small){
    shapeContain = Shape::Triangle;
    TContain = Contain;
    shapeSmall = Shape::Rectangle;
    RSmall = Small;
}
ComposedShape::ComposedShape(const Triangle &Contain, Triangle Small){
    shapeContain = Shape::Triangle;
    TContain = Contain;
    shapeSmall = Shape::Triangle;
    TSmall = Small;
}
ComposedShape::ComposedShape(const Triangle &Contain, Circle Small){
    shapeContain = Shape::Triangle;
    TContain = Contain;
    shapeSmall = Shape::Circle;
    CSmall = Small;
}
ComposedShape::ComposedShape(const Circle &Contain, Rectangle Small){
    shapeContain = Shape::Circle;
    CContain = Contain;
    shapeSmall = Shape::Rectangle;
    RSmall = Small;
}
ComposedShape::ComposedShape(const Circle &Contain, Circle Small){
    shapeContain = Shape::Circle;
    CContain = Contain;
    shapeSmall = Shape::Circle;
    CSmall = Small;
}
ComposedShape::ComposedShape(const Circle &Contain, Triangle Small){
    shapeContain = Shape::Circle;
    CContain = Contain;
    shapeSmall = Shape::Triangle;
    TSmall = Small;
}
ComposedShape::ComposedShape(void){
    cerr << "You haven't specify any shapes..." << endl;
    exit(EXIT_FAILURE);
}
//We will draw small shapes in optimalFit so we don't want svg file to close
//Start end the end is controlled by these 2 functions
void ComposedShape::startSVG(ofstream &myfile,const double &width,const double &height)const{

    myfile << "<svg version=\"1.1\" " << endl << "baseProfile=\"full\"" << endl;
    myfile << "width=" << "\"" << width << "\"" ;
    myfile << " height=" << "\"" << height << "\""  << endl;
    myfile << "xmlns=\"http://www.w3.org/2000/svg\">" << endl;
}

//These 2 functions draw container shape and small shape
void ComposedShape::draw(ofstream &myfile) const{

    if ( shapeContain == Shape::Rectangle ){
        double x = RContain.getX();
        double y = RContain.getY();
        double width = RContain.getSide1();
        double height = RContain.getSide2();

        startSVG(myfile, width, height);
        myfile << "<rect width=\"100%\" height=\"100%\" stroke=\"black\" stroke-width=\"1\" fill=\"blue\" />" << endl;
    } else if ( shapeContain == Shape::Triangle){
        double x1 = TContain.getX1();
        double y1 = TContain.getY1();
        double x2 = TContain.getX2();
        double y2 = TContain.getY2();
        double x3 = TContain.getX3();
        double y3 = TContain.getY3();
        double Side = TContain.getSide();
        startSVG(myfile, Side, Side);

        myfile << "<polygon points=\"" << x1 << "," << y1 << " " << x2 << "," << y2 << " " << x3 ;
        myfile << "," << y3 << "\""<< endl;
        myfile << "stroke=\"black\" stroke-width=\"1\" fill=\"blue\" />" << endl;
    } else if ( shapeContain == Shape::Circle){
        double r = CContain.getRadius();
        double cx = CContain.getCx();
        double cy = CContain.getCy();

        startSVG(myfile, 2*r, 2*r);

        myfile << "<circle cx=\"" << cx << "\"";
        myfile << " cy=\"" << cy <<"\"";
        myfile << " r=\""<< r << "\" stroke=\"black\" stroke-width=\"1\" fill=\"blue\" />" << endl;
    } else {
        cerr << "Something went wrong :(" << endl;
        exit(EXIT_FAILURE);
    }

    for (auto i = 0; i < InnerShape.size() ; ++i){
        myfile << InnerShape[i];
    }


    myfile << "</svg>" << endl;
}

//This function calls suitable Shapeoptimal function and calculates areas and shape numbers
void ComposedShape::optimalFit(){
    double areaContain, areaSmall, shapeNum;
    if ( shapeContain == Shape::Rectangle ){
        areaContain = RContain.getArea();
        if ( shapeSmall == Shape::Rectangle ){
            RRoptimal();
        } else if ( shapeSmall == Shape::Triangle){
            RToptimal();
        } else if ( shapeSmall == Shape::Circle){
            RCoptimal();
        } else {
            cerr << "Something went wrong :(" << endl;
            exit(EXIT_FAILURE);
        }
    } else if ( shapeContain == Shape::Triangle){
        areaContain = TContain.getArea();
        if ( shapeSmall == Shape::Rectangle ){
            TRoptimal();
        } else if ( shapeSmall == Shape::Triangle){
            TToptimal();
        } else if ( shapeSmall == Shape::Circle){
            TCoptimal();
        } else {
            cerr << "Something went wrong :(" << endl;
            exit(EXIT_FAILURE);
        }
    } else if ( shapeContain == Shape::Circle){
        areaContain = CContain.getArea();
        if ( shapeSmall == Shape::Rectangle ){
            CRoptimal();
        } else if ( shapeSmall == Shape::Triangle){
            CToptimal();
        } else if ( shapeSmall == Shape::Circle){
            CCoptimal();
        } else {
            cerr << "Something went wrong :(" << endl;
            exit(EXIT_FAILURE);
        }
    } else {
        cerr << "Something went wrong :(" << endl;
        exit(EXIT_FAILURE);
    }
    shapeNum = InnerShape.size();
    if ( shapeSmall == Shape::Rectangle ){
        areaSmall = shapeNum * RSmall.getArea();
    } else if ( shapeSmall == Shape::Triangle){
        areaSmall = shapeNum * TSmall.getArea();
    } else if ( shapeSmall == Shape::Circle){
        areaSmall = shapeNum * CSmall.getArea();
    } else {
        cerr << "Something went wrong :(" << endl;
        exit(EXIT_FAILURE);
    }
    cout << "I can fit at most " << shapeNum << " small shapes into the main container." ;
    cout << " The empty area (blue) in container is " << areaContain - areaSmall << "." << endl;
}
//Shapeoptimal functions
//fits small shape in container shape and puts them in InnerShape vector
//InnerShape vector will be used in draw function and optimalFit function
inline void ComposedShape::RRoptimal(){
    double SmallA = RSmall.getSide1();
    double SmallB = RSmall.getSide2();
    double x = RSmall.getX();
    double y = RSmall.getY();
    double ContainA = RContain.getSide1();
    double ContainB = RContain.getSide2();
// decide if small shape is horizontal or vertical
    if((SmallA>=ContainA && SmallA<=ContainB && SmallB<=ContainA)||
       (SmallB>=ContainB && SmallB<=ContainA && SmallA<=ContainB) ){

        double temp = SmallA;
        SmallA = SmallB;
        SmallB = temp;
    }
    // outer loop is rows and inner loop is columns
    // and ranges are determined due to containers width and height
    for ( int i = (int)(ContainB/SmallB) ; i>0; i--){
        for(int j = (int)(ContainA/SmallA) ; j>0 ; j --){
            Rectangle rect(SmallA, SmallB, x, y);
            InnerShape.push_back(Polygon(rect));
            x += SmallA;
        }
        x = 0;
        y += SmallB;
    }
}
inline void ComposedShape::RToptimal(){
    double SmallA = TSmall.getSide();
    double ContainA = RContain.getSide1();
    double ContainB  =RContain.getSide2();
    double xup = SmallA/2, yup = 0, xleft = 0, ydown = (SmallA/2)*SQRT3, xright = SmallA;
    double adown = SmallA, aleft = SmallA/2, aright = (SmallA*3)/2, bup = 0, bdown = (SmallA/2)*SQRT3;

    // outer loop is rows and inner loop is columns
    // and ranges are determined due to containers width and height
    for ( int i = (int)(ContainB/(SQRT3*(SmallA/2))) ; i>0; i--){
        for(int j = (int)(ContainA/(SmallA)) ; j>0 ; j--){
            Triangle tri(SmallA, xup, yup, xleft, ydown, xright, ydown);
            InnerShape.push_back(Polygon(tri));
            xup += SmallA;
            xright += SmallA;
            xleft += SmallA;
        }
        yup += (SmallA/2)*SQRT3;
        ydown += (SmallA/2)*SQRT3;
        xup = SmallA/2;
        xleft = 0;
        xright = SmallA;
    }
    // this loop draws reverse triangles
    for ( int i = (int)(ContainB/(SQRT3*(SmallA/2))) ; i>0; i--){
        for(int j = (int)((ContainA-(SmallA/2))/(SmallA)) ; j>0 ; j --){
            Triangle tri2(SmallA, adown, bdown, aleft, bup, aright, bup);
            InnerShape.push_back(Polygon(tri2));
            adown += SmallA;
            aright += SmallA;
            aleft += SmallA;
        }
        bup += (SmallA/2)*SQRT3;
        bdown += (SmallA/2)*SQRT3;
        adown = SmallA;
        aleft = SmallA/2;
        aright = (SmallA*3)/2;
    }
}
inline void ComposedShape::RCoptimal(){
    double ContainA = RContain.getSide1();
    double ContainB = RContain.getSide2();
    double SmallA = CSmall.getRadius();
    double cx=SmallA, cy=SmallA;
    for ( int i = (int)(ContainB/(SmallA*2)); i>0; i--){
        for(int j = (int)(ContainA/(2*SmallA)) ; j>0 ; j --){
            Circle circ(SmallA, cx, cy);
            InnerShape.push_back(Polygon(circ));
            cx += 2*SmallA;
        }

        cx = SmallA;
        cy += 2*SmallA;
    }
}

inline void ComposedShape::CRoptimal(){
    double ContainA = CContain.getRadius();
    double SmallA = RSmall.getSide1();
    double SmallB = RSmall.getSide2();
    double x=0, y=0;

    for ( int i = (int)((ContainA*2)/SmallB) ; i>0; i--){
        for(int j = (int)((ContainA*2)/SmallA) ; j>0 ; j --){
            if(checkRectInCircle(x, y, SmallA, SmallB, ContainA)){
                Rectangle rect(SmallA, SmallB, x, y);
                InnerShape.push_back(Polygon(rect));
            }
            x += SmallA;
        }
        x = 0;
        y += SmallB;
    }
}
inline void ComposedShape::CCoptimal(){
    double ContainA = CContain.getRadius();
    double SmallA = CSmall.getRadius();
    double cx = 0, cy = 0;

    for ( int i = (int)(ContainA/SmallA) ; i>0; i--){
        for(int j = (int)(ContainA/SmallA) ; j>0 ; j --){
            while((cx<=ContainA) && (!checkCircleInCircle(cx, cy, SmallA, ContainA))){
                cx++;
            }
            if(checkCircleInCircle(cx, cy, SmallA, ContainA)){
                Circle circ(SmallA, cx, cy);
                InnerShape.push_back(Polygon(circ));
            }
            cx += 2*SmallA;
        }
        cx = 0;
        cy += 2*SmallA;
    }
    if (InnerShape.size() == 0 && SmallA<=ContainA){
        Circle circ(SmallA, ContainA, ContainA);
        InnerShape.push_back(Polygon(circ));
    }
}
inline void ComposedShape::CToptimal(){
    double ContainA = CContain.getRadius();
    double SmallA = TSmall.getSide();
    double xup = SmallA/2, yup = 0, xleft = 0, ydown = (SmallA/2)*SQRT3, xright = SmallA;
    double adown = SmallA, aleft = SmallA/2, aright = (SmallA*3)/2, bup = 0, bdown = (SmallA/2)*SQRT3;
    for ( int i = (int)((ContainA*2)/(SQRT3*(SmallA/2))) ; i>0; i--){
        for(int j = (int)((ContainA*2)/(SmallA)) ; j>0 ; j --){
            if(checkTriInCircle(xup, yup, xleft, ydown, xright, ydown, ContainA)) {
                Triangle tri(SmallA, xup, yup, xleft, ydown, xright, ydown);
                InnerShape.push_back(Polygon(tri));
            }
            xup += SmallA;
            xright += SmallA;
            xleft += SmallA;
        }
        yup += (SmallA/2)*SQRT3;
        ydown += (SmallA/2)*SQRT3;
        xup = SmallA/2;
        xleft = 0;
        xright = SmallA;
    }
    // checks if triangles are in circle and draws reverse triangles
    for ( int i = (int)((ContainA*2)/(SQRT3*(SmallA/2))) ; i>0; i--){
        for(int j = (int)(((ContainA*2)-(SmallA/2))/(SmallA)) ; j>0 ; j --){
            if(checkTriInCircle(adown, bdown, aleft, bup, aright, bup, ContainA)) {
                Triangle tri(SmallA, adown, bdown, aleft, bup, aright, bup);
                InnerShape.push_back(Polygon(tri));
            }
            adown += SmallA;
            aright += SmallA;
            aleft += SmallA;
        }
        bup += (SmallA/2)*SQRT3;
        bdown += (SmallA/2)*SQRT3;
        adown = SmallA;
        aleft = SmallA/2;
        aright = (SmallA*3)/2;
    }
}

inline void ComposedShape::TCoptimal(){
    double ContainA = TContain.getSide();
    double SmallA = CSmall.getRadius();
    double cx = ContainA/2;
    double cy = 2*SmallA;
    int rownum = 1;
    // by geometrical calculations i found that with every row i can
    // add another circle so i decided inner loop's range by that
    for ( int i = (int)((ContainA/(2*SmallA))-SQRT3+1) ; i>0; i--){
        for( int j =rownum ; j>0 ; j --) {
            Circle circle(SmallA, cx, cy);
            InnerShape.push_back(Polygon(circle));
            cx += 2 * SmallA;
        }

        cx = (ContainA/2) - (rownum*SmallA);
        cy += SmallA*SQRT3;
        rownum++;
    }
}
inline void ComposedShape::TRoptimal(){
    double SmallA = RSmall.getSide1();
    double SmallB = RSmall.getSide2();
    double ContainA = TContain.getSide();
    //makes rectangles horizontal
    if(SmallA<SmallB){
        double swap = SmallA;
        SmallA = SmallB;
        SmallB = swap;
    }
    double x = SmallB/SQRT3;
    double y = (((ContainA/2)*SQRT3)-SmallB);
    double changeContain=0 , temp = ContainA ;
    // outer loop is rows and inner loop is columns
    // and ranges are determined due to containers width and height
    for ( int i = (int)(((ContainA/2)*SQRT3)/SmallB) ; i>0; i--){
        for(int j = (int)((temp-(2*SmallB/SQRT3))/SmallA) ; j>0 ; j --){
            Rectangle rect(SmallA, SmallB, x, y);
            InnerShape.push_back(Polygon(rect));
            x += SmallA;
        }
        changeContain +=SmallB/SQRT3;
        y -= SmallB;
        x = (SmallB/SQRT3) + changeContain;
        temp -= 2*(SmallB/SQRT3);
    }
}
inline void ComposedShape::TToptimal(){
    double ContainA = TContain.getSide();
    double SmallA = TSmall.getSide();
    double xup = ContainA/2, yup = 0, xleft = (ContainA-SmallA)/2, ydown = SmallA*SQRT3/2, xright = (ContainA + SmallA)/2;
    double adown = ContainA/2, bdown = SmallA*SQRT3, aleft = (ContainA-SmallA)/2, aright = (ContainA + SmallA)/2 , bup = SmallA*SQRT3/2;

    // outer loop is rows and inner loop is columns
    // and ranges are determined due to containers width and height

    int k = 1;
    while (ydown <= (ContainA*SQRT3/2)){
        while(xright<=((ContainA/2)+(SmallA/2*k))){
            Triangle tri(SmallA, xup, yup, xleft, ydown, xright, ydown);
            InnerShape.push_back(Polygon(tri));
            xup += SmallA;
            xright += SmallA;
            xleft += SmallA;
        }
        yup += (SmallA/2)*SQRT3;
        ydown += (SmallA/2)*SQRT3;
        xup = (ContainA/2) - (k*SmallA/2);
        xleft = ((ContainA-SmallA)/2) - (k*SmallA/2);
        xright =((ContainA+SmallA)/2) - (k*SmallA/2);
        k++;
    }
    k = 1;
    //draws reverse triangles
    while (bdown<= (ContainA*SQRT3/2)){
        while(aright<=((ContainA/2)+(SmallA/2*k))){
            Triangle tri2(SmallA, adown, bdown, aleft, bup, aright, bup);
            InnerShape.push_back(Polygon(tri2));
            adown += SmallA;
            aright += SmallA;
            aleft += SmallA;
        }

        bdown += (SmallA/2)*SQRT3;
        bup += (SmallA/2)*SQRT3;
        adown = (ContainA/2) - (k*SmallA/2);
        aleft = ((ContainA-SmallA)/2) - (k*SmallA/2);
        aright =((ContainA+SmallA)/2) - (k*SmallA/2);
        k++;
    }
}

//This function sends outputstream to << overloading function in main for ComposedShape
ostream& ComposedShape::output(ostream& outputStream)const{
    if ( shapeContain == Shape::Rectangle ){
        outputStream << "Container shape is a Rectangle" << endl;
        outputStream << "Width:" << RContain.getSide1() << " Height:";
        outputStream << RContain.getSide2() << " area:" << RContain.getArea() ;
        outputStream <<  " perimeter length:" << RContain.getPerimeter() << endl;
    } else if ( shapeContain == Shape::Triangle){
        outputStream << "Container shape is a Triangle" << endl;
        outputStream << "Side:" << TContain.getSide() << " area:" ;
        outputStream << TContain.getArea() <<  " perimeter length:" << TContain.getPerimeter() << endl;
    } else if ( shapeContain == Shape::Circle){
        outputStream << "Container shape is a Circle" << endl;
        outputStream << "Radius:" << CContain.getRadius() <<  " area:" ;
        outputStream<< CContain.getArea() <<  " perimeter length:" << CContain.getPerimeter() << endl;
    } else {
        cerr << "Something went wrong :(" << endl;
        exit(EXIT_FAILURE);
    }

    if ( shapeSmall == Shape::Rectangle ){
        outputStream << "Small shape is a Rectangle" << endl;
        outputStream << "Width:" << RSmall.getSide1() << " Height:";
        outputStream << RSmall.getSide2() << " area:" << RSmall.getArea() ;
        outputStream <<  " perimeter length:" << RSmall.getPerimeter() << endl;
    } else if ( shapeSmall == Shape::Triangle){
        outputStream << "Small shape is a Triangle" << endl;
        outputStream << "Side:" << TSmall.getSide() << " area:" ;
        outputStream << TSmall.getArea() <<  " perimeter length:" << TSmall.getPerimeter() << endl;
    } else if ( shapeSmall == Shape::Circle){
        outputStream << "Small shape is a Circle" << endl;
        outputStream << "Radius:" << CSmall.getRadius() <<  " area:" ;
        outputStream<< CSmall.getArea() <<  " perimeter length:" << CSmall.getPerimeter() << endl;
    } else {
        cerr << "Something went wrong :(" << endl;
        exit(EXIT_FAILURE);
    }
    return outputStream;
}
//This function overloads [] for ComposedShape Class
//takes rectangle as a parameter and returns Polygon object
Polygon ComposedShape::operator [](Rectangle &rect){
    Polygon temp(rect);
    return temp;
}
//This function overloads [] for ComposedShape Class
//takes triangle as a parameter and returns Polygon object
Polygon ComposedShape::operator [](Triangle &tri){
    Polygon temp(tri);
    return temp;
}
//This function overloads [] for ComposedShape Class
//takes circle as a parameter and returns Polygon object
Polygon ComposedShape::operator [](Circle &circ){
    Polygon temp(circ);
    return temp;
}
//This function overloads +- for ComposedShape Class
//takes rectangle as a parameter and adds it to InnerShape vector
const ComposedShape ComposedShape::operator +=(Rectangle &rect) {
    if(shapeSmall!=Shape::Rectangle){
        cerr << "Incompatible to small Shapes";
        exit (EXIT_FAILURE);
    }

    InnerShape.push_back(Polygon(rect));
    return *this;
}
//This function overloads +- for ComposedShape Class
//takes triangle as a parameter and adds it to InnerShape vector
const ComposedShape ComposedShape::operator +=(Triangle &tri){
    if(shapeSmall!=Shape::Triangle){
        cerr << "Incompatible to small Shapes";
        exit (EXIT_FAILURE);
    }

    InnerShape.push_back(Polygon(tri));
    return *this;
}
//This function overloads +- for ComposedShape Class
//takes circle as a parameter and adds it to InnerShape vector
const ComposedShape ComposedShape::operator +=(Circle &circ){
    if(shapeSmall!=Shape::Circle){
        cerr << "Incompatible to small Shapes";
        exit (EXIT_FAILURE);
    }

    InnerShape.push_back(Polygon(circ));
    return *this;
}

