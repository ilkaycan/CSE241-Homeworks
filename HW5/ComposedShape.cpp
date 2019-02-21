#include "ComposedShape.h"
#include <iostream>
#include <fstream>
#include <vector>
#include<cmath>
#include "Rectangle.h"
#include "Triangle.h"
#include "NegativityException.h"
#include "Circle.h"
#include "Shape.h"
#include "NoParamConstructorException.h"

#define PI 3.1415926535897
#define SQRT3 1.73205080757

using namespace std;
namespace GTU {
    //checks if given circle fits in circle by
//(x-a)^2 + (y-b)^2 = r^2
    bool ComposedShape::checkCircleInCircle(const double &cx, const double &cy, const double &SmallA,
                                            const double &ContainA) const {
        bool result = false;
        double x, y;

        x = (ContainA - cx) * (ContainA - cx);
        y = (ContainA - cy) * (ContainA - cy);

        if ((ContainA - SmallA) >= sqrt(x + y)) {
            result = true;
        }

        return result;
    }

//checks if given rectangle fits in circle by
//(x-a)^2 + (y-b)^2 = r^2
    bool ComposedShape::checkRectInCircle(const double &x, const double &y, const double &SmallA,
                                          const double &SmallB, const double &ContainA) const {
        double xdownleft = x, ydownleft = y + SmallB;
        double xupright = x + SmallA, yupright = y, xdownright = x + SmallA, ydownright = y + SmallB;
        bool result = false;

        if (((((x - ContainA) * (x - ContainA)) + ((y - ContainA) * (y - ContainA))) <= (ContainA * ContainA)) &&
            ((((xdownleft - ContainA) * (xdownleft - ContainA)) + ((ydownleft - ContainA) * (ydownleft - ContainA))) <=
             (ContainA * ContainA)) &&
            ((((xupright - ContainA) * (xupright - ContainA)) + ((yupright - ContainA) * (yupright - ContainA))) <=
             (ContainA * ContainA)) &&
            ((((xdownright - ContainA) * (xdownright - ContainA)) +
              ((ydownright - ContainA) * (ydownright - ContainA))) <= (ContainA * ContainA))) {
            result = true;
        }
        return result;
    }

//checks if given triangle fits in circle by
//(x-a)^2 + (y-b)^2 = r^2
    bool ComposedShape::checkTriInCircle(const double &x1, const double &y1, const double &x2, const double &y2,
                                         const double &x3, const double &y3, const double &ContainA) const {
        bool result = false;

        if (((((x1 - ContainA) * (x1 - ContainA)) + ((y1 - ContainA) * (y1 - ContainA))) <= (ContainA * ContainA)) &&
            ((((x2 - ContainA) * (x2 - ContainA)) + ((y2 - ContainA) * (y2 - ContainA))) <= (ContainA * ContainA)) &&
            ((((x3 - ContainA) * (x3 - ContainA)) + ((y3 - ContainA) * (y3 - ContainA))) <= (ContainA * ContainA))) {
            result = true;
        }

        return result;
    }

//constructors
    ComposedShape::ComposedShape(const Rectangle &Contain, Rectangle Small) {
        shapeContain = ShapeType::Rectangle;
        RContain = Contain;
        shapeSmall = ShapeType::Rectangle;
        RSmall = Small;

    }

    ComposedShape::ComposedShape(const Rectangle &Contain, Circle Small) {
        shapeContain = ShapeType::Rectangle;
        RContain = Contain;
        shapeSmall = ShapeType::Circle;
        CSmall = Small;
        ptr = nullptr;
    }

    ComposedShape::ComposedShape(const Rectangle &Contain, Triangle Small) {
        shapeContain = ShapeType::Rectangle;
        RContain = Contain;
        shapeSmall = ShapeType::Triangle;
        TSmall = Small;
        ptr = nullptr;

    }

    ComposedShape::ComposedShape(const Triangle &Contain, Rectangle Small) {
        shapeContain = ShapeType::Triangle;
        TContain = Contain;
        shapeSmall = ShapeType::Rectangle;
        RSmall = Small;
        ptr = nullptr;

    }

