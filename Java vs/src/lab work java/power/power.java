import java.util.Scanner;

public class power {
    public static void main(String[]Args){
    Scanner input = new Scanner(System.in);
    System.out.println("enter the base:");
    double x =input.nextDouble();
    System.out.println("enter the exponant:");
    int y = input.nextInt();
    input.close();
    double results = Math.pow(x,y);
    System.out.println(x+" raised to the power "+y+" is: " +results);

    }
    
}
