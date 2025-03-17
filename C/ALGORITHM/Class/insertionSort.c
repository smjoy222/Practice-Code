#include<stdio.h>
int insertion_sort(int A[],int n)
{
    int i,j,key;
    for(i=1;i<=n;i++)
    {
        key=A[i];
        j=i-1;
        while(j>=0 && A[j]>key)
        {
            A[j+1]=A[j];
            j=j-1;
        }
        A[j+1]=key;
    }
}
int descending_sort(int A[], int n)
{
    int i,j,key;
    for(i=1;i<=n;i++)
    {
        key=A[i];
        j=i-1;
        while(j>=0 && A[j]<key)
        {
            A[j+1]=A[j];
            j=j-1;
        }
        A[j+1]=key;
    }
}
void display_ascending(int A[],int n)
{
    int i;
    for(i=0;i<=n;i++)
    {
        printf("%d",A[i]);
    }
}
void display_descending(int A[],int n)
{
    int i;
    for(i=0;i<=n;i++)
    {
        printf("%d",A[i]);
    }
}
int main()
{
    int n;
    printf("Enter the size of array: \n");
    scanf("%d",&n);
    int A[n];
    printf("Enter the elements: \n");
    for(int i=0;i<=n;i++)
    {
        scanf("%d",&A[i]);
    }
    printf("Before sorting: ");
    for(int i=0;i<=n;i++)
    {
        printf("%d",A[i]);
    }
    printf("\n\n");
    insertion_sort(A,n);
    printf("After sorting:Ascending order: ");
    display_ascending(A,n);
    descending_sort(A,n);
    printf("\nAfter sorting:Descending order: ");
    display_descending(A,n);
    return 0;
}