#include "PolygonDyn.h"
#include <cmath>
#include <iostream>
#include "NegativityException.h"
#define PI 3.1415926535897
namespace GTU{
    //Constructors
    PolygonDyn::PolygonDyn(const Polygon::Point2D &Point){
        size = 1;
        Coordinate = new Point2D[1];
        Coordinate[0] = Point;
    }
    PolygonDyn::PolygonDyn(const vector <Polygon::Point2D> PPoints ){
        size = PPoints.size();
        Coordinate = new Point2D[size];

        for (int i = 0; i < size; i++) {
            Coordinate[i] = PPoints[i];
        }
    }
    PolygonDyn::PolygonDyn(const Rectangle &rect){
        Coordinate = new Point2D[4];
        size = 4;
        Coordinate[0].setX(rect.getX());
        Coordinate[0].setY(rect.getY());
        Coordinate[1].setX(rect.getX() + rect.getSide1());
        Coordinate[1].setY(rect.getY());
        Coordinate[2].setX(rect.getX() + rect.getSide1());
        Coordinate[2].setY(rect.getY() + rect.getSide2());
        Coordinate[3].setX(rect.getX());
        Coordinate[3].setY(rect.getY() + rect.getSide2());

    }
    PolygonDyn::PolygonDyn(const Circle &circ){
        Coordinate = new Point2D[100];

        size = 100;

        double angle = 0;
        double change = 3.6;

        for (int i = 0; i < 100; i++) {
            Coordinate[i].setX(circ.getCx() + (circ.getRadius() * cos((angle + (i * change)) * PI / 180.0)));
            Coordinate[i].setY(circ.getCy() + (circ.getRadius() * sin((angle + (i * change)) * PI / 180.0)));
        }

    }
    PolygonDyn::PolygonDyn(const Triangle &tri){
        Coordinate = new Point2D[3];
        size = 3;
        Coordinate[0].setX(tri.getX1());
        Coordinate[0].setY(tri.getY1());
        Coordinate[1].setX(tri.getX2());
        Coordinate[1].setY(tri.getY2());
        Coordinate[2].setX(tri.getX3());
        Coordinate[2].setY(tri.getY3());

    }
    PolygonDyn::PolygonDyn(void)throw(NoParamConstructorException){
        throw NoParamConstructorException();
    }
    //Setters that change directly 2D Array
    void PolygonDyn::setSize(const int &Size) {
        size = Size;
    }

    void PolygonDyn::changeArraySize(const int &Size) {
        delete[] Coordinate;

        Coordinate = new Polygon::Point2D[Size];
    }

    void PolygonDyn::setArray(const int &index, const Polygon::Point2D &newCoord) {
        if (size < index + 1) {
            cerr << "This index doesn't exist" << endl;
            exit(EXIT_FAILURE);
        }
        Coordinate[index] = newCoord;
    }
    //Big Three
    //Assignment operator overloading
    PolygonDyn &PolygonDyn::operator=(const PolygonDyn &rtSide) {
        if (size != rtSide.getSize()) {
            delete[] Coordinate;
            Coordinate = new Point2D[rtSide.getSize()];
            size = rtSide.getSize();
        }

        for (int i = 0; i < size; i++) {
            Coordinate[i] = rtSide.getArray()[i];
        }

        return *this;

    }

    //Destructor
    PolygonDyn::~PolygonDyn(void) {
        delete[] Coordinate;
    }

    //Copy constructor
    PolygonDyn::PolygonDyn(const PolygonDyn &copyobj){
        size = copyobj.getSize();
        Coordinate = new Point2D[size];

        for (int i = 0; i < size; i++) {
            Coordinate[i] = copyobj.getArray()[i];
        }
    }
    // clone function to use in other functions
    PolygonDyn *PolygonDyn::duplicatefunction(void){
        return new PolygonDyn(*this);
    }
    // << overloading helper function
    void PolygonDyn::output(ostream& outputStream){

        outputStream << "<polygon points=\"";
        for (int i = 0; i < (*this).getSize(); i++) {
            outputStream << (*this).getArray()[i].getX() << "," << (*this).getArray()[i].getY() << " ";

        }
        outputStream << "\"" << endl;
        outputStream << "stroke=\"black\" stroke-width=\"1\" fill=\"purple\" />" << endl;
    }
    //Writes Polygon to the file
    void PolygonDyn::draw(ofstream &myfile){
        startSVG(myfile, 1000, 1000);
        myfile << (*this);
        endSVG(myfile);
    }
    // Calculates area of Polygon
    double PolygonDyn::getArea(void){

        for (int i = 0; i < size; i++) {
            if(i != size-1) {
                area += Coordinate[i].getX() * Coordinate[i + 1].getY();
                area -= Coordinate[i + 1].getX() * Coordinate[i].getY();
            }else {
                area += Coordinate[size-1].getX() * Coordinate[0].getY();
                area -= Coordinate[0].getX() * Coordinate[size-1].getY();
            }
        }

        return abs(area*0.5);

    }

    // Calculates perimeter of Polygon
    double PolygonDyn::getPerimeter(void){

        for (int i = 0; i < size-1; i++){
           perimeter+= sqrt(pow(Coordinate[i].getX()- Coordinate[i+1].getX(), 2) + pow(Coordinate[i].getY()- Coordinate[i+1].getY(), 2));
        }
        perimeter+= sqrt(pow(Coordinate[0].getX()- Coordinate[size-1].getX(), 2) + pow(Coordinate[0].getY()- Coordinate[size-1].getY(), 2));

        return perimeter;
    }

    //Increment and decrement operators are overrided below
    const PolygonDyn &PolygonDyn::operator ++(int){
        static PolygonDyn temp = *this;
        temp = *this;
        ++(*this);

        return temp;
    } //postfix
    PolygonDyn &PolygonDyn::operator ++(){
        double temp;
        for (int i = 0; i < size; i++){
            temp = Coordinate[i].getX();
            Coordinate[i].setX(temp+1);
            temp = Coordinate[i].getY();
            Coordinate[i].setY(temp+1);
        }

        return *this;
    }
    const PolygonDyn &PolygonDyn::operator --(int)throw(NegativityException){
        for(int i =0; i<size ; i++){
            if(Coordinate[i].getX()<0 || Coordinate[i].getY()<0){
                throw NegativityException();
            }
        }
        static PolygonDyn temp = *this;
        temp = *this;
        --(*this);

        return temp;
    } //postfix
    PolygonDyn &PolygonDyn::operator --()throw(NegativityException){
        double temp;
        for(int i =0; i<size ; i++){
            if(Coordinate[i].getX()<0 || Coordinate[i].getY()<0){
                throw NegativityException();
            }
        }
        for (int i = 0; i < size; i++){
            temp = Coordinate[i].getX();
            Coordinate[i].setX(temp-1);
            temp = Coordinate[i].getY();
            Coordinate[i].setY(temp-1);
        }

        return *this;
    }
}