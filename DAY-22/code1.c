/* C Program to Check palindrome */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to remove newline character from fgets input
void removeNewline(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

// Function to check if a string is a palindrome (case-insensitive)
int isPalindrome(const char *str) {
    int left = 0;
    int right = strlen(str) - 1;

    while (left < right) {
        // Skip non-alphanumeric characters
        while (left < right && !isalnum((unsigned char)str[left])) left++;
        while (left < right && !isalnum((unsigned char)str[right])) right--;

        // Compare ignoring case
        if (tolower((unsigned char)str[left]) != tolower((unsigned char)str[right])) {
            return 0; // Not a palindrome
        }
        left++;
        right--;
    }
    return 1; // Palindrome
}

int main() {
    char input[256];

    printf("Enter a string or number: ");
    if (fgets(input, sizeof(input), stdin) == NULL) {
        printf("Error reading input.\n");
        return 1;
    }

    removeNewline(input);

    if (strlen(input) == 0) {
        printf("Empty input is not valid.\n");
        return 1;
    }

    if (isPalindrome(input)) {
        printf("\"%s\" is a palindrome.\n", input);
    } else {
        printf("\"%s\" is not a palindrome.\n", input);
    }

    return 0;
}
