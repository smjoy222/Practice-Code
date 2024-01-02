public class Me {
    static int p;
    static String q;
    static {     // this is for static block          
      p = 5;     // this is not using in code 
      q = "due";

    }
    public void display(){
        System.out.println("I am not Static Method");
    }
    public static void display2(){
        System.out.println("I am Static Method");
    }
    
}
