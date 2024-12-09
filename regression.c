#include <stdio.h>

int main()
{
  int n, i;
  double x[100], y[100];
  double sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0;
  double meanX, meanY, b_yx, c_yx, userX, predictedY;

  printf("Enter the number of data points: ");
  scanf("%d", &n);

  printf("Enter the values of x: ");
  for (i = 0; i < n; i++)
  {
    scanf("%lf", &x[i]);
  }

  printf("Enter the values of y: ");
  for (i = 0; i < n; i++)
  {
    scanf("%lf", &y[i]);
  }

  // Calculate sums
  for (i = 0; i < n; i++)
  {
    sumX += x[i];
    sumY += y[i];
    sumXY += x[i] * y[i];
    sumX2 += x[i] * x[i];
  }

  // Calculate means
  meanX = sumX / n;
  meanY = sumY / n;

  // Calculate slope (b_yx)
  b_yx = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);

  // Calculate intercept using the formula c_yx = meanY - b_yx * meanX
  c_yx = meanY - b_yx * meanX;

  // Print the regression equation
  printf("\nThe regression line of y on x is:\n");
  printf("y - %.5lf = %.5lf * (x - %.5lf)\n", meanY, b_yx, meanX);
  printf("Or equivalently:\n");
  printf("y = %.5lf * x + %.5lf\n", b_yx, c_yx);

  // Accept user input for x and predict y
  printf("\nEnter a value for x to predict y: ");
  scanf("%lf", &userX);

  // Calculate predicted y
  predictedY = b_yx * userX + c_yx;

  printf("\nFor x = %.5lf, the predicted value of y is: %.5lf\n", userX, predictedY);

  return 0;
}
