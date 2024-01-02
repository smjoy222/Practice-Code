import java.util.Scanner;
public class Triangle {
 
public static void main(String[]args){
  Scanner input= new Scanner(System.in);
System.out.println("Enter 1st side length:");
double l1=input.nextDouble();
System.out.println("Enter 2nd side length:");
double l2=input.nextDouble();
System.out.println("Enter 3rd side length:");
double l3=input.nextDouble();

if ((l1+l2>l3)&&(l2+l3>l1)&&(l1+l3>l2)){
    System.out.println("this is a triangle");
}
    else 
    {
    System.out.println("this is not triangle");
    }
input.close();
}
  }  

