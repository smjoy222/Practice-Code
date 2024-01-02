import java.util.Scanner;
public class Possition2 {
  public static void main(String[]args){
  Scanner input = new Scanner(System.in);
  System.out.println("Enter the size of array:");
  int size = input.nextInt();
  int[] arr = new int[size];
  System.out.println("Enter the elements of the array: ");
  for (int i=0;i<size;i++){
  arr[i]=input.nextInt();

  }
input.close();
int smallest= arr[0];
int position=0;
for(int i=1;i<size;i++){
    if(arr[i]<smallest){
      smallest= arr[i];
      position=i;
    }
}
System.out.println("Smallest Number: "+smallest+ " And Possition: "+position);
  }   
}
