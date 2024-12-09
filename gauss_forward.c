#include <stdio.h>

int main() {
    int n;
    float x, y;
    printf("Enter the number of data points (n): ");
    scanf("%d", &n);
    float arr[n][n + 1];
    printf("Enter the values of x:\n");
    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i][0]);
    }

    printf("Enter the values of y:\n");
    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i][1]);
    }

    printf("Enter the value of x for which you want to find y: ");
    scanf("%f", &x);

    for (int j = 2; j < n + 1; j++) {
        for (int i = 0; i < n - j + 1; i++) {
            arr[i][j] = arr[i + 1][j - 1] - arr[i][j - 1];
        }
    }

    printf("\nDifference table:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n - i; j++) {
            printf("%f    ", arr[i][j]);
        }
        printf("\n");
    }
    float h = arr[1][0] - arr[0][0];
    int i = 0;

    while (arr[i][0] < x) {
        i++;
    }
    i--;

    float u = (x - arr[i][0]) / h;
    float m = u;
    if (u < 0 || u > 0.5) {
        printf("Wrong data\n");
    } else {
        int k = 0, l = 3;
        y = m * arr[i - k][2];

        for (int j = 2; j < n + 1; j++) {
            if (j % 2 == 1) {
                m = m * ((u + k) / j);
            } else {
                k = k + 1;
                m = m * ((u - k) / j);
            }

            if ((i - k) < 0 || (i - k) > (n - j + 1)) {
                break;
            }

            y = y + m * arr[i - k][l];
            l++;
        }
    }
    y = y + arr[i][1];
    printf("\nValue of y at x = %f is %f\n", x, y);

    return 0;
}
