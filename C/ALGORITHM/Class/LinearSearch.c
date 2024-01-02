#include<stdio.h>
int i,x;
void searchlinear(int Array[],int x)
{
    int found=0;

    for(i=0; i<5; i++)
    {
        if(Array[i]==x)
            {
                printf("Found %d at %d\n",Array[i],i+1);
                found++;
                break;
            }
    }

    if(found==0)
    {
        printf("Not Found\n");
    }
}
int main()
{
    int Array[]= {2,1,8,6,7};
    scanf("%d",&x);
    searchlinear(Array,x);
}

