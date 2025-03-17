#include<stdio.h>
int add(int a,int b)
{
    return a+b;
}
int main()
{
    int a,b;
    
    printf("Enter Two Numbers-");
    printf("\n\nFirst Number: ");
    scanf("%d",&a);
    printf("Second Number: ");
    scanf("%d",&b);
    int sum;
    sum=add(a,b);
    printf("\nSum of %d and %d = %d\n",a,b,sum);
    
    
    return 0;  
}