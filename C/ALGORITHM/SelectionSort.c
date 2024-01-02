#include <stdio.h>

// Function to perform selection sort in ascending order and count iterations
void SelectionSortAscending(int arr[], int n, int *iterations) {
    for (int i = 0; i < n - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
                (*iterations)++; // Increment the iteration count
            }
        }
        // Swap the minimum element with the current element
        if(min_index!=i){
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
        }
    }
}

// Function to perform selection sort in descending order and count iterations
void SelectionSortDescending(int arr[], int n, int *iterations) {
    for (int i = 0; i < n - 1; i++) {
        int max_index = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[max_index]) {
                max_index = j;
                (*iterations)++; // Increment the iteration count
            }
        }
        // Swap the maximum element with the current element
        if(max_index!=0){
        int temp = arr[i];
        arr[i] = arr[max_index];
        arr[max_index] = temp;
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
    SelectionSortAscending(arr, n, &iterations_asc);
    printf("Sorted array in ascending order: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("Iterations for ascending order: %d\n", iterations_asc);

    // Sort in descending order
    SelectionSortDescending(arr, n, &iterations_desc);
    printf("Sorted array in descending order: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("Iterations for descending order: %d\n", iterations_desc);

    return 0;
}
