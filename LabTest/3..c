#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1000

int max(int a, int b) {
    return (a > b) ? a : b;
}

void longest_common_subsequence(char str1[MAX_LENGTH], char str2[MAX_LENGTH]) {
    int m = strlen(str1);
    int n = strlen(str2);
    int dp[m + 1][n + 1];

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    int lcs_length = dp[m][n];
    char lcs[lcs_length + 1];
    lcs[lcs_length] = '\0';

    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (str1[i - 1] == str2[j - 1]) {
            lcs[--lcs_length] = str1[i - 1];
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }


    printf("%s\n", lcs);
}

int main() {
    int n;
    scanf("%d", &n);

    char enchanted_strings[n][MAX_LENGTH];


    for (int i = 0; i < n; i++) {
        scanf("%s", enchanted_strings[i]);
    }

 
    if (n > 1) {
        for (int i = 1; i < n; i++) {
            char lcs_result[MAX_LENGTH];
            longest_common_subsequence(enchanted_strings[0], enchanted_strings[i]);
        }
    } else {
        
        printf("%s\n", enchanted_strings[0]);
    }

    return 0;
}
