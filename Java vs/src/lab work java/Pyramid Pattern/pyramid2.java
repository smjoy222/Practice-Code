public class pyramid2 {
    public static void main(String[] args) {
        int rows = 5; // Specify the number of rows for the pyramid

        for (int i = 1; i <= rows; i++) {
            // Print spaces before the asterisks
            for (int j = 1; j <= rows - i; j++) {
                System.out.print(" ");
            }

            // Print the asterisks
            for (int k = 1; k <= 2 * i - 1; k++) {
                System.out.print("*");
            }

            // Move to the next line
            System.out.println();
        }
    }
}
