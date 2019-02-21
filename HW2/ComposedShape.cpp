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

using namespace std;
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
ComposedShape::ComposedShape(const Rectangle &Contain, const Rectangle &Small){
    shapeContain = Shape::Rectangle;
    shapeSmall = Shape::Rectangle;
    RContain = Contain;
    RSmall = Small;

}
ComposedShape::ComposedShape(const Rectangle &Contain, const Circle &Small){
    shapeContain = Shape::Rectangle;
    shapeSmall = Shape::Circle;
    RContain = Contain;
    CSmall = Small;
}
ComposedShape::ComposedShape(const Rectangle &Contain, const Triangle &Small){
    shapeContain = Shape::Rectangle;
    shapeSmall = Shape::Triangle;
    RContain = Contain;
    TSmall = Small;
}
ComposedShape::ComposedShape(const Triangle &Contain, const Rectangle &Small){
    shapeContain = Shape::Triangle;
    shapeSmall = Shape::Rectangle;
    TContain = Contain;
    RSmall = Small;
}
ComposedShape::ComposedShape(const Triangle &Contain, const Triangle &Small){
    shapeContain = Shape::Triangle;
    shapeSmall = Shape::Triangle;
    TContain = Contain;
    TSmall = Small;
}
ComposedShape::ComposedShape(const Triangle &Contain, const Circle &Small){
    shapeContain = Shape::Triangle;
    shapeSmall = Shape::Circle;
    TContain = Contain;
    CSmall = Small;
}
ComposedShape::ComposedShape(const Circle &Contain, const Rectangle &Small){
    shapeContain = Shape::Circle;
    shapeSmall = Shape::Rectangle;
    CContain = Contain;
    RSmall = Small;
}
ComposedShape::ComposedShape(const Circle &Contain, const Circle &Small){
    shapeContain = Shape::Circle;
    shapeSmall = Shape::Circle;
    CContain = Contain;
    CSmall = Small;
}
ComposedShape::ComposedShape(const Circle &Contain, const Triangle &Small){
    shapeContain = Shape::Circle;
    shapeSmall = Shape::Triangle;
    CContain = Contain;
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

    if ( shapeSmall == Shape::Rectangle ){
        for (int i = 0; i < vectorR.size() ; ++i){
            myfile << "<rect x=\""<< vectorR[i].getX() <<"\" y=\"" << vectorR[i].getY() << "\" width=\"" << vectorR[i].getSide1();
            myfile <<"\" height=\""<< vectorR[i].getSide2() << "\" stroke=\"black\" stroke-width=\"1\" fill=\"purple\" />" << endl;
        }

    } else if ( shapeSmall == Shape::Triangle){
        for(int j = 0; j < vectorT.size(); ++j){
            myfile << "<polygon points=\"" << vectorT[j].getX1() << "," << vectorT[j].getY1() << " " ;
            myfile << vectorT[j].getX2() <<"," << vectorT[j].getY2() << " " ;
            myfile << vectorT[j].getX3() << "," << vectorT[j].getY3() << "\"" << endl;
            myfile << "stroke=\"black\" stroke-width=\"1\" fill=\"purple\" />" << endl;
        }
    } else if ( shapeSmall == Shape::Circle){
        for(int k = 0; k < vectorC.size(); ++k){
            myfile << "<circle cx=\""<< vectorC[k].getCx() <<"\" cy=\"" << vectorC[k].getCy() ;
            myfile << "\" r=\"" << vectorC[k].getRadius();
            myfile << "\" stroke=\"black\" stroke-width=\"1\" fill=\"purple\" />" << endl;
        }
    } else {
        cerr << "Something went wrong :(" << endl;
        exit(EXIT_FAILURE);
    }

    myfile << "</svg>" << endl;
}

