#include<stdio.h>
void swap  (int a ,int b);
void _swap  (int *a ,int *b);
int main()
{
int a= 3,b= 5;

swap(a,b);
printf("a=%d & b=%d\n",a,b);
_swap(&a,&b);
printf("*a=%d & *b=%d\n",a,b);
return 0;
}


void swap  (int a ,int b)
{
    int t = a;
    t=b;
    a=b;
    printf("a=%d & b=%d\n",a,b);
}
void _swap  (int* a ,int* b)
{
    int t = *a;
    t=*b;
    *a=*b;
  printf("*a=%d & *b=%d\n",*a,*b);
}
