/* C Program to Create menu-driven array operations system */

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100  // Maximum array size

// Function prototypes
void insertElement(int arr[], int *n);
void deleteElement(int arr[], int *n);
void searchElement(int arr[], int n);
void displayArray(int arr[], int n);

int main() {
    int arr[MAX_SIZE];
    int n = 0; // Current number of elements
    int choice;

    while (1) {
        // Menu display
        printf("\n===== Array Operations Menu =====\n");
        printf("1. Insert Element\n");
        printf("2. Delete Element\n");
        printf("3. Search Element\n");
        printf("4. Display Array\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");

        // Validate menu choice input
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number between 1 and 5.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        switch (choice) {
            case 1:
                insertElement(arr, &n);
                break;
            case 2:
                deleteElement(arr, &n);
                break;
            case 3:
                searchElement(arr, n);
                break;
            case 4:
                displayArray(arr, n);
                break;
            case 5:
                printf("Exiting program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please select between 1 and 5.\n");
        }
    }
    return 0;
}

// Function to insert an element at a given position
void insertElement(int arr[], int *n) {
    if (*n >= MAX_SIZE) {
        printf("Array is full! Cannot insert more elements.\n");
        return;
    }

    int pos, value;
    printf("Enter position to insert (1 to %d): ", *n + 1);
    if (scanf("%d", &pos) != 1 || pos < 1 || pos > *n + 1) {
        printf("Invalid position!\n");
        while (getchar() != '\n');
        return;
    }

    printf("Enter value to insert: ");
    if (scanf("%d", &value) != 1) {
        printf("Invalid value!\n");
        while (getchar() != '\n');
        return;
    }

    // Shift elements to the right
    for (int i = *n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos - 1] = value;
    (*n)++;
    printf("Element inserted successfully.\n");
}

// Function to delete an element from a given position
void deleteElement(int arr[], int *n) {
    if (*n == 0) {
        printf("Array is empty! Nothing to delete.\n");
        return;
    }

    int pos;
    printf("Enter position to delete (1 to %d): ", *n);
    if (scanf("%d", &pos) != 1 || pos < 1 || pos > *n) {
        printf("Invalid position!\n");
        while (getchar() != '\n');
        return;
    }

    // Shift elements to the left
    for (int i = pos - 1; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--;
    printf("Element deleted successfully.\n");
}

// Function to search for an element
void searchElement(int arr[], int n) {
    if (n == 0) {
        printf("Array is empty! Nothing to search.\n");
        return;
    }

    int value, found = 0;
    printf("Enter value to search: ");
    if (scanf("%d", &value) != 1) {
        printf("Invalid value!\n");
        while (getchar() != '\n');
        return;
    }

    for (int i = 0; i < n; i++) {
        if (arr[i] == value) {
            printf("Element found at position %d.\n", i + 1);
            found = 1;
        }
    }
    if (!found) {
        printf("Element not found in the array.\n");
    }
}

// Function to display the array
void displayArray(int arr[], int n) {
    if (n == 0) {
        printf("Array is empty!\n");
        return;
    }

    printf("Array elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
