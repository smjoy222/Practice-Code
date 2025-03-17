#include<stdio.h>
#include<string.h>
#define max(x,y)(x>y?x:y);
char x[20],y[20],b[20][20];
int l[20][20];
int i,j,m,n;

void print(int i,int j)
{
    if(i==0||j==0)
    {
        return;
    }
    if(b[i][j]=='c')
    {
        print(i-1,j-1);
        printf("%c",x[i-1]);
    }
    else if(b[i][j]=='u')
    {
        print(i-1,j);
    }
    else
    {
        print(i,j-1);
    }
}
int lcs(){
    m=strlen(x);
    n=strlen(y);

   for(i=0;i<=m;i++)
    {
      l[i][0]=0;
    }
     for(i=0;i<=n;i++)
    {
      l[0][i]=0;
    }

    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(i==0 || j==0)
            {
                l[i][j]=0;
                b[i][j]='l';
            }
            if(x[i-1]==y[j-1])
            {
                l[i][j]=l[i-1][j-1]+1;
                b[i][j]='c';
            }
            else if(l[i-1][j]>=l[i][j-1])
            {
                l[i][j]=l[i-1][j];
                b[i][j]='u';
            }
            else
            {
                l[i][j]=l[i][j-1];
                b[i][j]='l';
            }
        }
    }
    return l[m][n];
}
int main()
{
    printf("Enter 1st Sequence:");
    scanf("%s",x);


    printf("Enter 2nd Sequence:");
    scanf("%s",y);
    n=strlen(y);
    int len=lcs();
    printf("Longest Common Subsequence is:%d\n",len);
    print(m,n);
    return 0;
}


/*char S1[] = "AGGTAB";
    char S2[] = "GXTXAYB";*/
