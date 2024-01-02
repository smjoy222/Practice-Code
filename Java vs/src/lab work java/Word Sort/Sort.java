
import java.util.Arrays;
import java.util.Scanner;
public class Sort {
    public static void main(String[]args){
    Scanner input = new Scanner(System.in);
    System.out.println("Enter for how many words you want:");
    int n =input.nextInt();
    input.nextLine();
    String[] words = new String[n];
    System.out.println("Enter The words:"); 
    for(int i =0;i<n;i++){
        words[i]=input.nextLine();
    }
    input.close();
Arrays.sort(words);
System.out.println("Sorted words: ");
for(String word : words){
    System.out.println(word);
}
    }
}
