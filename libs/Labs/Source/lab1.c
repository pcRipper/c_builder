#include "..\Headers\lab1.h"

String* decimalConverter(int num,char (*func)(int*)){
    String* result = string_init();

    while(num > 0){
        string_append(result,func(&num));
    }

    return string_reverse(result);
}

String* floatConverter(double num,int system,int precision){
    static const char chars[] = "0123456789ABCDEF";
    String* integer_part = string_init();
    
    int int_iterations = ceil(log(num) / log(system));
    size_t num_int = (size_t)(num * pow(system,8));
    
    printf("%d\n",int_iterations);
    printf("%d\n",num_int);

    while(int_iterations-- > 0){
        size_t x = num_int / system;
        string_append(integer_part,chars[num_int - (system * x)]);
        num_int = x;      
    }

    return string_reverse(integer_part);
    
    String *floating_part = string_init();
    while(num != 0 && precision-- > 0){
        int x = num / system;
        string_append(floating_part,chars[(int)num - (system * x)]);
        num = x;    
    }

    return string_insert(
        string_append(string_reverse(integer_part),'.'),
        string_get(string_reverse(floating_part))
    );
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