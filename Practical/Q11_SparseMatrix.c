#include <stdio.h>

#define MAX_ROWS 10
#define MAX_COLS 10

// Function to check if a matrix is sparse
int isMatrixSparse(int mat[MAX_ROWS][MAX_COLS], int rows, int cols) {
    int zeroCount = 0;
    int sparsityThreshold = (rows * cols) / 4;  // Set a threshold for sparsity

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (mat[i][j] == 0) {
                zeroCount++;
            }
        }
    }

    return (zeroCount > sparsityThreshold) ? 1 : 0;  // Matrix is sparse if zeroCount is greater than threshold
}

// Function to convert matrix to sparse triplet representation
void convertToSparseTripletForm(int mat[MAX_ROWS][MAX_COLS], int rows, int cols, int sparseTriplet[3][MAX_ROWS * MAX_COLS], int *colnumber) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (mat[i][j] != 0) {
                sparseTriplet[0][*colnumber] = i;          // Row index
                sparseTriplet[1][*colnumber] = j;          // Column index
                sparseTriplet[2][*colnumber] = mat[i][j];  // Value
                (*colnumber)++;
            }
        }
    }
}

// Function to display the sparse triplet representation
void printSparseTripletForm(int sparseTriplet[3][MAX_ROWS * MAX_COLS], int count, int row, int col) {
    printf("Sparse triplet representation:\n");
    printf("%d\t%d\t%d\n", row, col, count);

    for (int i = 0; i < count; i++) {
        printf("%d\t%d\t%d\n", sparseTriplet[0][i], sparseTriplet[1][i], sparseTriplet[2][i]);
    }
}

int main() {
    int numRows, numCols;

    // Get the number of rows and columns from the user
    printf("Enter the number of rows in the matrix: ");
    scanf("%d", &numRows);

    printf("Enter the number of columns in the matrix: ");
    scanf("%d", &numCols);

    if (numRows > MAX_ROWS || numCols > MAX_COLS) {
        printf("Error: Matrix size exceeds the maximum allowed size.\n");
        return 1;
    }

    int inputMat[MAX_ROWS][MAX_COLS];

    // Input matrix elements from the user
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            printf("Enter element at position [%d][%d]: ", i, j);
            scanf("%d", &inputMat[i][j]);
        }
    }

    // Display the input matrix
    printf("The matrix is:\n");
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            printf("%d\t", inputMat[i][j]);
        }
        printf("\n");
    }

    // Check if the matrix is sparse or not
    if (isMatrixSparse(inputMat, numRows, numCols)) {
        printf("The matrix is sparse.\n");

        // Convert the matrix to sparse triplet representation
        int sparseTriplet[3][MAX_ROWS * MAX_COLS];
        int nonZeroCount = 0;
        convertToSparseTripletForm(inputMat, numRows, numCols, sparseTriplet, &nonZeroCount);

        // Display the sparse triplet representation
        printSparseTripletForm(sparseTriplet, nonZeroCount, numRows, numCols);
    } else {
        printf("The matrix is not sparse.\n");
    }

    return 0;
}