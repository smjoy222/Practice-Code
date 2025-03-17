#include <stdio.h>

// Function to perform Bubble Sort in ascending order and count iterations
void BubbleSortAscending(int arr[], int n, int *iterations) {
    for (int i = 0; i < n - 1; i++) {
        int swapped = 0; // Flag to optimize the algorithm
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
            (*iterations)++; // Increment the iteration count
        }
        // If no two elements were swapped in inner loop, the array is already sorted
        if (swapped == 0) {
            break;
        }
    }
}

// Function to perform Bubble Sort in descending order and count iterations
void BubbleSortDescending(int arr[], int n, int *iterations) {
    for (int i = 0; i < n - 1; i++) {
        int swapped = 0; // Flag to optimize the algorithm
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
            (*iterations)++; // Increment the iteration count
        }
        // If no two elements were swapped in inner loop, the array is already sorted
        if (swapped == 0) {
            break;
        }
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
    int iterations_desc = 0;

    // Sort in ascending order
    BubbleSortAscending(arr, n, &iterations_asc);
    printf("Sorted array in ascending order: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("Iterations for ascending order: %d\n", iterations_asc);

    // Sort in descending order
    BubbleSortDescending(arr, n, &iterations_desc);
    printf("Sorted array in descending order: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("Iterations for descending order: %d\n", iterations_desc);

    return 0;
}
