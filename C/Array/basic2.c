#include <stdio.h>

int main() {
    int i, sum = 0, num[10];

    for (i = 0; i < 10; i++) {
        num[i] = i + 1; 
    }

    for (i = 0; i < 10; i++) {
        sum = sum + num[i];
    }

    printf("%d", sum);

    return 0;
}
