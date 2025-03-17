package constructor;
public class Teacher {
    String name,gender ;
    int phone;
     public Teacher (String n,String g,int ph){
      
       name =n;
       gender=g;
       phone=ph;
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
