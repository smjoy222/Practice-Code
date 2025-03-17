#include<stdio.h>
int main ()
{
    int  num[]= {2,6,7,5,3,4,45,66};
    int value =4,pos=-1,i;
    ; // array 0 index theke sure hoy

    for(i=0; i<8; i++)
    {
        if(value==num[i])
        {
            pos=i+1;
            break;
        }
    }


    if (pos == -1)
        printf("not found");

    else
        printf ("The positoin of %d is : %d\n",value,pos);

    return 0;
}
