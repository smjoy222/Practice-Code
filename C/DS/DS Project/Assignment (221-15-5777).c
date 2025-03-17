#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_SUBDIRECTORIES 100
#define MAX_FILES 100

struct Directory {
    char name[MAX_NAME_LENGTH];
    struct Directory* subdirectories[MAX_SUBDIRECTORIES];
    char files[MAX_FILES][MAX_NAME_LENGTH];
    int num_subdirectories;
    int num_files;
};

struct Directory* create_directory(const char* name) {
    struct Directory* new_directory = (struct Directory*)malloc(sizeof(struct Directory));
    strcpy(new_directory->name, name);
    new_directory->num_subdirectories = 0;
    new_directory->num_files = 0;
    return new_directory;
}

void add_directory(struct Directory* parent, const char* new_directory_name) {
    struct Directory* new_directory = create_directory(new_directory_name);
    parent->subdirectories[parent->num_subdirectories++] = new_directory;
}

void add_file(struct Directory* parent, const char* file_name) {
    strcpy(parent->files[parent->num_files++], file_name);
}

void delete_directory(struct Directory* parent, const char* directory_name) {
    for (int i = 0; i < parent->num_subdirectories; ++i) {
        if (strcmp(parent->subdirectories[i]->name, directory_name) == 0) {
            free(parent->subdirectories[i]);
            for (int j = i; j < parent->num_subdirectories - 1; ++j) {
                parent->subdirectories[j] = parent->subdirectories[j + 1];
            }
            parent->num_subdirectories--;
            return;
        }
    }
}

void rename_directory(struct Directory* directory, const char* new_name) {
    strcpy(directory->name, new_name);
}

void view_directory_contents(struct Directory* directory) {
    printf("Inside this %s:\n", directory->name);

    printf("Subdirectories:\n");
    for (int i = 0; i < directory->num_subdirectories; ++i) {
        printf(" - %s\n", directory->subdirectories[i]->name);
    }

    printf("Files:\n");
    for (int i = 0; i < directory->num_files; ++i) {
        printf(" - %s\n", directory->files[i]);
    }
}

void depth_first_traversal(struct Directory* root) {
    struct Directory* stack[MAX_SUBDIRECTORIES];
    int top = -1;
    stack[++top] = root;

    while (top != -1) {
        struct Directory* current_directory = stack[top--];
        view_directory_contents(current_directory);

        for (int i = current_directory->num_subdirectories - 1; i >= 0; --i) {
            stack[++top] = current_directory->subdirectories[i];
        }
    }
}

int main() {
    struct Directory* root = create_directory("Root");

    int choice;
    char name[MAX_NAME_LENGTH];

    do {
        printf("\nMenu:\n");
        printf("1. Add Directory\n");
        printf("2. Add File\n");
        printf("3. Delete Directory\n");
        printf("4. Rename Directory\n");
        printf("5. View Directory Structure\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the name of the new directory: ");
                scanf("%s", name);
                add_directory(root, name);
                break;

            case 2:
                printf("Enter the name of the file to add: ");
                scanf("%s", name);
                add_file(root, name);
                break;

            case 3:
                printf("Enter the name of the directory to delete: ");
                scanf("%s", name);
                delete_directory(root, name);
                break;

            case 4:
                printf("Enter the name of the directory to rename: ");
                scanf("%s", name);
                struct Directory* directory_to_rename = NULL;
                for (int i = 0; i < root->num_subdirectories; ++i) {
                    if (strcmp(root->subdirectories[i]->name, name) == 0) {
                        directory_to_rename = root->subdirectories[i];
                        break;
                    }
                }
                if (directory_to_rename != NULL) {
                    printf("Enter the new name for the directory: ");
                    scanf("%s", name);
                    rename_directory(directory_to_rename, name);
                } else {
                    printf("Directory not found.\n");
                }
                break;

            case 5:
                printf("Directory Structure:\n");
                depth_first_traversal(root);
                break;

            case 0:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 0);

    // Clean up memory
    free(root);

    return 0;
}
