#include <stdio.h> 
#include <math.h> 
float f(float x) 
{ 
    return cos(x)-3*x+1;
} 
float phi(float x) 
{ 
    return (cos(x)+1)/3; 
}
float df(float x) 
{ 
    return fabs(sin(x)/3); 
} 
int main() 
{ 
    float aerr, xo, x; 
    int flag = 0; 
    do 
    { 
        printf("Enter value of x0: "); 
        scanf("%f", &xo); 
        float res = df(xo); 
        if (res < 1) 
        { 
            printf("Condition Satisfied\n"); 
            flag = 1; 
        } 
 
        else 
        { 
            printf("Condition not satisfied, Please try again..."); 
        } 
 
    } while (flag != 1); 
    printf("Enter accepted error: "); 
    scanf("%f", &aerr); 
    float temp = xo; 
    int itr = 0; 
    do 
    { 
        itr++; 
        x = phi(temp); 
        float p = f(temp); 
        printf("Root after %d iteration is %f, value of x = %f and error = %f\n", itr, x, temp, p); 
        if (fabs(p) < aerr) {
            printf("root is %f:",x);
        }
        temp = x; 
    } while (fabs(f(x))>=aerr); 
} 