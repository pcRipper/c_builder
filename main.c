#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libs\General\Headers\String.h"
#include "libs\Labs\Headers\lab1.h"

//compile command :
// gcc -o main .\main.c .\libs\General\Source\String.c .\libs\Labs\Source\lab1.c -std=c99


int main(int argc,char** argv){

    String* result = AnyToAny(string_init("175.11463146314631463146314631463"),8,10,10);

    printf("Result = %s",string_get(result));

    string_delete(result);
    return 0;
}