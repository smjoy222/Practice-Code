import java.util.Scanner;
public class Convert {
    public static void main(String[]args){
    Scanner input = new Scanner(System.in);
    System.out.println("Enter the distance in centimeters:");
    double cemtimeter = input.nextDouble();
    input.close();
    double inches = cemtimeter/2.54;
    System.out.println("Corresponding value in inches: "+inches);



    }
}
