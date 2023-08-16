#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libs\General\Headers\String.h"
#include "libs\Labs\Headers\lab1.h"

//compile command :
// gcc -o main .\main.c .\libs\General\Source\String.c .\libs\Labs\Source\lab1.c -std=c99

double mod(double l,double r){
    int x = l / r;
    return l - (r * x);
}

int main(int argc,char** argv){
    
    // String* res = floatConverter(212.34,16,4);

    // printf("%s", string_get(res));
    
    String *res = string_init("Hello world");
    
    string_insertAt(res,9,"This is ");

    printf("%s",string_get(res));
    
    string_delete(res);
    return 0;
}