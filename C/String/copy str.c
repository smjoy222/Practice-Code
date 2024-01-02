#include<stdio.h>
int main()
{
 char source[100];
 printf("Enter your full name :");
 gets(source);
char target [100];
 strcpy(target,source);
 printf("source string = %s\n",source);
printf("target string = %s\n",target);
  return 0;
}
