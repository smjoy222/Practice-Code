import java.util.Scanner;

public class Temperature2 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter temperature: ");
        double temperature = scanner.nextDouble();

        double celsius = fahrenheitToCelsius(temperature);
        double fahrenheit = celsiusToFahrenheit(temperature);

        System.out.println("Temperature in Celsius: " + celsius + "°C");
        System.out.println("Temperature in Fahrenheit: " + fahrenheit + "°F");

        scanner.close();
    }

    public static double fahrenheitToCelsius(double fahrenheit) {
        return (fahrenheit - 32) * 5 / 9;
    }

    public static double celsiusToFahrenheit(double celsius) {
        return (celsius * 9 / 5) + 32;
    }
}
