/**
 * This class fits small shapes into a container shape
 * Extended from Shape
 * @author İlkay CAN - 171044053
 */
import java.awt.Graphics;


public class ComposedShape implements Shape{
    private Shape[] InnerShape;
    private Shape Contain, Small;
    private static final double SQRT3 = 1.73205080757; 

    //Constructor 
    
    /**
     * Constructor ; takes small shape and container shape
     * @param contain
     * @param small
     */
    public ComposedShape(Shape contain, Shape small){
    	Contain = contain;
    	Small = small;
    }
    
    //Calculates area
	public double area(){
		return Contain.area();
	}
	
	//Calculates perimeter length
	public double perimeter(){
		return Contain.perimeter();
	}
	
    //Changes small shapes' position +1
	public Shape increment(){
		for(int i = 0; i < InnerShape.length; ++i){
			InnerShape[i].increment();
		}
		return this;
	}
	
    //Changes small shapes' position -1
	public Shape decrement(){
		for(int i = 0; i < InnerShape.length; ++i){
			InnerShape[i].decrement();
		}
		return this;
	}
	
	public int compareTo(Shape compared){
		if(this.area() == compared.area()){
			return 0;
		} else if(this.area() < compared.area()){
			return -1;
		}
		
		return 1;
	}
	
	//checks if given rectangle fits in circle by
	//(x-a)^2 + (y-b)^2 = r^2
    private boolean checkRectInCircle (double x, double y, double SmallA,
            double SmallB, double ContainA){
    	double xdownleft = x, ydownleft = y + SmallB;
        double xupright = x + SmallA, yupright = y, xdownright = x + SmallA, ydownright = y + SmallB;
        boolean result = false;

        if (((((x - ContainA) * (x - ContainA)) + ((y - ContainA) * (y - ContainA))) <= (ContainA * ContainA)) &&
            ((((xdownleft - ContainA) * (xdownleft - ContainA)) + ((ydownleft - ContainA) * (ydownleft - ContainA))) <=
             (ContainA * ContainA)) &&
            ((((xupright - ContainA) * (xupright - ContainA)) + ((yupright - ContainA) * (yupright - ContainA))) <=
             (ContainA * ContainA)) &&
            ((((xdownright - ContainA) * (xdownright - ContainA)) +
              ((ydownright - ContainA) * (ydownright - ContainA))) <= (ContainA * ContainA))) {
            result = true;
        }
        return result;
    }

    //checks if given triangle fits in circle by
    //(x-a)^2 + (y-b)^2 = r^2
    private boolean checkTriInCircle(double x1, double y1, double x2, double y2,
           double x3, double y3, double ContainA){
        boolean result = false;

        if (((((x1 - ContainA) * (x1 - ContainA)) + ((y1 - ContainA) * (y1 - ContainA))) <= (ContainA * ContainA)) &&
            ((((x2 - ContainA) * (x2 - ContainA)) + ((y2 - ContainA) * (y2 - ContainA))) <= (ContainA * ContainA)) &&
            ((((x3 - ContainA) * (x3 - ContainA)) + ((y3 - ContainA) * (y3 - ContainA))) <= (ContainA * ContainA))) {
            result = true;
        }

        return result;
    }

    //checks if given circle fits in circle by
    //(x-a)^2 + (y-b)^2 = r^2
    private boolean checkCircleInCircle(double cx, double cy, double SmallA,
              double ContainA){
        boolean result = false;
        double x, y;

        x = (ContainA - cx) * (ContainA - cx);
        y = (ContainA - cy) * (ContainA - cy);

        if ((ContainA - SmallA) >= Math.sqrt(x + y)) {
            result = true;
        }

        return result;
    }
    
 // Optimal fit calls suitable function to calculate how many small shapes
 // fits in the Container and how to position them
    
