#include<stdio.h>
int main()
{
    char first_name[100];
    printf("Enter your 1st name :");
    gets(first_name);
    char second_name [100];
    printf("Enter your 2nd name :");
    gets(second_name );




    int i=0,len=0,j=0;
    while (first_name[i]!='\0')
    {
        i++;
        len++;
    }
    while (second_name[j]!='\0')
    {
        first_name[len+j]=second_name[j];
        j++;

    }
    printf("full name  = %s\n",first_name);
    return 0;
}
