#include <stdio.h>
#include <math.h>
float f(float x)
{
    return 1 / (powf(x, 3) + 10);
}
int main()
{
    float a, b;
    int n;
    printf("Enter no. of observations:");
    scanf("%d", &n);
    printf("Enter lower and upper limit:");
    scanf("%f %f", &a, &b);
    float h = (b - a) / n;
    float y[n + 1];
    for (int i = 0; i <= n; ++i)
    {
        float x = a + i * h;
        y[i] = f(x);
    }
    float res = 0;
    for (int i = 1; i < n; ++i)
        res += y[i];
    res = res * 2;
    res += y[0] + y[n];
    res = res * h / 2;
    for (int i = 0; i <= n; ++i)
        printf("%f\t", y[i]);
    printf("\nResult: %f", res);
}