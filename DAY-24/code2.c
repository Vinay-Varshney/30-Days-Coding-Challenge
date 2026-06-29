/* C program to Compress a string */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to compress a string using Run-Length Encoding
void compressString(const char *input, char *output) {
    int len = strlen(input);
    int count = 1;
    int j = 0;

    for (int i = 0; i < len; i++) {
        // Copy the current character
        output[j++] = input[i];

        // Count consecutive occurrences
        count = 1;
        while (i + 1 < len && input[i] == input[i + 1]) {
            count++;
            i++;
        }

        // Append count if greater than 1
        if (count > 1) {
            // Convert count to string and append
            char countStr[12]; // Enough for large counts
            sprintf(countStr, "%d", count);
            for (int k = 0; countStr[k] != '\0'; k++) {
                output[j++] = countStr[k];
            }
        }
    }
    output[j] = '\0'; // Null-terminate the compressed string
}

int main() {
    char input[101], output[201]; // Output may be larger if counts are multi-digit

    printf("Enter a string (max 100 characters): ");
    if (scanf("%100s", input) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    // Validate input: only allow printable characters
    for (int i = 0; input[i] != '\0'; i++) {
        if (!isprint((unsigned char)input[i])) {
            printf("Error: String contains non-printable characters.\n");
            return 1;
        }
    }

    compressString(input, output);

    printf("Compressed string: %s\n", output);

    return 0;
}
