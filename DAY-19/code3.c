/* C Program to Transpose matrix */

#include <stdio.h>
#include <stdlib.h>

#define MAX 50 // Maximum allowed rows/columns

// Function to read a matrix from user
void readMatrix(int matrix[MAX][MAX], int rows, int cols) {
    printf("Enter elements of the matrix (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (scanf("%d", &matrix[i][j]) != 1) {
                printf("Invalid input. Please enter integers only.\n");
                exit(1);
            }
        }
    }
}

// Function to print a matrix
void printMatrix(int matrix[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to find transpose of a matrix
void transposeMatrix(int matrix[MAX][MAX], int transpose[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }
}

int main() {
    int matrix[MAX][MAX], transposed[MAX][MAX];
    int rows, cols;

    // Input matrix dimensions
    printf("Enter number of rows and columns (max %d): ", MAX);
    if (scanf("%d %d", &rows, &cols) != 2 || rows <= 0 || cols <= 0 || rows > MAX || cols > MAX) {
        printf("Invalid matrix size.\n");
        return 1;
    }

    // Read matrix
    readMatrix(matrix, rows, cols);

    // Display original matrix
    printf("\nOriginal Matrix:\n");
    printMatrix(matrix, rows, cols);

    // Compute transpose
    transposeMatrix(matrix, transposed, rows, cols);

    // Display transposed matrix
    printf("\nTransposed Matrix:\n");
    printMatrix(transposed, cols, rows);

    return 0;
}
