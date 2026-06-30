/* C Program to Find common characters in strings */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_STRINGS 50
#define MAX_LEN 100

// Function to find common characters in n strings
void findCommonChars(char strings[][MAX_LEN], int n) {
    int freq[256] = {0}; // Frequency array for ASCII characters
    int i, j;

    // Initialize frequency with first string's characters
    for (i = 0; strings[0][i] != '\0'; i++) {
        unsigned char ch = strings[0][i];
        freq[ch] = 1; // Mark as present in first string
    }

    // Update frequency for remaining strings
    for (i = 1; i < n; i++) {
        int temp[256] = {0}; // Temporary array for current string
        for (j = 0; strings[i][j] != '\0'; j++) {
            unsigned char ch = strings[i][j];
            if (freq[ch] == i) { // Only update if it was present in all previous strings
                temp[ch] = 1;
            }
        }
        // Update freq array for characters present in current string
        for (j = 0; j < 256; j++) {
            if (temp[j]) {
                freq[j] = i + 1;
            }
        }
    }

    // Print common characters
    int found = 0;
    printf("Common characters: ");
    for (i = 0; i < 256; i++) {
        if (freq[i] == n) {
            printf("%c ", i);
            found = 1;
        }
    }
    if (!found) {
        printf("None");
    }
    printf("\n");
}

int main() {
    int n, i;
    char strings[MAX_STRINGS][MAX_LEN];

    printf("Enter number of strings: ");
    if (scanf("%d", &n) != 1 || n <= 0 || n > MAX_STRINGS) {
        printf("Invalid number of strings.\n");
        return 1;
    }

    getchar(); // Clear newline from buffer

    printf("Enter %d strings:\n", n);
    for (i = 0; i < n; i++) {
        if (!fgets(strings[i], sizeof(strings[i]), stdin)) {
            printf("Error reading string.\n");
            return 1;
        }
        strings[i][strcspn(strings[i], "\n")] = '\0'; // Remove newline
    }

    findCommonChars(strings, n);

    return 0;
}
