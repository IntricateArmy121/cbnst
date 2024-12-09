#include <stdio.h>
#include <math.h>
#include <stdlib.h>
float f(float x)
{
    return 1 / (x * x + 1);
}
int main()
{
    float a, b;
    int n;
    printf("Enter no. of intervals:");
    scanf("%d", &n);
    printf("Enter lower and upper limit:");
    scanf("%f %f", &a, &b);
    if (n % 2 != 0)
    {
        printf("Intervals are not in multiple of 2!");
        exit(0);
    }
    float h = (b - a) / n;
    printf("H is: %f\n", h);
    float y[n + 1];
    for (int i = 0; i <= n; ++i)
    {
        float x = a + i * h;
        y[i] = f(x);
    }
    float res = 0, oddSum = 0, evenSum = 0;
    for (int i = 1; i < n; ++i)
    {
        if (i % 2)
            oddSum += y[i];
        else
            evenSum += y[i];
    }
    oddSum *= 4;
    evenSum *= 2;
    res = (h / 3.0) * (y[0] + y[n] + oddSum + evenSum);
    for (int i = 0; i <= n; ++i)
        printf("%f\t", y[i]);
    printf("\nResult: %f", res);
}