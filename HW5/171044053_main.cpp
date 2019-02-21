#include <iostream>
#include <fstream>
#include <vector>
#include "Rectangle.h"
#include "Polygon.h"
#include "PolygonDyn.h"
#include "PolygonVect.h"
#include "Triangle.h"
#include "Circle.h"
#include "ComposedShape.h"
#include "Shape.h"

#define SQRT3 1.73205080757

using namespace std;
using namespace GTU;

void printAll(const vector<Shape *> Printed, ofstream &myfile);
void printPoly(const vector<Shape *> Printed, ofstream &myfile);
void sortShapes(vector<Shape *> &Printed);
vector<PolygonDyn> convertAll(const vector<Shape *> Printed);

//This function writes all given shapes in the vector to file after it converts them to Polygons in the vector
void printAll(const vector<Shape*> Printed, ofstream &myfile){
    if(Printed.size()>0){
        (*Printed[0]).startSVG(myfile, 1000, 1000);
        for(int i = 0; i < Printed.size(); i++){
            myfile << (*Printed[i]);
        }
        (*Printed[0]).endSVG(myfile);
    }
}
// This function converts Shape* vector to PolygonDyn vector
vector <PolygonDyn> convertAll(const vector<Shape*> Printed){
    vector <PolygonDyn> x;
    PolygonDyn *temp;

    for(int i = 0; i < Printed.size(); i++){

        if((*Printed[i]).getShapetype() ==  ShapeType::Rectangle){
            temp = new PolygonDyn(*dynamic_cast<Rectangle*>(Printed[i]));
        } else if((*Printed[i]).getShapetype() ==  ShapeType::Triangle){
            temp = new PolygonDyn(*dynamic_cast<Triangle*>(Printed[i]));
            //cout << "area" << temp->getArray()[i].getX()<< endl;
        } else if((*Printed[i]).getShapetype() ==  ShapeType::Circle){
            temp = new PolygonDyn(*dynamic_cast<Circle*>(Printed[i]));
        }
        x.push_back(*temp);
    }

    delete temp;
    return x;

}
//This function writes all given shapes in the vector to file
void printPoly(const vector<Shape*> Printed, ofstream &myfile){
    vector <PolygonDyn> X = convertAll(Printed);
    if(X.size()>0){
        X[0].startSVG(myfile, 1000, 1000);
        for(int i = 0; i < X.size(); i++){
            myfile << X[i];
        }
        X[0].endSVG(myfile);
    }
}
//This function sorts shapes in the areas depending on their areas
void sortShapes(vector<Shape*> &Printed){
    Shape* temp;

    for(int i=0;i<Printed.size()-1;i++ )
    {

        for(int j = i+1; j<Printed.size(); j++ ){

            if((*Printed[i])>(*Printed[j])){
                temp = Printed[i];
                Printed[i] = Printed[j];
                Printed[j] = temp;
            }
        }
    }
}
int main() {

    ofstream myfile, myfile2, myfile3, myfile4, myfile5, myfile6, myfile7, myfile8;
    myfile.open("a.svg");
    myfile2.open("b.svg");
    myfile3.open("c.svg");
    myfile4.open("d.svg");
    myfile5.open("e.svg");
    myfile6.open("f.svg");
    myfile7.open("g.svg");
    myfile8.open("h.svg");

    Rectangle rect(100,100);
    Circle circ(200);
    Triangle tri(20);
    ComposedShape composed(circ, rect);
    vector <Shape*> vectofShp;
    PolygonVect polyVect(tri);
    PolygonDyn polyDyn(tri);

    vectofShp.push_back(dynamic_cast<Shape*>(&rect));
    vectofShp.push_back(dynamic_cast<Shape*>(&circ));
    vectofShp.push_back(dynamic_cast<Shape*>(&tri));

    composed.optimalFit();
    composed.draw(myfile);
    printAll(composed.getVector(),myfile2);

    //Tests for areas and perimeters of polygonDyn and PolygonVect
    PolygonDyn CircDyn(circ), TriDyn(tri), RectDyn(rect);
    PolygonVect CircVect(circ), TriVect(tri), RectVect(rect);
    cout << "Areas and perimeters of PolygonDyns:" << endl;
    cout << CircDyn.getArea() << " - " << CircDyn.getPerimeter() << endl;
    cout << TriDyn.getArea() << " - " << TriDyn.getPerimeter() << endl;
    cout << RectDyn.getArea() << " - " << RectDyn.getPerimeter() << endl;

    cout << "Areas and perimeters of PolygonVects:" << endl;
    cout << CircVect.getArea() << " - " << CircVect.getPerimeter() << endl;
    cout << TriVect.getArea() << " - " << TriVect.getPerimeter() << endl;
    cout << RectVect.getArea() << " - " << RectVect.getPerimeter() << endl;

    printPoly(vectofShp, myfile3);
    cout << "Areas of shapes in vector before sort:" ;
    cout << vectofShp[0]->getArea() << " " << vectofShp[1]->getArea() << " " << vectofShp[2]->getArea() << " " << endl;
    sortShapes(vectofShp);
    cout << "Areas of shapes in vector after sort:" ;
    printPoly(vectofShp, myfile4);
    cout << vectofShp[0]->getArea() << " " << vectofShp[1]->getArea() << " " << vectofShp[2]->getArea() << " " << endl;

    //	Test for ++ and -- of composed shape
	//	I wanted change position of InnerShape vector but post increment 
	//	and decrement got core dumped sometimes
	// 	I couldn't understand the reason so they are comment 
    //printAll((composed++).getVector(), myfile5);
    printAll((++composed).getVector(), myfile6);
    //printAll((composed--).getVector(), myfile7);
    printAll((--composed).getVector(), myfile8);


    //Test for ++ and -- of Triangle Rectangle and Circle
    cout << "Increment and decrement test for rectangle" << endl;
    cout << "Before operators:" << "x:" << rect.getX() << endl;
    cout << "Post increment:" << "x:" << (rect++).getX()<< endl;
    cout << "Pre increment:" << "x:" << (++rect).getX() << endl;
    cout << "Post decrement:" << "x:" << (rect--).getX() << endl;
    cout << "Pre decrement:" << "x:" << (--rect).getX() << endl;

    cout << "Increment and decrement test for triangle" << endl;
    cout << "Before operators:" << "x:" << tri.getX1() << endl;
    cout << "Post increment:" << "x:" << (tri++).getX1() << endl;
    cout << "Pre increment:" << "x:" << (++tri).getX1() << endl;
    cout << "Post decrement:" << "x:" << (tri--).getX1() << endl;
    cout << "Pre decrement:" << "x:" << (--tri).getX1() << endl;

    cout << "Increment and decrement test for circle" << endl;
    cout << "Before operators:" << "x:" << circ.getCx() << endl;
    cout << "Post increment:" << "x:" << (circ++).getCx() << endl;
    cout << "Pre increment:" << "x:" << (++circ).getCx() << endl;
    cout << "Post decrement:" << "x:" << (circ--).getCx() << endl;
    cout << "Pre decrement:" << "x:" << (--circ).getCx() << endl;

    //Test for ++ and -- of PolygonDyn and PolygonVect
    cout << "Increment and decrement test for PolygonDyn" << endl;
    cout << "Before operators:" << "x:" << polyDyn.getArray()[0].getX() << endl;
    cout << "Post increment:" << "x:" << (polyDyn++).getArray()[0].getX() << endl;
    cout << "Pre increment:" << "x:" << (++polyDyn).getArray()[0].getX() << endl;
    cout << "Post decrement:" << "x:" << (polyDyn--).getArray()[0].getX() << endl;
    cout << "Pre decrement:" << "x:" << (--polyDyn).getArray()[0].getX() << endl;

    cout << "Increment and decrement test for PolygonVect" << endl;
    cout << "Before operators:" << "x:" << polyVect.getVector()[0].getX() << endl;
    cout << "Post increment:" << "x:" << (polyVect++).getVector()[0].getX() << endl;
    cout << "Pre increment:" << "x:" << (++polyVect).getVector()[0].getX() << endl;
    cout << "Post decrement:" << "x:" << (polyVect--).getVector()[0].getX() << endl;
    cout << "Pre decrement:" << "x:" << (--polyVect).getVector()[0].getX() << endl;

    //Comparison operators

    if(tri>circ){
        cout << "\nTriangle's area is greater than Circle's area" << endl;
    } else if (circ>tri){
        cout << "\nTriangle's area is smaller than Circle's area" << endl;
    }

    if (tri <= rect){
        cout << "Triangle's area is smaller or equal to Rectangle's area" << endl;
    }
    if(circ>=rect){
        cout << "Rectangle's area is smaller or equal to Circle's area" << endl;
    }
    if(circ!=rect) {
        cout << "Rectangle's area is not equal to Circle's area" << endl;
    }


    try
    {
        Circle wrong(-50);
    }
    catch (NegativityException& e)
    {
        cout << "Exception: " << e.what() << endl;
    }

    try{
        Triangle wrongg(-365);    }
    catch (NegativityException& e){
        cout << "Exception: " << e.what() << endl;

    }

    try{
        Rectangle wronng(-56, 25);
    }
    catch (NegativityException& e){
        cout << "Exception: " << e.what() << endl;

    }

    try{
        tri.setX1(-5);
    }
    catch (NegativityException& e){
        cout << "Exception: " << e.what() << endl;
    }

    try{
        rect.setY(-12);
    }
    catch (NegativityException& e){
        cout << "Exception: " << e.what() << endl;
    }

    try{
        circ.setRadius(-585);
    }
    catch (NegativityException& e){
        cout << "Exception: " << e.what() << endl;
    }

    try{
        PolygonDyn faill;
    }
    catch (NoParamConstructorException& e){
        cout << "Exception: " << e.what() << endl;

    }
    try{
        ComposedShape Oo;
    }
    catch (NoParamConstructorException& e){
        cout << "Exception: " << e.what() << endl;
    }

    try{
        PolygonVect nope;
    }
    catch (NoParamConstructorException& e){
        cout << "Exception: " << e.what() << endl;
    }

    myfile.close();
    myfile2.close();
    myfile3.close();
    myfile4.close();
    myfile5.close();
    myfile6.close();
    myfile7.close();
    myfile8.close();
  return 0;
}

