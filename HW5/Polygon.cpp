#include "Polygon.h"
namespace GTU{
//Constructors for Point2D class
Polygon::Point2D::Point2D(void) {

    x = 0;
    y = 0;
}

Polygon::Point2D::Point2D(const double &coordx, const double &coordy) {
    if(x <0 || y<0){
        throw NegativityException();
    }
    x = coordx;
    y = coordy;
}

// Setters of Point2D class
void Polygon::Point2D::setX(const double &coordx) {
    if(x <0 || y<0){
        throw NegativityException();
    }
    x = coordx;
}

void Polygon::Point2D::setY(const double &coordy) {
    if(x <0 || y<0){
        throw NegativityException();
    }
    y = coordy;
}

}