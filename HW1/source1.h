#include<fstream>
enum class Shape{Circ, Tri, Rect, Err};
using namespace std;

#ifndef SOURCE1_H_
#define SOURCE1_H_

Shape askShape(Shape &CorS, string Which);
void askInfo(Shape CorS, double &a, double &b);
void drawRR(double ContainA, double ContainB, double SmallA, double SmallB, ofstream &myfile);
void drawRC(double ContainA, double ContainB, double SmallA, ofstream &myfile);
void drawRT(double ContainA, double ContainB, double SmallA, ofstream &myfile);
void drawTR(double ContainA, double SmallA, double SmallB, ofstream &myfile);
void drawTT(double ContainA, double SmallA, ofstream &myfile);
void drawTC(double ContainA, double SmallA, ofstream &myfile);
void drawCR(double ContainA, double SmallA, double SmallB, ofstream &myfile);
void drawCC(double ContainA, double SmallA, ofstream &myfile);
void drawCT(double ContainA, double SmallA, ofstream &myfile);
bool checkRectInCircle(double x, double y, double SmallA, double SmallB, double ContainA);
bool checkTriInCircle(double x1, double y1, double x2, double y2, double x3, double y3,double ContainA);
bool checkCircleInCircle(double cx, double cy, double SmallA, double ContainA);

#endif 	
