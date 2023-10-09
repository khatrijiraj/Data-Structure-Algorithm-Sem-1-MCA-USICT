#include <stdio.h>
#include <stdlib.h>

struct SparseMatrix {
    int rows, cols, count;
    int *row_ptr;
    int *col_idx;
    int *values;
};

struct SparseMatrix createSparseMatrix(int rows, int cols, int count) {
    struct SparseMatrix matrix;
    matrix.rows = rows;
    matrix.cols = cols;
    matrix.count = count;

    matrix.row_ptr = (int *)malloc((rows + 1) * sizeof(int));
    matrix.col_idx = (int *)malloc(count * sizeof(int));
    matrix.values = (int *)malloc(count * sizeof(int));

    if (!matrix.row_ptr || !matrix.col_idx || !matrix.values) {
        fprintf(stderr, "Memory allocation failed. Exiting...\n");
        exit(EXIT_FAILURE);
    }

    return matrix;
}

void insertElement(struct SparseMatrix *matrix, int row, int col, int value) {
    if (row < 0 || row >= matrix->rows || col < 0 || col >= matrix->cols) {
        printf("Invalid row or column index. Element not inserted.\n");
        return;
    }

    if (matrix->count >= matrix->rows * matrix->cols) {
        printf("Matrix is full. Element not inserted.\n");
        return;
    }

    matrix->values[matrix->count] = value;
    matrix->col_idx[matrix->count] = col;
    matrix->count++;

    for (int i = row + 1; i <= matrix->rows; i++) {
        matrix->row_ptr[i]++;
    }
}

int getElement(struct SparseMatrix matrix, int row, int col) {
    if (row < 0 || row >= matrix.rows || col < 0 || col >= matrix.cols) {
        printf("Invalid row or column index.\n");
        return 0;
    }

    for (int i = matrix.row_ptr[row]; i < matrix.row_ptr[row + 1]; i++) {
        if (matrix.col_idx[i] == col) {
            return matrix.values[i];
        }
    }

    return 0;  // Element is zero if not found
}

void printSparseMatrix(struct SparseMatrix matrix) {
    printf("Sparse Matrix (%dx%d):\n", matrix.rows, matrix.cols);
    for (int i = 0; i < matrix.rows; i++) {
        for (int j = 0; j < matrix.cols; j++) {
            int value = getElement(matrix, i, j);
            printf("%d ", value);
        }
        printf("\n");
    }
}

int main() {
    int rows, cols, count;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);
    printf("Enter the number of non-zero elements: ");
    scanf("%d", &count);

    struct SparseMatrix matrix = createSparseMatrix(rows, cols, count);

    printf("Enter the non-zero elements (row, column, value):\n");
    for (int i = 0; i < count; i++) {
        int row, col, value;
        scanf("%d %d %d", &row, &col, &value);
        insertElement(&matrix, row, col, value);
    }

    printSparseMatrix(matrix);

    free(matrix.row_ptr);
    free(matrix.col_idx);
    free(matrix.values);

    return 0;
}