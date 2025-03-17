#include<stdio.h>
int main()
{
 char s1[30];
 printf("Enter your full name :");
 gets(s1);
int i,len;
 for(i=0,len=0;s1[i]!='\0';i++,len++)

{


 printf("Length = %d\n",len);


}


  return 0;
}
