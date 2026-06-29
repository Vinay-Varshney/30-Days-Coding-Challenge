/* C Program to Convert lowercase to uppercase */

#include <stdio.h>
#include <ctype.h>   // For toupper()
#include <string.h>  // For strlen()

#define MAX_LEN 200  // Maximum string length

int main() {
    char str[MAX_LEN];

    printf("Enter a string: ");

    // Read input safely (including spaces)
    if (fgets(str, sizeof(str), stdin) == NULL) {
        printf("Error reading input.\n");
        return 1;
    }

    // Remove trailing newline if present
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }

    // Convert each character to uppercase
    for (size_t i = 0; str[i] != '\0'; i++) {
        str[i] = (char)toupper((unsigned char)str[i]);
    }

    printf("Uppercase string: %s\n", str);

    return 0;
}
