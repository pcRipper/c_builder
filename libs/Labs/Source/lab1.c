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

    double temp = num - (size_t)num;
    while(int_part-- > 0){
        size_t next = num / system;
        string_append(result,chars[(size_t)(num - next*system)]);
        num = next;
    }

    num = temp;
    string_reverse(result);
    if(precision > 0 && num != 0)string_append(result,'.');

    double divisor = 1;
    while(precision-- > 0 && num != 0){
        divisor /= system;
        size_t c = num / divisor;
        string_append(result,chars[c]);
        num -= divisor * c;
    }

    return result;
}

double toDecimalConverter(String* str,size_t system){

    size_t limit = 0;
    while(limit < str->size && str->data[limit] != '.'){
        ++limit;
    }
    
    double result = 0;
    double multiplier = pow(system,limit - 1);

    for(size_t i = 0;i < limit;++i){
        result += multiplier * (str->data[i] - (str->data[i] > '9' ? 'A'-10 : '0'));
        multiplier /= system;
    }

    while(++limit < str->size){
        result += multiplier * (str->data[limit] - (str->data[limit] > '9' ? 'A'-10 : '0'));
        multiplier /= system;
    }

    return result;
}

String* AnyToAny(String* data,size_t from_system,size_t to_system,int precision){
    return floatConverter(toDecimalConverter(data,from_system),to_system,precision);
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