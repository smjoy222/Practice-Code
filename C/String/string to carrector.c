#include<stdio.h>
int main()
{
 char s1[30];
 printf("Enter your full name :");
 gets(s1);
 int i=0;
 while (s1[i] !='\0'){

 printf("Full Name  = %c\n",s1[i]);
 i++;

 }
                    // use \0 to stop string
  return 0;                  // for multiple charrector with array
}
