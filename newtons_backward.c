
#include <stdio.h>
int main()
{
    int n;
    printf("Enter number of terms: ");
    scanf("%d", &n);

    float mat[n][n + 1];
    float x, u, u1, y;
    int fact;

    printf("Enter values of x: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%f", &mat[i][0]);
    }

    printf("Enter values of y: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%f", &mat[i][1]);
    }

    printf("Enter x for which you want to calculate y: ");
    scanf("%f", &x);

    for (int i = 2; i < n + 1; i++)
    {
        for (int j = n - 1; j >= i - 1; j--)
        {
            mat[j][i] = mat[j][i - 1] - mat[j - 1][i - 1];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i + 1; j++)
        {
            printf("%.2f ", mat[i][j]);
        }
        printf("\n");
    }

    u = (x - mat[n - 1][0]) / (mat[1][0] - mat[0][0]);
    u1 = u;
    y = mat[n - 1][1];
    fact = 1;

    for (int i = 2; i < n + 1; i++)
    {
        y = y + (u1 * mat[n - 1][i]) / fact;
        fact = fact * i;
        u1 = u1 * (u + (i - 1));
    }

    printf("Value of f(%f) is %f", x, y);
    return 0;
}
