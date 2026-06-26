/*C Program to write Selection sort */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to perform Selection Sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        // Find the index of the smallest element in the remaining array
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swap if a smaller element is found
        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

// Function to safely read an integer
bool readInt(int *num) {
    return scanf("%d", num) == 1;
}

int main() {
    int n;

    printf("Enter number of elements: ");
    if (!readInt(&n) || n <= 0) {
        printf("Invalid input. Please enter a positive integer.\n");
        return 1;
    }

    int arr[n];
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        if (!readInt(&arr[i])) {
            printf("Invalid input. Please enter integers only.\n");
            return 1;
        }
    }

    selectionSort(arr, n);

    printf("Sorted array in ascending order:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
