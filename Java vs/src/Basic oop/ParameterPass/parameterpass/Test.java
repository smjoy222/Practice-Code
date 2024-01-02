package parameterpass;
public class Test{
  public static void main(String[] args) {

    Teacher t1 = new Teacher();
    System.out.println("T--1");
    t1.setinfo("Joy","Male",1);
    t1.display();

    Teacher t2= new Teacher();
    System.out.println("T--2");
    t2.setinfo("Anika", "Female");
    t2.display();
  }

}