import java.awt.BorderLayout;

import javax.swing.JFrame;

@SuppressWarnings("unused")
public class Main_171044053 {
	
	public static void main(String[] args) {
		
		Rectangle rectC = new Rectangle(500, 500);
		Rectangle rectS = new Rectangle(10, 50);
		  
		Circle circC = new Circle(250);
		Circle circS = new Circle(10);
	  
		Triangle triC = new Triangle(500);
		Triangle triS = new Triangle(10);
		
		PolygonDyn polyrect = new PolygonDyn(rectC);
		PolygonVect polycirc = new PolygonVect(circS);
		
		System.out.println("compareTo methods");

		System.out.println(circC.compareTo(triC));
		System.out.println(triS.compareTo(rectC));
		System.out.println(rectC.compareTo(rectC));
		System.out.println(polyrect.compareTo(circS));
		System.out.println(polycirc.compareTo(circC));
		
		System.out.println("area and perimeter methods");

		System.out.println("Area " + circC.area() + " perimeter" + circC.perimeter());
		System.out.println("Area " + rectS.area() + " perimeter" + rectS.perimeter());
		System.out.println("Area " + triC.area() + " perimeter" + triC.perimeter());
		System.out.println("Area " + polyrect.area() + " perimeter" + polyrect.perimeter());
		System.out.println("Area " + polycirc.area() + " perimeter" + polycirc.perimeter());
		
		System.out.println("Increment and decrements");
		System.out.println("Coordinates before increment");

		System.out.println("Circle x: " + circC.getCx() + " y " + circC.getCy());
		System.out.println("Rectangle x " + rectS.getX() + " y " + rectS.getY());
		System.out.println("Triangle x " + triC.getX1() + " y " + triC.getY1());
	
		circC.increment();
		rectS.increment();
		triC.increment();

		System.out.println("Coordinates after increment");

		System.out.println("Circle x: " + circC.getCx() + " y " + circC.getCy());
		System.out.println("Rectangle x " + rectS.getX() + " y " + rectS.getY());
		System.out.println("Triangle x " + triC.getX1() + " y " + triC.getY1());

		circC.decrement();
		rectS.decrement();
		triC.decrement();

		System.out.println("Coordinates after decrement");

		System.out.println("Circle x: " + circC.getCx() + " y " + circC.getCy());
		System.out.println("Rectangle x " + rectS.getX() + " y " + rectS.getY());
		System.out.println("Triangle x " + triC.getX1() + " y " + triC.getY1());
		
		System.out.println("ComposedShape and StaticMethods graphics and optimal fits");
		
	    Rectangle rect = new Rectangle(100,100);
	    Circle circ = new Circle(200);
	    Triangle tri = new Triangle(20);
	    
	    Shape[] testArr = {rect, circ, tri};
		System.out.println("Areas before sort");
		
		for(int i = 0 ; i < testArr.length ; ++i)
			System.out.println(testArr[i].area());
		
		StaticMethods.sortShapes(testArr);
		
		System.out.println("Areas after sort");
		
		for(int i = 0 ; i < testArr.length ; ++i)
			System.out.println(testArr[i].area());
		
		
		Shape[] convertarr = StaticMethods.convertAll(testArr);

		for(int i = 0 ; i < convertarr.length ; ++i)
			System.out.println(convertarr[i].area());
		
		try{
			Circle circle = new Circle(-20);
		} catch(Exception e){
			System.out.println(e);

		}
		try{
			Triangle triangle = new Triangle(-20);
		} catch(Exception e){
			System.out.println(e);

		}
		try{
			Rectangle rectangle = new Rectangle(-20, -40);
		} catch(Exception e){
			System.out.println(e);

		}
		
		TestGUI a = new TestGUI(0,0);

	}
}


