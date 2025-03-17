#include <stdio.h>

int main () {
    int x;
    scanf("%d", &x);

    int total_cells = 0;

    if (x == 1) {
        total_cells = 1;
    } else {
        total_cells = 2 * x * (x - 1) + 1;
    }

    printf("%d\n", total_cells);

    return 0;
}