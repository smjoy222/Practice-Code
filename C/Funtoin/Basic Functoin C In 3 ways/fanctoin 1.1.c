#include<stdio.h>
int main ()
{

int a,b,c;
scanf("%d%d%d",&a,&b,&c);
int result=sum(a,b,c);
printf("sum is %d\n",result);
}
int sum (int a,int b,int c)
{

    return a+b+c;
}
