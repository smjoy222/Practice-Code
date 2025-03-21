#include<stdio.h>
void sort_descending(int a[], int n)
{
    int i,j,k;
    for(i=1;i<n;i++)
    {
        j=i-1;
        k=a[i];
        while(j>=0 && a[j]<k)
        {
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=k;
    }
}
int first_fit_decreasing(int a[],int n,int C)
{
    int count=0,bins[n];
    for(int i=0;i<n;i++)
    {
        bins[i]=C;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(bins[j]-a[i]>=0)
            {
                bins[j]-=a[i];
                break;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        if(bins[i]!=C)
        count++;
    }
    return count;
}
int main()
{
    int n;
    printf("Enter section no: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter section's sizes: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    sort_descending(a,n);
    int total=0;
    for(int i=0;i<n;i++)
    {
        total+=a[i];
    }
    int lower_bound;
    printf("Enter the capacity of the bin: ");
    int C;
    scanf("%d",&C);
    lower_bound=total/C;
    int min;
    min=first_fit_decreasing(a,n,C);
    if(min>lower_bound)
    {
        printf("Total %d bin required\n",min);
        printf("Not Optimal\n");
    }
    else
    {
        printf("Total %d bin required\n",min);
        printf("Optimal Solution\n");
    }
    return 0;
}
/*Enter section no: 6
Enter section's sizes: 9 8 2 2 5 4
Enter the capacity of the bin: 10
*/
