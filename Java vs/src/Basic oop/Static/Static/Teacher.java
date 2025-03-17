package Static;
public class Teacher {

    String name,gender ;
    static int phone =2;
    //Here Phone Static variable for all

    static String w = "Static calling with class not with object";

  
     public Teacher (String n,String g,int ph){
      
       name =n;
       gender=g;
       
       //but Here Phone instance variable for T1
       
    }

    public Teacher (){
     

      System.out.println("T--3");
      System.out.println("no value");
    }


    public Teacher (String n,String g){
      System.out.println("T--4");
      
      name = n;
      gender =g;
    }
    

     public void display(){
       System.out.println("Name: "+name);
       System.out.println("Gender: "+gender);
       System.out.println("Phone: "+phone); 
    }
 
 }