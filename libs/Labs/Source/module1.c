#include "..\Headers\module1.h"

BigNum* decimalToBinary(BigNum* decimal){
    if(decimal == NULL || decimal->size == 0){
        return bignum_init(0);
    }
    
    BigNum* result = string_init(NULL);

    while(true){
        char c = (decimal->data[decimal->size-1]-48)%2 + 48;
        string_append(result, c);
        decimal = bignum_halfOf(decimal);
        if(decimal->size == 1 && decimal->data[0] == '0')break;
    }

    return string_reverse(string_popBack(result));
}

BigNum* binaryToDecimal(BigNum* binary){
    if(binary == NULL){
        return bignum_init(0);
    }

    //remove leading zeroes
    int l = 0;
    while(l < binary->size && binary->data[l] == '0'){
        l+=1;
    }

    BigNum* result = bignum_init(0);
    while(l < binary->size){
        bignum_doubleIt(result);
        if(binary->data[l++] == '0')continue;
        BigNum* next = bignum_add(result,bignum_init(1));
        string_delete(result);
        result = next;
    }

    return result;
}

void test_module1(){
    {
        BigNum* decimal = binaryToDecimal(string_init("00000000001001111"));
        printf("%s\n",string_get(decimal));
        BigNum* binary = decimalToBinary(decimal);
        printf("%s\n",string_get(binary));
    }
    printf("\n");
    {
        BigNum* decimal = string_init("99123877183913457918239193745189");
        BigNum* binary = decimalToBinary(decimal);
        printf("%s\n",string_get(binary));
    }
}