
package human_inheritance;


public class Girl extends Human_inheritance{
    @Override
    public void eat(){
    System.out.println("girl can eat");
    }
    public static void main(String[]args){
        Girl g = new Girl();
        g.eat();
    }
}