    /**
     * This method fits small shapes into container
     */
     public void optimalFit() {
         double areaContain, areaSmall, shapeNum;
         areaContain = Contain.area();
         areaSmall = Small.area();
         
         if (Contain.getClass().getSimpleName().equals("Rectangle")) {
             if (Small.getClass().getSimpleName().equals("Rectangle")) {
                 RRoptimal();
             } else if (Small.getClass().getSimpleName().equals("Triangle")) {
                 RToptimal();
             } else if (Small.getClass().getSimpleName().equals("Circle")) {
                 RCoptimal();
             }
         } else if (Contain.getClass().getSimpleName( ).equals("Triangle")) {
             if (Small.getClass().getSimpleName().equals("Rectangle")) {
                 TRoptimal();
             } else if (Small.getClass().getSimpleName().equals("Triangle")) {
                 TToptimal();
             } else if (Small.getClass().getSimpleName().equals("Circle")) {
                 TCoptimal();
             }
         } else if (Contain.getClass().getSimpleName().equals("Circle")) {
             if (Small.getClass().getSimpleName().equals("Rectangle")) {
                 CRoptimal();
             } else if (Small.getClass().getSimpleName().equals("Triangle")) {
                 CToptimal();
             } else if (Small.getClass().getSimpleName().equals("Circle")) {
                 CCoptimal();
             }
         }
         if(InnerShape != null){
        	 shapeNum = InnerShape.length;
         } else {
        	 shapeNum = 0;
         }
         areaSmall = shapeNum * Small.area();
         
         System.out.println("I can fit at most" + shapeNum + " small shapes into the main container.");
         System.out.println( " The empty area (blue) in container is " + (areaContain - areaSmall) );
     }
     //This function modifies InnerShape array
     private void addShape(Shape add){
    	 Shape temp[];
    	 if (null == InnerShape){
    		 temp = new Shape[1];
    		 temp[0] = add;
    	 }else {
    		 temp = new Shape[InnerShape.length + 1];
    	     System.arraycopy(InnerShape, 0, temp, 0, temp.length-1);
    	     temp[InnerShape.length] = add;

    	 }
        InnerShape = temp;   
       
	
     }
     
     	// Following functions  calculate how many small shapes
     	// fits in the Container and how to position them
     private void RRoptimal() {
      		double SmallA = ((Rectangle)Small).getSide1();
      		double SmallB = ((Rectangle)Small).getSide2();
      		double x = ((Rectangle)Small).getX();
      		double y = ((Rectangle)Small).getY();
      		double ContainA = ((Rectangle)Contain).getSide1();
      		double ContainB = ((Rectangle)Contain).getSide2();
      // decide if small shape is horizontal or vertical
      		if ((SmallA >= ContainA && SmallA <= ContainB && SmallB <= ContainA) ||
      				(SmallB >= ContainB && SmallB <= ContainA && SmallA <= ContainB)) {

      			double temp = SmallA;
      			SmallA = SmallB;
      			SmallB = temp;
      		}
      		// outer loop is rows and inner loop is columns
      		// and ranges are determined due to containers width and height
          for (int i = (int) (ContainB / SmallB); i > 0; i--) {
              for (int j = (int) (ContainA / SmallA); j > 0; j--) {
                  Rectangle rect = new Rectangle(SmallA, SmallB, x, y);
                  this.addShape(rect);
                  x += SmallA;
              }
              x = 0;
              y += SmallB;
          }
      }
     
     private void RToptimal() {
         double SmallA = ((Triangle)Small).getSide();
         double ContainA = ((Rectangle)Contain).getSide1();
         double ContainB = ((Rectangle)Contain).getSide2();
         double xup = SmallA / 2, yup = 0, xleft = 0, ydown = (SmallA / 2) * SQRT3, xright = SmallA;
         double adown = SmallA, aleft = SmallA / 2, aright = (SmallA * 3) / 2, bup = 0, bdown = (SmallA / 2) * SQRT3;

         // outer loop is rows and inner loop is columns
         // and ranges are determined due to containers width and height
         for (int i = (int) (ContainB / (SQRT3 * (SmallA / 2))); i > 0; i--) {
             for (int j = (int) (ContainA / (SmallA)); j > 0; j--) {
                 Triangle tri = new Triangle(SmallA, xup, yup, xleft, ydown, xright, ydown);
                 this.addShape(tri);
                 xup += SmallA;
                 xright += SmallA;
                 xleft += SmallA;
             }
             yup += (SmallA / 2) * SQRT3;
             ydown += (SmallA / 2) * SQRT3;
             xup = SmallA / 2;
             xleft = 0;
             xright = SmallA;
         }
         // this loop draws reverse triangles
         for (int i = (int) (ContainB / (SQRT3 * (SmallA / 2))); i > 0; i--) {
             for (int j = (int) ((ContainA - (SmallA / 2)) / (SmallA)); j > 0; j--) {
                 Triangle tri2 = new Triangle(SmallA, adown, bdown, aleft, bup, aright, bup);
                 this.addShape(tri2);
                 adown += SmallA;
                 aright += SmallA;
                 aleft += SmallA;
             }
             bup += (SmallA / 2) * SQRT3;
             bdown += (SmallA / 2) * SQRT3;
             adown = SmallA;
             aleft = SmallA / 2;
             aright = (SmallA * 3) / 2;
         }
     }
     
