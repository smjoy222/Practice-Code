#include <stdio.h>
int palindrom(int n)
{ int original=n;
    int reversal=0;

    while (n>0)
    {
        int reminder=n%10;
        reversal=reversal*10+reminder;
        n=n/10;
    }
    return original==reversal;
}
int main()
{
    int k;
    scanf("%d",&k);
    for (int caseNum = 1; caseNum <= k; caseNum++)
    {   int n;
        scanf("%d", &n);

        if (palindrom(n))
        {
            printf("case %d: yes\n",caseNum);
        }
        else{
            printf("case %d: no\n",caseNum);
        }


    }
    return 0;
}
