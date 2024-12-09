#include <stdio.h> 
#include <math.h> 
float f(float x){
    return (x*x*x*x-x-10);
}
float df(float x) 
{ 
    return fabs(4*(x*x*x)-1); 
} 
float fn(float x){
    return x-(f(x)/df(x));
}

int main(){
    float x0,x1;
    int flag=0;
     do { 
        printf("Enter values for x0 and x1: "); 
        scanf("%f %f", &x0, &x1); 
 
        if (f(x0) * f(x1) < 0) { 
            flag = 1; 
            printf("Root lies between %f and %f.\n", x0, x1); 
        } else { 
            printf("Invalid input. Re-enter values.\n"); 
            flag = 0; 
        } 
    } while (flag != 1);

    float aerr;
    printf("enter allowed error: "); 
    scanf("%f", &aerr);

    float x,x_new;
    int itr=0;
    printf("enter a value between %f and %f:",x0,x1);
    scanf("%f",&x);
    do{
        itr++;
       x_new=fn(x);
       printf("after %d iteration value of x is %f:\n",itr,x_new);
       if(fabs(f(x_new))< aerr){
            break;
       }
       x=x_new;

    }while(fabs(f(x))>=aerr);


}