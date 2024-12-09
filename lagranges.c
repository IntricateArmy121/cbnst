#include <stdio.h> 
int main() 
{ 
    int n;  
    float x, y = 0; 
 
    printf("Enter number of terms: "); 
    scanf("%d", &n); 
 
    float X[n], Y[n]; 
 
    printf("Enter values of x: "); 
    for (int i = 0; i < n; i++) 
    { 
        scanf("%f", &X[i]); 
    } 
 
    printf("Enter values of y: "); 
    for (int i = 0; i < n; i++) 
    { 
        scanf("%f", &Y[i]); 
    } 
 
    printf("Enter x: "); 
    scanf("%f", &x); 
 
    for (int i = 0; i < n; i++) 
    { 
        float term = Y[i]; 
        for (int j = 0; j < n; j++) 
        { 
            if (j != i) 
            { 
                term = term * (x - X[j]) / (X[i] - X[j]); 
            } 
        } 
        y += term; 
    } 
 
    printf("Value of f(%f) is %f", x, y); 
    return 0; 
} 