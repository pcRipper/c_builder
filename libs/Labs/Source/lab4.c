#include "..\Headers\lab4.h"

void task1(){
    static const double HALF_PI = MATH_PI / 2.0;
    double x;
    printf("Input X value: ");
    scanf("%lf",&x);
    
    double y;
    if(x < 0){
        y = x + 2;
    }
    else if(x < HALF_PI){
        y = sin(x) + 0.5;
    }
    else {
        y = x*x*x + 5;
    }

    printf("Y = %lf\n",y);
}

void task2(){
    double x,y;
    printf("Input X and Y values: ");
    scanf("%lf%lf",&x,&y);

    if(pow(x,4) < 1 || cos(x) == 1){
        printf("Values are invalid for this function\n");
        return;
    }

    double b = (sqrt(pow(x,4) - 1) + 3*x*y)/(1 - cos(x));
    printf("B = %lf\n",b);

}

void taskI8_1(){
    double x,y;
    printf("Input X and Y values: ");
    scanf("%lf%lf",&x,&y);
    
    double r,a,b;
    printf("Input R,a and b :");
    scanf("%lf%lf%lf",&r,&a,&b);
    
    bool z = pow((x - a),2) + pow((y - b),2) <= r*r;
    printf("Z = %d\n",z);
}

void taskI8_2(){
    double x,y,z;
    printf("Input X,Y and Z values: ");
    scanf("%lf%lf%lf",&x,&y,&z);

    if(x == 0.5 || x == -0.5){
        printf("Values are invalid for this function : division by 0\n");
        return;
    }

    double square_root = 1 - (2*x*z - y)/(4*x*x - 1);

    if(square_root < 0){
        printf("Values are invalid for this function : square root value below 0\n");
        return;
    }

    double b = sqrt(square_root) - 10000.0;

    printf("B = %lf",b);
}

void taskI8_3(){
    int a,b,k;
    printf("Input A,B and K values: ");
    scanf("%d%d%d",&a,&b,&k);

    int c = k*(a+b);

    printf("Remainder = %d,",c%4);
    switch (c%4)
    {
    case 1:
    case 3:
        c -= c%4;
    break;
    case 2:
        c += 2;
    default:
        break;
    }
    printf("C = %d\n",c);
}