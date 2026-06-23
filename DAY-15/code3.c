/* C Program to Rotate an array right*/

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

// Function to right rotate the array by k positions
void rightRotate(int arr[], int n, int k) {
    if (n <= 1) return; // No rotation needed for size 0 or 1

    k = k % n; // Handle cases where k > n
    if (k == 0) return; // No rotation needed

    // Reverse the whole array
    reverse(arr, 0, n - 1);
    // Reverse first k elements
    reverse(arr, 0, k - 1);
    // Reverse remaining n-k elements
    reverse(arr, k, n - 1);
}

int main() {
    int n, k;

    // Input array size
    printf("Enter number of elements in array: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid size. Must be a positive integer.\n");
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

    // Input rotation count
    printf("Enter number of positions to rotate right: ");
    if (scanf("%d", &k) != 1 || k < 0) {
        printf("Invalid rotation count. Must be a non-negative integer.\n");
        return 1;
    }

    // Perform rotation
    rightRotate(arr, n, k);

    // Output rotated array
    printf("Array after right rotation: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
