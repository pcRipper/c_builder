#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "libs\Labs\Headers\lab7.h"
// #include "libs\Labs\Headers\lab8.h"
// #include "libs\General\Headers\Vector.h"
// #include "libs\General\Headers\Matrix.h"

//compile commands :
//  with general libs : 
//      gcc -o main .\main.c .\libs\General\Source\String.c .\libs\General\Source\BigNum.c
//  for labs :
//      gcc -o main .\main.c .\libs\General\Source\String.c .\libs\Labs\Source\lab1.c
//      gcc -o main .\main.c .\libs\General\Source\String.c .\libs\General\Source\BigNum.c .\libs\Labs\Source\module1.c


int main(int argc,char** argv){ 
    srand(time(NULL));

    taskI8_2();

    return 0;
}