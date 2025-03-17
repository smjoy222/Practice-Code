#include <stdio.h>

// Function to perform insertion sort in ascending order
void InsertionSortAscending(int arr[], int n, int *iterations) {
    for (int i = 1; i < n; i++) {
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j = j - 1;
            (*iterations)++; // Increment the iteration count
        }
        arr[j + 1] = temp;
    }
}

// Function to perform insertion sort in descending order
void InsertionSortDescending(int arr[], int n, int *iterations) {
    for (int i = 1; i < n; i++) {
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] < temp) { // Change the comparison to sort in descending order
            arr[j + 1] = arr[j];
            j = j - 1;
            (*iterations)++; // Increment the iteration count
        }
        arr[j + 1] = temp;
    }
}

int main() {
    int n;
    printf("Enter Size: ");
    scanf("%d", &n);
    int arr[n];

    printf("Enter The array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int iterations_asc = 0;
    // Sort in ascending order
    InsertionSortAscending(arr, n, &iterations_asc);

    printf("Sorted array in ascending order: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("Iterations for ascending order: %d\n", iterations_asc);

    int iterations_desc = 0;
    // Sort in descending order
    InsertionSortDescending(arr, n, &iterations_desc);

    printf("Sorted array in descending order: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("Iterations for descending order: %d\n", iterations_desc);

    return 0;
}
