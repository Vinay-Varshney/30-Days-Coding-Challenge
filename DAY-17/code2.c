/* C Program to write Union of arrays */

#include <stdio.h>

int main() {
    int arr1[50], arr2[50], unionArr[100];
    int n1, n2, i, j, k = 0;
    int isDuplicate;

    // Input first array
    printf("Enter size of first array: ");
    scanf("%d", &n1);
    printf("Enter elements of first array: ");
    for (i = 0; i < n1; i++) {
        scanf("%d", &arr1[i]);
        unionArr[k++] = arr1[i]; // Add directly to union array
    }

    // Input second array
    printf("Enter size of second array: ");
    scanf("%d", &n2);
    printf("Enter elements of second array: ");
    for (i = 0; i < n2; i++) {
        scanf("%d", &arr2[i]);
    }

    // Add elements from second array if not already in unionArr
    for (i = 0; i < n2; i++) {
        isDuplicate = 0;
        for (j = 0; j < k; j++) {
            if (arr2[i] == unionArr[j]) {
                isDuplicate = 1;
                break;
            }
        }
        if (!isDuplicate) {
            unionArr[k++] = arr2[i];
        }
    }

    // Output union array
    printf("Union of the two arrays: ");
    for (i = 0; i < k; i++) {
        printf("%d ", unionArr[i]);
    }
    printf("\n");

    return 0;
}
