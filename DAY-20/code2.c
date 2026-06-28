/* C Program to Check symmetric matrix */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to check if a matrix is symmetric
bool isSymmetric(int matrix[50][50], int rows, int cols) {
    // Symmetric matrix must be square
    if (rows != cols) {
        return false;
    }

    // Compare elements with their transpose
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int matrix[50][50];
    int rows, cols;

    // Input matrix dimensions
    printf("Enter number of rows and columns: ");
    if (scanf("%d %d", &rows, &cols) != 2 || rows <= 0 || cols <= 0 || rows > 50 || cols > 50) {
        printf("Invalid input. Please enter positive integers (max 50).\n");
        return 1;
    }

    // Input matrix elements
    printf("Enter elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (scanf("%d", &matrix[i][j]) != 1) {
                printf("Invalid input. Please enter integers only.\n");
                return 1;
            }
        }
    }

    // Check and display result
    if (isSymmetric(matrix, rows, cols)) {
        printf("The matrix is symmetric.\n");
    } else {
        printf("The matrix is NOT symmetric.\n");
    }

    return 0;
}
