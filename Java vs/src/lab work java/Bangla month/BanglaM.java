import java.util.Scanner;

public class BanglaM {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter a number between 1 and 12: ");
        int monthNumber = scanner.nextInt();

        String monthName = getBanglaMonthName(monthNumber);

        System.out.println("Bangla Month: " + monthName);

        scanner.close();
    }

    private static String getBanglaMonthName(int monthNumber) {
        String monthName;

        switch (monthNumber) {
            case 1:
                monthName = "বৈশাখ";
                break;
            case 2:
                monthName = "জ্যৈষ্ঠ";
                break;
            case 3:
                monthName = "আষাঢ়";
                break;
            case 4:
                monthName = "শ্রাবণ";
                break;
            case 5:
                monthName = "ভাদ্র";
                break;
            case 6:
                monthName = "আশ্বিন";
                break;
            case 7:
                monthName = "কার্তিক";
                break;
            case 8:
                monthName = "অগ্রহায়ণ";
                break;
            case 9:
                monthName = "পৌষ";
                break;
            case 10:
                monthName = "মাঘ";
                break;
            case 11:
                monthName = "ফাল্গুন";
                break;
            case 12:
                monthName = "চৈত্র";
                break;
            default:
                monthName = "Invalid month number";
                break;
        }

        return monthName;
    }
}
