/**
 * This class has some methods that working on collections
 * @author İlkay CAN - 171044053
 */
import java.awt.*;

public class StaticMethods {

	
	
	/**
	 * This function gets called from paintComponent() method
	 * @param Printed
	 * @param o
	 */
	public static void drawAll(Shape[] Printed, Graphics o){
		for ( int i = 0 ; i < Printed.length ; ++i ){
			Printed[i].draw(o);
		}
	}
	
	// This method converts Shape reference array to PolygonDyn reference array
	
	/**
	 * This method converts Shape reference array to PolygonDyn reference array
	 * @param Printed
	 * @return new array
	 * @throws IllegalArgumentException if given parameter is not true
	 */
	public static Polygon[] convertAll(Shape[] Printed) throws IllegalArgumentException
	{
	    Polygon[]  x = new Polygon[Printed.length];
	    PolygonDyn temp;

	    for(int i = 0; i < Printed.length; i++)
	    {

	        if(Printed[i].getClass().getSimpleName() ==  "Rectangle")
	        {
	            temp = new PolygonDyn((Rectangle)Printed[i]);
	        } else if(Printed[i].getClass().getSimpleName() ==  "Triangle")
	        {
	            temp = new PolygonDyn((Triangle)Printed[i]);
	        } else if(Printed[i].getClass().getSimpleName() ==  "Circle")
	        {
	            temp = new PolygonDyn((Circle)Printed[i]);
	        } else {
	        	throw new IllegalArgumentException("Invalid Parameter");
	        }
	       
	        x[i] = temp;
	    }

	    return x;

	}
	
	//This method sorts shapes in the areas depending on their areas
	
	/**
	 * This method sorts shapes in the areas depending on their areas
	 * @param Printed
	 */
	public static void sortShapes(Shape[] Printed){
	    Shape temp;

	    for(int i=0;i<Printed.length-1;i++ )
	    {

	        for(int j = i+1; j<Printed.length; j++ ){

	            if(Printed[i].area()>(Printed[j].area())){
	                temp = Printed[i];
	                Printed[i] = Printed[j];
	                Printed[j] = temp;
	            }
	        }
	    }
	}


}
