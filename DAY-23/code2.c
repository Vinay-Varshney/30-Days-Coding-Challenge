/* C Program to Find first repeating character */

#include <stdio.h>
#include <string.h>

#define ASCII_SIZE 256  // Total possible ASCII characters

// Function to find the first repeating character
char firstRepeatingChar(const char *str) {
    int seen[ASCII_SIZE] = {0}; // Array to track occurrences

    for (int i = 0; str[i] != '\0'; i++) {
        unsigned char ch = (unsigned char)str[i]; // Handle extended ASCII safely
        if (seen[ch] == 1) {
            return ch; // Found first repeating character
        }
        seen[ch] = 1;
    }
    return '\0'; // No repeating character found
}

int main() {
    char str[1000];

    printf("Enter a string: ");
    if (fgets(str, sizeof(str), stdin) == NULL) {
        printf("Error reading input.\n");
        return 1;
    }

    // Remove trailing newline if present
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }

    if (strlen(str) == 0) {
        printf("Empty string entered.\n");
        return 0;
    }

    char result = firstRepeatingChar(str);

    if (result != '\0') {
        printf("First repeating character: '%c'\n", result);
    } else {
        printf("No repeating characters found.\n");
    }

    return 0;
}
