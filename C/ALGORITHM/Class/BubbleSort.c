#include<stdio.h>
void bubble_sort(int a[], int n)
{
    for(int i=0;i<n-1;i++)
    {
        int flag=0;
        for(int j=0;j<n-1-i;j++)
        {
            if(a[j]>a[j+1])
            {
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                flag = 1;
            }
        }
        if(flag==0)
            break;
    }
}

void display_ascending(int a[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}

int main()
{
   int n;
    printf("Enter the size of array: \n");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements: \n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Before sorting: ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n\n");

    bubble_sort(a,n);
    printf("After sorting: ");
    display_ascending(a,n);

    return 0;
}
