#include<stdio.h>
#define INF 100000
#define MIN(x,y)((x<y)?x:y);
void traceback(int coins[],int c[], int total)
{
    while(total!=0)
    {
        printf("%d ",coins[c[total]]);
        total=total-coins[c[total]];
    }
    printf("\n");
}

int dp_cc(int coins[],int total,int n)
{
    int t[total+1];
    int c[total+1];
    int temp;
    t[0]=0;
    c[0]=-1;
    for(int i=1;i<=total;i++)
    {
        t[i]=INF;
        c[i]=-1;
    }
    for(int j=0;j<n;j++)
    {
        for(int i=coins[j];i<=total;i++)
        {
            if(i>=coins[j])
            {
                temp=MIN(t[i],1+t[i-coins[j]]);
                if(temp!=t[i])
                {
                    t[i]=temp;
                    c[i]=j;
                }
            }
        }
    }
    traceback(coins,c,total);
    return t[total];
}

int main()
{
    int total,n,i;
    printf("Enter Available coins no: ");
    scanf("%d",&n);
    int coins[n];
    printf("Enter Available coins: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&coins[i]);
    }
    printf("Enter Denomination: ");
    scanf("%d",&total);
    int coin=dp_cc(coins,total,n);
    printf("Minimum coin=%d\n",coin);
    
    return 0;
}