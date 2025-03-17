import java.util.Scanner;
public class hcf {
    public static void main(String[]args){
    Scanner input = new Scanner(System.in);
    System.out.println("Enter 1st number:");
    int a = input.nextInt();
    System.out.println("Enter 2nd number:");
    int b = input.nextInt();
    input.close();
    int hcf= findHcf(a,b);
    System.out.println("HCF is: "+hcf);
    }
    
    public static int findHcf(int x, int y){
    int hcf =1;
    int smallest =Math.min(x,y);
    for(int i =1;i<=smallest;i++){
        if(x%i==0 &&y%i==0){
            hcf=i;
        }
    }
    return hcf; 

    }
}
