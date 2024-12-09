#include <stdio.h>

#define SIZE 10

// Function to perform Gauss-Jordan Elimination
void gaussJordan(float mat[SIZE][SIZE], int n) {
    int i, j, k;

    // Applying Gauss-Jordan Elimination
    for (i = 0; i < n; i++) {
        // Make the diagonal element 1 and scale the entire row
        float diagonalElement = mat[i][i];
        if (diagonalElement != 0) {
            for (j = 0; j <= n; j++) {
                mat[i][j] /= diagonalElement;
            }
        }

        // Make all the elements in the current column (except the pivot) 0
        for (k = 0; k < n; k++) {
            if (k != i) { // Skip the pivot row
                float factor = mat[k][i];
                for (j = 0; j <= n; j++) {
                    mat[k][j] -= factor * mat[i][j];
                }
            }
        }
    }
}

// Function to print the matrix
void printMatrix(float mat[SIZE][SIZE], int n) {
    printf("Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            printf("%8.3f", mat[i][j]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    float mat[SIZE][SIZE];
    int n;

    // Input the size of the matrix (number of equations)
    printf("Enter the number of equations: ");
    scanf("%d", &n);

    // Input the augmented matrix
    printf("Enter the coefficients of the augmented matrix (including RHS values):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            scanf("%f", &mat[i][j]);
        }
    }

    // Perform Gauss-Jordan Elimination
    gaussJordan(mat, n);

    // Print the final matrix (which should be in the form of an identity matrix with solutions)
    printMatrix(mat, n);

    // Print the solutions
    printf("Solutions:\n");
    for (int i = 0; i < n; i++) {
        printf("x%d = %.3f\n", i + 1, mat[i][n]);
    }

    return 0;
}
