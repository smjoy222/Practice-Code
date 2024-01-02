#include<stdio.h>
int main()
{
    char name[100];
    printf("Enter your name :");
    gets(name);
    char reverse [100];

    int i=0,len=0,j;
    while (name[i]!='\0')
    {
        i++;
        len++;
    }
    for (j=0,i=len-1;i>=0;i--,j++)
    {
        reverse[j]=name[i];
    }
    reverse[j]='\0';
    printf("reverse  = %s\n",reverse);
    return 0;
}
