#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*link;
};
struct node* add_at_f(struct node *head,int d){
    struct node *add=(struct node*)malloc(sizeof(struct node));
    add->data=d;
    add->link=NULL;

    add->link=head;
    head=add;
    return head;
}
int main(){
    struct node *head=NULL;
    head = (struct node*)malloc(sizeof(struct node));
    head->data=40;
    head->link=NULL;

    struct node *node1=(struct node*)malloc(sizeof(struct node));
    node1->data=60;
    node1->link=NULL;

    head->link=node1;

    node1=(struct node*)malloc(sizeof(struct node));
    node1->data=80;
    node1->link=NULL;

    head->link->link=node1;

    struct node *ptr =(struct node*)malloc(sizeof(struct node));
    ptr->data=100;
    ptr->link=NULL;
    head->link->link->link=ptr;

    int data=5;
    head=add_at_f(head,data);
    struct node *newhead=NULL;
    newhead=head;
    while(newhead !=NULL){
    printf("%d\n",newhead->data);
    newhead=newhead->link;
    }

    //printf("%d\n",head->data);
   // printf("%d\n",head->link->data);
   // printf("%d\n",head->link->link->data);
   // printf("%d\n",node1->data);

}
