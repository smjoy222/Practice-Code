package Static;
public class Test{
    public static void main(String[] args) {
      System.out.println("T--1");
      Teacher t1 = new Teacher("Joy","Male",1);
       // here 1 but print 2 for static variable
      t1.display();

      System.out.println("T--2");
      Teacher t2= new Teacher("Anika", "Female",3); 
      // here 3 but print 2 for static
      t2.display();


      Teacher t3 = new Teacher();
      t3.display();  //default Constructor
      
      
      Teacher t4 = new Teacher("sazzad","Male"); 
      // overloading, same method different perameter
      t4.display();

      System.out.println( Teacher.w); 
      // rule 2 : to print static variable with class name

      
    }
  
  }