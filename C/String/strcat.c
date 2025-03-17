#include<stdio.h>
int main()
{
    char first_name[100];
    printf("Enter your 1st name :");
    gets(first_name);
    char second_name [100];
    printf("Enter your 2nd name :");
    gets(second_name );
    strcat(first_name,second_name );

    printf("full name  = %s\n",first_name);
    return 0;
}
