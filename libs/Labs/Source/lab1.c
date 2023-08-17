#include "..\Headers\lab1.h"


String* decimalConverter(int num,char (*func)(int*)){
    String* result = string_init(NULL);

    while(num > 0){
        string_append(result,func(&num));
    }

    return string_reverse(result);
}

String* floatConverter(double num,size_t system,int precision){
    static const char chars[] = "0123456789ABCDEF";
    String* result = string_init(NULL);
    
    int int_part = ceil(log(num) / log(system));
    size_t num_int = (size_t)(num * pow(system,8));

    while(num_int != 0){
        size_t x = num_int / system;
        string_append(result,chars[num_int - (system * x)]);
        num_int = x;
    }

    return string_reverse(result);
}

double toDecimalConverter(String* str,size_t system){

    size_t limit = 0;
    while(limit < str->size){

    }

    size_t multiplier = pow(limit,system);

    return 0;
}

char asHex(int* num){
    static const char chars[] = "0123456789ABCDEF";
    char c = chars[*num & 0xF];
    *num = *num >> 4;
    return c;
}

char asBinary(int* num){
    char c = *num & 1 ? '1' : '0';
    *num = *num >> 1;
    return c;
}

char asHexFloating(double* num){
    return '0';
}