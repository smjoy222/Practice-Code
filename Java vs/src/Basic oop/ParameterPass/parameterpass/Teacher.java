package parameterpass;

public class Teacher {
   String name,gender ;
   int phone;


    public void setinfo (String n,String g,int ph){
      this.name =n;
      this.gender=g; 
      this.phone=ph;
      //here,(this. ) is using to make instance variable to local 
   }


   public void setinfo(String n,String g){  // method overriding
      name =n;
      gender=g;
   }


    public void display(){
      System.out.println("Name: "+name);
      System.out.println("Gender: "+gender);
      System.out.println("Phone: "+phone);
   }

}
