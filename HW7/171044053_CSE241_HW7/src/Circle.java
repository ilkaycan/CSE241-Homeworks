/**
 * This class extends from Shape and creates circles
 * @author İlkay CAN - 171044053
 */

import java.awt.Graphics;

public class Circle implements Shape {
    private static final double PI = 3.1415926535897; 
	private double radius;
    private double cx, cy;
    
    //Getters
    
    /**
     * Radius getter
     * @return radius of circle
     */
    public double getRadius(){
    	return radius;
    }
    
    /**
     * x coordinate getter
     * @return x of center
     */
    public double getCx(){
    	return cx;
    }
    
    /**
     * y coordinate getter
     * @return y of center
     */
    public double getCy(){
    	return cy;
    }
    
  //checks the input value    
    
    /**
     * Checks if given value is true for constructers or setters 
     * @param num is given value
     * @return true if given value is bigger than 0 or equals to 0
     * @throws IllegalArgumentException if given value is smaller than 0
     */
    private boolean testValue(double num) throws IllegalArgumentException{
        if(num>=0){
            return true;
        }else{
        	throw new IllegalArgumentException("Negative values are unacceptable!");
        }
    }
    
    //Calculates area
	public double area(){
		return PI*radius*radius;
	}
	
	//Calculates perimeter length
	
	public double perimeter(){
		return 2*PI*radius;
	}
	
    //Constructors
	
	/**
	 * No parameter constructor
	 */
    public Circle(){
    	this(10);
    }
    
    /**
     * This contructor takes radius as parameter 
     * @param r 
     */
    public Circle (double r){
    	this(r, r, r);
    }
    
    /**
     * Constructor that take coordinates of center and radius
     * @param r
     * @param x
     * @param y
     */
    public Circle (double r, double x, double y){
        if(testValue(r) && testValue(x) && testValue(y) ){
	    	radius = r;
	    	cx = x;
	    	cy = y;
        }
    }
    
  //setter methods 
    
    /**
     * Changes radius
     * @param r
     */
    public void setradius(double r){
        if(testValue(r)){
	        radius = r;
        }

    }
    
    /**
     * Changes x of center
     * @param x
     */
    public void setCx(double x ){
        if(testValue(x)){
	        cx = x;
        }
    }
    
    /**
     * Changes y of center
     * @param y
     */
    public void setCy(double y ){
        if(testValue(y)){
        	cy = y;
        }
    }
    
    //Changes position +1
	public Shape increment(){
		this.setCx(cx+1);
		this.setCy(cy+1);
		return this;
	}
	
    //Changes position -1
	public Shape decrement(){
		this.setCx(cx-1);
		this.setCy(cy-1);
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
		object.drawOval((int)(cx-radius), (int)(cy-radius), (int)(2*radius), (int)(2*radius));
	}
}
