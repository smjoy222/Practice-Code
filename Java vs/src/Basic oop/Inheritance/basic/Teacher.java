package Inheritance.basic;

public class Teacher extends Person {
    // String name; // for inheritance
    // int age; // this variable not need to initialize
    // beacause of techer acuare everything of person

    String status = "Good";
    // new variable for this class

    void display2() {
        System.out.println("Name: " + name);
        System.out.println("Age: " + age);
        System.out.println("Status: " + status);
    }
}