#include<stdio.h>
int top = -1;
void push(int *arr,int data,int size);
int pop(int *arr);
void display(int *arr);
int main(){
    int size;
    printf("Enter the size of Stack\n");
    scanf("%d",&size);
    int arr[size];
    push(arr,10,size);
    push(arr,20,size);
    push(arr,30,size);
    push(arr,40,size);
    int x= pop(arr);


    display(arr);

}
void push(int *arr,int data,int size){
    if(top==(size-1))
        printf("Stack Overflowed!\n");
    else{
        top++;
        arr[top] = data;
    }
}
int pop(int *arr){
    int x=-1;
    if(top == -1)
        printf("Stack Underflow\n");
    else{
        x = arr[top];
        top--;
    }
    return x;
}
void display(int *arr){
    for(int i=top;i>=0;i--)
        printf("%d ",arr[i]);
    printf("\n");
}