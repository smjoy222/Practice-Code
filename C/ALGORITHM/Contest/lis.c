#include<stdio.h>
void lis(int seq[],int n)
{
    int length[n];
    for(int i=0; i<n; i++)
    {
        length[i]=1;
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<i; j++)
        {
            if(seq[j]<seq[i])
            {
                 if(length[i]<length[j]+1)
            {


                length[i]=length[j]+1;}

            }
        }
    }


    int maxlis=length[0];

    for(int i=0; i<n; i++)
    {
        if(length[i]>maxlis)
        {
            maxlis=length[i];
        }
    }
    printf("the lis is %d\n",maxlis);



}
int main()
{
    int n;
    printf("enter your array size : ");
    scanf("%d",&n);
    printf("\n");
    int seq[n];
    printf("enter array element : ");
    for(int i=0; i<n; i++)
    {
        scanf("%d",&seq[i]);
    }
    lis(seq,n);
}
