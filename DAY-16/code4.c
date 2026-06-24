/* C Program to Remove duplicates from array */

#include <stdio.h>
#include <stdlib.h>

// Function to remove duplicates from an array
int removeDuplicates(int arr[], int n) {
    if (n <= 0) return 0;

    int i, j, k;
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; ) {
            if (arr[i] == arr[j]) {
                // Shift elements left to overwrite duplicate
                for (k = j; k < n - 1; k++) {
                    arr[k] = arr[k + 1];
                }
                n--; // Reduce array size
            } else {
                j++; // Move to next element
            }
        }
    }
    return n; // Return new size
}

int main() {
    int n, i;

    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input. Please enter a positive integer.\n");
        return 1;
    }

    int arr[n];
    printf("Enter %d integers: ", n);
    for (i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input. Please enter integers only.\n");
            return 1;
        }
    }

    // Remove duplicates
    int newSize = removeDuplicates(arr, n);

    // Display result
    printf("Array after removing duplicates: ");
    for (i = 0; i < newSize; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

/* Enter number of elements: 5
Enter 5 integers: 1 2 4 5 2
Array after removing duplicates: 1 2 4 5 */