    ComposedShape::ComposedShape(const Triangle &Contain, Triangle Small) {
        shapeContain = ShapeType::Triangle;
        TContain = Contain;
        shapeSmall = ShapeType::Triangle;
        TSmall = Small;
        ptr = nullptr;

    }

    ComposedShape::ComposedShape(const Triangle &Contain, Circle Small) {
        shapeContain = ShapeType::Triangle;
        TContain = Contain;
        shapeSmall = ShapeType::Circle;
        CSmall = Small;
        ptr = nullptr;

    }

    ComposedShape::ComposedShape(const Circle &Contain, Rectangle Small) {
        shapeContain = ShapeType::Circle;
        CContain = Contain;
        shapeSmall = ShapeType::Rectangle;
        RSmall = Small;
        ptr = nullptr;

    }

    ComposedShape::ComposedShape(const Circle &Contain, Circle Small) {
        shapeContain = ShapeType::Circle;
        CContain = Contain;
        shapeSmall = ShapeType::Circle;
        CSmall = Small;
        ptr = nullptr;

    }

    ComposedShape::ComposedShape(const Circle &Contain, Triangle Small) {
        shapeContain = ShapeType::Circle;
        CContain = Contain;
        shapeSmall = ShapeType::Triangle;
        TSmall = Small;
        ptr = nullptr;

    }

    ComposedShape::ComposedShape(void) throw(NoParamConstructorException){
        throw NoParamConstructorException();
    }
// Optimal fit calls suitable function to calculate how many small shapes
// fits in the Container and how to position them
    void ComposedShape::optimalFit() {
        double areaContain, areaSmall, shapeNum;
        if (shapeContain == ShapeType::Rectangle) {
            areaContain = RContain.getArea();
            if (shapeSmall == ShapeType::Rectangle) {
                RRoptimal();
            } else if (shapeSmall == ShapeType::Triangle) {
                RToptimal();
            } else if (shapeSmall == ShapeType::Circle) {
                RCoptimal();
            } else {
                cerr << "Something went wrong :(" << endl;
                exit(EXIT_FAILURE);
            }
        } else if (shapeContain == ShapeType::Triangle) {
            areaContain = TContain.getArea();
            if (shapeSmall == ShapeType::Rectangle) {
                TRoptimal();
            } else if (shapeSmall == ShapeType::Triangle) {
                TToptimal();
            } else if (shapeSmall == ShapeType::Circle) {
                TCoptimal();
            } else {
                cerr << "Something went wrong :(" << endl;
                exit(EXIT_FAILURE);
            }
        } else if (shapeContain == ShapeType::Circle) {
            areaContain = CContain.getArea();
            if (shapeSmall == ShapeType::Rectangle) {
                CRoptimal();
            } else if (shapeSmall == ShapeType::Triangle) {
                CToptimal();
            } else if (shapeSmall == ShapeType::Circle) {
                CCoptimal();
            } else {
                cerr << "Something went wrong :(" << endl;
                exit(EXIT_FAILURE);
            }
        } else {
            cerr << "Something went wrong :(" << endl;
            exit(EXIT_FAILURE);
        }
        shapeNum = InnerShape.size();
        if (shapeSmall == ShapeType::Rectangle) {
            areaSmall = shapeNum * RSmall.getArea();
        } else if (shapeSmall == ShapeType::Triangle) {
            areaSmall = shapeNum * TSmall.getArea();
        } else if (shapeSmall == ShapeType::Circle) {
            areaSmall = shapeNum * CSmall.getArea();
        } else {
            cerr << "Something went wrong :(" << endl;
            exit(EXIT_FAILURE);
        }
        cout << "I can fit at most " << shapeNum << " small shapes into the main container.";
        cout << " The empty area (blue) in container is " << areaContain - areaSmall << "." << endl;
    }
// Following functions  calculate how many small shapes
// fits in the Container and how to position them
    void ComposedShape::RRoptimal() {
        double SmallA = RSmall.getSide1();
        double SmallB = RSmall.getSide2();
        double x = RSmall.getX();
        double y = RSmall.getY();
        double ContainA = RContain.getSide1();
        double ContainB = RContain.getSide2();
// decide if small shape is horizontal or vertical
        if ((SmallA >= ContainA && SmallA <= ContainB && SmallB <= ContainA) ||
            (SmallB >= ContainB && SmallB <= ContainA && SmallA <= ContainB)) {

            double temp = SmallA;
            SmallA = SmallB;
            SmallB = temp;
        }
        // outer loop is rows and inner loop is columns
        // and ranges are determined due to containers width and height
        for (int i = (int) (ContainB / SmallB); i > 0; i--) {
            for (int j = (int) (ContainA / SmallA); j > 0; j--) {
                Rectangle rect(SmallA, SmallB, x, y);
                ptr = new Rectangle(rect);
                InnerShape.push_back(ptr);
                x += SmallA;
            }
            x = 0;
            y += SmallB;
        }
    }

