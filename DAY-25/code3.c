/* C Program to Sort names alphabetically */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAMES 100     // Maximum number of names
#define MAX_LENGTH 100    // Maximum length of each name

// Function to trim newline character from fgets input
void trim_newline(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

// Function to convert string to lowercase for case-insensitive sorting
void to_lowercase(char *dest, const char *src) {
    while (*src) {
        *dest++ = tolower((unsigned char)*src++);
    }
    *dest = '\0';
}

int main() {
    char names[MAX_NAMES][MAX_LENGTH];
    char temp[MAX_LENGTH];
    int n;

    printf("Enter number of names (max %d): ", MAX_NAMES);
    if (scanf("%d", &n) != 1 || n <= 0 || n > MAX_NAMES) {
        printf("Invalid number of names.\n");
        return 1;
    }

    getchar(); // Clear newline from input buffer

    // Input names
    for (int i = 0; i < n; i++) {
        printf("Enter name %d: ", i + 1);
        if (fgets(names[i], sizeof(names[i]), stdin) == NULL) {
            printf("Error reading name.\n");
            return 1;
        }
        trim_newline(names[i]);
        if (strlen(names[i]) == 0) {
            printf("Empty name is not allowed.\n");
            return 1;
        }
    }

    // Sort names alphabetically (case-insensitive)
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            char lower_i[MAX_LENGTH], lower_j[MAX_LENGTH];
            to_lowercase(lower_i, names[i]);
            to_lowercase(lower_j, names[j]);

            if (strcmp(lower_i, lower_j) > 0) {
                strcpy(temp, names[i]);
                strcpy(names[i], names[j]);
                strcpy(names[j], temp);
            }
        }
    }

    // Display sorted names
    printf("\nNames in alphabetical order:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", names[i]);
    }

    return 0;
}
