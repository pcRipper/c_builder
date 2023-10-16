#include "..\Headers\lab5.h"

void task1(){
    static const int N = 8;
    double x;
    printf("Input X value: ");
    scanf("%lf",&x);

    double sum = 0;
    for(int i = 1;i <= N;++i){
        sum += pow(x,i);
    }

    printf("Sum = %lf",sum);
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