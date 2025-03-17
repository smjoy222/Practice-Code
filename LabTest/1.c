#include <stdio.h>
#include <string.h>

int main() {
    char str[100];  
    int length = 0; 

    printf("Enter a string: ");
    gets(str);

    length = strlen(str);
    printf("Length of String: %d\n", length);

    return 0;
}