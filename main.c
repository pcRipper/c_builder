#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "libs\Labs\Headers\lab8_1.h"

//compile commands :
//  with general libs : 
//      gcc -o main .\main.c .\libs\General\Source\String.c .\libs\General\Source\BigNum.c
//  for labs :
//      gcc -o main .\main.c .\libs\General\Source\String.c .\libs\Labs\Source\lab1.c
//      gcc -o main .\main.c .\libs\General\Source\String.c .\libs\General\Source\BigNum.c .\libs\Labs\Source\module1.c

int main(int argc,char** argv){ 
    srand(time(NULL));

    int cube[3][3][3] = {
        {
            {623,12,625},
            {13,1,14},
            {634,15,645},
        },
        {
            {23,3,25},
            {2,0,4},
            {34,5,36},
        },
        {
            {125,45,123},
            {46,6,56},
            {134,26,145},
        }
    };

    printf("%d",isRubiksCube(cube));

    return 0;
}