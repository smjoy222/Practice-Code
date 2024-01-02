
package Drawing;


public class Line implements Drawing {

    @Override
    public void draw()
    {
    
    System.out.println("i am drawing a line");
    
    }
    
    public static void main (String[]args){
        Line l =new Line();
        l.draw();
    }
}
