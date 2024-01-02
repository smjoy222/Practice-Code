package Abstruction.abstraction;
public class Idog extends Dog {

    public static void main(String[] args){
    Idog d = new Idog();
    d.eat();
    
    }
    
    public void eat(){
        System.out.println("dog can eat");
    }
    }