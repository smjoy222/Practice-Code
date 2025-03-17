#include<stdio.h>
void des(int a[],int n)
{
    int i,j,k;
    for(int i=1;i<n;i++){
        j=i-1;
        k=a[i];
        while(j>=0 && a[j]<k){
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=k;
    }
}

int ff(int a[],int n,int C){
    int count=0,bins[n];
    for(int i=0;i<n;i++){
        bins[i]=C;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(bins[j]-a[i]>=0){
            bins[j]-=a[i];
            break;
            }
          }
        }
        for(int i=0;i<n;i++){
            if(bins[i]!=C)
            count++;
        }
        return count;
    
}
int main (){
    int C;
    scanf("%d",&C);
        int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
       scanf("%d",&a[i]);
    }
    des(a,n);
    
    int total=0;
    for(int i=0;i<n;i++){
       total=total+a[i];
    }
    int lower_bound;
    lower_bound=total/C;
    int pack;
    pack=ff(a,n,C);
    printf("%d",pack);
    return 0;

    
}
