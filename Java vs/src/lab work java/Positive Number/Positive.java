import java.util.Scanner;
public class Positive {
    public static void main(String[]args){
Scanner input= new Scanner(System.in);
System.out.println("Enter 5 Numbers:");
int positive = 0;
    int sum = 0;
for(int i=0;i<5;i++){
    
    int n = input.nextInt();
    
    if(n>0){
        positive ++;
       sum= sum + n;
    }
    
}
System.out.println("Possitive found :"+ positive + "Sum : " + sum);
input.close();


    }
}
