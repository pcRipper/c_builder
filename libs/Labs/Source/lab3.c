#include "..\Headers\lab3.h"

//https://www.symbolab.com/solver/algebra-calculator

void task1(){
    //a\:=\:\frac{sqrt\left(abs\left(x-1\right)\right)\:-\:sqrt\left(abs\left(y\right)\right)}{1\:+\:\frac{x}{2}^2+\frac{y}{4}^2},\:x\:=\:-3,\:y\:=\:4
    double x, y;

    printf("Input X and Y values : ");
    scanf("%lf %lf",&x,&y);

    double result = (sqrt(fabs(x-1)) - sqrt(fabs(y)))/(1.0 + x*x/2.0 + y*y/4.0);

    printf("A = %lf\n",result);
}

void task2(){
    double x,a,b;
    printf("Input Y,A and B values : ");
    scanf("%lf%lf%lf",&x,&a,&b);

    double y = (fabs(log10(x)) + 5)/(x + 4.0);
    double c = pow(sin(a*(2*y*y+1)),2);
    double z = (c + 29 * b)/(c + b);

    printf("Y = %lf, Z = %lf\n",y,z);
}

void taskI1(){
    //variant #8
    //check : a\:=\:\frac{1\:+\:sin^2\left(x+y\right)}{2\:+\:abs\left(x\:-\:\frac{2x}{1\:+\:x^2\cdot \:y^2}\right)}\:+\:x,\:x\:=\:-2,\:y\:=\:12
    double x,y;
    printf("Input X and Y values : ");
    scanf("%lf%lf",&x,&y);

    double a = (1 + pow(sin(x + y),2))/(2 + fabs(x - (2*x)/(1 + x*x*y*y))) + x;

    printf("A = %lf\n",a);
}

void taskI2(){
    //variant #8

    double x,a,b;
    printf("Input Y,A and B values : ");
    scanf("%lf%lf%lf",&x,&a,&b);

    double y = (sqrt(pow(E,x-2) + 3))/x;
    double z = (pow(a,0.25) + sqrt(5*y + 20))/(sqrt(5*y + 20) + b);

    printf("Y = %lf, Z = %lf\n",y,z);

}