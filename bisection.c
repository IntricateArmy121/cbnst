#include <stdio.h> 
#include <math.h> 
float f(float x) { 
    return (x * x * x - 4*x - 9); 
} 
int main() { 
    float a, b,x, aerr = 0.0001; 
    int flag = 0, k = 0; 
 
    do { 
        printf("Enter values for a and b: "); 
        scanf("%f %f", &a, &b); 
 
        if (f(a) * f(b) < 0) { 
            flag = 1; 
            printf("Root lies between %f and %f.\n", a, b); 
        } else { 
            printf("Invalid input. Re-enter values.\n"); 
            flag = 0; 
        } 
    } while (flag != 1); 
    float x1 = a, x2 = b; 
    do { 
        k++; 
        x = (x1 + x2) / 2; 
        printf("\nIteration %d: x = %f, f(x) = %f", k, x, f(x)); 
 
        if (fabs(f(x)) < aerr) { 
            printf("\nThe root of the equation is %f after %d iterations.\n", x, k); 
        } else if (f(x) < 0) { 
            x1 = x; 
        } else { 
            x2 = x; 
        } 
    } while (fabs(f(x))>=aerr); 
    return 0; 
}