#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Shape.h"
#include "Polygon.h"
#include "PolygonDyn.h"
#include "PolygonVect.h"
#include "NegativityException.h"


using namespace std;
namespace GTU{

    //Comparison operators depending on areas

    bool Shape::operator <( Shape& compare){
        return (this->getArea() < compare.getArea());
    }

    bool Shape::operator >( Shape& compare){
        return (this->getArea() > compare.getArea());
    }

    bool Shape::operator <=( Shape& compare){
        return (this->getArea() <= compare.getArea());
    }

    bool Shape::operator >=( Shape& compare){
        return (this->getArea() >= compare.getArea());
    }

    bool Shape::operator ==( Shape& compare){
        return (this->getArea() == compare.getArea());
    }

    bool Shape::operator !=( Shape& compare){
        return (this->getArea() != compare.getArea());
    }
    //checks negative value error
    bool Shape::testValue(const double &num)const throw(NegativityException){
        if(num>=0){
            return true;
        }else{
            throw NegativityException();
        }
    }
    //Those functions write SVG file start and ends
    void Shape::startSVG(ofstream &myfile, const double &width, const double &height)const{
        myfile << "<svg version=\"1.1\" " << endl << "baseProfile=\"full\"" << endl;
        myfile << "width=" << "\"" << width << "\"" ;
        myfile << " height=" << "\"" << height << "\""  << endl;
        myfile << "xmlns=\"http://www.w3.org/2000/svg\">" << endl;
    }

    void Shape::endSVG(ofstream &myfile){
        myfile << "</svg>" << endl;
    }
    // << overloading
    ostream& operator <<(ostream& outputStream, Shape &S)
    {
        S.output(outputStream);
        return outputStream;
    }
}