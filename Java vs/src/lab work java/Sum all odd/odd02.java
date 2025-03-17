import java.util.Scanner;
public class odd02 {
    public static void main(String[]args){
        
    Scanner input = new Scanner(System.in);
    System.out.println("Enter the number of N:");
    int n= input.nextInt();
    int sum=0;
    int count=0;
    for(int i=0;i<n;i++){
        if(i%2!=0){
         sum=sum+i;
         count ++;
        }
    }



input.close();
System.out.println("the odd are:"  +  count + "the sum is: " + sum);
    }

}
