#include<stdio.h>
#include<stdlib.h>
int front=-1,rear=-1;
int n;
void enqueue(int *arr,int data);
int dequeue(int *arr);
void display(int *arr);
int main(){
    printf("Enter the size of Queue\n");
    scanf("%d",&n);
    int queue[n];

    //update & modify the queue
    enqueue(queue,10);
    enqueue(queue,20);
    enqueue(queue,30);
    enqueue(queue,40);
    enqueue(queue,50);
    enqueue(queue,60);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);


    //displaying the queue
    display(queue);

}
void enqueue(int *arr,int data){
    if(rear==(n-1)){
        printf("Queue Full!No space left\n");
    }
    else if(rear==-1 && front==-1){
        rear++;
        front++;
        arr[rear] = data;
    }
    else{
        rear++;
        arr[rear] = data;
    }
}
int dequeue(int *arr){
    if(front==-1 && rear==-1){
        printf("Queue is Empty!\n");
        return -1;
    }
    else if(front==rear){
        int temp = arr[front];
        front=-1;
        rear= -1;
        return temp;
    }
    else{
        int temp = arr[front];
        front++;
        return temp;
    }
}
void display(int *arr){
    if(front!=-1){
    for(int i=front;i<=rear;i++)
        printf("%d ",arr[i]);

    printf("\n");
    }
}