/* C Program to Find row-wise sum */

#include <stdio.h>

#define MAX 50  // Maximum allowed rows and columns

int main() {
    int rows, cols;
    int matrix[MAX][MAX];
    int i, j;

    // Input number of rows and columns
    printf("Enter number of rows (1-%d): ", MAX);
    if (scanf("%d", &rows) != 1 || rows <= 0 || rows > MAX) {
        printf("Invalid number of rows.\n");
        return 1;
    }

    printf("Enter number of columns (1-%d): ", MAX);
    if (scanf("%d", &cols) != 1 || cols <= 0 || cols > MAX) {
        printf("Invalid number of columns.\n");
        return 1;
    }

    // Input matrix elements
    printf("Enter %d elements of the matrix:\n", rows * cols);
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (scanf("%d", &matrix[i][j]) != 1) {
                printf("Invalid input. Please enter integers only.\n");
                return 1;
            }
        }
    }

    // Calculate and display row-wise sum
    printf("\nRow-wise sums:\n");
    for (i = 0; i < rows; i++) {
        int sum = 0;
        for (j = 0; j < cols; j++) {
            sum += matrix[i][j];
        }
        printf("Sum of row %d = %d\n", i + 1, sum);
    }

    return 0;
}
