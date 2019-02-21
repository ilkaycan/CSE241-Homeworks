#include <iostream>
#include <fstream>
#include "Rectangle.h"
#include "Triangle.h"
#include "Circle.h"
#include "ComposedShape.h"
#define SQRT3 1.73205080757
using namespace std;
//If you remove '//' for couts you can see get functions' returns
int main() {

    ofstream myfile, myfile2, myfile3, myfile4;
    myfile.open("rectangle.svg");
    myfile2.open("triangle.svg");
    myfile3.open("circle.svg");
    myfile4.open("composedshape.svg");

    Circle arrC[4];
    Triangle arrT[4];
    Rectangle arrR[4];

    int k = 100;
    for(auto i = 0; i<4 ; i++){
        //cout << "For Circle" << endl;
        arrC[i].setRadius(k*(i+1));
        arrC[i].setX(k*(i+1));
        arrC[i].setY(k*(i+1));
        double r = arrC[i].getRadius();
        double cx = arrC[i].getCx();
        double cy = arrC[i].getCy();
        //cout << "Radius:" << r << " cx:" << cx << " cy:" << cy << endl;

        //cout << "For Triangle" << endl;
        arrT[i].setSide(k*(i+1));
        double side = arrT[i].getSide();
        arrT[i].setX1(side/2);
        arrT[i].setY1(0);
        arrT[i].setX2(0);
        arrT[i].setY2(side*SQRT3/2);
        arrT[i].setX3(side);
        arrT[i].setY3(side*SQRT3/2);
        double x1 = arrT[i].getX1();
        double x2 = arrT[i].getX2();
        double x3 = arrT[i].getX3();
        double y1 = arrT[i].getY1();
        double y2 = arrT[i].getY2();
        double y3 = arrT[i].getY3();
        //cout << "Side:" << side << " Coordinates:" << x1 <<","<< y1;
        //cout << " " << x2 << "," << y2 << " " << x3 << "," << y3 << endl;

        //cout << "For rectangle" << endl;
        arrR[i].setSide1((k*(i+1))+25);
        arrR[i].setSide2(k*(i+1));
        arrR[i].setX(0);
        arrR[i].setY(0);
        double width = arrR[i].getSide1();
        double height = arrR[i].getSide2();
        double x = arrR[i].getX();
        double y = arrR[i].getY();
        //cout << "Width:" << width << " Height:" << height << " x:" ;
        //cout << x << " y:" << y << endl;
    }

    ComposedShape a(arrC[3], arrC[0]), b(arrT[3], arrR[0]), c(arrR[3], arrT[0]), d(arrT[3], arrC[0]) ;
    ComposedShape arrCS[4] = {a, b, c, d};
    Shape Contain, Small;

    //cout << "For composed Shape" << endl;
    for(auto i = 0; i<4 ; i++){
        Contain = arrCS[i].getShapeContain();
        Small = arrCS[i].getShapeSmall();
        if(Contain == Shape::Triangle){
           // cout << "Container is Triangle" << endl ;
        }else if(Contain == Shape::Circle){
           // cout << "Container is Circle" << endl ;
        }else if(Contain == Shape::Rectangle){
           // cout << "Container is Rectangle" << endl ;
        }

        if(Small == Shape::Triangle){
            vector<Triangle> vectorTri = arrCS[i].getVectorT();
          //  cout << "Small is Triangle" << endl << "x1 of first triangle:" << vectorTri[0].getX1() << endl;
        }else if(Small == Shape::Circle){
            vector<Circle> vectorCirc = arrCS[i].getVectorC();
          //  cout << "Small is Circle" << endl << "cx of first circle:" << vectorCirc[0].getCx() << endl;
        }else if(Small == Shape::Rectangle){
            vector<Rectangle> vectorRect = arrCS[i].getVectorR();
           // cout << "Small is Rectangle" << endl << "x of first rectangle:" << vectorRect[i].getX() << endl;
        }

        arrCS[i].optimalFit();
    }
//You can change index between 0 and 4 and draw different shapes
    arrR[3].draw(myfile);
    arrT[3].draw(myfile2);
    arrC[3].draw(myfile3);
    arrCS[3].draw(myfile4);

    myfile.close();
    myfile2.close();
    myfile3.close();
    myfile4.close();

    return 0;
}


