/* C Program to Find pair with given sum */

#include <stdio.h>
#include <stdlib.h>

// Function to find and print a pair with the given sum
void findPairWithSum(int arr[], int size, int target) {
    int *hashTable = (int *)calloc(100000, sizeof(int)); // Simple hash table for positive/negative numbers
    if (!hashTable) {
        printf("Memory allocation failed.\n");
        return;
    }

    int found = 0;
    for (int i = 0; i < size; i++) {
        int complement = target - arr[i];

        // Check if complement exists in hash table
        if (hashTable[complement + 50000] > 0) { // Offset for negative numbers
            printf("Pair found: (%d, %d)\n", complement, arr[i]);
            found = 1;
            break; // Remove this break if you want all pairs
        }
        // Mark current number as seen
        hashTable[arr[i] + 50000] = 1;
    }

    if (!found) {
        printf("No pair found with sum %d.\n", target);
    }

    free(hashTable);
}

int main() {
    int n, target;

    printf("Enter number of elements in array: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input. Please enter a positive integer.\n");
        return 1;
    }

    int arr[n];
    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input. Please enter integers only.\n");
            return 1;
        }
    }

    printf("Enter target sum: ");
    if (scanf("%d", &target) != 1) {
        printf("Invalid input. Please enter an integer.\n");
        return 1;
    }

    findPairWithSum(arr, n, target);

    return 0;
}

/* Enter number of elements in array: 5
Enter 5 integers: 1 3 4 5 6 
Enter target sum: 7
Pair found: (3, 4)  */