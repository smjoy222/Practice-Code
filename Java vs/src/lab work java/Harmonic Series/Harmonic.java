import java.util.Scanner;
public class Harmonic{
   public static void main(String[]args){
   Scanner input = new Scanner(System.in);
   System.out.println("Enter any value of N:");
   int n = input.nextInt();
   input.close();
   System.out.println("Harmonic Series of "+n+ " is: ");
   double sum = 0.0;
   for(int i =1;i<n;i++){
   double term = 1.0/i;
   System.out.print(term +" ");
    sum = sum + term;
   }


  System.out.println("Sum of the series : "+sum);
   }


}