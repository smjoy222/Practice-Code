import java.util.Scanner;
public class Fibonacci {
    public static void main(String[]args){
    Scanner input = new Scanner(System.in);
    System.out.println("Enter the value of N:");
    int n = input.nextInt();
    input.close();
    int first =0;
    int second =1;
    System.out.println("Fibonacci series:");
    for(int i = 0;i<n;i++){
        System.out.print(first+"");
        int next = first + second;
        first = second;
        second = next;
        
    }


    }
}
