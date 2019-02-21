all : Rectangle.o Circle.o Triangle.o ComposedShape.o Shape.o Polygon.o PolygonVect.o PolygonDyn.o NegativityException.o NoParamConstructorException.o 171044053_main.o
	g++ -o exe Rectangle.o Circle.o Triangle.o ComposedShape.o Shape.o Polygon.o PolygonVect.o PolygonDyn.o NegativityException.o NoParamConstructorException.o 171044053_main.o

Rectangle.o : Rectangle.cpp
	g++ -c -std=c++11 -Wall Rectangle.cpp

Circle.o : Circle.cpp
	g++ -c -std=c++11 -Wall Circle.cpp

Triangle.o : Triangle.cpp
	g++ -c -std=c++11 -Wall Triangle.cpp

ComposedShape.o : ComposedShape.cpp
	g++ -c -std=c++11 -Wall ComposedShape.cpp

Shape.o : Shape.cpp
	g++ -c -std=c++11 -Wall Shape.cpp

Polygon.o : Polygon.cpp
	g++ -c -std=c++11 -Wall Polygon.cpp

PolygonVect.o : PolygonVect.cpp
	g++ -c -std=c++11 -Wall PolygonVect.cpp

PolygonDyn.o : PolygonDyn.cpp
	g++ -c -std=c++11 -Wall PolygonDyn.cpp

NegativityException.o : NegativityException.cpp
	g++ -c -std=c++11 -Wall NegativityException.cpp

NoParamConstructorException.o : NoParamConstructorException.cpp
	g++ -c -std=c++11 -Wall NoParamConstructorException.cpp

171044053_main.o :  171044053_main.cpp
	g++ -c -std=c++11 -Wall 171044053_main.cpp

clean:
	rm *.o exe
