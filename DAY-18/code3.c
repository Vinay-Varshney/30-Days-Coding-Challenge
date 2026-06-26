/* C Program to Write Binary search */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to check if the array is sorted in ascending order
bool isSorted(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1]) {
            return false;
        }
    }
    return true;
}

// Iterative Binary Search
int binarySearchIterative(int arr[], int n, int target) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2; // Prevents overflow
        if (arr[mid] == target)
            return mid; // Found
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1; // Not found
}

// Recursive Binary Search
int binarySearchRecursive(int arr[], int left, int right, int target) {
    if (left > right)
        return -1; // Not found

    int mid = left + (right - left) / 2;
    if (arr[mid] == target)
        return mid;
    else if (arr[mid] < target)
        return binarySearchRecursive(arr, mid + 1, right, target);
    else
        return binarySearchRecursive(arr, left, mid - 1, target);
}

int main() {
    int n, target;

    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid size. Must be a positive integer.\n");
        return 1;
    }

    int arr[n];
    printf("Enter %d integers in sorted order: ", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input. Please enter integers only.\n");
            return 1;
        }
    }

    // Check if array is sorted
    if (!isSorted(arr, n)) {
        printf("Error: Array must be sorted in ascending order for binary search.\n");
        return 1;
    }

    printf("Enter the element to search: ");
    if (scanf("%d", &target) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    // Iterative Search
    int indexIter = binarySearchIterative(arr, n, target);
    if (indexIter != -1)
        printf("[Iterative] Element found at index %d\n", indexIter);
    else
        printf("[Iterative] Element not found.\n");

    // Recursive Search
    int indexRec = binarySearchRecursive(arr, 0, n - 1, target);
    if (indexRec != -1)
        printf("[Recursive] Element found at index %d\n", indexRec);
    else
        printf("[Recursive] Element not found.\n");

    return 0;
}
