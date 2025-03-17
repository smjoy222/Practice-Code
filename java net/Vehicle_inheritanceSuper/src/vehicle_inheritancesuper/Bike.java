
package vehicle_inheritancesuper;


public class Bike extends Vehicle_inheritanceSuper {
   int speed = 100;
   void display(){
   System.out.println(super.speed);//if only speed written then print 100
   }
   public static void main(String[]args){
   Bike b = new Bike();
   b.display();
   }


}
