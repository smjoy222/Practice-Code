#include<stdio.h>
int SWAP(int *n1,int*n2){
    int temp = *n1;
    *n1=*n2;
    *n2=temp;
}
int main(){
    int n1,n2;
    printf("a = ");
    scanf("%d",&n1);
    printf("b = ");
    scanf("%d",&n2);
    SWAP(&n1,&n2);
    printf("a = %d\nb = %d\n",n1,n2);
    return 0;
}