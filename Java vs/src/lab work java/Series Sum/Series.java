import java.util.Scanner;
public class Series {
     public static void main(String[] args) {
     Scanner input = new Scanner(System.in);
     System.out.println("Enter the value of N:");
     int n = input.nextInt();
     input.close();
     int term =1;
     int sum=0;
     System.out.println("Series: ");
     for(int i =1;i<=n;i++){
        System.out.print(term + " ");
     sum = sum + term;
     term = term*10+1;   
     }
     System.out.println("Sum of the Series:"+sum);
    }
}
