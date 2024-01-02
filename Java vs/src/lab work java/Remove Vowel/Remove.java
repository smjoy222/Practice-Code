import java.util.Scanner;

public class Remove {
    public static void main(String[] args) {
        String a;
        Scanner input = new Scanner(System.in);
        a = input.nextLine();
        input.close();
        int b = a.length();
        String result = "";

        for (int i = 0; i < b; i++) {
            if (a.charAt(i) != 'A' && a.charAt(i) != 'E' && a.charAt(i) != 'I' && a.charAt(i) != 'O' && a.charAt(i) != 'U' &&
                a.charAt(i) != 'a' && a.charAt(i) != 'e' && a.charAt(i) != 'i' && a.charAt(i) != 'o' && a.charAt(i) != 'u') {
                result += a.charAt(i);
            }
        }

        System.out.println("After removing the vowels: " + result);
    }
}

