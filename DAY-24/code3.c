/* C Program to Find longest word */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to find the longest word in a string
void findLongestWord(const char *str, char *longestWord) {
    int maxLen = 0, currentLen = 0;
    char currentWord[100] = "";
    int i = 0;

    while (1) {
        char ch = str[i];

        // Check if character is alphabetic (part of a word)
        if (isalpha((unsigned char)ch)) {
            currentWord[currentLen++] = ch;
        } else {
            // End of a word
            if (currentLen > 0) {
                currentWord[currentLen] = '\0'; // Null-terminate

                if (currentLen > maxLen) {
                    maxLen = currentLen;
                    strcpy(longestWord, currentWord);
                }
                currentLen = 0; // Reset for next word
            }
        }

        if (ch == '\0') break; // End of string
        i++;
    }
}

int main() {
    char str[200];
    char longestWord[100] = "";

    printf("Enter a sentence: ");
    if (fgets(str, sizeof(str), stdin) == NULL) {
        printf("Error reading input.\n");
        return 1;
    }

    // Remove trailing newline if present
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }

    // Handle empty input
    if (strlen(str) == 0) {
        printf("No input provided.\n");
        return 0;
    }

    findLongestWord(str, longestWord);

    if (strlen(longestWord) > 0) {
        printf("Longest word: %s\n", longestWord);
        printf("Length: %zu\n", strlen(longestWord));
    } else {
        printf("No valid words found.\n");
    }

    return 0;
}
