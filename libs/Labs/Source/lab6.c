#include "..\Headers\lab6.h"


void taskI19_1(){
    double x,y;
    printf("Input X and Y values: ");
    scanf("%lf%lf",&x,&y);

    double result;
    if(x > y && x != -1){
        result = (x-1)/(x+1);
    }
    else if(x < y){
        result = x*y;
    }
    else {
        result = 3*y;
    }

    printf("F(x,y) = %lf\n",result);
}

void taskI19_2(){
    double x;
    printf("Input X value: ");
    scanf("%lf",&x);

    if(x == 0){
        printf("Values are invalid for this formula : x cannot be 0\n");
        return;
    }
    
    double divisor = 1 - (2*x*x - 1)/(2*x);
    
    if(divisor == 0){
        printf("Values are invalid for this formula : divisor cannot be 0\n");
        return;
    }

    double F = (sqrt(1 + sqrt(fabs(x))) + log10(x*x*x))/divisor + 10000*pow(cos(x),2);
}
void taskI19_3(){
    double a,b,c,d;

}
void taskI19_4(){
    printf("two-digit numbers,whose in power of 3 have 3 same last digits: ");
    for(int i = 10;i < 100;++i){
        int square = i * i;
        if(square%10 == (square/10)%10 && square%10 == (square/100)%10){
            printf("%d,",i);
        }
    }
    printf("\b \n");
}
void taskI19_5(){
    int x, y;
    printf("Input interval limits: ");
    scanf("%d%d",&x,&y);

    if(x&1)x+=1;

    long long sum = 0;
    while(x <= y){
        sum += x*x*x;
        x+=2;
    }
    printf("Sum = %ld\n",sum);
}

bool isOctal(double N,int precision){

    uint64_t int_part = N;
    while(int_part > 0){
        printf("%ld\n",int_part);
        if(int_part%10 > 7)return false;
        int_part/=10;
    }

    N -= (uint64_t)N;
    while(N != 0 && precision-- > 0){
        N*=10;
        int top = N;
        if(top > 7)return false;
        N -= top;
    }

    return true;
}

void taskI19_6(){
    double N;
    printf("Input your number: ");
    scanf("%lf",&N);

    printf("This number is%s octal\n", isOctal(N,3) ? " " : " not");
}

void taskI19_7(){
    double x,a;
    printf("Input X and A values :");
    scanf("%lf",&x,&a);

    double factorial = 1;
    int i = 1;
    double iteration;
    double sum = 1;
    while(true){
        iteration = pow(x*log10(a),i)/factorial;
        if(fabs(iteration) < 0.0001)break;
        sum += iteration;
        factorial *= ++i;
    }

    printf("Sum = %lf, Iterations amount = %d\n",sum,i - 1);
}
void taskI19_8(){

}
void taskI19_9(){

}