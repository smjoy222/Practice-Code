#include<stdio.h>
#include<string.h>

#define Bound 50

int main()
{
    int n;
    scanf("%d",&n);
    if(n<=0 || n>Bound)
        {
            printf("Invalid number of recipes\n");
            return 0;
        }
        
    char kacchi[Bound][100];
    for(int i=0;i<n;i++)
    {
        scanf(" %[^\n]", kacchi[i]);
    }
    int yes=-1;
    for(int i=0;i<n;i++)
    {
        if(strcmp(kacchi[i],"Kacchi Biriyani")==0)
        {
            yes=i+1;
            break;
        }
    }
    if(yes!= -1)
        printf("Kacchi Biriyani is found: %d\n",yes);
    else
        printf("Kacchi Biriyani is not found\n");
         
    return 0;
}