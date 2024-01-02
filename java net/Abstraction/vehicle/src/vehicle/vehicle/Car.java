
package vehicle;


public class Car extends Vehicle {

    
    @Override
    public void move()
    { 
     System.out.println("Car can Move");
    
    }
    public static void main (String[]args){
        Car c = new Car();
        c.move();
        c.carry();
        
    }
    
    
}