     private void RCoptimal() {
         double ContainA = ((Rectangle)Contain).getSide1();
         double ContainB = ((Rectangle)Contain).getSide2();
         double SmallA = ((Circle)Small).getRadius();
         double cx = SmallA, cy = SmallA;
         for (int i = (int) (ContainB / (SmallA * 2)); i > 0; i--) {
             for (int j = (int) (ContainA / (2 * SmallA)); j > 0; j--) {
                 Circle circ = new Circle(SmallA, cx, cy);
                 this.addShape(circ);
                 cx += 2 * SmallA;
             }

             cx = SmallA;
             cy += 2 * SmallA;
         }
     }
     
     private void CRoptimal() {
         double ContainA = ((Circle)Contain).getRadius();
         double SmallA = ((Rectangle)Small).getSide1();
         double SmallB = ((Rectangle)Small).getSide2();
         double x = 0, y = 0;

         for (int i = (int) ((ContainA * 2) / SmallB); i > 0; i--) {
             for (int j = (int) ((ContainA * 2) / SmallA); j > 0; j--) {
                 if (checkRectInCircle(x, y, SmallA, SmallB, ContainA)) {
                     Rectangle rect = new Rectangle(SmallA, SmallB, x, y);
                     this.addShape(rect);
                 }
                 x += SmallA;
             }
             x = 0;
             y += SmallB;
         }
     }
    
     private void CCoptimal() {
         double ContainA = ((Circle)Contain).getRadius();
         double SmallA = ((Circle)Small).getRadius();
         double cx = 0, cy = 0;

         for (int i = (int) (ContainA / SmallA); i > 0; i--) {
             for (int j = (int) (ContainA / SmallA); j > 0; j--) {
                 while ((cx <= ContainA) && (!checkCircleInCircle(cx, cy, SmallA, ContainA))) {
                     cx++;
                 }
                 if (checkCircleInCircle(cx, cy, SmallA, ContainA)) {
                     Circle circ = new Circle(SmallA, cx, cy);
                     this.addShape(circ);
                 }
                 cx += 2 * SmallA;
             }
             cx = 0;
             cy += 2 * SmallA;
         }
         if (InnerShape.length == 0 && SmallA <= ContainA) {
             Circle circ = new Circle(SmallA, ContainA, ContainA);
             this.addShape(circ);
         }
     }
     
     private void CToptimal() {
         double ContainA = ((Circle)Contain).getRadius();
         double SmallA = ((Triangle)Small).getSide();
         double xup = SmallA / 2, yup = 0, xleft = 0, ydown = (SmallA / 2) * SQRT3, xright = SmallA;
         double adown = SmallA, aleft = SmallA / 2, aright = (SmallA * 3) / 2, bup = 0, bdown = (SmallA / 2) * SQRT3;
         for (int i = (int) ((ContainA * 2) / (SQRT3 * (SmallA / 2))); i > 0; i--) {
             for (int j = (int) ((ContainA * 2) / (SmallA)); j > 0; j--) {
                 if (checkTriInCircle(xup, yup, xleft, ydown, xright, ydown, ContainA)) {
                     Triangle tri = new Triangle(SmallA, xup, yup, xleft, ydown, xright, ydown);
                     this.addShape(tri);
                 }
                 xup += SmallA;
                 xright += SmallA;
                 xleft += SmallA;
             }
             yup += (SmallA / 2) * SQRT3;
             ydown += (SmallA / 2) * SQRT3;
             xup = SmallA / 2;
             xleft = 0;
             xright = SmallA;
         }
         // checks if triangles are in circle and draws reverse triangles
         for (int i = (int) ((ContainA * 2) / (SQRT3 * (SmallA / 2))); i > 0; i--) {
             for (int j = (int) (((ContainA * 2) - (SmallA / 2)) / (SmallA)); j > 0; j--) {
                 if (checkTriInCircle(adown, bdown, aleft, bup, aright, bup, ContainA)) {
                     Triangle tri2 = new Triangle(SmallA, adown, bdown, aleft, bup, aright, bup);
                     this.addShape(tri2);
                 }
                 adown += SmallA;
                 aright += SmallA;
                 aleft += SmallA;
             }
             bup += (SmallA / 2) * SQRT3;
             bdown += (SmallA / 2) * SQRT3;
             adown = SmallA;
             aleft = SmallA / 2;
             aright = (SmallA * 3) / 2;
         }
     }
     private void TCoptimal() {
         double ContainA = ((Triangle)Contain).getSide();
         double SmallA = ((Circle)Small).getRadius();
         double cx = ContainA / 2;
         double cy = 2 * SmallA;
         int rownum = 1;
         // by geometrical calculations i found that with every row i can
         // add another circle so i decided inner loop's range by that
         for (int i = (int) ((ContainA / (2 * SmallA)) - SQRT3 + 1); i > 0; i--) {
             for (int j = rownum; j > 0; j--) {
                 Circle circle = new Circle(SmallA, cx, cy);
                 this.addShape(circle);
                 cx += 2 * SmallA;
             }

             cx = (ContainA / 2) - (rownum * SmallA);
             cy += SmallA * SQRT3;
             rownum++;
         }
     }
     
