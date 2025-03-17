import java.util.Scanner;

class Cal{
public static void main(String[]args){
    char operator;
    double n1,n2,result;
Scanner input = new Scanner(System.in);
System.out.println("Enter 1st digit:");
n1=input.nextDouble();
System.out.println("Enter 2nd digit");
n2=input.nextDouble();
System.out.println("Enter operator");
operator=input.next().charAt(0);

switch(operator){
case '+':
result=n1+n2;
System.out.println(n1+"+"+n2+"="+result);
break;
case '-':
result=n1-n2;
System.out.println(n1+"-"+n2+"="+result);
break;
case '*':
result=n1*n2;
System.out.println(n1+"*"+n2+"="+result);
break;
case '/':
result = n1/n2;
System.out.println(n1+"/"+n2+"="+result);
break;
}

input.close();

 }

}