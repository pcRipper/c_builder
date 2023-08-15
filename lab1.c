#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libs\Headers\String.h"

void toHex(int num){
    static const char chars[] = "0123456789ABCDEF";
    String* result = initString();
    
    while(num > 0){
        appendString(result,chars[num & 0xF]);
        num = num >> 4;
    }

    reverse(result);
    printf("%s",getString(result));
    deleteString(result);
}

int main(int argc,char** argv){

    toHex(212);

    return 0;
}