     private void TRoptimal() {
         double SmallA = ((Rectangle)Small).getSide1();
         double SmallB = ((Rectangle)Small).getSide2();
         double ContainA = ((Triangle)Contain).getSide();
         //makes rectangles horizontal
         if (SmallA < SmallB) {
             double swap = SmallA;
             SmallA = SmallB;
             SmallB = swap;
         }
         double x = SmallB / SQRT3;
         double y = (((ContainA / 2) * SQRT3) - SmallB);
         double changeContain = 0, temp = ContainA;
         // outer loop is rows and inner loop is columns
         // and ranges are determined due to containers width and height
         for (int i = (int) (((ContainA / 2) * SQRT3) / SmallB); i > 0; i--) {
             for (int j = (int) ((temp - (2 * SmallB / SQRT3)) / SmallA); j > 0; j--) {
                 Rectangle rect = new Rectangle(SmallA, SmallB, x, y);
                 this.addShape(rect);
                 x += SmallA;
             }
             changeContain += SmallB / SQRT3;
             y -= SmallB;
             x = (SmallB / SQRT3) + changeContain;
             temp -= 2 * (SmallB / SQRT3);
         }
     }
     
     private void TToptimal() {
         double ContainA = ((Triangle)Contain).getSide();
         double SmallA = ((Triangle)Small).getSide();
         double xup = ContainA / 2, yup = 0, xleft = (ContainA - SmallA) / 2, ydown = SmallA * SQRT3 / 2, xright =
                 (ContainA + SmallA) / 2;
         double adown = ContainA / 2, bdown = SmallA * SQRT3, aleft = (ContainA - SmallA) / 2, aright =
                 (ContainA + SmallA) / 2, bup = SmallA * SQRT3 / 2;

         // outer loop is rows and inner loop is columns
         // and ranges are determined due to containers width and height

         int k = 1;
         while (ydown <= (ContainA * SQRT3 / 2)) {
             while (xright <= ((ContainA / 2) + (SmallA / 2 * k))) {
                 Triangle tri = new Triangle(SmallA, xup, yup, xleft, ydown, xright, ydown);
                 this.addShape(tri);
                 xup += SmallA;
                 xright += SmallA;
                 xleft += SmallA;
             }
             yup += (SmallA / 2) * SQRT3;
             ydown += (SmallA / 2) * SQRT3;
             xup = (ContainA / 2) - (k * SmallA / 2);
             xleft = ((ContainA - SmallA) / 2) - (k * SmallA / 2);
             xright = ((ContainA + SmallA) / 2) - (k * SmallA / 2);
             k++;
         }
         k = 1;
         //draws reverse triangles
         while (bdown <= (ContainA * SQRT3 / 2)) {
             while (aright <= ((ContainA / 2) + (SmallA / 2 * k))) {
                 Triangle tri2 = new Triangle(SmallA, adown, bdown, aleft, bup, aright, bup);
                 this.addShape(tri2);
                 adown += SmallA;
                 aright += SmallA;
                 aleft += SmallA;
             }

             bdown += (SmallA / 2) * SQRT3;
             bup += (SmallA / 2) * SQRT3;
             adown = (ContainA / 2) - (k * SmallA / 2);
             aleft = ((ContainA - SmallA) / 2) - (k * SmallA / 2);
             aright = ((ContainA + SmallA) / 2) - (k * SmallA / 2);
             k++;
         }
     }
     
	public void draw(Graphics object){
		Contain.draw(object);
		for(int i = 0 ; i < InnerShape.length ; ++i ){
			InnerShape[i].draw(object);
		}
	}

}
