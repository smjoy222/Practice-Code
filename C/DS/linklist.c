#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *link;
};

int main(){
    struct node *head=NULL;
    head=(struct node *)malloc(sizeof(struct node));
    head->data=45;
    head->link=NULL;
/*
    struct node *node2=(struct node *)malloc(sizeof(struct node));
    node2->data=100;
    node2->link=NULL;

    head->link=node2;   //the connection line
     
    struct node *node3 =(struct node*)malloc(sizeof(struct node));
    node3->data=200;
    node3->link=NULL;

    node2->link=node3;   //the connection line

    printf("%d\n",head->data);          //will print line 12
    printf("%d\n",head->link->data);    //will print line 16
    printf("%d\n",head->link);         //will print address
    printf("%d\n",node2->data);         //will print line 16
    printf("%d\n",node2->link);         //will print address
    printf("%d\n",head->link->link->data); //will print line 23
    printf("%d\n",node3->data);         //will print line 23
    printf("%d\n",node3->link);         //will print line 24
*/
    struct node *node2=(struct node *)malloc(sizeof(struct node));
    node2->data=100;
    node2->link=NULL;

    head->link=node2;   //the connection line
     
    node2 =(struct node*)malloc(sizeof(struct node)); //not creating pointer again for unnessery storage
    node2->data=200;
    node2->link=NULL;

    head->link->link=node2;   //the connection line

    printf("%d\n",head->data);          //will print line 12
    printf("%d\n",head->link->data);    //will print line 16
    printf("%d\n",head->link);         //will print address
    printf("%d\n",node2->data);         //will print line 16
    printf("%d\n",node2->link);         //will print address
    printf("%d\n",head->link->link->data); //will print line 23
    printf("%d\n",node2->data);         //will print line 23
    printf("%d\n",node2->link);         //will print line 24
}
