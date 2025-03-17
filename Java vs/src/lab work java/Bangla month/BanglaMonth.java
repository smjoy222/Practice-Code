import java.util.Scanner;

public class BanglaMonth {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter a number between 1 and 12: ");
        int monthNumber = scanner.nextInt();

        String monthName = getBanglaMonthName(monthNumber);

        System.out.println("Bangla Month: " + monthName);

        scanner.close();
    }

    private static String getBanglaMonthName(int monthNumber) {
        String[] monthNames = {
            "Boisakh", "Joistho", "Ashar", "Srabon",
            "Badro", "Asshin", "Kartik", "Agrohayon",
            "Poush", "Magh", "Falgun", "choitra"
        };

        if (monthNumber >= 1 && monthNumber <= 12) {
            return monthNames[monthNumber - 1];
        } else {
            return "Invalid month number";
        }
    }
}
