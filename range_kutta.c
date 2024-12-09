#include <stdio.h>
#include <math.h>
#include <stdlib.h>
float f(float x, float y)
{
    return (y * y - x * x) / (y * y + x * x);
}
int main()
{
    float x, y, xn, h;
    int n;
    printf("Enter initital x and y:");
    scanf("%f %f", &x, &y);
    printf("Enter the calculating point:");
    scanf("%f", &xn);
    printf("Enter the no. of steps n:");
    scanf("%d", &n);
    h = (xn - x) / n;
    float res;
    for (int i = 0; i < n; ++i)
    {
        float k1 = h * f(x, y);
        float k2 = h * f(x + h / 2, y + k1 / 2);
        float k3 = h * f(x + h / 2, y + k2 / 2);
        float k4 = h * f(x + h, y + k3);
        float finalK = (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        y = y + finalK;
        x = x + h;
        printf("Value at %f is %f\n", x, y);
    }
    printf("Answer at %f os %f", x, y);
}