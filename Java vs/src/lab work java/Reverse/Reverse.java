import java.util.Scanner;
public class Reverse {
public static void main(String[] args) {
    Scanner input = new Scanner(System.in);
     System.out.println("Enter the array size:");
     int n = input.nextInt();
     int[] arr = new int[n];
     System.out.println("Enter the values: ");
     for(int i=0;i<n;i++){
      arr[i]=input.nextInt();  
     }
    input.close();
      System.out.println("The reverse value order:");
      for(int i =n-1;i>=0;i--){
        System.out.println(arr[i]);
      }
    }
}
