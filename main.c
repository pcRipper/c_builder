#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libs\General\Headers\Vector.h"
#include "libs\General\Headers\Functions.h"
// #include "libs\General\Headers\String.h"
// #include "libs\General\Headers\Functions.h"
// #include "libs\Labs\Headers\lab5.h"
// #include "libs\Labs\Headers\lab6.h"
// #include "libs\General\Headers\BigNum.h"
// #include "libs\Labs\Headers\module1.h"

//compile commands :
//  with general libs : 
//      gcc -o main .\main.c .\libs\General\Source\String.c .\libs\General\Source\BigNum.c
//  for labs :
//      gcc -o main .\main.c .\libs\General\Source\String.c .\libs\Labs\Source\lab1.c
//      gcc -o main .\main.c .\libs\General\Source\String.c .\libs\General\Source\BigNum.c .\libs\Labs\Source\module1.c

DEFINE_VECTOR_TYPE(IntVector,int)

int func(int x,size_t index){
    return x < 0 && x%2 == 0 ? 1 : x;
}

int main(int argc,char** argv){

    int arr[] = {1, 2, 3, -14, 5, -1, -3};
    IntVector* v1 = IntVector_initData(arr, 7);

    IntVector_map(v1,func);

    printf("%d: {",v1->size);
    for(size_t i = 0;i < v1->size;++i){
        printf("%d, ",v1->data[i]);
    }
    printf("\b\b};\n");

    return 0;
}