
package human_inheritance;


public class Boy extends Human_inheritance
 {
    @Override
    public void eat(){
     System.out.println("boy can eat");
    }
    public static void main (String[]args){
    Boy b = new Boy();
    b.eat();
    }
}