    void ComposedShape::RToptimal() {
        double SmallA = TSmall.getSide();
        double ContainA = RContain.getSide1();
        double ContainB = RContain.getSide2();
        double xup = SmallA / 2, yup = 0, xleft = 0, ydown = (SmallA / 2) * SQRT3, xright = SmallA;
        double adown = SmallA, aleft = SmallA / 2, aright = (SmallA * 3) / 2, bup = 0, bdown = (SmallA / 2) * SQRT3;

        // outer loop is rows and inner loop is columns
        // and ranges are determined due to containers width and height
        for (int i = (int) (ContainB / (SQRT3 * (SmallA / 2))); i > 0; i--) {
            for (int j = (int) (ContainA / (SmallA)); j > 0; j--) {
                Triangle tri(SmallA, xup, yup, xleft, ydown, xright, ydown);
                ptr = new Triangle(tri);
                InnerShape.push_back(ptr);
                xup += SmallA;
                xright += SmallA;
                xleft += SmallA;
            }
            yup += (SmallA / 2) * SQRT3;
            ydown += (SmallA / 2) * SQRT3;
            xup = SmallA / 2;
            xleft = 0;
            xright = SmallA;
        }
        // this loop draws reverse triangles
        for (int i = (int) (ContainB / (SQRT3 * (SmallA / 2))); i > 0; i--) {
            for (int j = (int) ((ContainA - (SmallA / 2)) / (SmallA)); j > 0; j--) {
                Triangle tri2(SmallA, adown, bdown, aleft, bup, aright, bup);
                ptr = new Triangle(tri2);
                InnerShape.push_back(ptr);
                adown += SmallA;
                aright += SmallA;
                aleft += SmallA;
            }
            bup += (SmallA / 2) * SQRT3;
            bdown += (SmallA / 2) * SQRT3;
            adown = SmallA;
            aleft = SmallA / 2;
            aright = (SmallA * 3) / 2;
        }
    }

    void ComposedShape::RCoptimal() {
        double ContainA = RContain.getSide1();
        double ContainB = RContain.getSide2();
        double SmallA = CSmall.getRadius();
        double cx = SmallA, cy = SmallA;
        for (int i = (int) (ContainB / (SmallA * 2)); i > 0; i--) {
            for (int j = (int) (ContainA / (2 * SmallA)); j > 0; j--) {
                Circle circ(SmallA, cx, cy);
                ptr = new Circle(circ);
                InnerShape.push_back(ptr);
                cx += 2 * SmallA;
            }

            cx = SmallA;
            cy += 2 * SmallA;
        }
    }

    void ComposedShape::CRoptimal() {
        double ContainA = CContain.getRadius();
        double SmallA = RSmall.getSide1();
        double SmallB = RSmall.getSide2();
        double x = 0, y = 0;

        for (int i = (int) ((ContainA * 2) / SmallB); i > 0; i--) {
            for (int j = (int) ((ContainA * 2) / SmallA); j > 0; j--) {
                if (checkRectInCircle(x, y, SmallA, SmallB, ContainA)) {
                    Rectangle rect(SmallA, SmallB, x, y);
                    ptr = new Rectangle(rect);
                    InnerShape.push_back(ptr);
                }
                x += SmallA;
            }
            x = 0;
            y += SmallB;
        }
    }

