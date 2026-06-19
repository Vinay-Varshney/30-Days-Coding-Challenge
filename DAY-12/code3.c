/* C Program to write function for fibonacci */

#include <stdio.h>

// Function declaration
void printFibonacci(int terms);

int main() {
    int n;

    printf("Enter the number of terms: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Please enter a valid positive integer.\n");
        return 1;
    }

    printf("Fibonacci Series: ");
    printFibonacci(n);

    return 0;
}

// Function to calculate and print the Fibonacci sequence
void printFibonacci(int terms) {
    long long first = 0, second = 1, next;

    for (int i = 1; i <= terms; i++) {
        // Print the current term
        printf("%lld", first);
        
        // Format the output with commas, except for the last item
        if (i < terms) {
            printf(", ");
        }

        // Calculate the next term in the sequence
        next = first + second;
        first = second;
        second = next;
    }
    printf("\n");
}