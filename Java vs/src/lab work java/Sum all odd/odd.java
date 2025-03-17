import java.util.Scanner;

public class odd {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the value of N: ");
        int N = scanner.nextInt();

        int sum = 0;

        for (int i = 0; i < N; i++) {
            System.out.print("Enter a number: ");
            int num = scanner.nextInt();

            if (num % 2 != 0) {
                sum += num;
            }
        }

        System.out.println("Sum of odd numbers: " + sum);

        scanner.close();
    }
}
