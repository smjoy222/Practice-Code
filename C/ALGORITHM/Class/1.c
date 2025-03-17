#include<stdio.h>
void lis(int sc[],int n){
    int len[n];
    for(int i=0;i<n;i++){
        len[i]=0;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(sc[j]<sc[i]){
                if(len[i]<len[j]+1){
                    len[i]=len[j]+1;
                }
            }
        }
    }
    int m=len[0];
    for(int i=0;i<n;i++){
        if(m<len[i]){
            m=len[i];
        }
    }
    if(m>(n/2)){
        printf("Eligible for the Research Award\n");

    }
    else {
         printf("Not Eligible for the Research Award\n");
    }
    printf("the lis is %d\n",m);
}
int main(){
    int n;
    scanf("%d",&n);
    int sc[n];
    for(int i=0;i<n;i++){
        scanf("%d",&sc[i]);
    }
    lis(sc,n);


}
