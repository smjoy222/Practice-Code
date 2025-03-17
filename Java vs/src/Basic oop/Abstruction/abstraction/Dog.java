package Abstruction.abstraction;

public class Dog extends Animal {

    public void run(){
        System.out.println("dog can run");
    }
    public static void main (String []args){
     Dog d = new Dog();
     d.run();
     d.jump();   
    }
    } 
