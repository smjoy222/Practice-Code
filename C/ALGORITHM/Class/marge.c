#include<stdio.h>
void merge(int a[],int l, int q, int r)
{
    int i,j,k;
    int n1=q-l+1;
    int n2=r-q;
    
    int L[n1],R[n2];
    
    for(i=0;i<n1;i++)
    {
        L[i]=a[l+i];
    }
    for(j=0;j<n2;j++)
    {
        R[j]=a[q+1+j];
    }
    i=0;
    j=0;
    k=l;
    while(i<n1 && j<n2)
    {
        if(L[i]<=R[j])
        {
            a[k]=L[i];
            i++;
        }
        else
        {
            a[k]=R[j];
            j++;
        }
        k++;
    }
    
    while(i<n1)
    {
        a[k]=L[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        a[k]=R[j];
        j++;
        k++;
    }
}

void merge_sort(int a[],int l, int r)
{
    if(l<r)
    {
        int q=(l+r)/2;
        merge_sort(a,l,q);
        merge_sort(a,q+1,r);
        merge(a,l,q,r);
    }
}

void printarray(int a[], int size)
{
    int i;
    for(i=0;i<size;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}

int main()
{
    int a[]={12,11,13,5,6,7};
    int a_size=sizeof(a)/sizeof(a[0]);
    
    printf("Given array is: \n");
    printarray(a,a_size);
    
    merge_sort(a,0,a_size-1);
    
    printf("\nSorted array is: \n");
    printarray(a,a_size);
    return 0;
}