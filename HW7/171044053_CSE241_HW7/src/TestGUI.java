/**
 * This class helps creating graphics of my shapes
 * @author İlkay CAN - 171044053
 */

import java.awt.*;
import java.awt.event.*;
import java.util.ArrayList;
import javax.swing.*;

@SuppressWarnings("unused")
public class TestGUI {
	JFrame window ;
	static private int myA, myB;
	
	/**
	 * This is constructor for this class takes two parameter(0,0) and then recursively calls
	 * itself and creates new frames 
	 * @param a
	 * @param b
	 */
	TestGUI(int a, int b){
		myA = a;
		myB = b;
		window = new JFrame("171044053");
		window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); 
		window.setSize(600,600);  
		window.setLayout(new BorderLayout());    
		
		Rectangle rectC = new Rectangle(500, 500);
		Rectangle rectS = new Rectangle(10, 50);
		  
		Circle circC = new Circle(250);
		Circle circS = new Circle(10);
	  
		Triangle triC = new Triangle(500);
		Triangle triS = new Triangle(10);
		  
		Shape sample;
		
		if(a == 0 && b == 0){
			sample = new ComposedShape(rectC, rectS );
		}	else if(a == 0 && b == 1 ){
			sample = new ComposedShape(rectC, triS );
		} else if(a == 0 && b == 2 ){
			sample = new ComposedShape(rectC, circS );
		} else if(a == 0 && b == 3){
			sample = new ComposedShape(triC, rectS );
		} else if(a == 1 && b == 0){	
			sample = new ComposedShape(triC, triS );
		} else if(a == 1 && b == 1){
			sample = new ComposedShape(triC, circS );
		} else if(a == 1 && b == 2){
			sample = new ComposedShape(circC, rectS );
		} else if( a == 1 && b == 3 ){
			sample = new ComposedShape(circC, triS );
		} else if( a == 2 && b == 0 ) {
			sample = new ComposedShape(circC, circS );
		} else if( a == 2 && b == 1 ) {
			System.out.println("Increment and decrement will be tested starting from here");
			sample = new PolygonDyn(circC);
			sample.increment();
		} else if( a == 2 && b == 2 ) {
			sample = new PolygonDyn(circC);
			sample.increment();
			sample.decrement();
		} else if( a == 2 && b == 3 ) {
			sample = new PolygonDyn(circC);
		} else if( a == 3 && b == 0 ) {
			sample = new PolygonVect(circC);
		} else if( a == 3 && b == 1 ) {
			sample = new PolygonVect(circC);
			sample.increment();
		} else if( a == 3 && b == 2 ) {
			//Those functions causes error so they are in comment
			sample = new ComposedShape(circC, circS );
			//sample.increment();
		} else  {
			//Those functions causes error so they are in comment
			sample = new ComposedShape(circC, circS );
			//sample.increment();
			//sample.decrement();

		}
		
		if(sample.getClass().getSimpleName() == "ComposedShape"){
			((ComposedShape)sample).optimalFit();
		}
		
		Button nextbutton = new Button("Next");
		myGUI o = new myGUI(sample);
		o.setSize(500, 500);
		window.add(o, BorderLayout.CENTER);
		window.add(nextbutton, BorderLayout.SOUTH);
		//nextbutton.setBounds(50,100,60,30);  
		nextbutton.addActionListener(new ActionListener(){  
			  public void actionPerformed(ActionEvent e){
					window.setVisible(false);
				  if(myA == 3 && myB == 3){
					  	System.exit(0);
				  }else {
					  if(myB == 3){
						  TestGUI x = new TestGUI(myA+1 , 0);
					  } else {
						  TestGUI x = new TestGUI(myA , myB+1);

					  }
				  }
		    	
			  }  
		    });
		window.setVisible(true);
	  }
		
	
}