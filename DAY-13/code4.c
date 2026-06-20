/* C Program to count even and odd elements */

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, evenCount = 0, oddCount = 0;

    // Input: size of the array
    printf("Enter the number of elements in the array: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input. Please enter a positive integer for size.\n");
        return 1;
    }

    int arr[n]; // Variable Length Array (C99+)

    // Input: array elements
    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input. Please enter integers only.\n");
            return 1;
        }
    }

    // Count even and odd numbers
    for (i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            evenCount++;
        } else {
            oddCount++;
        }
    }

    // Output results
    printf("Total Even numbers: %d\n", evenCount);
    printf("Total Odd numbers: %d\n", oddCount);

    return 0;
}

/* Enter the number of elements in the array: 6
Enter 6 integers:
2 5 8 7 0 -3
Total Even numbers: 3
Total Odd numbers: 3  */