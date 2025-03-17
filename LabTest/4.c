#include<stdio.h>
#include<stdlib.h>
void sort(int a[],int n)
{
    int i,j,k;
    for(i=1;i<n;i++)
    {
        k=a[i];
        j=i-1;
        while(j>=0 && a[j]<k)
        {
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=k;
    }
}
void fit(int arr[],int c,int n)
{
    int binn=0,i,j;
    int cap[n];
    for(i=0;i<n;i++)
        cap[i]=c;
    
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(cap[j]-arr[i]>=0)
            {
                cap[j]-=arr[i];
                break;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        if(cap[i]!=c)
            binn++;
    }
    printf("%d\n",binn);
}
int main()
{
    int c,n;
    scanf("%d",&c);
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    {
       scanf("%d",&arr[i]);
    }
    sort(arr,n);
    fit(arr,c,n);
    
    return 0;
}