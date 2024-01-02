#include<stdio.h>
int main()
{

int x;
int *ptr;
 ptr = &x;
 *ptr=0;

printf ("X =%u\n",x);
printf ("*ptr =%d\n",*ptr);
 *ptr +=5;

printf ("X =%u\n",x);
printf ("*ptr =%d\n",*ptr);
printf ("ptr =%d\n",ptr);
(*ptr)++;
printf ("X =%u\n",x);
printf ("*ptr =%d\n",*ptr);

}
