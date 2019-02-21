import java.awt.*; 
import javax.swing.*;

@SuppressWarnings("serial")
public class myGUI extends JPanel {
	
	private Shape shape;
	public myGUI(Shape object){
		shape = object;
	}
	
	@Override
	protected void paintComponent(Graphics obj){
		super.paintComponent(obj);
		shape.draw(obj);
	}
}