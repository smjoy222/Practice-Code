import java.util.Scanner;;
public class Palindrome {
 public static void main (String[]args){
Scanner input = new Scanner(System.in);
System.out.println("Enter any String:");
String app = input.nextLine();
input.close();
String reverse = new StringBuilder(app).reverse().toString();
if (app.equalsIgnoreCase(reverse)){
    System.out.println("The input is palindrome");
}
else{
    System.out.println("the string is not palindrom");
}
 }
}
