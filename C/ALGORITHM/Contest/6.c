
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100001

int main() {
    char s[MAX_LENGTH];
    scanf("%s", s);

    int len = strlen(s);
    int player = 1;  // Player 1 starts the game
    int top = 0;
    char stack[MAX_LENGTH];

    for (int i = 0; i < len; i++) {
        if (top > 0 && stack[top - 1] == s[i]) {
            top--;  // Remove the consecutive letters
            // Switch to the other player's turn
            player = 3 - player;
        } else {
            stack[top++] = s[i];
        }
    }

    if (player == 1) {
        printf("No\n"); // First player couldn't make a move, so second player wins.
    } else {
        printf("Yes\n"); // Second player couldn't make a move, so first player wins.
    }

    return 0;
}


/*
wrong for time limit
#include <stdio.h>
#include <string.h>

int main() {
    char s[100001];
    scanf("%s", s);

    int len = strlen(s);
    int player = 1;  

    for (int i = 0; i < len - 1; i++) {
        if (s[i] == s[i + 1]) {

            for (int j = i; j < len - 2; j++) {
                s[j] = s[j + 2];
            }
            len -= 2;

           
            player = 3 - player;

           
            i = -1;
        }
    }

    if (player == 1) {
        printf("No\n"); 
        printf("Yes\n"); 
    }

    return 0;
}
--------------------------------------------------------------------------------------------------------------------------
wrong for test case 1
include <stdio.h>
#include <string.h>

int main() {
    char s[100001];
    scanf("%s", s);

    int len = strlen(s);
    int player = 1;  // Player 1 starts the game

    for (int i = 0; i < len - 1; i++) {
        if (s[i] == s[i + 1]) {
            // If two consecutive letters are equal, a player can make a move.
            // Remove those two letters from the string.
            for (int j = i; j < len - 2; j++) {
                s[j] = s[j + 2];
            }
            len -= 2;

            // Switch to the other player's turn.
            player = 3 - player;
            
            // Start checking the string from the beginning.
            i = -1;
        }
    }

    if (player == 1) {
        printf("No\n"); // First player couldn't make a move, so second player wins.
    } else {
        printf("Yes\n"); // Second player couldn't make a move, so first player wins.
    }

    return 0;
}

*/