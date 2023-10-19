#include "..\Headers\lab5.h"

void task1(){
    static const int N = 8;
    double x;
    printf("Input X value: ");
    scanf("%lf",&x);

    if(x <= 0 || x > 5)return;

    double sum = 0;
    double xs = x;
    for(int i = 1;i <= N;++i){
        sum += xs;
        xs *= x;
    }

    printf("Sum = %lf\n",sum);
}

void task2(){
    double x;
    printf("Input X value :");
    scanf("%lf",&x);

    int i = 1;
    double iteration;
    double sum = 0;
    while(true){
        iteration = sin(i*x) / i++;
        if(fabs(iteration) < 0.0001)break;
        sum += iteration;
    }

    printf("Sum = %lf, Iterations amount = %d\n",sum,i - 1);
}

void task3(){
    static const int limit = 30;
    static const double diff = 0.0001;

    double x;
    printf("Input value of X : ");
    scanf("%lf",&x);
    
    int iterations = 0;
    double ex = 1;
    double xs = 1;
    double exP = exp(x);

    while(iterations <= limit){
        xs = xs*x/++iterations;
        ex += xs;
        if(fabs(exP - ex) < diff)break;
    }

    printf("e^%lf = %lf | e^%lf = %lf \niterations = %d\n",x,ex,x,exP,iterations);
}

void task4(){
    int n;
    printf("Input amount of numbers: ");
    scanf("%d",&n);
    printf("Input your %d numbers: ",n);

    double sum = 0;
    double iteration;
    while(n-- > 0){
        scanf("%lf",&iteration);
        sum += iteration;
    }

    printf("Sum = %lf\n",sum);
}

void taskI8_1(){
    for(int from = 105;from <= 1000;from += 7){
        int sum = from/100 + ((from/10)%10) + from%10;
        if(sum%7 == 0){
            printf("%d ",from);
        }
    }
}