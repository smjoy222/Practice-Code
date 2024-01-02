import java.util.Scanner;

public class Temperature {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter temperature: ");
        double temperature = scanner.nextDouble();

        System.out.println("1. Fahrenheit to Celsius");
        System.out.println("2. Celsius to Fahrenheit");
        System.out.print("Enter your choice (1 or 2): ");
        int choice = scanner.nextInt();

        double convertedTemperature;

        if (choice == 1) {
            convertedTemperature = (temperature - 32) * 5 / 9;
            System.out.println("Temperature in Celsius: " + convertedTemperature + "°C");
        } else if (choice == 2) {
            convertedTemperature = (temperature * 9 / 5) + 32;
            System.out.println("Temperature in Fahrenheit: " + convertedTemperature + "°F");
        } else {
            System.out.println("Invalid choice!");
        }

        scanner.close();
    }
}
