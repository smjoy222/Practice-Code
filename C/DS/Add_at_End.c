#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

void add_at_end(struct node *head, int data) {
    struct node *ptr, *temp;
    ptr = head;
    
    while (ptr->link != NULL) {
        ptr = ptr->link;
    }
    ptr->link = temp;
}

int main() {
    struct node *head = NULL;
    head = (struct node *)malloc(sizeof(struct node));
    head->data = 40;
    head->link = NULL;
    struct node *node1 = (struct node *)malloc(sizeof(struct node));
    node1->data = 60;
    node1->link = NULL;
    head->link = node1;
    node1 = (struct node *)malloc(sizeof(struct node));
    node1->data = 80;
    node1->link = NULL;
    head->link=node1;

    int data;
    struct node *temp;//++
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = 777;
    //temp->data = data;
    temp->link = NULL;
    head->link->link=temp;

    add_at_end(head, data);
    //add_at_end(head, 777);

    printf("%d\n", head->data); //40
    printf("%d\n", head->link->data); //60
    printf("%p\n", head->link);// address
    printf("%d\n", node1->data);//80
    printf("%p\n", node1->link);//000000
    printf("%d\n", head->link->data);  //60  
    printf("%d\n", head->link->link->data);//777
    printf("%d\n", node1->data);//80
    printf("%p\n", node1->link);//00000
    printf("%d\n", temp->data);//777
    printf("%p\n", temp->link);//00000
/*
    // Free the allocated memory
    free(temp);
    free(node1);
    free(head);
*/
    return 0;
}