    void ComposedShape::CCoptimal() {
        double ContainA = CContain.getRadius();
        double SmallA = CSmall.getRadius();
        double cx = 0, cy = 0;

        for (int i = (int) (ContainA / SmallA); i > 0; i--) {
            for (int j = (int) (ContainA / SmallA); j > 0; j--) {
                while ((cx <= ContainA) && (!checkCircleInCircle(cx, cy, SmallA, ContainA))) {
                    cx++;
                }
                if (checkCircleInCircle(cx, cy, SmallA, ContainA)) {
                    Circle circ(SmallA, cx, cy);
                    ptr = new Circle(circ);
                    InnerShape.push_back(ptr);
                }
                cx += 2 * SmallA;
            }
            cx = 0;
            cy += 2 * SmallA;
        }
        if (InnerShape.size() == 0 && SmallA <= ContainA) {
            Circle circ(SmallA, ContainA, ContainA);
            ptr = new Circle(circ);
            InnerShape.push_back(ptr);
        }
    }

    void ComposedShape::CToptimal() {
        double ContainA = CContain.getRadius();
        double SmallA = TSmall.getSide();
        double xup = SmallA / 2, yup = 0, xleft = 0, ydown = (SmallA / 2) * SQRT3, xright = SmallA;
        double adown = SmallA, aleft = SmallA / 2, aright = (SmallA * 3) / 2, bup = 0, bdown = (SmallA / 2) * SQRT3;
        for (int i = (int) ((ContainA * 2) / (SQRT3 * (SmallA / 2))); i > 0; i--) {
            for (int j = (int) ((ContainA * 2) / (SmallA)); j > 0; j--) {
                if (checkTriInCircle(xup, yup, xleft, ydown, xright, ydown, ContainA)) {
                    Triangle tri(SmallA, xup, yup, xleft, ydown, xright, ydown);
                    ptr = new Triangle(tri);
                    InnerShape.push_back(ptr);
                }
                xup += SmallA;
                xright += SmallA;
                xleft += SmallA;
            }
            yup += (SmallA / 2) * SQRT3;
            ydown += (SmallA / 2) * SQRT3;
            xup = SmallA / 2;
            xleft = 0;
            xright = SmallA;
        }
        // checks if triangles are in circle and draws reverse triangles
        for (int i = (int) ((ContainA * 2) / (SQRT3 * (SmallA / 2))); i > 0; i--) {
            for (int j = (int) (((ContainA * 2) - (SmallA / 2)) / (SmallA)); j > 0; j--) {
                if (checkTriInCircle(adown, bdown, aleft, bup, aright, bup, ContainA)) {
                    Triangle tri2(SmallA, adown, bdown, aleft, bup, aright, bup);
                    ptr = new Triangle(tri2);
                    InnerShape.push_back(ptr);
                }
                adown += SmallA;
                aright += SmallA;
                aleft += SmallA;
            }
            bup += (SmallA / 2) * SQRT3;
            bdown += (SmallA / 2) * SQRT3;
            adown = SmallA;
            aleft = SmallA / 2;
            aright = (SmallA * 3) / 2;
        }
    }

    void ComposedShape::TCoptimal() {
        double ContainA = TContain.getSide();
        double SmallA = CSmall.getRadius();
        double cx = ContainA / 2;
        double cy = 2 * SmallA;
        int rownum = 1;
        // by geometrical calculations i found that with every row i can
        // add another circle so i decided inner loop's range by that
        for (int i = (int) ((ContainA / (2 * SmallA)) - SQRT3 + 1); i > 0; i--) {
            for (int j = rownum; j > 0; j--) {
                Circle circle(SmallA, cx, cy);
                ptr = new Circle(circle);
                InnerShape.push_back(ptr);
                cx += 2 * SmallA;
            }

            cx = (ContainA / 2) - (rownum * SmallA);
            cy += SmallA * SQRT3;
            rownum++;
        }
    }

