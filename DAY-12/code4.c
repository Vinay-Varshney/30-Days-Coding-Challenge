/* C Program to write function for perfect number */

#include <stdio.h>

/**
 * Function: isPerfect
 * Description: Checks if a number is a perfect number.
 * Parameters: num - The integer to check.
 * Returns: 1 if the number is perfect, 0 otherwise.
 */
int isPerfect(int num) {
    // 0, negative numbers, and 1 cannot be perfect numbers
    if (num <= 1) {
        return 0;
    }

    int sum = 0;

    // Loop through possible proper divisors up to num / 2
    for (int i = 1; i <= num / 2; i++) {
        if (num % i == 0) {
            sum += i; // Add divisor to sum
        }
    }

    // If sum of proper divisors equals the original number, it's perfect
    if (sum == num) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int number;

    // Prompt user for input
    printf("Enter a positive integer: ");
    if (scanf("%d", &number) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    // Call the isPerfect function and display the result
    if (isPerfect(number)) {
        printf("%d is a perfect number.\n", number);
    } else {
        printf("%d is NOT a perfect number.\n", number);
    }

    return 0;
}