#include "..\Headers\lab1.h"
#include "..\..\General\Headers\String.h"

String* toHex(int num){
    static const char chars[] = "0123456789ABCDEF";
    String* result = string_init();

    while(num > 0){
        string_append(result,chars[num & 0xF]);
        num = num >> 4;
    }

    return string_reverse(result);
}