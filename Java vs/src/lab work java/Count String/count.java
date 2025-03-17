import java.util.Scanner;
public class count {
   public static void main(String[]args){
Scanner input = new Scanner(System.in);
System.out.println("Enter any string:");
String app = input.nextLine();
input.close();
app= app.toLowerCase();
int vowel =0;
int consonant =0;
for(int i=0;i<app.length();i++){
char ch =app.charAt(i);
if (Character.isLetter(ch)){
    if(ch=='a'|| ch=='e' || ch =='i'||ch == 'o' || ch == 'u' ){
    vowel++;
}
else{
    consonant++;
}

}
}
System.out.println("Vowel Found:"+vowel);
System.out.println("Consonant Found:"+consonant);

 
}
}
