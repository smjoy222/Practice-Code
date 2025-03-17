import java.util.Scanner;
public class practice {
    public static void main(String[]args){
    Scanner input = new Scanner(System.in);
    System.out.println("Enter Tmperature:");
    double temp = input.nextDouble();
    double celsius = fahrenheitToCelsius(temp);
    double fahrenheit = celsiusToFahrenheit(temp);
    System.out.println("Temperature to Celsius: "+celsius+"*C");
    System.out.println("Temperature to Fahrenheit: "+fahrenheit +"*F");
    input.close();
    }
    public static double fahrenheitToCelsius(double fahrenheit){
        return (fahrenheit-32)*5/9;
    }
    public static double celsiusToFahrenheit(double celsius){
        return(celsius*9/5)+32;
    }
    
    
}
