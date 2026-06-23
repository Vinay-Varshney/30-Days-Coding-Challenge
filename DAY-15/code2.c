/* C Program to Rotate an array left */

#include <stdio.h>
#include <stdlib.h>

// Function to reverse a portion of the array
void reverse(int arr[], int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

// Function to left rotate the array by d positions
void leftRotate(int arr[], int n, int d) {
    if (n <= 0) return; // Empty array case
    d = d % n; // Handle rotations greater than array size
    if (d == 0) return; // No rotation needed

    // Step 1: Reverse first d elements
    reverse(arr, 0, d - 1);
    // Step 2: Reverse remaining n-d elements
    reverse(arr, d, n - 1);
    // Step 3: Reverse the whole array
    reverse(arr, 0, n - 1);
}

int main() {
    int n, d;

    printf("Enter number of elements in array: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid size.\n");
        return 1;
    }

    int *arr = (int *)malloc(n * sizeof(int));
    if (!arr) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input.\n");
            free(arr);
            return 1;
        }
    }

    printf("Enter number of positions to rotate left: ");
    if (scanf("%d", &d) != 1 || d < 0) {
        printf("Invalid rotation count.\n");
        free(arr);
        return 1;
    }

    leftRotate(arr, n, d);

    printf("Array after left rotation: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}