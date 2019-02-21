#include <iostream>
#include <fstream>
#include "Rectangle.h"
#include "Triangle.h"
#include "Circle.h"
#include "ComposedShape.h"
#define SQRT3 1.73205080757
using namespace std;

//If you remove '//' for couts you can see get functions returns

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
//<< overloading for composed shape
ostream& operator <<(ostream& outputStream, const ComposedShape& cs)
{
    return cs.output(outputStream);
}
//overloading << for ShapeElem
ostream& operator <<(ostream& outputStream, const ComposedShape::ShapeElem& CS)
{
    return CS.output(outputStream);
}
int main() {

    ofstream myfile, myfile2, myfile3, myfile4, myfile5;

    myfile.open("rectangle.svg");
    myfile2.open("triangle.svg");
    myfile3.open("circle.svg");
    myfile4.open("composedshape.svg");
    myfile5.open("add.svg");

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
        double areaC = arrC[i].getArea();
        double periC = arrC[i].getPerimeter();
        //cout << "Radius:" << r << " cx:" << cx << " cy:" << cy ;
        //cout << " area:" << areaC <<  " perimeter length:" << periC << endl;
        //cout << arrC[i];

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
        double areaT = arrT[i].getArea();
        double periT = arrT[i].getPerimeter();
		//cout << "Side:" << side << " Coordinates:" << x1 <<","<< y1;
        //cout << " " << x2 << "," << y2 << " " << x3 << "," << y3 << endl;
        //cout << arrT[i];

        //cout << "For rectangle" << endl;
        arrR[i].setSide1((k*(i+1))+25);
        arrR[i].setSide2(k*(i+1));
        arrR[i].setX(0);
        arrR[i].setY(0);
        double width = arrR[i].getSide1();
        double height = arrR[i].getSide2();
        double x = arrR[i].getX();
        double y = arrR[i].getY();
        double areaR = arrR[i].getArea();
        double periR = arrR[i].getPerimeter();
		//cout << "Width:" << width << " Height:" << height << " x:" ;
        //cout << x << " y:" << y << endl;
        //cout << arrR[i];
    }

    ComposedShape a(arrC[3], arrC[0]), b(arrT[3], arrR[0]), c(arrR[3], arrT[0]), d(arrT[3], arrC[0]) ;
    ComposedShape arrCS[4] = {a, b, c, d};
    Shape Contain, Small;

    //cout << "For composed Shape" << endl;
    for(auto i = 0; i<4 ; i++){
        Contain = arrCS[i].getShapeContain();
        Small = arrCS[i].getShapeSmall();
    //Test for composed shape << overloading
        cout << arrCS[i];
        if(Contain == Shape::Triangle){
           // cout << "Container shape is Triangle" << endl ;
        }else if(Contain == Shape::Circle){
           // cout << "Container shape is Circle" << endl ;
        }else if(Contain == Shape::Rectangle){
           // cout << "Container shape is Rectangle" << endl ;
        }
        if(Small == Shape::Triangle){
            // cout << "Small shape is Triangle" << endl ;
        }else if(Small == Shape::Circle){
            // cout << "Small shape is Circle" << endl ;
        }else if(Small == Shape::Rectangle){
            // cout << "Small shape is Rectangle" << endl ;
        }
        arrCS[i].optimalFit();
    }

//You can change index between 0 and 4 and draw different shapes
    arrR[3].draw(myfile);
    arrT[3].draw(myfile2);
    arrC[3].draw(myfile3);
    arrCS[0].draw(myfile4);

    Triangle tri(200);
    Rectangle rect(210, 200);
    Circle circ (200);

    Triangle tri2(30);
    Rectangle rect2(210, 200);
    Circle circ2(300);
    cout << rect << tri << circ << endl ;

//Test for postfix ++ and << for each class
    cout << rect++ << tri++ << circ++ << endl ;

//Test for pretfix ++ and << for each class
    cout << ++rect << ++tri << ++circ << endl ;

