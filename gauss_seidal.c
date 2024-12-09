#include <stdio.h>
#include <math.h>

#define SIZE 10  // Maximum size of the matrix

// Function to implement the Gauss-Seidel method
void gaussSeidel(float mat[SIZE][SIZE], float x[SIZE], int n, int maxIterations, float aerr) {
    float temp[SIZE];  // Array to hold temporary values
    int iteration = 0;
    float sum, error;

    // Initialize the solution array with zeros
    for (int i = 0; i < n; i++) {
        x[i] = 0;
    }

    printf("Iteration results:\n");

    // Perform the iterations
    do {
        // Copy current solution to temp array
        for (int i = 0; i < n; i++) {
            temp[i] = x[i];
        }

        for (int i = 0; i < n; i++) {
            sum = 0;

            // Compute the sum of known values in the current row
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    sum += mat[i][j] * x[j];
                }
            }

            // Update the value of x[i]
            x[i] = (mat[i][n] - sum) / mat[i][i];
        }

        // Print the current solution
        printf("Iteration %d: ", iteration + 1);
        for (int i = 0; i < n; i++) {
            printf("%.4f ", x[i]);
        }
        printf("\n");

        // Calculate the error
        error = 0;
        for (int i = 0; i < n; i++) {
            error += fabs(x[i] - temp[i]);
        }

        iteration++;

    } while (error > aerr && iteration < maxIterations);

    // Final solution
    printf("\nFinal Solution:\n");
    for (int i = 0; i < n; i++) {
        printf("x%d = %.4f\n", i + 1, x[i]);
    }
}

int main() {
    float mat[SIZE][SIZE], x[SIZE];
    int n, maxIterations;
    float aerr;

    // Input the number of variables (size of the matrix)
    printf("Enter the number of equations: ");
    scanf("%d", &n);

    // Input the coefficients of the augmented matrix
    printf("Enter the coefficients of the augmented matrix (including RHS values):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            scanf("%f", &mat[i][j]);
        }
    }

    // Input the maximum number of iterations
    printf("Enter the maximum number of iterations: ");
    scanf("%d", &maxIterations);

    // Input the tolerance level for convergence
    printf("Enter the tolerance level (e.g., 0.001): ");
    scanf("%f", &aerr);

    // Perform Gauss-Seidel Iteration
    gaussSeidel(mat, x, n, maxIterations, aerr);

    return 0;
}
