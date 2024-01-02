#include<stdio.h>
int factorial(int );
int main()
{
    int a,f;
    scanf("%d",&a);
    f=factorial(a);
    printf("Factorial is= %d",f);
    return 0;
}
int factorial(int n)
{
    if(n==0)
        return 1;
    else
        return n*factorial(n-1);
}
