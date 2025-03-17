import java.util.Scanner;

public class Permutation {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter the value of N: ");
        int N = input.nextInt();
        input.close();

        System.out.println("Permutations:");
        generatePermutations(new int[N], new boolean[N], 0);

        System.out.println("\nCombinations:");
        generateCombinations(new int[N], 0, 1, N);
    }

    public static void generatePermutations(int[] arr, boolean[] used, int index) {
        if (index == arr.length) {
            printArray(arr);
            return;
        }

        for (int i = 0; i < arr.length; i++) {
            if (!used[i]) {
                arr[index] = i + 1;
                used[i] = true;
                generatePermutations(arr, used, index + 1);
                used[i] = false;
            }
        }
    }

    public static void generateCombinations(int[] arr, int index, int start, int N) {
        if (index == arr.length) {
            printArray(arr);
            return;
        }

        for (int i = start; i <= N; i++) {
            arr[index] = i;
            generateCombinations(arr, index + 1, i + 1, N);
        }
    }

    public static void printArray(int[] arr) {
        for (int num : arr) {
            System.out.print(num + " ");
        }
        System.out.println();
    }
}

