import java.util.Scanner;

public class pos {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int countPositive = 0;
        int sumPositive = 0;

        System.out.println("Enter 5 numbers:");
        for (int i = 0; i < 5; i++) {
            int num = input.nextInt();
            if (num > 0) {
                countPositive++;
                sumPositive += num;
            }
        }

        input.close();

        if (countPositive > 0) {
            int averagePositive = sumPositive / countPositive;
            System.out.println("Number of positive numbers: " + countPositive);
            System.out.println("Average of positive numbers: " + averagePositive);
        } else {
            System.out.println("No positive numbers were entered.");
        }
    }
}

