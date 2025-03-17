import java.util.Scanner;
public class LcmGdc{
  public static void main(String[]args){
  Scanner input = new Scanner(System.in);  
  System.out.println("Enter 1st number:");
  int a = input.nextInt();
  System.out.println("Enter 2nd number:");
  int b = input.nextInt();
  System.out.println("Enter 3rd number:");
  int c = input.nextInt();
  input.close();
  int gcd = findGcd(a,b,c);
  int lcm = findLcm(a,b,c);
  System.out.println("GCD: "+gcd);
  System.out.println("LCM: "+lcm);
  }
public static int findGcd(int x,int y, int z){
    int gcd =1;
    int smallest=Math.min(Math.min(x,y),z);
    for(int i=1;i<=smallest;i++){
        if(x%i==0 && y%i==0 && z%i==0){
            gcd=i;
        }
    }
    return gcd;
}
public static int findLcm(int x,int y,int z){
    int lcm =1;
    int largest = Math.max(Math.max(x,y),z);
    while(true){
        if (largest%x==0 && largest%y==0 && largest%z==0){
            lcm=largest;
            break;
        }
        largest++;
    }
    return lcm;
}

}


