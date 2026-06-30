/* C Program to Sort words by length */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_LEN   50

// Function to swap two strings
void swap(char str1[], char str2[]) {
    char temp[MAX_LEN];
    strcpy(temp, str1);
    strcpy(str1, str2);
    strcpy(str2, temp);
}

// Stable sort by length (Bubble Sort)
void sortByLength(char words[][MAX_LEN], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (strlen(words[j]) > strlen(words[j + 1])) {
                swap(words[j], words[j + 1]);
            }
        }
    }
}

int main() {
    char words[MAX_WORDS][MAX_LEN];
    int count = 0;

    printf("Enter words (type 'END' to stop):\n");

    // Read words until "END" or limit reached
    while (count < MAX_WORDS) {
        if (scanf("%49s", words[count]) != 1) {
            printf("Input error.\n");
            return 1;
        }
        if (strcmp(words[count], "END") == 0) {
            break;
        }
        count++;
    }

    if (count == 0) {
        printf("No words entered.\n");
        return 0;
    }

    // Sort words by length
    sortByLength(words, count);

    // Display sorted words
    printf("\nWords sorted by length:\n");
    for (int i = 0; i < count; i++) {
        printf("%s\n", words[i]);
    }

    return 0;
}
