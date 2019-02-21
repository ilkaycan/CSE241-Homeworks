/**
 * This abstract class implements Shape and keeps shapes as Polygons
 * @author İlkay CAN - 171044053
 */
import java.awt.Graphics;


public abstract class Polygon implements Shape{
	
	// Compares shapes depending on their areas
	public int compareTo(Shape compared){
		if(this.area() == compared.area()){
			return 0;
		} else if(this.area() < compared.area()){
			return -1;
		}
		
		return 1;
	}
	public abstract double area();
	public abstract double perimeter();
	public abstract Shape increment();
	public abstract Shape decrement();
	public abstract void draw(Graphics object);

}
