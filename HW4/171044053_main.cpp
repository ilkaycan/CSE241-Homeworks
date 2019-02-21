#include <iostream>
#include <fstream>
#include "Rectangle.h"
#include "Triangle.h"
#include "Circle.h"
#include "Polygon.h"
#include "Polyline.h"
#include "ComposedShape.h"
#define SQRT3 1.73205080757
using std::cout;
using std::endl;
using std::ofstream;
using namespace HW4_171044053;
namespace{
    int k = 100;

	//<< overloading for composed shape
	ostream& operator <<(ostream& outputStream, const ComposedShape& cs)
	{
		return cs.output(outputStream);
	}
	// << overloading for circle
	ostream& operator <<(ostream& outputStream, const Circle& c)
	{
		return c.output(outputStream);
	}
	// << overloading for rectangle
	ostream& operator <<(ostream& outputStream, const Rectangle& r)
	{
		return r.output(outputStream);
	}
	// << overloading for triangle
	ostream& operator <<(ostream& outputStream, const Triangle& t)
	{
		return t.output(outputStream);
	}
}

int main() {
    ofstream myfile, myfile2, myfile3, myfile4, myfile5, myfile6, myfile7;
	ofstream myfile8, myfile9, myfile10, myfile11, myfile12,myfile13, myfile14, myfile15;

    myfile.open("1.svg");
    myfile2.open("2.svg");
    myfile3.open("3.svg");
    myfile4.open("4.svg");
    myfile5.open("5.svg");
    myfile6.open("6.svg");
    myfile7.open("7.svg");
    myfile8.open("8.svg");
    myfile9.open("9.svg");
    myfile10.open("10.svg");
	myfile11.open("11.svg");
	myfile12.open("12.svg");
	myfile13.open("13.svg");
	myfile14.open("14.svg");
	myfile15.open("15.svg");

    Circle arrC[5];
    Triangle arrT[5];
    Rectangle arrR[5];


    for(auto i = 0; i<5 ; i++){
//For Circle
        arrC[i].setRadius(k*(i+1));
        arrC[i].setX(k*(i+1));
        arrC[i].setY(k*(i+1));

//For Triangle
        arrT[i].setSide(k*(i+1));
        double side = arrT[i].getSide();
        arrT[i].setX1(side/2);
        arrT[i].setY1(0);
        arrT[i].setX2(0);
        arrT[i].setY2(side*SQRT3/2);
        arrT[i].setX3(side);
        arrT[i].setY3(side*SQRT3/2);

//For rectangle
        arrR[i].setSide1((k*(i+1))+25);
        arrR[i].setSide2(k*(i+1));
        arrR[i].setX(0);
        arrR[i].setY(0);
    }
    Rectangle rect(210, 200);
    Triangle tri(30);
    ComposedShape a(arrC[3], arrC[0]), b(arrT[3], arrR[0]), c(arrR[3], arrT[0]), d(arrT[3], arrC[0]), e(rect, tri) ;
    ComposedShape arrCS[5] = {a, b, c, d, e};
    Shape Contain, Small;

    //cout << "For composed Shape" << endl;
    for(auto i = 0; i<5 ; i++){
        Contain = arrCS[i].getShapeContain();
        Small = arrCS[i].getShapeSmall();
        //Test for composed shape << overloading
        cout << arrCS[i];
        if(Contain == Shape::Triangle){
             cout << "Container shape is Triangle" << endl ;
        }else if(Contain == Shape::Circle){
            // cout << "Container shape is Circle" << endl ;
        }else if(Contain == Shape::Rectangle){
             cout << "Container shape is Rectangle" << endl ;
        }
        if(Small == Shape::Triangle){
             cout << "Small shape is Triangle" << endl ;
        }else if(Small == Shape::Circle){
             cout << "Small shape is Circle" << endl ;
        }else if(Small == Shape::Rectangle){
             cout << "Small shape is Rectangle" << endl ;
        }
        arrCS[i].optimalFit();
    }

//Draw function of ComposedShape
//This one also checks << overload of Polygon
//Because draw function uses << of Polygon to write small shapes in SVG file

    arrCS[0].draw(myfile);
    arrCS[1].draw(myfile2);
    arrCS[2].draw(myfile3);
    arrCS[3].draw(myfile4);
    arrCS[4].draw(myfile5);

//Test for composed shape << overloading
    for(int i = 0; i<5; i++){
        cout << arrCS[i] << endl;
    }

//Test for +=
    Triangle add(10);
    Rectangle add2(10,10, 200, 50);
    Circle add3(5, 200, 60);
//adding triangle
    arrCS[4] += add;
    arrCS[4].draw(myfile6);
//adding rectangle
    arrCS[1] += add2;
    arrCS[1].draw(myfile7);
//adding circle
    arrCS[0] += add3;
    arrCS[0].draw(myfile8);

//Test for [] overload of Composed Shape
    Polygon P1 = arrCS[0][rect];

    Polygon P2 = arrCS[0][tri];

    Circle circ(200);
    Polygon P3 = arrCS[0][circ];

//Testing constructors of Polygon and Point2D
    Polygon P4(rect);
    Polygon P5(tri);
    Polygon P6(circ);

    Polygon::Point2D A(201, 152);
    Polygon::Point2D B;
    Polygon::Point2D C(125, 300);
    vector<Polygon::Point2D> vector2D;
    vector2D.push_back(A);
    vector2D.push_back(B);
    vector2D.push_back(C);

    Polygon P7(A);
    Polygon P8(vector2D);
    Polygon P9(C);

    Polygon arrP[9] = {P1, P2, P3, P4, P5, P6, P7, P8, P9};

//Testing == of Polygon and [] of Composed Shape
    for(int i = 0; i<3; i++){
        if(arrP[i] == arrP[i+3]){
            cout << "== Success" << endl;
        }
    }

//Testing != of Polygon
    for(int i = 0; i<3; i++){
        if(arrP[i+3] != arrP[i+6]) {
            cout << "!= Success" << endl;
        }
    }

//Testing [] and getters of Polygon
//Getters are used in [] overloading
    for(int i = 0; i < 9; i++) {
        Polygon::Point2D Point = arrP[i][0];
        cout << "x:" << Point.getX() << "y:" << Point.getY() << endl;
    }
//Test for + overloading
    int sizeold = arrP[0].getSize();
    int sizeadded = arrP[5].getSize();
	Polygon newPolygon = arrP[0] + arrP[5];
    int sizenew = newPolygon.getSize();
    cout << sizeold << "+" << sizeadded << "=" << sizenew << endl;
    myfile9 << "<svg version=\"1.1\" " << endl << "baseProfile=\"full\"" << endl;
    myfile9 << "width=" << "\"" << 750 << "\"" ;
    myfile9 << " height=" << "\"" << 750 << "\""  << endl;
    myfile9 << "xmlns=\"http://www.w3.org/2000/svg\">" << endl;
    myfile9 << newPolygon;
    myfile9 << "</svg>" << endl;

//Test for Polyline <<

    Polyline Ax(circ), Bx(tri), Cx(rect), Dx(vector2D), Ex(rect);
	Polyline arrPy[5] = {Ax, Bx, Cx, Dx, Ex};
	
    myfile10 << arrPy[0];
	myfile11 << arrPy[1];
	myfile12 << arrPy[2];
	myfile13 << arrPy[3];
	myfile14 << arrPy[4];

//Testing == of Polyline
    if(arrPy[2] == arrPy[4]){
        cout << "== Success" << endl;
    }

	//Testing != of Polyline
    if(arrPy[1] != arrPy[2]) {
        cout << "!= Success" << endl;
    }

//Testing [] and getters of Polygon
//Getters are used in [] overloading
    for(int i = 0; i < 5; i++) {
        Polygon::Point2D PointPolyline = arrPy[i][0];
        cout << "x:" << PointPolyline.getX() << "y:" << PointPolyline.getY() << endl;
    }
//Test for + overloading
    sizeold = arrPy[1].getPolygon().getSize();
    sizeadded = arrPy[3].getPolygon().getSize();
	Polyline newPolyline = arrPy[1] + arrPy[3];
    sizenew = newPolyline.getPolygon().getSize();
    cout << sizeold << "+" << sizeadded << "=" << sizenew << endl;
	myfile15 << newPolyline;


    myfile.close();
    myfile2.close();
    myfile3.close();
    myfile4.close();
    myfile5.close();
    myfile6.close();
    myfile7.close();
    myfile8.close();
    myfile9.close();
    myfile10.close();
	myfile11.close();
	myfile12.close();
	myfile13.close();
	myfile14.close();
	myfile15.close();
    return 0;
}
