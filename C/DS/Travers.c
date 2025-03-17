#include<stdio.h>
#include<stdlib.h>

struct node {
int data;
struct node *link;
};
/*
int count_of_nodes(struct node *head) {
        int count = 0;
        if(head==NULL){
            return 0;
        }
        struct node *ptr=head;
        while (ptr!=NULL)
        {
            count++;
          ptr=ptr->link;  
        }
        return count;
    }
*/
void count_of_nodes(struct node *head) {
        int count = 0;
        if(head==NULL){
            printf("Linklist Is Empty");
        }
        struct node *ptr=NULL;
        ptr=head;
        while (ptr!=NULL)
        {
            count++;
            printf("Data are: %d\n",ptr->data);
          ptr=ptr->link;  
        }
       printf("Number of nodes in the linked list: %d\n", count);
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
    count_of_nodes(head);  //line ta vhul krsilam,void function calling e initialization lage na
                           // void type function na hole,function calling e initialization lage 
/*
    int number_of_nodes = count_of_nodes(head);
    printf("Number of nodes in the linked list: %d\n", number_of_nodes);
*/
   return 0;
}
