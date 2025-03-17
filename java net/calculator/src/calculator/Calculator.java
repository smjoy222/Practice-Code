
package calculator;
import java.util.Scanner;
public class Calculator {

  
    public static void main(String[] args) {
        char operator;
        double n1,n2,result;
       
        System.out.println("Enter 1st number ");
         Scanner input = new Scanner(System.in);
         n1=input.nextDouble();
        System.out.println("Enter 2nd number :");
        n2=input.nextDouble();
        System.out.println("Enter any operator :");
        operator=input.next().charAt(0);
        
        switch(operator){
        
            case '+':
                result = n1+n2;
                System.out.println(n1 + "+" +n2+ "="+ result);
                break;
            case '-':
                result = n1-n2;
                System.out.println(n1 + "-" +n2+ "="+ result);
                break;
            case '*':
                result = n1*n2;
                System.out.println(n1 + "*" +n2+ "="+ result);
                break;
            case '/':
                result = n1/n2;
                System.out.println(n1 + "/" +n2+ "="+ result);
                break;
        
       }
        
    }
    
}
