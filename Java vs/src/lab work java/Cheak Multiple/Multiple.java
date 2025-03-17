import java.util.Scanner;
public class Multiple {
    public static void main(String[]args){
    Scanner input = new Scanner(System.in);
    System.out.println("Enter the first intiger:");
    int first = input.nextInt();
    System.out.println("Enter the second number:");
    int second = input.nextInt();
    input.close();
    if(first%second==0){
    System.out.println(first+" is the multiple of the " +second);

    }
    else{
        System.out.println(first+" is not multiple of the "+second);
    }


    }
}
