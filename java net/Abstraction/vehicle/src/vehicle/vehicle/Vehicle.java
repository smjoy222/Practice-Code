
package vehicle;


public abstract class Vehicle {
   public Vehicle()
   {
       System.out.println("Vehicle is created (constructor)");
   }
   public abstract void move();
   public void carry(){
       System.out.println("can carry loads");
   }
    
}
