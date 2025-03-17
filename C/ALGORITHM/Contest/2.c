#include <stdio.h>

// Function to check if a number is palindromic
int isPalindromic(int n) {
    int original = n;
    int reverse = 0;

    while (n > 0) {
        int remainder = n % 10;
        reverse = reverse * 10 + remainder;
        n=n/10;
    }

    return original == reverse;
}

int main() {
    int T;
    scanf("%d", &T);

    for (int caseNum = 1; caseNum <= T; caseNum++) {
        int n;
        scanf("%d", &n);

        if (isPalindromic(n)) {
            printf("Case %d: Yes\n", caseNum);
        } else {
            printf("Case %d: No\n", caseNum);
        }
    }

    return 0;
}
