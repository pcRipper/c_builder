#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libs\General\Headers\String.h"
// #include "libs\Labs\Headers\lab2.h"
// #include "libs\Labs\Headers\lab1.h"
// #include "libs\Labs\Headers\lab3.h"
// #include "libs\Labs\Headers\lab4.h"
#include "libs\General\Headers\BigNum.h"
#include "libs\Labs\Headers\module1.h"

//compile commands :
//  with general libs : 
//      gcc -o main .\main.c .\libs\General\Source\String.c .\libs\General\Source\BigNum.c
//  for labs :
//      gcc -o main .\main.c .\libs\General\Source\String.c .\libs\Labs\Source\lab1.c
//      gcc -o main .\main.c .\libs\General\Source\String.c .\libs\Labs\Source\lab2.c 

int main(int argc,char** argv){

    test_module1();

    return 0;
}