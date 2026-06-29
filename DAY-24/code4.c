/* C Program to Remove duplicate characters */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to remove duplicate characters from a string
void removeDuplicates(char *str) {
    int len = strlen(str);
    if (len == 0) return;

    int index = 0; // Index for placing unique characters
    int seen[256] = {0}; // ASCII character tracker

    for (int i = 0; i < len; i++) {
        unsigned char ch = str[i];
        if (!seen[ch]) { // If character not seen before
            seen[ch] = 1;
            str[index++] = ch;
        }
    }
    str[index] = '\0'; // Null-terminate the result
}

int main() {
    char str[256];

    printf("Enter a string: ");
    if (fgets(str, sizeof(str), stdin) == NULL) {
        printf("Error reading input.\n");
        return 1;
    }

    // Remove newline character from fgets
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }

    removeDuplicates(str);

    printf("String after removing duplicates: %s\n", str);

    return 0;
}
