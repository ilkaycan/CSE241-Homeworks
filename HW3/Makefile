all : Rectangle.o Circle.o Triangle.o ComposedShape.o 171044053_main.o
	g++ -o exe Rectangle.o Circle.o Triangle.o ComposedShape.o 171044053_main.o

Rectangle.o : Rectangle.cpp
	g++ -c -std=c++11 -Wall Rectangle.cpp

Circle.o : Circle.cpp
	g++ -c -std=c++11 -Wall Circle.cpp

Triangle.o : Triangle.cpp
	g++ -c -std=c++11 -Wall Triangle.cpp

ComposedShape.o : ComposedShape.cpp
	g++ -c -std=c++11 -Wall ComposedShape.cpp

171044053_main.o : 171044053_main.cpp
	g++ -c -std=c++11 -Wall 171044053_main.cpp

clean:
	rm *.o exe
