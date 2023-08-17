#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libs\General\Headers\String.h"
#include "libs\Labs\Headers\lab1.h"

//compile command :
// gcc -o main .\main.c .\libs\General\Source\String.c .\libs\Labs\Source\lab1.c -std=c99


int main(int argc,char** argv){

    printf("Result#1 = %s\n",string_get(AnyToAny(string_init("68"),10,16,0)));
    printf("Result#2 = %s\n",string_get(AnyToAny(string_init("40"),16,10,0)));
    printf("Result#3 = %s\n",string_get(AnyToAny(string_init("001011"),2,16,0)));
    printf("Result#4 = %s\n",string_get(AnyToAny(string_init("40"),16,2,0)));
    printf("Result#5.1 = %s\n",string_get(AnyToAny(string_init("0.777"),10,2,4)));
    printf("Result#5.2 = %s\n",string_get(AnyToAny(string_init("0.777"),10,16,4)));
    printf("Result#6 = %s\n",string_get(AnyToAny(string_init("0.1110"),2,10,10)));
    printf("Result#7 = %s\n",string_get(AnyToAny(string_init("0.B8A"),16,10,10)));
    printf("Result#8 = %s\n",string_get(AnyToAny(string_init("0.1110"),2,16,10)));
    printf("Result#9 = %s\n",string_get(AnyToAny(string_init("0.B8A"),16,2,10)));
    printf("Result#10 = %s\n",string_get(AnyToAny(string_init("51,002"),10,16,3)));

    return 0;
}