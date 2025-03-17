import java.util.Scanner;
public class BanglaMonth2 {
    public static void main(String[]args){
    Scanner input = new Scanner(System.in);
    System.out.println("Enter 1 to 12 for months:");
    int months= input.nextInt();
    switch(months){
case 1 :
 {months='1';
    System.out.println("Boisakh");
    break;
 }
 

 case 2 :
 { months ='2';
    System.out.println("Jestho");
    break;
 }
 case 3 :
 {months='3';
    System.out.println("Ashar");
    break;
 }
 case 4 :
 {months='4';
    System.out.println("Srabon");
    break;
 }
 case 5 :
 {months='5';
    System.out.println("Badro");
    break;
 }case 6 :
 {months='6';
    System.out.println("Asshin");break;
 }
 case 7 :
 {months='7';
    System.out.println("Kartik");break;
 }
 case 8 :
 {months='8';
    System.out.println("Agrahayon");break;
 }
 case 9 :
 {months='9';
    System.out.println("Poush");break;
 }
 case 10 :
 {
    System.out.println("Magh");break;
 }
 case 11 :
 {
    System.out.println("Falgun");break;
 }
 case 12 :
 {
    System.out.println("Chaitra");break;
 }
 default:
 {
    System.out.println("Invalid Number");break;
 }


    }


input.close();

    }
    
}
