/*A program for displaying a sparse matrix*/
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int row;
    int col;
    int value;
} SparseMatrixElement;

void displaySparseMatrix(SparseMatrixElement *sparseMatrix, int nonZeroCount) {
    printf("Row\tColumn\tValue\n");
    for (int i = 0; i < nonZeroCount; i++) {
        printf("%d\t%d\t%d\n", sparseMatrix[i].row, sparseMatrix[i].col, sparseMatrix[i].value);
    }
}

int main() {
    int rows, cols, nonZeroCount = 0;

    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    // Create a dynamic array to hold the non-zero elements
    SparseMatrixElement *sparseMatrix = (SparseMatrixElement *)malloc(rows * cols * sizeof(SparseMatrixElement));
    if (sparseMatrix == NULL) {
        printf("Memory allocation failed!");
        return 1;
    }

    printf("Enter elements of the matrix (enter 0 for zero elements):\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int value;
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &value);
            if (value != 0) {
                sparseMatrix[nonZeroCount].row = i;
                sparseMatrix[nonZeroCount].col = j;
                sparseMatrix[nonZeroCount].value = value;
                nonZeroCount++;
            }
        }
    }

    // Resize the array to hold only the non-zero elements
    sparseMatrix = (SparseMatrixElement *)realloc(sparseMatrix, nonZeroCount * sizeof(SparseMatrixElement));

    // Display the sparse matrix
    printf("\nSparse Matrix Representation:\n");
    displaySparseMatrix(sparseMatrix, nonZeroCount);

    free(sparseMatrix);
    return 0;
}