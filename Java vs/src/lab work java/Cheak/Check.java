import java.util.Scanner;
public class Check {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.println("Enter to cheak:");
        String str = input.nextLine();
        input.close();
        for(int i =0;i<str.length();i++){
         char ch = str.charAt(i);
        if(Character.isDigit(ch)){
            System.out.println(str + " is a digit.");
        
        }
           
         else{
            System.out.println(str + " is not a digit.");
        }
    }
  }
}
