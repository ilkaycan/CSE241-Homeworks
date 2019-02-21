/**
 * This is a interface that implemented by Rectangle, Circle, Triangle 
 * and Polygon(PolygonDyn, PolygonVect) classes 
 * It extends from Comparable 
 * @author Ilkay CAN - 171044053
 */

import java.awt.*;

public interface Shape extends Comparable<Shape> {
	
	
	/**
	 * Compares to Shapes depending on areas
	 * @return -1 if this Shape is smalller, 0 if two shapes are equal, 1 if this shape is bigger
	 * @param compared
	 */
	public abstract int compareTo(Shape compared);
	
	/**
	 * Calculates area
	 * @return area
	 */
	public abstract double area();
	
	/**
	 * Calculate perimeter
	 * @return perimeterlength
	 */
	public abstract double perimeter();
	
	/**
	 * Change position +1
	 * @return new Shape
	 */
	public abstract Shape increment();
	
	/**
	 * Change position -1
	 * @return new Shape
	 */
	public abstract Shape decrement();
	
	/**
	 * This method will be called from the paintComponent method of a JPanel object.
	 * @param object
	 */
	public abstract void draw(Graphics object);
	
}
