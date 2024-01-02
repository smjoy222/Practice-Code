import java.util.Scanner;

public class Frequency {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the number of elements in the array: ");
        int n = scanner.nextInt();

        int[] array = new int[n];
        int[] frequency = new int[n];

        System.out.println("Enter the elements of the array:");

        
        for (int i = 0; i < n; i++) {
            array[i] = scanner.nextInt();
        }

        for (int i = 0; i < n; i++) {
            if (frequency[i] == -1) {
                continue; 
            }

            int count = 1;

            for (int j = i + 1; j < n; j++) {
                if (array[i] == array[j]) {
                    count++;
                    frequency[j] = -1; 
                }
            }

            frequency[i] = count;
        }

       
        for (int i = 0; i < n; i++) {
            if (frequency[i] != -1) {
                System.out.println("Element " + array[i] + " occurs " + frequency[i] + " times");
            }
        }

        scanner.close();
    }
}
