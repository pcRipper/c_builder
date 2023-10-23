#include "..\Headers\lab6.h"

void taskI19_1(){
    double x,y;
    printf("Input X and Y val: ");
    scanf("%lf%lf",&x,&y);

    double result = x > y && x != -1 ? (x-1)/(x+1) : (x < y ? x*y : 3*y);

    printf("F(x,y) = %lf\n",result);
}

void taskI19_2(){
    double x;
    printf("Input X value: ");
    scanf("%lf",&x);

    if(x <= 0){
        printf("Values are invalid for this formula : x cannot be <= 0\n");
        return;
    }
    
    double divisor = 1 - (2*x*x - 1)/(2*x);
    
    if(divisor == 0){
        printf("Values are invalid for this formula : divisor cannot be 0\n");
        return;
    }

    double F = (sqrt(1 + sqrt(fabs(x))) + log(x*x*x))/divisor + 10000*pow(cos(x),2);

    printf("F(x) = %lf\n",F);
}

void taskI19_3(){
    static const int triplets[4][3] = {
        {0,1,2},
        {0,1,3},
        {0,2,3},
        {1,2,3}
    };
    static const int duos[3][4] = {
        {0,1,2,3},
        {0,2,1,3},
        {0,3,1,2}
    };
    static const int pairs[6][2] = {
        {0,1},
        {0,2},
        {0,3},
        {1,2},
        {1,3},
        {2,3}
    };
    static double val[4];
    static double aval[4];

    printf("Input A,B,C and D val: ");
    scanf("%lf%lf%lf%lf",&val[0],&val[1],&val[2],&val[3]);
    for(int i = 0;i < 4;++i)aval[i] = fabs(val[i]);

    //checking triplets
    int any_triplets = -1;
    for(int i = 0;i < 4;++i){
        if(
            aval[triplets[i][0]] == aval[triplets[i][1]]
            &&
            aval[triplets[i][0]] == aval[triplets[i][2]]
        ){
            any_triplets = i;
            break;
        }
    }
    //checking duos
    int any_duos = -1;
    for(int i = 0;i < 3;++i){
        if(aval[duos[i][0]] == aval[duos[i][1]] && aval[duos[i][2]] == aval[duos[i][3]]){
            any_duos = i;
            break;
        }
    }
    //checking single pairs
    int any_pair = -1;
    for(int i = 0;i < 6;++i){
        if(aval[pairs[i][0]] == aval[pairs[i][1]]){
            any_pair = i;
            break;
        }
    }

    if(aval[0] == aval[1] && aval[2] == aval[3] && aval[0] == aval[2]){
        for(int i = 0;i < 4;++i)val[i] *= val[i];
    }
    else if(any_triplets != -1){
        for(int i = 0;i < 3;++i){
            val[triplets[any_triplets][i]] = -val[triplets[any_triplets][i]];
        }
    }
    else if(any_duos != -1){
        if(aval[duos[any_duos][0]] < aval[duos[any_duos][2]]){
            val[duos[any_duos][2]] *= 2;
            val[duos[any_duos][3]] *= 2;
            val[duos[any_duos][0]] *= 3;
            val[duos[any_duos][1]] *= 3;
        }
        else {
            val[duos[any_duos][2]] *= 3;
            val[duos[any_duos][3]] *= 3;
            val[duos[any_duos][0]] *= 2;
            val[duos[any_duos][1]] *= 2;
        }
    }
    else if(any_pair != -1){
        val[pairs[any_pair][0]] = val[pairs[any_pair][1]] = 0;
    }

    printf("A = %lf,B = %lf,C = %lf,D = %lf\n",val[0],val[1],val[2],val[3]);

}

void taskI19_4(){
    printf("two-digit numbers,whose in power of 3 have 3 same last digits: ");
    for(int i = 10;i < 100;++i){
        int square = (i * i)%1000;
        if(square%10 == (square/10)%10 && square%10 == square/100){
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

    printf("This number is%soctal\n", isOctal(N,3) ? " " : " not ");
}

void taskI19_7(){
    double x,a;
    printf("Input X and A val: ");
    scanf("%lf%lf",&x,&a);

    double const VAL = pow(a,x);
    double const TOP = x*log(a);
    double current = 1;
    int i = 1;
    double sum = 1;

    while(fabs(sum - VAL) >= 0.0001){
        current = current*TOP/i++;
        sum += current;
    }

    printf("Loop result = %lf | Function result = %lf\n",sum,VAL);
    printf("Iterations = %d\n",i);
}

void taskI19_8(){
    double x;
    printf("Input X value: ");
    scanf("%lf",&x);

    const double VAL = log((x+1)/(x-1));
    double itr_x = x;
    int i = 1;
    double sum = 0;

    while(fabs(VAL - sum) >= 0.00001){
        sum += 2/(itr_x*(i++*2-1));
        itr_x *= x*x;
    }

    printf("Loop result = %lf | Function result = %lf\n",sum,VAL);
    printf("Iterations = %d\n",i);
}

void taskI19_9(){
    for(int b = 3;b < 10;++b){
        double current = b;
        int iterations = 1;
        while(current > 0){
            current -= 1.0/sqrt((double)++iterations);
        }

        printf("B(%d) becomes negative(%lf) after %d operations\n",b,current,iterations);
    }
}