//Test for postfix -- and << for each class
    cout << rect-- << tri-- << circ-- << endl ;

//Test for pretfix -- and << for each class
    cout << --rect << --tri << --circ << endl ;


//Test for +
    double change = 23.56;
    rect = rect + change;
    tri = tri + change;
    circ = circ + change;

    cout << rect << tri << circ << endl ;

//Test for -
    rect = rect - change;
    tri = tri - change;
    circ = circ - change;

    cout << rect << tri << circ << endl ;

//tests for comparisons
    bool comparison ;
//Rectangle
    comparison = (rect<rect2);
    cout <<  comparison << endl;
    comparison = (rect>rect2);
    cout <<  comparison << endl;
    comparison = (rect<=rect2);
    cout <<  comparison << endl;
    comparison = (rect>=rect2);
    cout <<  comparison << endl;
    comparison = (rect==rect2);
    cout <<  comparison << endl;
    comparison = (rect!=rect2);
    cout <<  comparison << endl;
//Triangle
    comparison = (tri<tri2);
    cout <<  comparison << endl;
    comparison = (tri>tri2);
    cout <<  comparison << endl;
    comparison = (tri<=tri2);
    cout <<  comparison << endl;
    comparison = (tri>=tri2);
    cout <<  comparison << endl;
    comparison = (tri==tri2);
    cout <<  comparison << endl;
    comparison = (tri!=tri2);
    cout <<  comparison << endl;
//Circle
    comparison = (circ<circ2);
    cout <<  comparison << endl;
    comparison = (circ>circ2);
    cout <<  comparison << endl;
    comparison = (circ<=circ2);
    cout <<  comparison << endl;
    comparison = (circ>=circ2);
    cout <<  comparison << endl;
    comparison = (circ==circ2);
    cout <<  comparison << endl;
    comparison = (circ!=circ2);
    cout <<  comparison << endl;

//Test for composed shape << overloading
    ComposedShape CS(rect, tri2);
    CS.optimalFit();
    cout << CS << endl;
//Test for += you can delete // at draw function for the one you want to see
//i added all svg files by the way they're in the zip
    Triangle add(10);
    Rectangle add2(10,10, 200, 50);
    Circle add3(5, 200, 60);
//adding triangle
    CS += add;
    CS.draw(myfile5);
//adding rectangle
    arrCS[1] += add2;
    //arrCS[1].draw(myfile5);
//adding circle
    arrCS[0] += add3;
    //arrCS[0].draw(myfile5);
//Test for [] and ShapeElem's <<
//Test for ShapeElem's area and perimeter functions
    ComposedShape::ShapeElem SE = CS[rect];
    cout << SE ;
    cout << "area:" << SE.getareaElem() << endl;
    cout << "perimeter:" << SE.getperimeterElem() << endl;

    ComposedShape::ShapeElem SE2 = CS[tri];
    cout << SE2 ;
    cout << "area:" << SE2.getareaElem() << endl;
    cout << "perimeter:" << SE2.getperimeterElem() << endl;

    ComposedShape::ShapeElem SE3 = CS[circ];
    cout << SE3 ;
    cout << "area:" << SE3.getareaElem() << endl;
    cout << "perimeter:" << SE3.getperimeterElem() << endl;

    //Tests for statics  for each class
    cout << "Area of all Rectangles created: " << Rectangle::totalAreafunc() << endl;
    cout << "Area of all Triangles created: " << Triangle::totalAreafunc() << endl;
    cout << "Area of all Circles created: " << Circle::totalAreafunc() << endl;

    cout << "Perimeter length of all Rectangles created: " << Rectangle::totalPerimeterfunc() << endl;
    cout << "Perimeter of all Triangles created: " << Triangle::totalPerimeterfunc() << endl;
    cout << "Perimeter of all Circles created: " << Circle::totalPerimeterfunc() << endl;

    myfile.close();
    myfile2.close();
    myfile3.close();
    myfile4.close();
    myfile5.close();

    return 0;
}


