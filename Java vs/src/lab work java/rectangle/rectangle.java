import java.util.Scanner;

public class rectangle{
public static void main(String[]args){
double length,width,area,perimeter;

Scanner input = new Scanner(System.in);
System.out.println("Enter the lenght:");
length=input.nextDouble();
System.out.println("Enter the width:");
width=input.nextDouble();
perimeter=2*(length*width);
area=length*width;
System.out.println("perimeter:"+perimeter);
System.out.println("area:"+area);
input.close();

}
}