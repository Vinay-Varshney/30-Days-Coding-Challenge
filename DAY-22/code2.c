/* C Program to Count words in a sentence */

#include <stdio.h>
#include <ctype.h>  // For isspace()

// Function to count words in a sentence
int countWords(const char *str) {
    int count = 0;
    int inWord = 0; // Flag to track if we are inside a word

    while (*str) {
        if (isspace((unsigned char)*str)) {
            // If current char is space, mark that we are not in a word
            inWord = 0;
        } else {
            // If current char is not space and we were not in a word before
            if (!inWord) {
                count++;
                inWord = 1;
            }
        }
        str++;
    }
    return count;
}

int main() {
    char sentence[500];

    printf("Enter a sentence: ");
    if (!fgets(sentence, sizeof(sentence), stdin)) {
        printf("Error reading input.\n");
        return 1;
    }

    int wordCount = countWords(sentence);
    printf("Number of words: %d\n", wordCount);

    return 0;
}
