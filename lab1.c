#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libs\Headers\String.h"

String* toHex(int num){
    static const char chars[] = "0123456789ABCDEF";
    // String* result = initString();
    
    while(num > 0){
        // appendString(result,chars[num & 0xF]);
        printf("%c\n",chars[num & 0xF]);
        num = num >> 4;
    }

    // reverse(result);
    return initString();
}

int main(int argc,char** argv){

    int toTransfer = 212;

    printf("%d -> %s",toTransfer,getString(toHex(toTransfer)));

    return 0;
}