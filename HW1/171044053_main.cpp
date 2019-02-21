#include <iostream>
#include <string>
#include<fstream>
#include<cmath>
#include "source1.h"

#define PI 3.1415926535897
#define SQRT3 1.73205080757

using namespace std;

int main() {
    Shape Contain, Small; //Shape type variables
    double ContainA, ContainB, SmallA, SmallB;  // Length variables
    ofstream myfile;
    myfile.open ("output.svg");
    askShape(Contain, "main container");
    askInfo(Contain, ContainA, ContainB);
    askShape(Small, "small");
    askInfo(Small, SmallA, SmallB);
    //After calling input functions, with if statements decide draw function
    if(Contain == Shape::Circ && Small == Shape::Rect){
        drawCR(ContainA, SmallA, SmallB, myfile);
    } else if(Contain == Shape::Circ && Small == Shape::Circ){
        drawCC(ContainA, SmallA, myfile);
    } else if(Contain == Shape::Circ && Small == Shape::Tri){
        drawCT(ContainA, SmallA, myfile);
    } else if(Contain == Shape::Rect && Small == Shape::Rect){
        drawRR(ContainA,ContainB, SmallA, SmallB, myfile);
    } else if(Contain == Shape::Rect && Small == Shape::Circ){
        drawRC(ContainA,ContainB, SmallA, myfile);
    } else if(Contain == Shape::Rect && Small == Shape::Tri){
        drawRT(ContainA,ContainB, SmallA, myfile);
    } else if(Contain == Shape::Tri && Small == Shape::Tri){
        drawTT(ContainA, SmallA, myfile);
    } else if(Contain == Shape::Tri && Small == Shape::Circ){
        drawTC(ContainA, SmallA, myfile);
    } else if(Contain == Shape::Tri && Small == Shape::Rect){
        drawTR(ContainA, SmallA, SmallB, myfile);
    } else {
        cerr << "Something went wrong :(" << endl ;
    }

    myfile.close();
    return 0;
}
