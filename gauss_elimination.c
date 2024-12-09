#include <stdio.h>
#include<math.h>
// Function to perform Gauss Elimination
void gaussElimination(float mat[10][10], int n) {
    int i, j, k;

    // Performing Gauss Elimination
    for (k = 0; k < n; k++) {
        // Partial Pivoting
        for (i = k + 1; i < n; i++) {
            // Make the elements below the pivot elements equal to zero or eliminate the variables
            float factor = mat[i][k] / mat[k][k];
            for (j = 0; j <= n; j++) {
                mat[i][j] -= factor * mat[k][j];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            printf("%f ",mat[i][j]);
        }
        printf("\n");
    }
}

// Function to perform back substitution
void backSubstitution(float mat[10][10], int n) {
    float x[10];  // Array to store solution

    // Start back substitution
    for (int i = n - 1; i >= 0; i--) {
        x[i] = mat[i][n];
        for (int j = i + 1; j < n; j++) {
            x[i] -= mat[i][j] * x[j];
        }
        x[i] = x[i] / mat[i][i];
    }

    // Print solution
    printf("Solution:\n");
    for (int i = 0; i < n; i++) {
        printf("x%d = %.2f\n", i + 1, x[i]);
    }
}

int main() {
    float mat[10][10];
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

    // Perform Gauss Elimination
    gaussElimination(mat, n);

    // Perform Back Substitution
    backSubstitution(mat, n);

    return 0;
}
