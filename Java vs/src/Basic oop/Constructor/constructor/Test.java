package constructor;
public class Test{
    public static void main(String[] args) {
      Teacher t1 = new Teacher("Joy","Male",1);
      System.out.println("T--1 and T--2");
      t1.display();

      Teacher t2= new Teacher("Anika", "Female", 2);
      t2.display();

      Teacher t3 = new Teacher();
      
      //default Constructor
      t3.display();  
      

      
      Teacher t4 = new Teacher("sazzad","Male"); 
      // overloading, same method different perameter
      t4.display();
    }
  
  }
