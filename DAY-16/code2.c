/* C Program to Find maximum frequency element */

#include <stdio.h>
#include <stdlib.h>

// Function to find the most frequent element
int mostFrequentElement(int arr[], int n) {
    int maxCount = 0;
    int mostFrequent = arr[0];

    for (int i = 0; i < n; i++) {
        int count = 0;

        // Count frequency of arr[i]
        for (int j = 0; j < n; j++) {
            if (arr[j] == arr[i]) {
                count++;
            }
        }

        // Update if higher frequency found
        // If tie, choose the larger element
        if (count > maxCount || (count == maxCount && arr[i] > mostFrequent)) {
            maxCount = count;
            mostFrequent = arr[i];
        }
    }

    return mostFrequent;
}

int main() {
    int n;

    printf("Enter number of elements: ");
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

    int result = mostFrequentElement(arr, n);
    printf("Most frequent element: %d\n", result);

    return 0;
}

/* Enter number of elements: 5
Enter 5 integers: 1 2 2 5 7 
Most frequent element: 2  */