#include <stdio.h>

// Function to perform the partition step of Quick Sort
int partition(int arr[], int low, int high, int *iterations) {
    int pivot = arr[low];
    int i = low + 1;
    int j = high;

    while (1) {
        while (i <= j && arr[i] <= pivot) {
            i++;
            (*iterations)++; // Increment the iteration count
        }
        while (arr[j] >= pivot && j >= i) {
            j--;
            (*iterations)++; // Increment the iteration count
        }
        if (j < i) {
            break;
        } else {
            // Swap arr[i] and arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Swap pivot with arr[j]
    int temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;

    return j;
}

// Function to perform Quick Sort in ascending order and count iterations
void QuickSortAscending(int arr[], int low, int high, int *iterations) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high, iterations);
        QuickSortAscending(arr, low, pivotIndex - 1, iterations);
        QuickSortAscending(arr, pivotIndex + 1, high, iterations);
    }
}

// Function to perform Quick Sort in descending order and count iterations
void QuickSortDescending(int arr[], int low, int high, int *iterations) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high, iterations);
        QuickSortDescending(arr, low, pivotIndex - 1, iterations);
        QuickSortDescending(arr, pivotIndex + 1, high, iterations);
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
    QuickSortAscending(arr, 0, n - 1, &iterations_asc);
    printf("Sorted array in ascending order: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("Iterations for ascending order: %d\n", iterations_asc);

    // Sort in descending order
    QuickSortDescending(arr, 0, n - 1, &iterations_desc);
    printf("Sorted array in descending order: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("Iterations for descending order: %d\n", iterations_desc);

    return 0;
}
