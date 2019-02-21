/**
 * This class extends from Shape and creates trşangles
 * @author İlkay CAN - 171044053
 */

import java.awt.Graphics;


public class Triangle implements Shape{
    private static final double SQRT3 = 1.73205080757; 
	private double Side;
    private double x1, x2, x3, y1, y2, y3;
    
    
    //Getter methods 
    /**
     * Side getter
     * @return side
     */
    public double getSide(){
    	return Side;
    }
    
    /**
     * Getter for first x of triangle
     * @return x1
     */
    public double getX1(){
    	return x1;
    }
    
    /**
     * Getter for first y of triangle
     * @return y1
     */
    public double getY1( ){
        return y1;
    }
    
    /**
     * Getter for second x of triangle
     * @return x2
     */
    public double getX2( ){
    	return x2;
    }
    
    /**
     * Getter for second y of triangle
     * @return y2
     */
    public double getY2(){
        return y2;
        
    }
    
   /**
    * Getter for third x of triangle
    * @return x3
    */
    public double getX3(){
	    return  x3;
    }
    
    /**
     * Getter for third y of triangle
     * @return y3
     */
    public double getY3(){
    	return y3;
    }
    
  //checks the input value    
    private boolean testValue(double num) throws IllegalArgumentException{
        if(num>=0){
            return true;
        }else{
        	throw new IllegalArgumentException("Negative values are unacceptable!");
        }
    }
    
    //Calculates area
	public double area(){
		return Side*Side*SQRT3/4;
	}
	
	//Calculates perimeter length
	
	public double perimeter(){
		return 3*Side;
	}
	
    //Constructors
	
	/**
	 * No parameter constructor
	 */
    public Triangle(){
    	this(10);
    }
    
    /**
     * Constructor that takes side as a parameter
     * @param side
     */
    public Triangle (double side){
    	this(side, side/2, 0, 0, side*SQRT3/2, side, side*SQRT3/2);
    }
    
    /**
     * Constructor that takes side and coordinates
     * @param side
     * @param a1
     * @param b1
     * @param a2
     * @param b2
     * @param a3
     * @param b3
     */
    public Triangle (double side, double a1, double b1, double a2,
    		double b2, double a3, double b3){
        if(testValue(side) && testValue(a1) && testValue(a2) && testValue(a3)&&
        		testValue(b1) && testValue(b2) && testValue(b3)){
        	Side = side;
            x1 = a1;
            x2 = a2;
            x3 = a3;
            y1 = b1;
            y2 = b2;
            y3 = b3;
        }
    }
    
  //setter methods 
    
    /**
     * Sets side to given value
     * @param side
     */
    public void setSide(double side){
        if(testValue(side)){
	        Side = side;
        }
        this.setX1(Side / 2);
        this.setY1(0);
        this.setX2(0);
        this.setY2(Side * SQRT3 / 2);
        this.setX3(Side);
        this.setY3(Side * SQRT3 / 2);
    }
    
    /**
     * Sets x1 to given value
     * @param x
     */
    public void setX1(double x ){
        if(testValue(x)){
	        x1 = x;
        }
    }
    
    /**
     * sets y1 to given value
     * @param y
     */
    public void setY1(double y ){
        if(testValue(y)){
        	y1 = y;
        }
    }
    
    /**
     * sets x2 to given value
     * @param x
     */
    public void setX2(double x ){
        if(testValue(x)){
	        x2 = x;
        }
    }
    
    /**
     * sets y2 to given value
     * @param y
     */
    public void setY2(double y ){
        if(testValue(y)){
        	y2 = y;
        }
    }
    
    /**
     * sets x3 to given value
     * @param x
     */
    public void setX3(double x ){
        if(testValue(x)){
	        x3 = x;
        }
    }
    
    /**
     * sets y3 to given value
     * @param y
     */
    public void setY3(double y ){
        if(testValue(y)){
        	y3 = y;
        }
    }
    
    //Changes position +1
	public Shape increment(){
		this.setX1(x1+1);
		this.setY1(y1+1);
		this.setX2(x2+1);
		this.setY2(y2+1);
		this.setX3(x3+1);
		this.setY3(y3+1);
		return this;
	}
	
    //Changes position -1
	public Shape decrement(){
		this.setX1(x1-1);
		this.setY1(y1-1);
		this.setX2(x2-1);
		this.setY2(y2-1);
		this.setX3(x3-1);
		this.setY3(y3-1);
		return this;
	}
	
	//Compares shapes depending on areas
	public int compareTo(Shape compared){
		if(this.area() == compared.area()){
			return 0;
		} else if(this.area() < compared.area()){
			return -1;
		}
		
		return 1;
	}

	
	// gets called from the paintComponent
	public void draw(Graphics object){
		int[] xarr = {(int)x1, (int)x2, (int)x3};
		int[] yarr = {(int)y1,(int)y2, (int)y3 };

		object.drawPolygon(xarr, yarr, 3);
	}
}
