#include <stdio.h>
#include <math.h>
#include <stdlib.h>
float f(float x, float y)
{
    return x+y;
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
        y = y + h * f(x + h * i, y);
        printf("Value at %f is %f \n", x + h * i, y);
    }
    printf("Answer for x:%f is %f", xn, y);
}