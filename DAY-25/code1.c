/* C program to Merge two sorted arrays */

#include <stdio.h>
#include <stdlib.h>

// Function to merge two sorted arrays into a single sorted array
void mergeSortedArrays(int arr1[], int n1, int arr2[], int n2, int merged[]) {
    int i = 0, j = 0, k = 0;

    // Merge elements until one array is exhausted
    while (i < n1 && j < n2) {
        if (arr1[i] <= arr2[j]) {
            merged[k++] = arr1[i++];
        } else {
            merged[k++] = arr2[j++];
        }
    }

    // Copy remaining elements from arr1 (if any)
    while (i < n1) {
        merged[k++] = arr1[i++];
    }

    // Copy remaining elements from arr2 (if any)
    while (j < n2) {
        merged[k++] = arr2[j++];
    }
}

int main() {
    int n1, n2;

    // Input size of first array
    printf("Enter size of first sorted array: ");
    if (scanf("%d", &n1) != 1 || n1 < 0) {
        printf("Invalid size.\n");
        return 1;
    }

    int arr1[n1];
    printf("Enter %d elements (sorted in ascending order): ", n1);
    for (int i = 0; i < n1; i++) {
        if (scanf("%d", &arr1[i]) != 1) {
            printf("Invalid input.\n");
            return 1;
        }
    }

    // Input size of second array
    printf("Enter size of second sorted array: ");
    if (scanf("%d", &n2) != 1 || n2 < 0) {
        printf("Invalid size.\n");
        return 1;
    }

    int arr2[n2];
    printf("Enter %d elements (sorted in ascending order): ", n2);
    for (int i = 0; i < n2; i++) {
        if (scanf("%d", &arr2[i]) != 1) {
            printf("Invalid input.\n");
            return 1;
        }
    }

    // Array to store merged result
    int merged[n1 + n2];

    // Merge the arrays
    mergeSortedArrays(arr1, n1, arr2, n2, merged);

    // Display merged array
    printf("Merged sorted array: ");
    for (int i = 0; i < n1 + n2; i++) {
        printf("%d ", merged[i]);
    }
    printf("\n");

    return 0;
}
