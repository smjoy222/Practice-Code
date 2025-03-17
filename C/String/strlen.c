#include<stdio.h>
int main()
{
 char s1[30];
 printf("Enter your full name :");
 gets(s1);

 int len= strlen(s1);

 printf("Length = %d\n",len);


  return 0;
}
