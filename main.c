#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <conio.h>
// #include "libs\Labs\Headers\lab8_1.h"
#include "libs\Labs\Headers\module2.h"

//compile commands :
//  with general libs : 
//      gcc -o main .\main.c .\libs\General\Source\String.c .\libs\General\Source\BigNum.c
//  for labs :
//      gcc -o main .\main.c .\libs\General\Source\String.c .\libs\Labs\Source\lab1.c
//      gcc -o main .\main.c .\libs\General\Source\String.c .\libs\General\Source\BigNum.c .\libs\Labs\Source\module1.c
// recent :
//      gcc -o main .\main.c .\libs\Labs\Source\lab8_1.c .\libs\General\Source\VectorFunctions.c

DEFINE_VECTOR_TYPE(VectorInt,int)

bool intComparer(int l,int r){
    return l == r;
}

int main(int argc,char** argv){ 
    srand(time(NULL));

    task();

    return 0;
}