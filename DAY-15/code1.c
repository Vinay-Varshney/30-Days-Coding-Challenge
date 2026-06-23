/* C Program to Reverse an array */

#include <stdio.h>
#include <stdlib.h>

// Function to reverse the array in-place
void reverseArray(int arr[], int size) {
    int start = 0, end = size - 1;
    while (start < end) {
        // Swap elements at start and end
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++;
        end--;
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;

    // Input array size
    printf("Enter number of elements in the array: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input. Please enter a positive integer.\n");
        return 1;
    }

    int arr[n];

    // Input array elements
    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input. Please enter integers only.\n");
            return 1;
        }
    }

    // Display original array
    printf("Original array: ");
    printArray(arr, n);

    // Reverse the array
    reverseArray(arr, n);

    // Display reversed array
    printf("Reversed array: ");
    printArray(arr, n);

    return 0;
}