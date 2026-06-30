/* C Program to Create voting eligibility system */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Function to clear input buffer
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

int main() {
    int age;
    char name[100];

    printf("=== Voting Eligibility System ===\n");

    // Get user's name
    printf("Enter your name: ");
    if (fgets(name, sizeof(name), stdin) == NULL) {
        printf("Error reading name.\n");
        return 1;
    }

    // Remove newline character from name if present
    for (int i = 0; name[i] != '\0'; i++) {
        if (name[i] == '\n') {
            name[i] = '\0';
            break;
        }
    }

    // Get user's age with validation
    printf("Enter your age: ");
    if (scanf("%d", &age) != 1) {
        printf("Invalid input. Please enter a valid number for age.\n");
        return 1;
    }

    if (age < 0 || age > 150) {
        printf("Invalid age entered. Please enter a realistic age.\n");
        return 1;
    }

    // Check voting eligibility
    if (age >= 18) {
        printf("Hello %s, you are eligible to vote.\n", name);
    } else {
        printf("Hello %s, you are NOT eligible to vote. You need to wait %d more year(s).\n",
               name, 18 - age);
    }

    return 0;
}
