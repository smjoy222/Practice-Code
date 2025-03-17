import java.util.Scanner;
public class Cube {
    public static void main (String[]args){
    Scanner input = new Scanner (System.in);
    System.out.println("Enter the side lenght:");
    double lenght= input.nextDouble();
    input.close();
    double surfaceArea= 6*lenght*lenght;
    double volume = lenght*lenght*lenght;
    System.out.println("The cube surface area is: " + surfaceArea + " And Volume is: " +volume);



    }
}
