#include<stdio.h>
int main ()
{

int a,b,c;
scanf("%d%d%d",&a,&b,&c);
printf("sum is %d\n",sum(a,b,c));
}
int sum (int a,int b,int c)
{
    return a+b+c;
}
