/**
 * This class extends from Polygon and keep points by using ArrayList
 * @author İlkay CAN - 171044053
 */

import java.awt.Graphics;
import java.awt.geom.Point2D;
import java.util.ArrayList;


public class PolygonVect extends Polygon {
	private static final double PI = 3.1415926535897; 

	private ArrayList<Point2D.Double> Coordinate;
	private int size;
	private double area=0.0, perimeter=0.0;
	
	//Constructor
	/**
	 * Constructor takes shape as parameter
	 * @param shape
	 */
    public PolygonVect(Shape shape){
    	Point2D.Double temp;
		Coordinate = new ArrayList<Point2D.Double>();

    	if(shape.getClass().getSimpleName() == "Rectangle"){
    		size = 4;

    		temp = new Point2D.Double(((Rectangle)shape).getX(), ((Rectangle)shape).getY());
            Coordinate.add(temp);
            temp = new Point2D.Double(((Rectangle)shape).getX() + ((Rectangle)shape).getSide1() , ((Rectangle)shape).getY());
            Coordinate.add(temp); 
            temp = new Point2D.Double(((Rectangle)shape).getSide1() + ((Rectangle)shape).getX() , ((Rectangle)shape).getY() + ((Rectangle)shape).getSide2());
            Coordinate.add(temp); 
            temp = new Point2D.Double(((Rectangle)shape).getX(), ((Rectangle)shape).getY() + ((Rectangle)shape).getSide2());
            Coordinate.add(temp); 

    	} else if (shape.getClass().getSimpleName() == "Triangle"){
    		size = 3;

    		temp = new Point2D.Double(((Triangle)shape).getX1(), ((Triangle)shape).getY1());
            Coordinate.add(temp);
            temp = new Point2D.Double(((Triangle)shape).getX2(), ((Triangle)shape).getY2());
            Coordinate.add(temp);
            temp = new Point2D.Double(((Triangle)shape).getX3(), ((Triangle)shape).getY3());
            Coordinate.add(temp); 

    	} else {
    		size = 100;
    		
            double angle = 0;
            double change = 3.6;

            for (int i = 0; i < 100; i++) {
            	temp = new Point2D.Double(((Circle)shape).getCx() + (((Circle)shape).getRadius() * Math.cos((angle + (i * change)) * PI / 180.0)), (((Circle)shape).getCy() + ((Circle)shape).getRadius() * Math.sin((angle + (i * change)) * PI / 180.0)));
                Coordinate.add(temp);
            }
    	}
    }
    
	//Calculates area
	public double area(){
        for (int i = 0; i < size; i++) {
            if(i != size-1) {
                area += Coordinate.get(i).getX() * Coordinate.get(i+1).getY();
                area -= Coordinate.get(i+1).getX() * Coordinate.get(i).getY();
            }else {
                area += Coordinate.get(size-1).getX() * Coordinate.get(0).getY();
                area -= Coordinate.get(0).getX() * Coordinate.get(size-1).getY();
            }
        }

        return Math.abs(area*0.5);
	}
	
	//Calculates perimeter length
	public double perimeter(){
        for (int i = 0; i < size-1; i++){
            perimeter+= Math.sqrt(Math.pow(Coordinate.get(i).getX()- Coordinate.get(i+1).getX(), 2) + Math.pow(Coordinate.get(i).getY()- Coordinate.get(i+1).getY(), 2));
         }
         perimeter+= Math.sqrt(Math.pow(Coordinate.get(0).getX()- Coordinate.get(size-1).getX(), 2) + Math.pow(Coordinate.get(0).getY()- Coordinate.get(size-1).getY(), 2));

         return perimeter;
	}
	
	//Changes position by +1
	public Shape increment(){
		for(int i = 0; i < size; ++i){
			Coordinate.get(i).setLocation(Coordinate.get(i).getX()+1, Coordinate.get(i).getY()+1);
		}
		return this;
	}
	
	//Changes position by -1
	public Shape decrement() throws IllegalArgumentException{
		for(int i = 0; i < size; ++i){
			if(Coordinate.get(i).getX()-1 < 0 || Coordinate.get(i).getY()-1 < 0){
				throw new IllegalArgumentException("Invalid Corrdinate"); 
			}

			Coordinate.get(i).setLocation(Coordinate.get(i).getX()-1, Coordinate.get(i).getY()-1);
		}
		return this;
	}
	
	// gets called from the paintComponent
	public  void draw(Graphics object){
		int[] xarr = new int[size];
		int[] yarr = new int[size];
		
		for(int i = 0; i < size ; ++i){
			xarr[i] = (int) Coordinate.get(i).getX();
			yarr[i] = (int) Coordinate.get(i).getY();
		}
		object.drawPolygon(xarr, yarr, size);
	}

}
