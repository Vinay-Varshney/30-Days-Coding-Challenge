/* C Program to Remove spaces from string */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to remove all spaces from a string
void removeSpaces(char *str) {
    int i = 0, j = 0;

    // Loop through each character
    while (str[i] != '\0') {
        if (str[i] != ' ') { // Copy only non-space characters
            str[j++] = str[i];
        }
        i++;
    }
    str[j] = '\0'; // Null-terminate the modified string
}

int main() {
    char str[256]; // Buffer for input string

    printf("Enter a string: ");
    if (fgets(str, sizeof(str), stdin) == NULL) {
        printf("Error reading input.\n");
        return 1;
    }

    // Remove newline character from fgets if present
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }

    // Remove spaces
    removeSpaces(str);

    printf("String without spaces: \"%s\"\n", str);

    return 0;
}
