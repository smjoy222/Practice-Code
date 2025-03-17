#include <stdio.h>

// Merge two subarrays of arr[]
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r, int *iterations) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temporary arrays
    int L[n1], R[n2];

    // Copy data to temporary arrays L[] and R[]
    for (i = 0; i < n1; i++) {
        L[i] = arr[l + i];
        (*iterations)++;
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
        (*iterations)++;
    }

    // Merge the temporary arrays back into arr[l..r]
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
        (*iterations)++;
    }

    // Copy the remaining elements of L[], if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Main function to perform Merge Sort in ascending order
void mergeSortAscending(int arr[], int l, int r, int *iterations) {
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for large l and r
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSortAscending(arr, l, m, iterations);
        mergeSortAscending(arr, m + 1, r, iterations);

        // Merge the sorted halves
        merge(arr, l, m, r, iterations);
    }
}

// Main function to perform Merge Sort in descending order
void mergeSortDescending(int arr[], int l, int r, int *iterations) {
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for large l and r
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSortDescending(arr, l, m, iterations);
        mergeSortDescending(arr, m + 1, r, iterations);

        // Merge the sorted halves
        merge(arr, l, m, r, iterations);
    }
}

int main() {
    int n;
    printf("Enter Size: ");
    scanf("%d", &n);
    int arr[n];

    printf("Enter The array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]); // Use &arr[i] instead of &arr[n]
    }

    int iterations_asc = 0;
    int iterations_desc = 0;

    // Sort in ascending order
    mergeSortAscending(arr, 0, n - 1, &iterations_asc);
    printf("Sorted array in ascending order: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("Iterations for ascending order: %d\n", iterations_asc);

    // Sort in descending order
    mergeSortDescending(arr, 0, n - 1, &iterations_desc);
    printf("Sorted array in descending order: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("Iterations for descending order: %d\n", iterations_desc);

    return 0;
}
