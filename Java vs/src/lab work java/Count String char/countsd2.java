import java.util.Scanner;
public class countsd2 {
    public static void main(String[]args){
    Scanner input=new Scanner(System.in);
    System.out.println("Enter any String");
    String str = input.nextLine();
    input.close();
    int alphaCount =0;
    int digitCOunt =0;
    int charCount =0;


    for(int i=0;i<str.length();i++){
        char ch = str.charAt(i);
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
            alphaCount++;
        } else if (ch >= '0' && ch <= '9') {
            digitCOunt++;
        } else {
            charCount++;
        }
    }

System.out.println("Alphabets count: "+ alphaCount);
   System.out.println("Digits count: "+ digitCOunt);
   System.out.println("Special characters count: "+ charCount);

}
}

