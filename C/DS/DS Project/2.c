#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100

typedef struct node {
    char name[MAX_NAME_LENGTH];
    struct node *subdirectories;
    struct node *files;
} node;

node *create_node(char *name) {
    node *new_node = (node *)malloc(sizeof(node));
    strcpy(new_node->name, name);
    new_node->subdirectories = NULL;
    new_node->files = NULL;
    return new_node;
}

void add_directory(node *parent, char *name) {
    node *new_node = create_node(name);
    new_node->subdirectories = parent->subdirectories;
    parent->subdirectories = new_node;
}

void add_file(node *parent, char *name) {
    node *new_node = create_node(name);
    new_node->files = parent->files;
    parent->files = new_node;
}

void delete_directory(node *parent, char *name) {
    node *current = parent->subdirectories;
    node *previous = NULL;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (previous == NULL) {
                parent->subdirectories = current->subdirectories;
            } else {
                previous->subdirectories = current->subdirectories;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->subdirectories;
    }
}

void delete_file(node *parent, char *name) {
    node *current = parent->files;
    node *previous = NULL;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (previous == NULL) {
                parent->files = current->files;
            } else {
                previous->files = current->files;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->files;
    }
}

void rename_directory(node *parent, char *old_name, char *new_name) {
    node *current = parent->subdirectories;
    while (current != NULL) {
        if (strcmp(current->name, old_name) == 0) {
            strcpy(current->name, new_name);
            return;
        }
        current = current->subdirectories;
    }
}

void view_directory_contents(node *parent) {
    node *current = parent->subdirectories;
    while (current != NULL) {
        printf("%s/\n", current->name);
        current = current->subdirectories;
    }
    current = parent->files;
    while (current != NULL) {
        printf("%s\n", current->name);
        current = current->files;
    }
}

void depth_first_traversal(node *root) {
    if (root == NULL) {
        return;
    }

    printf("%s/\n", root->name);

    depth_first_traversal(root->subdirectories);
    depth_first_traversal(root->files);
}

void breadth_first_traversal(node *root) {
    if (root == NULL) {
        return;
    }

    node *queue[100];
    int front = 0, rear = -1;
    queue[++rear] = root;

    while (front <= rear) {
        node *current = queue[front++];
        printf("%s/\n", current->name);

        node *subdir = current->subdirectories;
        while (subdir != NULL) {
            queue[++rear] = subdir;
            subdir = subdir->subdirectories;
        }

        node *file = current->files;
        while (file != NULL) {
            printf("%s\n", file->name);
            file = file->files;
        }
    }
}

int main() {
    node *root = create_node("root");
    char input[MAX_NAME_LENGTH];
    int choice = 0;

    while (choice != 6) {
        printf("\n\nDirectory contents:\n");
        view_directory_contents(root);
        printf("\n\nMenu:\n");
        printf("1. Add directory\n");
        printf("2. Add file\n");
        printf("3. Delete directory\n");
        printf("4. Rename directory\n");
        printf("5. View Directory Structure (DFS)\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter directory name: ");
                scanf("%s", input);
                add_directory(root, input);
                break;
            case 2:
                printf("\nEnter file name: ");
                scanf("%s", input);
                add_file(root, input);
                break;
            case 3:
                printf("\nEnter directory name: ");
                scanf("%s", input);
                delete_directory(root, input);
                break;
            case 4:
                printf("\nEnter old directory name: ");
                scanf("%s", input);
                char old_name[MAX_NAME_LENGTH];
                strcpy(old_name, input);
                printf("\nEnter new directory name: ");
                scanf("%s", input);
                rename_directory(root, old_name, input);
                break;
            case 5:
                printf("\nDirectory Structure (DFS):\n");
                depth_first_traversal(root);
                break;
            case 6:
                printf("\nExiting program.\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }

    // Clean up memory
    free(root);

    return 0;
}

