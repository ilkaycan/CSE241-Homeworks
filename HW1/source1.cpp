#include <iostream>
#include <string>
#include<fstream>
#include<cmath>
#include "source1.h"
#define PI 3.1415926535897
#define SQRT3 1.73205080757

using namespace std;

//Asks shape to user
Shape askShape(Shape &CorS, string Which){
    char A;
    cout << "Please enter the " << Which << " shape (R, C, T)" << endl;
    cin >> A;
    if(A == 'R' || A == 'r'){
        CorS = Shape::Rect;
    } else if(A == 'C' || A == 'c'){
        CorS = Shape::Circ;
    } else if(A == 'T' || A == 't'){
        CorS = Shape::Tri;
    } else {
        cerr << "You have entered wrong letter!!!" << endl;
        CorS = Shape::Err;
    }
    return CorS;
}
//Asks shape lenght to user
void askInfo(Shape CorS, double &a, double &b){
    if(CorS == Shape::Rect){
        cout << "Please enter the width" << endl;
        cin >> a;
        cout << "Please enter the height" << endl;
        cin >> b;
    }else if(CorS == Shape::Circ){
        cout << "Please enter the radius" << endl;
        cin >> a;
    } else if(CorS == Shape::Tri){
        cout << "Please enter the one side of equiatral triangle" << endl;
        cin >> a;
    }
}
//checks if given rectangle fits in circle by
//(x-a)^2 + (y-b)^2 = r^2
bool checkRectInCircle(double x, double y, double SmallA, double SmallB, double ContainA){
    double xdownleft = x, ydownleft = y+SmallB;
    double xupright = x+SmallA, yupright = y, xdownright = x+SmallA, ydownright = y+SmallB;
    bool result = false;

    if( ( ( ((x-ContainA)*(x-ContainA)) + ((y-ContainA)*(y-ContainA)) ) <= (ContainA*ContainA) ) &&
        ( ( ((xdownleft-ContainA)*(xdownleft-ContainA)) + ((ydownleft-ContainA)*(ydownleft-ContainA)) ) <= (ContainA*ContainA) ) &&
        ( ( ((xupright-ContainA)*(xupright-ContainA)) + ((yupright-ContainA)*(yupright-ContainA)) ) <= (ContainA*ContainA) ) &&
        ( ( ((xdownright-ContainA)*(xdownright-ContainA)) + ((ydownright-ContainA)*(ydownright-ContainA)) ) <= (ContainA*ContainA) ) ){
        result = true;
    }
    return result;
}
//checks if given triangle fits in circle by
//(x-a)^2 + (y-b)^2 = r^2
bool checkTriInCircle(double x1, double y1, double x2, double y2, double x3, double y3,double ContainA){
    bool result = false;

    if( ((((x1-ContainA)*(x1-ContainA)) + ((y1-ContainA)*(y1-ContainA)) ) <= (ContainA*ContainA) ) &&
        ((((x2-ContainA)*(x2-ContainA)) + ((y2-ContainA)*(y2-ContainA)) ) <= (ContainA*ContainA) ) &&
        ((((x3-ContainA)*(x3-ContainA)) + ((y3-ContainA)*(y3-ContainA)) ) <= (ContainA*ContainA) )   ){
        result = true;
    }

    return result;
}
//checks if circle rectangle fits in circle by
//If [(x-x0)^2+(y-y0)^2]^0.5 <= R-r
bool checkCircleInCircle(double cx, double cy, double SmallA, double ContainA){
    bool result = false;
    double x, y;

    x = (ContainA - cx) * (ContainA - cx);
    y = (ContainA - cy) * (ContainA - cy);

    if ( (ContainA-SmallA) >= sqrt(x+y) ){
        result = true;
    }

    return result;
}
// draws rectangle in rectangle
void drawRR(double ContainA, double ContainB, double SmallA, double SmallB, ofstream &myfile){
    double x=0, y=0, shapenum = 0, area;
    myfile << "<svg version=\"1.1\" " << endl << "baseProfile=\"full\"" << endl;
    myfile << "width=" << "\"" << ContainA << "\"" ;
    myfile << " height=" << "\"" << ContainB << "\""  << endl;
    myfile << "xmlns=\"http://www.w3.org/2000/svg\">" << endl;
    myfile << "<rect width=\"100%\" height=\"100%\" stroke=\"black\" stroke-width=\"1\" fill=\"blue\" />" << endl;
    // decide if small shape is horizontal or vertical
    if((SmallA>=ContainA && SmallA<=ContainB && SmallB<=ContainA)||
       (SmallB>=ContainB && SmallB<=ContainA && SmallA<=ContainB) ||
       ((ContainA/SmallB)*(ContainB/SmallA))>((ContainA/SmallA)*(ContainB/SmallB))){
        double temp = SmallA;
        SmallA = SmallB;
        SmallB = temp;
    }
    // outer loop is rows and inner loop is columns
    // and ranges are determined due to containers width and height
    for ( int i = (int)(ContainB/SmallB) ; i>0; i--){
        for(int j = (int)(ContainA/SmallA) ; j>0 ; j --){
            myfile << "<rect x=\""<< x <<"\" y=\"" << y << "\" width=\"" << SmallA;
            myfile <<"\" height=\""<< SmallB << "\" stroke=\"black\" stroke-width=\"1\" fill=\"purple\" />" << endl;
            x += SmallA;
            shapenum++;
        }
        x = 0;
        y += SmallB;
    }

    myfile << "</svg>" << endl;

    area = (ContainA*ContainB) - (shapenum*SmallA*SmallB);

    cout << "I can fit at most " << shapenum << " small shapes into the main container." ;
    cout << " The empty area (blue) in container is " << area << "." ;
}
// draws circle in rectangle
void drawRC(double ContainA, double ContainB, double SmallA, ofstream &myfile){
    double cx=SmallA, cy=SmallA, shapenum = 0, area;
    myfile << "<svg version=\"1.1\" " << endl << "baseProfile=\"full\"" << endl;
    myfile << "width=" << "\"" << ContainA << "\"" ;
    myfile << " height=" << "\"" << ContainB << "\""  << endl;
    myfile << "xmlns=\"http://www.w3.org/2000/svg\">" << endl;
    myfile << "<rect width=\"100%\" height=\"100%\" stroke=\"black\" stroke-width=\"1\" fill=\"blue\" />" << endl;
    // outer loop is rows and inner loop is columns
    // and ranges are determined due to containers width and height
    for ( int i = (int)(ContainB/(SmallA*2)); i>0; i--){
        for(int j = (int)(ContainA/(2*SmallA)) ; j>0 ; j --){
            myfile << "<circle cx=\""<< cx <<"\" cy=\"" << cy << "\" r=\"" << SmallA;
            myfile << "\" stroke=\"black\" stroke-width=\"1\" fill=\"purple\" />" << endl;
            cx += 2*SmallA;
            shapenum++;
        }

        cx = SmallA;
        cy += 2*SmallA;

    }

    myfile << "</svg>" << endl;

    area = (ContainA*ContainB) - (shapenum*SmallA*SmallA*PI);

    cout << "I can fit at most " << shapenum << " small shapes into the main container." ;
    cout << " The empty area (blue) in container is " << area << "." ;

}
// draws triangle in rectangle
void drawRT(double ContainA, double ContainB, double SmallA, ofstream &myfile){
    double shapenum = 0, area;
    double xup = SmallA/2, yup = 0, xleft = 0, ydown = (SmallA/2)*SQRT3, xright = SmallA;
    double adown = SmallA, aleft = SmallA/2, aright = (SmallA*3)/2, bup = 0, bdown = (SmallA/2)*SQRT3;
    myfile << "<svg version=\"1.1\" " << endl << "baseProfile=\"full\"" << endl;
    myfile << "width=" << "\"" << ContainA << "\"" ;
    myfile << " height=" << "\"" << ContainB << "\""  << endl;
    myfile << "xmlns=\"http://www.w3.org/2000/svg\">" << endl;
    myfile << "<rect width=\"100%\" height=\"100%\" stroke=\"black\" stroke-width=\"1\" fill=\"blue\" />" << endl;
    // outer loop is rows and inner loop is columns
    // and ranges are determined due to containers width and height
    for ( int i = (int)(ContainB/(SQRT3*(SmallA/2))) ; i>0; i--){
        for(int j = (int)(ContainA/(SmallA)) ; j>0 ; j --){
            myfile << "<polygon points=\"" << xup << "," << yup << " " ;
            myfile << xleft <<"," << ydown << " " ;
            myfile << xright << "," << ydown << "\"" << endl;
            myfile << "stroke=\"black\" stroke-width=\"1\" fill=\"purple\" />" << endl;
            xup += SmallA;
            xright += SmallA;
            xleft += SmallA;
            shapenum++;
        }
        yup += (SmallA/2)*SQRT3;
        ydown += (SmallA/2)*SQRT3;
        xup = SmallA/2;
        xleft = 0;
        xright = SmallA;
    }
    // this loop draws reverse triangles
    for ( int i = (int)(ContainB/(SQRT3*(SmallA/2))) ; i>0; i--){
        for(int j = (int)((ContainA-(SmallA/2))/(SmallA)) ; j>0 ; j --){
            myfile << "<polygon points=\"" << adown << "," << bdown << " " ;
            myfile << aleft <<"," << bup << " " ;
            myfile << aright << "," << bup << "\"" << endl;
            myfile << "stroke=\"black\" stroke-width=\"1\" fill=\"purple\" />" << endl;
            adown += SmallA;
            aright += SmallA;
            aleft += SmallA;
            shapenum++;
        }
        bup += (SmallA/2)*SQRT3;
        bdown += (SmallA/2)*SQRT3;
        adown = SmallA;
        aleft = SmallA/2;
        aright = (SmallA*3)/2;
    }
    myfile << "</svg>" << endl;

    area = (ContainA*ContainB) - ((shapenum*SmallA*SmallA*SQRT3)/4);

    cout << "I can fit at most " << shapenum << " small shapes into the main container." ;
    cout << " The empty area (blue) in container is " << area << "." ;
}
// draws rectangle in triangle
void drawTR(double ContainA, double SmallA, double SmallB, ofstream &myfile){
    double x = SmallB/SQRT3;
    double y = (((ContainA/2)*SQRT3)-SmallB);
    double shapenum = 0, area, changeContain=0 , temp = ContainA ;
    myfile << "<svg version=\"1.1\" " << endl << "baseProfile=\"full\"" << endl;
    myfile << "width=" << "\"" << ContainA << "\"" ;
    myfile << " height=" << "\"" << ContainA << "\""  << endl;
    myfile << "xmlns=\"http://www.w3.org/2000/svg\">" << endl;
    myfile << "<polygon points=\"" << ContainA/2 << ",0 0," << (ContainA/2)*SQRT3 <<" "<< ContainA ;
    myfile << "," << (ContainA/2)*SQRT3 << "\""<< endl;
    myfile << "stroke=\"black\" stroke-width=\"1\" fill=\"blue\" />" << endl;
    //makes rectangles horizontal
    if(SmallA<SmallB){
        double swap = SmallA;
        SmallA = SmallB;
        SmallB = swap;
    }
    // outer loop is rows and inner loop is columns
    // and ranges are determined due to containers width and height
    for ( int i = (int)(((ContainA/2)*SQRT3)/SmallB) ; i>0; i--){
        for(int j = (int)((temp-(2*SmallB/SQRT3))/SmallA) ; j>0 ; j --){
            myfile << "<rect x=\""<< x <<"\" y=\"" << y << "\" width=\"" << SmallA;
            myfile <<"\" height=\""<< SmallB << "\" stroke=\"black\" stroke-width=\"1\" fill=\"purple\" />" << endl;
            x += SmallA;
            shapenum++;
        }
        changeContain +=SmallB/SQRT3;
        y -= SmallB;
        x = (SmallB/SQRT3) + changeContain;
        temp -= 2*(SmallB/SQRT3);
    }
    myfile << "</svg>" << endl;

    area = ((ContainA*ContainA*SQRT3)/4) - ((shapenum*SmallA*SmallB));

    cout << "I can fit at most " << shapenum << " small shapes into the main container." ;
    cout << " The empty area (blue) in container is " << area << "." ;
}
// draws triangle in triangle
void drawTT(double ContainA, double SmallA, ofstream &myfile){
 	double shapenum = 0, area;
    double xup = ContainA/2, yup = 0, xleft = (ContainA-SmallA)/2, ydown = SmallA*SQRT3/2, xright = (ContainA + SmallA)/2;
    double adown = ContainA/2, bdown = SmallA*SQRT3, aleft = (ContainA-SmallA)/2, aright = (ContainA + SmallA)/2 , bup = SmallA*SQRT3/2;

    myfile << "<svg version=\"1.1\" " << endl << "baseProfile=\"full\"" << endl;
    myfile << "width=" << "\"" << ContainA << "\"" ;
    myfile << " height=" << "\"" << ContainA << "\""  << endl;
    myfile << "xmlns=\"http://www.w3.org/2000/svg\">" << endl;
    myfile << "<polygon points=\"" << ContainA/2 << ",0 0," << (ContainA/2)*SQRT3 <<" "<< ContainA ;
    myfile << "," << (ContainA/2)*SQRT3 << "\""<< endl;
    myfile << "stroke=\"black\" stroke-width=\"1\" fill=\"blue\" />" << endl;
    // outer loop is rows and inner loop is columns
    // and ranges are determined due to containers width and height

	int k = 1;
    while (ydown <= (ContainA*SQRT3/2)){
        while(xright<=((ContainA/2)+(SmallA/2*k))){
            myfile << "<polygon points=\"" << xup << "," << yup << " " ;
            myfile << xleft <<"," << ydown << " " ;
            myfile << xright << "," << ydown << "\"" << endl;
            myfile << "stroke=\"black\" stroke-width=\"1\" fill=\"purple\" />" << endl;
            xup += SmallA;
            xright += SmallA;
            xleft += SmallA;
            shapenum++;
        }
        yup += (SmallA/2)*SQRT3;
        ydown += (SmallA/2)*SQRT3;
        xup = (ContainA/2) - (k*SmallA/2);
        xleft = ((ContainA-SmallA)/2) - (k*SmallA/2);
        xright =((ContainA+SmallA)/2) - (k*SmallA/2);
		k++;
    }
	k = 1;
	//draws reverse triangles
    while (bdown<= (ContainA*SQRT3/2)){
        while(aright<=((ContainA/2)+(SmallA/2*k))){
            myfile << "<polygon points=\"" << adown << "," << bdown << " " ;
            myfile << aleft <<"," << bup << " " ;
            myfile << aright << "," << bup << "\"" << endl;
            myfile << "stroke=\"black\" stroke-width=\"1\" fill=\"purple\" />" << endl;
            adown += SmallA;
            aright += SmallA;
            aleft += SmallA;
            shapenum++;
        }

        bdown += (SmallA/2)*SQRT3;
        bup += (SmallA/2)*SQRT3;
        adown = (ContainA/2) - (k*SmallA/2);
        aleft = ((ContainA-SmallA)/2) - (k*SmallA/2);
        aright =((ContainA+SmallA)/2) - (k*SmallA/2);
		k++;
    }

    myfile << "</svg>" << endl;

    area = ((ContainA*ContainA*SQRT3)/4) - ((shapenum*SmallA*SmallA*SQRT3)/4);

    cout << "I can fit at most " << shapenum << " small shapes into the main container." ;
    cout << " The empty area (blue) in container is " << area << "." ;
}
// draws circle in triangle
void drawTC(double ContainA, double SmallA, ofstream &myfile){
    double shapenum = 0, area;
    myfile << "<svg version=\"1.1\" " << endl << "baseProfile=\"full\"" << endl;
    myfile << "width=" << "\"" << ContainA << "\"" ;
    myfile << " height=" << "\"" << ContainA << "\""  << endl;
    myfile << "xmlns=\"http://www.w3.org/2000/svg\">" << endl;
    myfile << "<polygon points=\"" << ContainA/2 << ",0 0," << (ContainA/2)*SQRT3 <<" "<< ContainA ;
    myfile << "," << (ContainA/2)*SQRT3 << "\""<< endl;
    myfile << "stroke=\"black\" stroke-width=\"1\" fill=\"blue\" />" << endl;
    double cx = ContainA/2;
    double cy = 2*SmallA;
    int rownum = 1;
    // by geometrical calculations i found that with every row i can
    // add another circle so i decided inner loop's range by that
    for ( int i = (int)((ContainA/(2*SmallA))-SQRT3+1) ; i>0; i--){
        for( int j =rownum ; j>0 ; j --) {
            myfile << "<circle cx=\"" << cx << "\" cy=\"" << cy << "\" r=\"" << SmallA;
            myfile << "\" stroke=\"black\" stroke-width=\"1\" fill=\"purple\" />" << endl;
            cx += 2 * SmallA;
            shapenum++;
        }

        cx = (ContainA/2) - (rownum*SmallA);
        cy += SmallA*SQRT3;
        rownum++;
    }
    myfile << "</svg>" << endl;

    area = ((ContainA*ContainA*SQRT3)/4) - (shapenum*SmallA*SmallA*PI);

    cout << "I can fit at most " << shapenum << " small shapes into the main container." ;
    cout << " The empty area (blue) in container is " << area << "." ;
}
// draws rectangle in circle
void drawCR(double ContainA, double SmallA, double SmallB, ofstream &myfile){
    double x=0, y=0, shapenum = 0, area;
    myfile << "<svg version=\"1.1\" " << endl << "baseProfile=\"full\"" << endl;
    myfile << "width=" << "\"" << ContainA*2 << "\"" ;
    myfile << " height=" << "\"" << ContainA*2 << "\""  << endl;
    myfile << "xmlns=\"http://www.w3.org/2000/svg\">" << endl;
    myfile << "<circle cx=\"" << ContainA << "\"";
    myfile << " cy=\"" << ContainA <<"\"";
    myfile << " r=\""<< ContainA << "\" stroke=\"black\" stroke-width=\"1\" fill=\"blue\" />" << endl;
    // check if rectangle is in circle and draw
    for ( int i = (int)((ContainA*2)/SmallB) ; i>0; i--){
        for(int j = (int)((ContainA*2)/SmallA) ; j>0 ; j --){
            if(checkRectInCircle(x, y, SmallA, SmallB, ContainA)){
                myfile << "<rect x=\""<< x <<"\" y=\"" << y << "\" width=\"" << SmallA;
                myfile <<"\" height=\""<< SmallB << "\" stroke=\"black\" stroke-width=\"1\" fill=\"purple\" />" << endl;
                shapenum++;
            }
            x += SmallA;
        }
        x = 0;
        y += SmallB;
    }
    myfile << "</svg>" << endl;

    area = (PI*ContainA*ContainA) - (shapenum*SmallA*SmallB);

    cout << "I can fit at most " << shapenum << " small shapes into the main container." ;
    cout << " The empty area (blue) in container is " << area << "." ;
}
// draws circle in circle
void drawCC(double ContainA, double SmallA, ofstream &myfile){
    double cx=0, cy = 0, shapenum = 0, area;
    myfile << "<svg version=\"1.1\" " << endl << "baseProfile=\"full\"" << endl;
    myfile << "width=" << "\"" << ContainA*2 << "\"" ;
    myfile << " height=" << "\"" << ContainA*2 << "\""  << endl;
    myfile << "xmlns=\"http://www.w3.org/2000/svg\">" << endl;
    myfile << "<circle cx=\"" << ContainA << "\"";
    myfile << " cy=\"" << ContainA <<"\"";
    myfile << " r=\""<< ContainA << "\" stroke=\"black\" stroke-width=\"1\" fill=\"blue\" />" << endl;
    // check if circle is in circle and draw
    for ( int i = (int)(ContainA/SmallA) ; i>0; i--){
        for(int j = (int)(ContainA/SmallA) ; j>0 ; j --){
            while((cx<=ContainA) && (!checkCircleInCircle(cx, cy, SmallA, ContainA))){
                cx++;
            }
            if(checkCircleInCircle(cx, cy, SmallA, ContainA)){
                myfile << "<circle cx=\""<< cx <<"\" cy=\"" << cy << "\" r=\"" << SmallA;
                myfile << "\" stroke=\"black\" stroke-width=\"1\" fill=\"purple\" />" << endl;
                shapenum++;
            }
            cx += 2*SmallA;
        }
        cx = 0;
        cy += 2*SmallA;
    }
    if (shapenum == 0 && SmallA<=ContainA){
        myfile << "<circle cx=\""<< ContainA <<"\" cy=\"" << ContainA << "\" r=\"" << SmallA;
        myfile << "\" stroke=\"black\" stroke-width=\"1\" fill=\"purple\" />" << endl;
        shapenum++;
    }
    myfile << "</svg>" << endl;

    area = (PI*ContainA*ContainA) - (shapenum*SmallA*SmallA*PI);
    cout << "I can fit at most " << shapenum << " small shapes into the main container." ;
    cout << " The empty area (blue) in container is " << area << "." ;
}
// draws triangle in circle
void drawCT(double ContainA, double SmallA, ofstream &myfile){
    double shapenum = 0, area;
    double xup = SmallA/2, yup = 0, xleft = 0, ydown = (SmallA/2)*SQRT3, xright = SmallA;
    double adown = SmallA, aleft = SmallA/2, aright = (SmallA*3)/2, bup = 0, bdown = (SmallA/2)*SQRT3;
    myfile << "<svg version=\"1.1\" " << endl << "baseProfile=\"full\"" << endl;
    myfile << "width=" << "\"" << ContainA*2 << "\"" ;
    myfile << " height=" << "\"" << ContainA*2 << "\""  << endl;
    myfile << "xmlns=\"http://www.w3.org/2000/svg\">" << endl;
    myfile << "<circle cx=\"" << ContainA << "\"";
    myfile << " cy=\"" << ContainA <<"\"";
    myfile << " r=\""<< ContainA << "\" stroke=\"black\" stroke-width=\"1\" fill=\"blue\" />" << endl;
    // checks if triangles are in circle and draws straigth triangles
    for ( int i = (int)((ContainA*2)/(SQRT3*(SmallA/2))) ; i>0; i--){
        for(int j = (int)((ContainA*2)/(SmallA)) ; j>0 ; j --){
            if(checkTriInCircle(xup, yup, xleft, ydown, xright, ydown, ContainA)) {
                myfile << "<polygon points=\"" << xup << "," << yup << " ";
                myfile << xleft << "," << ydown << " ";
                myfile << xright << "," << ydown << "\"" << endl;
                myfile << "stroke=\"black\" stroke-width=\"1\" fill=\"purple\" />" << endl;
                shapenum++;
            }
            xup += SmallA;
            xright += SmallA;
            xleft += SmallA;
        }
        yup += (SmallA/2)*SQRT3;
        ydown += (SmallA/2)*SQRT3;
        xup = SmallA/2;
        xleft = 0;
        xright = SmallA;
    }
    // checks if triangles are in circle and draws reverse triangles
    for ( int i = (int)((ContainA*2)/(SQRT3*(SmallA/2))) ; i>0; i--){
        for(int j = (int)(((ContainA*2)-(SmallA/2))/(SmallA)) ; j>0 ; j --){
            if(checkTriInCircle(adown, bdown, aleft, bup, aright, bup, ContainA)) {
                myfile << "<polygon points=\"" << adown << "," << bdown << " ";
                myfile << aleft << "," << bup << " ";
                myfile << aright << "," << bup << "\"" << endl;
                myfile << "stroke=\"black\" stroke-width=\"1\" fill=\"purple\" />" << endl;
                shapenum++;
            }
            adown += SmallA;
            aright += SmallA;
            aleft += SmallA;
        }
        bup += (SmallA/2)*SQRT3;
        bdown += (SmallA/2)*SQRT3;
        adown = SmallA;
        aleft = SmallA/2;
        aright = (SmallA*3)/2;
    }
    myfile << "</svg>" << endl;

    area = (PI*ContainA*ContainA) - ((shapenum*SmallA*SmallA*SQRT3)/4);

    cout << "I can fit at most " << shapenum << " small shapes into the main container." ;
    cout << " The empty area (blue) in container is " << area << "." ;
}