    void ComposedShape::TRoptimal() {
        double SmallA = RSmall.getSide1();
        double SmallB = RSmall.getSide2();
        double ContainA = TContain.getSide();
        //makes rectangles horizontal
        if (SmallA < SmallB) {
            double swap = SmallA;
            SmallA = SmallB;
            SmallB = swap;
        }
        double x = SmallB / SQRT3;
        double y = (((ContainA / 2) * SQRT3) - SmallB);
        double changeContain = 0, temp = ContainA;
        // outer loop is rows and inner loop is columns
        // and ranges are determined due to containers width and height
        for (int i = (int) (((ContainA / 2) * SQRT3) / SmallB); i > 0; i--) {
            for (int j = (int) ((temp - (2 * SmallB / SQRT3)) / SmallA); j > 0; j--) {
                Rectangle rect(SmallA, SmallB, x, y);
                ptr = new Rectangle(rect);
                InnerShape.push_back(ptr);
                x += SmallA;
            }
            changeContain += SmallB / SQRT3;
            y -= SmallB;
            x = (SmallB / SQRT3) + changeContain;
            temp -= 2 * (SmallB / SQRT3);
        }
    }

    void ComposedShape::TToptimal() {
        double ContainA = TContain.getSide();
        double SmallA = TSmall.getSide();
        double xup = ContainA / 2, yup = 0, xleft = (ContainA - SmallA) / 2, ydown = SmallA * SQRT3 / 2, xright =
                (ContainA + SmallA) / 2;
        double adown = ContainA / 2, bdown = SmallA * SQRT3, aleft = (ContainA - SmallA) / 2, aright =
                (ContainA + SmallA) / 2, bup = SmallA * SQRT3 / 2;

        // outer loop is rows and inner loop is columns
        // and ranges are determined due to containers width and height

        int k = 1;
        while (ydown <= (ContainA * SQRT3 / 2)) {
            while (xright <= ((ContainA / 2) + (SmallA / 2 * k))) {
                Triangle tri(SmallA, xup, yup, xleft, ydown, xright, ydown);
                ptr = new Triangle(tri);
                InnerShape.push_back(ptr);
                xup += SmallA;
                xright += SmallA;
                xleft += SmallA;
            }
            yup += (SmallA / 2) * SQRT3;
            ydown += (SmallA / 2) * SQRT3;
            xup = (ContainA / 2) - (k * SmallA / 2);
            xleft = ((ContainA - SmallA) / 2) - (k * SmallA / 2);
            xright = ((ContainA + SmallA) / 2) - (k * SmallA / 2);
            k++;
        }
        k = 1;
        //draws reverse triangles
        while (bdown <= (ContainA * SQRT3 / 2)) {
            while (aright <= ((ContainA / 2) + (SmallA / 2 * k))) {
                Triangle tri2(SmallA, adown, bdown, aleft, bup, aright, bup);
                ptr = new Triangle(tri2);
                InnerShape.push_back(ptr);
                adown += SmallA;
                aright += SmallA;
                aleft += SmallA;
            }

            bdown += (SmallA / 2) * SQRT3;
            bup += (SmallA / 2) * SQRT3;
            adown = (ContainA / 2) - (k * SmallA / 2);
            aleft = ((ContainA - SmallA) / 2) - (k * SmallA / 2);
            aright = ((ContainA + SmallA) / 2) - (k * SmallA / 2);
            k++;
        }
    }
// draw function writes ComposedShape to SVG file
    void ComposedShape::draw(ofstream &myfile) {

        if (shapeContain == ShapeType::Rectangle) {
            double x = RContain.getX();
            double y = RContain.getY();
            double width = RContain.getSide1();
            double height = RContain.getSide2();

            startSVG(myfile, width, height);
            myfile << RContain;
        } else if (shapeContain == ShapeType::Triangle) {
            double x1 = TContain.getX1();
            double y1 = TContain.getY1();
            double x2 = TContain.getX2();
            double y2 = TContain.getY2();
            double x3 = TContain.getX3();
            double y3 = TContain.getY3();
            double Side = TContain.getSide();
            startSVG(myfile, Side, Side);

            myfile << TContain;
        } else if (shapeContain == ShapeType::Circle) {
            double r = CContain.getRadius();
            double cx = CContain.getCx();
            double cy = CContain.getCy();

            startSVG(myfile, 2 * r, 2 * r);

            myfile << CContain;
        } else {
            cerr << "Something went wrong :(" << endl;
            exit(EXIT_FAILURE);
        }


        for (auto i = 0; i < InnerShape.size(); ++i) {
            myfile << *(InnerShape[i]);
        }
        endSVG(myfile);
    }
//Calculates container's area
    double ComposedShape::getArea(void) {
        if (shapeContain == ShapeType::Rectangle) {
            return RContain.getArea();
        } else if (shapeContain == ShapeType::Triangle) {
            return TContain.getArea();
        } else if (shapeContain == ShapeType::Circle) {
            return CContain.getArea();
        }
        exit(EXIT_FAILURE);
    }
// Calculates container's perimeter
    double ComposedShape::getPerimeter(void) {
        if (shapeContain == ShapeType::Rectangle) {
            return RContain.getPerimeter();
        } else if (shapeContain == ShapeType::Triangle) {
            return TContain.getPerimeter();
        } else if (shapeContain == ShapeType::Circle) {
            return CContain.getPerimeter();
        }
        exit(EXIT_FAILURE);
    }
// Increment and decrement operators overrided below
    const ComposedShape &ComposedShape::operator++(int) {
        static ComposedShape temp = *this;
        for (int i = 0; i < InnerShape.size(); i++) {
            (*InnerShape[i])++;
        }
        return temp;
    } //postfix
    ComposedShape &ComposedShape::operator++() {
        for (int i = 0; i < InnerShape.size(); i++) {
            ++(*(InnerShape[i]));
        }
        return *this;
    }

