#include <stdio.h>
#define MAX_ELEMENTS 100
// Function to find the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to perform the 0/1 knapsack dynamic programming algorithm
void knapsack(int n, int S, int s_i[], int v_i[]) {
    int V[MAX_ELEMENTS + 1][S + 1];

    // Initialize the table
    for (int s = 0; s <= S; s++) {
        V[0][s] = 0;
    }
    for(int i=0;i<=n;i++)
    {
        V[i][0]=0;
    }

    for (int i = 1; i <= n; i++) {
        for (int s = 1; s <= S; s++) {
            if (s_i[i - 1] <= s) {
                if (v_i[i - 1] + V[i - 1][s - s_i[i - 1]] > V[i - 1][s]) {
                    V[i][s] = v_i[i - 1] + V[i - 1][s - s_i[i - 1]];
                } else {
                    V[i][s] = V[i - 1][s];
                }
            } else {
                V[i][s] = V[i - 1][s];
            }
        }
    }

    // Trace back to find the selected elements
    int i = n, k = S;
    printf("Selected elements: ");
    while (i > 0 && k > 0) {
        if (V[i][k] != V[i - 1][k]) {
            printf("%d ", i);
            i = i - 1;
            k = k - s_i[i];
        } else {
            i = i - 1;
        }
    }
    printf("\n");
}

int main() {
    int n, S;

    // Get user input for the number of elements and maximum size of knapsack
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the maximum size of the knapsack: ");
    scanf("%d", &S);

    int s_i[MAX_ELEMENTS], v_i[MAX_ELEMENTS];

    // Get user input for the size and value of each element
    printf("Enter the size and value of each element:\n");
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d %d", &s_i[i], &v_i[i]);
    }

    // Call the knapsack function
    knapsack(n, S, s_i, v_i);

    return 0;
}
