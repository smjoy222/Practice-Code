import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Permutation2 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the array size: ");
        int N = scanner.nextInt();

        int[] numbers = new int[N];
        System.out.println("Enter " + N + " numbers:");
        for (int i = 0; i < N; i++) {
            numbers[i] = scanner.nextInt();
        }

        List<List<Integer>> permutations = generatePermutations(numbers);
        List<List<Integer>> combinations = generateCombinations(numbers);

        System.out.println("Permutations:");
        for (List<Integer> permutation : permutations) {
            System.out.println(permutation);
        }

        System.out.println("\nCombinations:");
        for (List<Integer> combination : combinations) {
            System.out.println(combination);
        }

        scanner.close();
    }

    public static List<List<Integer>> generatePermutations(int[] numbers) {
        List<List<Integer>> permutations = new ArrayList<>();
        backtrackPermutations(numbers, new ArrayList<>(), permutations);
        return permutations;
    }

    private static void backtrackPermutations(int[] numbers, List<Integer> current, List<List<Integer>> permutations) {
        if (current.size() == numbers.length) {
            permutations.add(new ArrayList<>(current));
            return;
        }

        for (int i = 0; i < numbers.length; i++) {
            if (current.contains(numbers[i])) {
                continue;
            }

            current.add(numbers[i]);
            backtrackPermutations(numbers, current, permutations);
            current.remove(current.size() - 1);
        }
    }

    public static List<List<Integer>> generateCombinations(int[] numbers) {
        List<List<Integer>> combinations = new ArrayList<>();
        backtrackCombinations(numbers, new ArrayList<>(), 0, combinations);
        return combinations;
    }

    private static void backtrackCombinations(int[] numbers, List<Integer> current, int start, List<List<Integer>> combinations) {
        combinations.add(new ArrayList<>(current));

        for (int i = start; i < numbers.length; i++) {
            current.add(numbers[i]);
            backtrackCombinations(numbers, current, i + 1, combinations);
            current.remove(current.size() - 1);
        }
    }
}