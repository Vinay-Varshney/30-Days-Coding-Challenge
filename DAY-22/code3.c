/* C Program to check Character frequency */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 1000  // Maximum string length

int main() {
    char str[MAX_LEN];
    int freq[256] = {0}; // Frequency array for all ASCII characters
    int i, length;

    // Input string
    printf("Enter a string: ");
    if (fgets(str, sizeof(str), stdin) == NULL) {
        printf("Error reading input.\n");
        return 1;
    }

    // Remove trailing newline if present
    length = strlen(str);
    if (length > 0 && str[length - 1] == '\n') {
        str[length - 1] = '\0';
        length--;
    }

    // Count frequency of each character
    for (i = 0; i < length; i++) {
        unsigned char ch = (unsigned char)str[i];
        freq[ch]++;
    }

    // Display frequencies
    printf("\nCharacter frequencies:\n");
    for (i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            if (isprint(i)) // Printable characters
                printf("'%c' : %d\n", i, freq[i]);
            else
                printf("'0x%02X' : %d\n", i, freq[i]); // Non-printable in hex
        }
    }

    return 0;
}
