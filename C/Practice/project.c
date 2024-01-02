#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define the structure for a student
struct Student {
    int student_id;
    char name[50];
    char email[100];
    char blood_group[4];
};

// Function to filter and print students based on matching ID or blood group
void choose_student(struct Student students[], int n, char filter_type[], char value[]) {
    int found = 0;

    for (int i = 0; i < n; i++) {
        if ((strcmp(filter_type, "id") == 0 && students[i].student_id == atoi(value)) ||
            (strcmp(filter_type, "blood_group") == 0 && strcmp(students[i].blood_group, value) == 0)) {
            found = 1;
            printf("ID: %d, Name: %s, Email: %s, Blood Group: %s\n",
                   students[i].student_id, students[i].name, students[i].email, students[i].blood_group);
        }
    }

    if (!found) {
        printf("No students found with matching %s: %s\n", filter_type, value);
    }
}

int main() {
    // Create an array of 10 students
    struct Student students[10] = {
        {1, "John Doe", "john@example.com", "A+"},
        {2, "Jane Smith", "jane@example.com", "B-"},
        {3, "Alice Johnson", "alice@example.com", "O+"},
        {4, "Bob Brown", "bob@example.com", "A+"},
        {5, "Eva Davis", "eva@example.com", "AB+"},
        {6, "Charlie Wilson", "charlie@example.com", "O-"},
        {7, "Grace Lee", "grace@example.com", "A-"},
        {8, "David Harris", "david@example.com", "B+"},
        {9, "Olivia Martin", "olivia@example.com", "AB-"},
        {10, "Michael Clark", "michael@example.com", "O+"}
    };

    // Example usage:
    choose_student(students, 10, "id", "3");           // Find students with ID 3
    choose_student(students, 10, "blood_group", "A+"); // Find students with blood group A+

    return 0;
}
