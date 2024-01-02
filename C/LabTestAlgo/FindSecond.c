#include<stdio.h>
int insertion_sort(int a[],int n)
{
    int i,j,temp,min_index;
    for(i=0; i<n; i++)
    {
        min_index=i;
        for(j=i+1; j<n; j++) //find min index
        {
            if(a[j]<a[min_index])
            {
                min_index=j;
            }
        }
        //swap(i,min_index)
        temp=a[i];
        a[i]=a[min_index];
        a[min_index]=temp;
    }
}
int main()
{
	int T,i,N,j;
	scanf("%d",&T);
	for(j=1;j<=T;j++)
	{
		scanf("%d",&N);
		int a[N];
		for(i=0;i<N;i++)
		{
			scanf("%d",&a[i]);
		}
		insertion_sort(a,N);
		printf("%d\n",a[N-2]);
	}
	return 0;
}
