#include <stdio.h> 
#include <math.h> 
float f(float x){
    return (x*x*x -5*x+1);
}
float fn(float a,float b){
    return b - ((b - a) / (f(b) - f(a))) * f(b);
}
int main(){
    float x0,x1,x,aerr;
    int flag=1;
    printf("Enter the value of xo: "); 
    scanf("%f", &x0); 
    printf("Enter the value of x1: "); 
    scanf("%f", &x1); 
    printf("enter the allowed error:");
    scanf("%f",&aerr);
    int itr=0;
    do{
        itr++;
        x=fn(x0,x1);
        printf("after %d iteration root is %f:\n",itr,x);
         if (fabs(f(x)) < aerr) {
            printf("Root has converged to: %f after %d iterations.\n", x, itr);
            break;
        }
        x0=x1;
        x1=x;

    }while(fabs(f(x))>=aerr);
    return 0;
}