//This function calls suitable Shapeoptimal function and calculates areas and shape numbers
void ComposedShape::optimalFit(){
    double areaContain, areaSmall, shapeNum;
    if ( shapeContain == Shape::Rectangle ){
        areaContain = RContain.getSide1() * RContain.getSide2();
        if ( shapeSmall == Shape::Rectangle ){
            RRoptimal();
            shapeNum = vectorR.size();
            areaSmall = shapeNum * RSmall.getSide1() * RSmall.getSide2();
        } else if ( shapeSmall == Shape::Triangle){
            RToptimal();
            shapeNum = vectorT.size();
            areaSmall = shapeNum * TSmall.getSide() * TSmall.getSide() * SQRT3 / 4;
        } else if ( shapeSmall == Shape::Circle){
            RCoptimal();
            shapeNum = vectorC.size();
            areaSmall = shapeNum * PI * CSmall.getRadius() * CSmall.getRadius();
        } else {
            cerr << "Something went wrong :(" << endl;
            exit(EXIT_FAILURE);
        }
    } else if ( shapeContain == Shape::Triangle){
        areaContain = TContain.getSide() * TContain.getSide() * SQRT3 / 4;
        if ( shapeSmall == Shape::Rectangle ){
            TRoptimal();
            shapeNum = vectorR.size();
            areaSmall = shapeNum * RSmall.getSide1() * RSmall.getSide2();
        } else if ( shapeSmall == Shape::Triangle){
            TToptimal();
            shapeNum = vectorT.size();
            areaSmall = shapeNum * TSmall.getSide() * TSmall.getSide() * SQRT3 / 4;
        } else if ( shapeSmall == Shape::Circle){
            TCoptimal();
            shapeNum = vectorC.size();
            areaSmall = shapeNum * PI * CSmall.getRadius() * CSmall.getRadius();
        } else {
            cerr << "Something went wrong :(" << endl;
            exit(EXIT_FAILURE);
        }
    } else if ( shapeContain == Shape::Circle){
        areaContain = PI * CContain.getRadius() * CContain.getRadius();
        if ( shapeSmall == Shape::Rectangle ){
            CRoptimal();
            shapeNum = vectorR.size();
            areaSmall = shapeNum * RSmall.getSide1() * RSmall.getSide2();
        } else if ( shapeSmall == Shape::Triangle){
            CToptimal();
            shapeNum = vectorT.size();
            areaSmall = shapeNum * TSmall.getSide() * TSmall.getSide() * SQRT3 / 4;
        } else if ( shapeSmall == Shape::Circle){
            CCoptimal();
            shapeNum = vectorC.size();
            areaSmall = shapeNum * PI * CSmall.getRadius() * CSmall.getRadius();
        } else {
            cerr << "Something went wrong :(" << endl;
            exit(EXIT_FAILURE);
        }
    } else {
        cerr << "Something went wrong :(" << endl;
        exit(EXIT_FAILURE);
    }
    cout << "I can fit at most " << shapeNum << " small shapes into the main container." ;
    cout << " The empty area (blue) in container is " << areaContain - areaSmall << "." ;
}
//Shapeoptimal functions
//finds
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
            vectorR.push_back(rect);
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
            vectorT.push_back(tri);
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
            vectorT.push_back(tri2);
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
            vectorC.push_back(circ);
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
                vectorR.push_back(rect);
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
                vectorC.push_back(circ);
            }
            cx += 2*SmallA;
        }
        cx = 0;
        cy += 2*SmallA;
    }
    if (vectorC.size() == 0 && SmallA<=ContainA){
            Circle circ(SmallA, ContainA, ContainA);
            vectorC.push_back(circ);
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
                vectorT.push_back(tri);
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
                vectorT.push_back(tri);
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
    decltype(cx) cy ;
	cy = 2*SmallA;
    int rownum = 1;
    // by geometrical calculations i found that with every row i can
    // add another circle so i decided inner loop's range by that
    for ( int i = (int)((ContainA/(2*SmallA))-SQRT3+1) ; i>0; i--){
        for( int j =rownum ; j>0 ; j --) {
            Circle circle(SmallA, cx, cy);
            vectorC.push_back(circle);
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
            vectorR.push_back(rect);
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
            vectorT.push_back(tri);
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
            vectorT.push_back(tri2);
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
