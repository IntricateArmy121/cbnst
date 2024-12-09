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
    if (n % 3 != 0)
    {
        printf("Intervals are not in multiple of 3!");
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
    float res = 0, sum3 = 0, allSum = 0;
    for (int i = 1; i < n; ++i)
    {
        allSum += y[i];
        if (i % 3 == 0)
            sum3 += y[i];
    }
    res = y[0] + y[n] + 2 * sum3 + 3 * (allSum - sum3);
    res = res * 3 * h / 8;
    for (int i = 0; i <= n; ++i)
        printf("%f\t", y[i]);
    printf("\nResult: %f", res);
}