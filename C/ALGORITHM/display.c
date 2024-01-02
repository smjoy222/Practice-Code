#include<stdio.h>
void printNum(int i){
    if(i>10)
        return;
    else
    {
        printf("%d ",i);
        printNum(++i);
    }
}
int main(){
    printf("Displaying Number upto 10:\n");
    printNum(1);
    return 0;
}