#include<stdio.h>
int main()
{
    char str [100];
    printf("Enter any text to reverse :");
    gets(str);
    strrev(str);


    printf("The Reverse str is = %s\n",str);


     return 0;
}
