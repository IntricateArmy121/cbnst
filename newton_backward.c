#include <stdio.h>

// Function to calculate the factorial of a number
int factorial(int n) {
    int fact = 1;
    for (int i = 2; i <= n; i++)
        fact *= i;
    return fact;
}

// Function to find Newton's backward interpolation value
float newtonBackwardInterpolation(float x[], float y[][10], float value, int n) {
    float sum = y[n-1][0]; // Initialize the sum with y0
    float u = (value - x[n-1]) / (x[1] - x[0]); // Calculate 'u'

    for (int i = 1; i < n; i++) {
        float term = u;

        // Calculate the term (u * (u-1) * (u-2) ... up to i terms)
        for (int j = 1; j < i; j++) {
            term *= (u + j);
        }

        // Add the i-th term to the sum
        sum += (term * y[n-i-1][i]) / factorial(i);
    }

    return sum;
}

// Function to generate the backward difference table
void generateBackwardDifferenceTable(float x[], float y[][10], int n) {
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            y[j][i] = y[j + 1][i - 1] - y[j][i - 1];
        }
    }
}
 
int main() {
    int n; 

    printf("Enter the number of data points: ");
    scanf("%d", &n);

    float x[n], y[n][10]; // x stores the x values, y stores the y values and difference table

    printf("Enter the values of x: ");
    for (int i = 0; i < n; i++) {
        scanf("%f", &x[i]);
    }

    printf("Enter the values of y: ");
    for (int i = 0; i < n; i++) {
        scanf("%f", &y[i][0]);
    }

    // Generate the backward difference table
    generateBackwardDifferenceTable(x, y, n);

    // Display the backward difference table
    printf("\nbackward Difference Table:\n");
    for (int i = 0; i < n; i++) {
        printf("%f", x[i]);
        for (int j = 0; j < n - i; j++) {
            printf("\t%f", y[i][j]);
        }
        printf("\n");
    }

    float value;
    printf("\nEnter the value of x for which you want to find y: ");
    scanf("%f", &value);

    // Calculate and display the interpolated value
    float result = newtonBackwardInterpolation(x, y, value, n);
    printf("\nThe value of y at x = %f is %f\n", value, result);

    return 0;
}
