/**
 * This class extends from Shape and creates rectangles
 * @author İlkay CAN - 171044053
 */
import java.awt.Graphics;


public class Rectangle implements Shape{
    
	private double Side1, Side2;
    private double x, y;
    
    //Getters
    /**
     * Width getter
     * @return width
     */
    public double getSide1(){
    	return Side1;
    }
    
    /**
     * Height getter
     * @return height
     */
    public double getSide2(){
    	return Side2;
    }
    
    /**
     * X coordinate getter
     * @return x 
     */
    public double getX(){
    	return x;
    }
    
    /**
     * y coordinate getter
     * @return x 
     */
    public double getY(){
    	return y;
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
		return Side1*Side2;
	}
	
	//Calculates perimeter length
	
	public double perimeter(){
		return 2*(Side1+Side2);
	}
	
    //Constructors
	/**
	 * No parameter constructor
	 */
    public Rectangle(){
    	this(10,10);
    }
    
    /**
     * This constructor takes width and height
     * @param width
     * @param height
     */
    public Rectangle(double width, double height){
    	this(width, height, 0, 0);
    }
    
    /**
     * This constructor takes width, height and coordinates
     * @param width
     * @param height
     * @param coordx
     * @param coordy
     */
    public Rectangle(double width, double height, double coordx, double coordy){
        if(testValue(width) && testValue(height) && testValue(coordx) && testValue(coordy)){
	    	Side1 = width;
	    	Side2 = height;
	    	x = coordx;
	    	y = coordy;
        }
    }
    
  //setter methods 
    /**
     * Sets width to given value
     * @param width
     */
    public void setSide1(double width){
        if(testValue(width)){
	        Side1 = width;
        }

    }
    
    /**
     * Sets height to given value
     * @param height
     */
    public void setSide2(double height ){
        if(testValue(height)){
	        Side2 = height;
        }
    }
    
    /**
     * Sets x to given value
     * @param coordinatex
     */
    public void setX(double coordinatex ){
        if(testValue(coordinatex)){
        	x = coordinatex;
        }
    }
    
    /**
     * sets y to given value
     * @param coordinatey
     */
    public void setY(double coordinatey ){
        if(testValue(coordinatey)){
        	y = coordinatey;
        }
    }
    
    //Changes position +1
	public Shape increment(){
		this.setX(x+1);
		this.setY(y+1);
		return this;
	}
	
    //Changes position -1
	public Shape decrement(){
		this.setX(x-1);
		this.setY(y-1);
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
		object.drawRect((int)x, (int)y, (int)Side1, (int)Side2);
	}

    
}
