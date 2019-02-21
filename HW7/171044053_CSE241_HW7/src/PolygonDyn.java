/**
 * This class extends from Polygon and keep points dynamically
 * @author İlkay CAN - 171044053
 */
import java.awt.Graphics;
import java.awt.geom.Point2D;


public class PolygonDyn extends Polygon{

	private static final double PI = 3.1415926535897; 

	private Point2D.Double[] Coordinate;
	private int size;
	private double area=0.0, perimeter=0.0;
	
	//Constructor
	/**
	 * Constructor takes shape as parameter
	 * @param shape
	 */
    public PolygonDyn(Shape shape){
    	
    	if(shape.getClass().getSimpleName() == "Rectangle"){
    		size = 4;
    		Coordinate = new Point2D.Double[size];

            Coordinate[0] = new Point2D.Double(((Rectangle)shape).getX(), ((Rectangle)shape).getY());
            Coordinate[1] = new Point2D.Double(((Rectangle)shape).getX() + ((Rectangle)shape).getSide1() , ((Rectangle)shape).getY());
            Coordinate[2] = new Point2D.Double(((Rectangle)shape).getSide1() + ((Rectangle)shape).getX() , ((Rectangle)shape).getY() + ((Rectangle)shape).getSide2());
            Coordinate[3] = new Point2D.Double(((Rectangle)shape).getX(), ((Rectangle)shape).getY() + ((Rectangle)shape).getSide2());

    	} else if (shape.getClass().getSimpleName() == "Triangle"){
    		size = 3;
    		Coordinate = new Point2D.Double[size];

            Coordinate[0] = new Point2D.Double(((Triangle)shape).getX1(), ((Triangle)shape).getY1());
            Coordinate[1] = new Point2D.Double(((Triangle)shape).getX2(), ((Triangle)shape).getY2());
            Coordinate[2] = new Point2D.Double(((Triangle)shape).getX3(), ((Triangle)shape).getY3());

    	} else {
    		size = 100;
    		Coordinate = new Point2D.Double[size];

            double angle = 0;
            double change = 3.6;

            for (int i = 0; i < 100; i++) {
                Coordinate[i] = new Point2D.Double(((Circle)shape).getCx() + (((Circle)shape).getRadius() * Math.cos((angle + (i * change)) * PI / 180.0)), (((Circle)shape).getCy() + ((Circle)shape).getRadius() * Math.sin((angle + (i * change)) * PI / 180.0)));
            }
    	}
    }
    
    // Calculates area
	public double area(){
        for (int i = 0; i < size; i++) {
            if(i != size-1) {
                area += Coordinate[i].getX() * Coordinate[i + 1].getY();
                area -= Coordinate[i + 1].getX() * Coordinate[i].getY();
            }else {
                area += Coordinate[size-1].getX() * Coordinate[0].getY();
                area -= Coordinate[0].getX() * Coordinate[size-1].getY();
            }
        }

        return Math.abs(area*0.5);
	}
	
	//Calculates perimeter length
	public double perimeter(){
        for (int i = 0; i < size-1; i++){
            perimeter+= Math.sqrt(Math.pow(Coordinate[i].getX()- Coordinate[i+1].getX(), 2) + Math.pow(Coordinate[i].getY()- Coordinate[i+1].getY(), 2));
         }
         perimeter+= Math.sqrt(Math.pow(Coordinate[0].getX()- Coordinate[size-1].getX(), 2) + Math.pow(Coordinate[0].getY()- Coordinate[size-1].getY(), 2));

         return perimeter;
	}
	
	//Change position by +1
	public Shape increment(){
		for(int i = 0; i < size; ++i){
			Coordinate[i].setLocation(Coordinate[i].getX()+1, Coordinate[i].getY()+1);
		}
		return this;
	}
	
	//Change position by -1
	public Shape decrement() throws IllegalArgumentException{
		for(int i = 0; i < size; ++i){
			if(Coordinate[i].getX()-1 < 0 || Coordinate[i].getY()-1 < 0){
				throw new IllegalArgumentException("Invalid Corrdinate"); 
			}

			Coordinate[i].setLocation(Coordinate[i].getX()-1, Coordinate[i].getY()-1);
		}
		return this;
	}
	
	// gets called from the paintComponent
	public  void draw(Graphics object){
		int[] xarr = new int[size];
		int[] yarr = new int[size];
		
		for(int i = 0; i < size ; ++i){
			xarr[i] = (int) Coordinate[i].getX();
			yarr[i] = (int) Coordinate[i].getY();
		}
		object.drawPolygon(xarr, yarr, size);

	}


}
