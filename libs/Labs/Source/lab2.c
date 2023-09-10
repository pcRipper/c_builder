#include "..\Headers\lab2.h"

void task1_1(){
    double x, y;
    printf("Input x and y : ");
    scanf("%lf %lf",&x,&y);
    double result = (sqrt(abs(x - 1)) - sqrt(abs(y)))/(1 + x*x/2 + y*y/4);
    printf("Answer = %lf\n",result);
}

void task2_1(){
    double x;
    printf("Input x : ");
    scanf("%lf",&x);

    double y = x < 0 ?
        pow(x,3) - 1.5
        :
        (x < MATH_PI ? 
            cos(x)+0.2
            :
            x * (x + 2)
        )
    ;

    printf("Answer = %lf;\n",y);
}

void task2_2(){
    double x,y;
    printf("Input x and y: ");
    scanf("%lf %lf",&x,&y);

    double dist = x*x + y*y;
    int result = dist > 16 ? 0 : (dist > 4 ? 2 : 1);
    printf("The point is int circle #%d",result);
}

void task3_1(){
    int n;
    printf("Input N number: ");
    scanf("%d",&n);

    int sum = 0;
    for(int i = 1;i <= n;++i){
        sum += i;
    }

    printf("Sum of %d first numbers = %d",n,sum);
}

void task3_2(){
    int n;
    printf("Input amount of numbers : ");
    scanf("%d",&n);
    
    double sum = 0;
    double product = 1; 
    while(n-- > 0){
        double x;
        scanf("%lf",&x);
        if(x < 0){
            sum += x;
            product *= x;
        } 
    }

    printf("Sum and product of positive numbers : %lf %lf",sum,product);
}

void task3_3(){
    double n,x;
    printf("Input values of N and X:");
    scanf("%lf %lf",&n,&x);

    double result = 0;
    while(n > 0){
        result += pow(x,n--);
    }

    printf("Sum = %lf",result);
}

void task3_4(){
    double x;
    
    printf("Input x: ");
    scanf("%lf",&x);

    int i = 1;
    double result = 0,iteration = 0;
    do{
        iteration = cos((i++) * x)/i;
        result += iteration;
    }while(abs(iteration) > 0.001);

    printf("Sum = %lf",result);
}

void task4_8(){
    int n;
    double x;
    printf("Input values of N and X:");
    scanf("%d %lf",&n,&x);

    double result = 0;
    while(n > 0){
        result += n * pow(x,n--);
    }

    printf("Sum = %lf",result);
}