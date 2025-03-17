#include<stdio.h>
void square (int n);
int main()
{
int number = 4;
square(number);

return 0;
}
void square (int n)
{

    n=n*n;
    printf("square=%d\n",n);
}
