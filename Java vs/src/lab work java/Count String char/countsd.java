import java.util.Scanner;
public class countsd {
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
        if(Character.isLetter(ch)){
            alphaCount++;
        }else if(Character.isDigit(ch)) {
          digitCOunt++;
        }
        else{
            charCount++;
        }
    }

System.out.println("Alphabets count: "+alphaCount+" Digit Count: "+digitCOunt+" Cahractor Count: "+charCount);
    }
}
