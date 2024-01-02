#include <stdio.h>
#include <math.h>

int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    // Get the number of stores.
    int n,i;
    scanf("%d", &n);

    // Read the stores' positions.
    int stores[n];
    for (i = 0; i < n; i++) {
        scanf("%d", &stores[i]);
    }

    // Initialize the minimum distance.
    int min_distance = 0;

    // For each store, calculate the distance between the store and the current position,
    // and update the minimum distance accordingly.
    int current_position = 0;
    for ( i = 0; i < n; i++) {
        int distance = abs(current_position - stores[i]);

        min_distance = min(min_distance, distance);
        current_position = stores[i];
    }

    // Print the minimum distance.
    printf("%d\n", min_distance);

    return 0;
}


