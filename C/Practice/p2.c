#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student
{
    char name[20];
    char id[12];
    char gmail[50];
    char cell[16];
    char blood[4];
    struct Student *next;
} S;

S *create_list(S *head)
{
    char name[20];
    printf("Enter Your Name: ");
    while (getchar() != '\n'); // Consume the newline character from the previous input
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0'; // Remove the trailing newline

    char id[12];
    printf("Enter Your ID: ");
    scanf("%s", id);

    char gmail[50];
    printf("Enter Your G-mail: ");
    scanf("%s", gmail);

    char cell[16];
    printf("Enter Your Cell Phone: ");
    scanf("%s", cell);

    char blood[4];
    printf("Enter Your Blood Group: ");
    scanf("%s", blood);

    S *newStudent = (S *)malloc(sizeof(S));
    if (newStudent == NULL)
    {
        printf("Memory allocation failed.\n");
        return head;
    }

    strcpy(newStudent->name, name);
    strcpy(newStudent->id, id);
    strcpy(newStudent->gmail, gmail);
    strcpy(newStudent->cell, cell);
    strcpy(newStudent->blood, blood);
    newStudent->next = NULL;

    if (head == NULL)
    {
        head = newStudent;
    }
    else
    {
        S *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newStudent;
    }

    return head;
}

void display(S *head)
{
    S *temp = head;
    int i = 1;
    while (temp != NULL)
    {
        printf("Student[%d] Name: %s\nID: %s\nGmail: %s\nCell-Phone: %s\nBlood Group: %s\n", i, temp->name, temp->id, temp->gmail, temp->cell, temp->blood);
        temp = temp->next;
        i++;
    }
}

void search(S *head, char name[])
{
    S *temp = head;
    int i = 1;
    int found = 0; // Added to track if the name was found
    while (temp != NULL)
    {
        if (strcmp(temp->name, name) == 0)
        {
            printf("Student[%d] Name: %s\nID: %s\nGmail: %s\nCell-Phone: %s\nBlood Group: %s\n", i, temp->name, temp->id, temp->gmail, temp->cell, temp->blood);
            found = 1; // Set found to 1 if the name is found
        }
        temp = temp->next;
        i++;
    }

    if (!found)
    {
        printf("Name not found.\n");
    }
}

S *insertAtFirst(S *head)
{
    S *newStudent = (S *)malloc(sizeof(S));

    printf("Enter Your Name: ");
    while (getchar() != '\n'); // Consume the newline character from the previous input
    fgets(newStudent->name, sizeof(newStudent->name), stdin);
    newStudent->name[strcspn(newStudent->name, "\n")] = '\0'; // Remove the trailing newline

    printf("Enter Your ID: ");
    scanf("%s", newStudent->id);

    printf("Enter Your G-mail: ");
    scanf("%s", newStudent->gmail);

    printf("Enter Your Cell Phone: ");
    scanf("%s", newStudent->cell);

    printf("Enter Your Blood Group: ");
    scanf("%s", newStudent->blood);

    if (head == NULL)
    {
        head = newStudent;
        newStudent->next = NULL; // Initialize the next pointer
    }
    else
    {
        newStudent->next = head;
        head = newStudent;
    }

    return head;
}

S *insertAtLast(S *head)
{
    S *temp, *newStudent;
    newStudent = (S *)malloc(sizeof(S));

    printf("Enter Your Name: ");
    while (getchar() != '\n'); // Consume the newline character from the previous input
    fgets(newStudent->name, sizeof(newStudent->name), stdin);
    newStudent->name[strcspn(newStudent->name, "\n")] = '\0'; // Remove the trailing newline

    printf("Enter Your ID: ");
    scanf("%s", newStudent->id);

    printf("Enter Your G-mail: ");
    scanf("%s", newStudent->gmail);

    printf("Enter Your Cell Phone: ");
    scanf("%s", newStudent->cell);

    printf("Enter Your Blood Group: ");
    scanf("%s", newStudent->blood);

    if(head==NULL)
{
        head = newStudent;
        newStudent->next = NULL; // Initialize the next pointer
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newStudent;
        newStudent->next = NULL;
    }

    return head;
}

S *insertAtIndex(S *head, int index)
{
    S *temp, *newStudent;
    newStudent = (S *)malloc(sizeof(S));

    printf("Enter Your Name: ");
    while (getchar() != '\n'); // Consume the newline character from the previous input
    fgets(newStudent->name, sizeof(newStudent->name), stdin);
    newStudent->name[strcspn(newStudent->name, "\n")] = '\0'; // Remove the trailing newline

    printf("Enter Your ID: ");
    scanf("%s", newStudent->id);

    printf("Enter Your G-mail: ");
    scanf("%s", newStudent->gmail);

    printf("Enter Your Cell Phone: ");
    scanf("%s", newStudent->cell);

    printf("Enter Your Blood Group: ");
    scanf("%s", newStudent->blood);

    if (index == 1)
    {
        newStudent->next = head;
        head = newStudent;
    }
    else
    {
        temp = head;
        for (int i = 1; i < index - 1; i++)
        {
            temp = temp->next;
        }
        newStudent->next = temp->next;
        temp->next = newStudent;
    }

    return head;
}

S *del(S *head, char namekey[])
{
    S *temp, *prev;
    temp = head;

    if (temp != NULL && strcmp(temp->name, namekey) == 0)
    {
        head = temp->next;
        free(temp);
        return head;
    }

    while (temp != NULL && strcmp(temp->name, namekey) != 0)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("%s is not found\n", namekey);
        return head;
    }

    prev->next = temp->next;
    free(temp);
    return head;
}

int main()
{
    int choice, index;
    S *head = NULL;
    char namekey[20];

    do
    {
        printf("Menu:\n");
        printf("1. Create List\n");
        printf("2. Display List\n");
        printf("3. Search By Name\n");
        printf("4. Insert at First\n");
        printf("5. Insert at Last\n");
        printf("6. Insert at Index\n");
        printf("7. Delete\n");
        printf("0. Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            head = create_list(head);
            break;
        case 2:
            display(head);
            break;
        case 3:
            printf("Enter Name to Search: ");
            scanf("%s", namekey);
            search(head, namekey);
            break;
        case 4:
            head = insertAtFirst(head);
            break;
        case 5:
            head = insertAtLast(head);
            break;
        case 6:
            printf("Enter Index to Insert: ");
            scanf("%d", &index);
            head = insertAtIndex(head, index);
            break;
        case 7:
            printf("Enter Name to Delete: ");
            while (getchar() != '\n'); // Consume the newline character from the previous input
            fgets(namekey, sizeof(namekey), stdin);
            namekey[strcspn(namekey, "\n")] = '\0'; // Remove the trailing newline
            head = del(head, namekey);
            break;
        case 0:
            exit(0);
        default:
            printf("Wrong Choice\n");
        }
    }
    while (choice != 0);

return 0;
}