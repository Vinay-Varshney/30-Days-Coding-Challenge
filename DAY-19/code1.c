/* C Program to Add matrices */

#include <stdio.h>
#include <stdlib.h>

// Function to safely read an integer
int readInt(const char *prompt) {
    int value;
    printf("%s", prompt);
    while (scanf("%d", &value) != 1) {
        // Clear invalid input
        while (getchar() != '\n');
        printf("Invalid input. Please enter an integer: ");
    }
    return value;
}

int main() {
    int rows, cols;

    // Read matrix dimensions
    rows = readInt("Enter number of rows: ");
    cols = readInt("Enter number of columns: ");

    if (rows <= 0 || cols <= 0) {
        printf("Matrix dimensions must be positive integers.\n");
        return 1;
    }

    int matrix1[rows][cols], matrix2[rows][cols], sum[rows][cols];

    // Input first matrix
    printf("\nEnter elements of first matrix (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix1[i][j] = readInt("");
        }
    }

    // Input second matrix
    printf("\nEnter elements of second matrix (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix2[i][j] = readInt("");
        }
    }

    // Calculate sum of matrices
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sum[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    // Display result
    printf("\nSum of the two matrices:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", sum[i][j]);
        }
        printf("\n");
    }

    return 0;
}
