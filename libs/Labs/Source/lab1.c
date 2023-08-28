#include "..\Headers\lab1.h"

String* floatConverter(double num,size_t system,int precision){
    static const char chars[] = "0123456789ABCDEF";
    String* result = string_init(NULL);
    
    int int_part = ceil(log(num) / log(system));

    double temp = num - (size_t)num;
    while(int_part-- >= 0){
        size_t next = num / system;
        string_append(result,chars[(size_t)(num - next*system)]);
        num = next;
    }

    num = temp;
    string_reverse(result);
    if(result->size > 1 && result->data[0] == '0')string_popFront(result);
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
    while(limit < str->size && str->data[limit] != '.' && str->data[limit] != ','){
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
    return floatConverter(
        toDecimalConverter(data,from_system),
        to_system,
        precision
    );
}

void lab1(){
    
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
    printf("Result#10 = %s\n",string_get(AnyToAny(string_init("51.002"),10,16,3)));
    
}