    const ComposedShape &ComposedShape::operator--(int) {
        static ComposedShape temp = *this;
        for (int i = 0; i < InnerShape.size(); i++) {
            (*InnerShape[i])--;
        }
        return temp;
/*		This was another idea for postfix increment and decrement
		But it got core dumped too.	
		To use this i have to free tempCom at destructor

        tempCom = new ComposedShape(*this);
        for (int i = 0; i < InnerShape.size(); i++) {
            ++(*InnerShape[i]);
        }
       return *tempCom;


*/
    } //postfix
    ComposedShape &ComposedShape::operator--() {

        for (int i = 0; i < InnerShape.size(); i++) {
            --(*InnerShape[i]);
        }
        return *this;
    }

    void ComposedShape::output(ostream &outputStream) {
/* Intentionally Empty
 * to prevent ComposedShape to be Abstract Class */
    }

//Big Three
//Assignment operator overloading

    ComposedShape &ComposedShape::operator=(const ComposedShape &rtSide) {
        *this = ComposedShape(rtSide);

        return *this;
    }

//Destructor
    ComposedShape::~ComposedShape(void) {
        if (ptr != nullptr) {
            delete ptr;
        }
/*        if (tempCom != nullptr) {
            delete tempCom;
       }
*/
        for (int i = 0; i < InnerShape.size(); i++) {
            if (InnerShape[i] != nullptr) {
                delete InnerShape[i];
            }
        }
    }

//Copy constructor
    ComposedShape::ComposedShape(const ComposedShape &copyObject) {
        ptr = copyObject.ptr;
//		tempCom = copyObject.tempCom;
        shapeContain = copyObject.shapeContain;
        shapeSmall = copyObject.shapeSmall;

        if (shapeContain == ShapeType::Rectangle) {
            RContain = copyObject.RContain;
        } else if (shapeContain == ShapeType::Triangle) {
            TContain = copyObject.TContain;
        } else if (shapeContain == ShapeType::Circle) {
            CContain = copyObject.CContain;
        }

        if (shapeSmall == ShapeType::Rectangle) {
            RSmall = copyObject.RSmall;
        } else if (shapeSmall == ShapeType::Triangle) {
            TSmall = copyObject.TSmall;
        } else if (shapeSmall == ShapeType::Circle) {
            CSmall = copyObject.CSmall;
        }
        for (int i = 0; i < copyObject.InnerShape.size(); i++) {
            InnerShape.push_back(copyObject.InnerShape[i]->duplicatefunction());
        }
    }

    ComposedShape *ComposedShape::duplicatefunction(void) {
        return new ComposedShape(*this);
    }
}
