#include "../Headers/BigNum.h"

BigNum* bignum_init(uint64_t x){
    BigNum* bignum = (BigNum*)malloc(sizeof(BigNum));

    if(x == 0){
        return string_init("0");
    }

    bignum = string_init(NULL);
    string_reserve(bignum,(uint64_t)ceil(log10(max(2,x))));

    while(x > 0){
        string_append(bignum,x%10 + 48);
        x /= 10;
    }

    return string_reverse(bignum);
}

BigNum* bignum_add(BigNum* left,BigNum* right){
    if (left->size < right->size){
        BigNum* temp = left;
        left = right;
        right = temp;
    }

    String* sum_num = string_reserve(string_init(""),left->size+1);
    int i1 = left->size, i2 = right->size;
    int carry = 0;
    while (0 < i2) {
        int digit = left->data[--i1] + right->data[--i2] + carry - 96;
        string_append(sum_num,(digit % 10) + '0');
        carry = digit / 10;
    }

    while (0 < i1) {
        int digit = left->data[--i1] + carry - 48;
        string_append(sum_num, digit % 10 + '0');
        carry = digit / 10;
    }

    return string_reverse(carry == 0 ? sum_num : string_append(sum_num,'1'));
}

BigNum* bignum_doubleIt(BigNum* num){

    char carry = 0;
    for(int i = num->size-1;0 <= i;--i){
        char current = (num->data[i] - 48) * 2 + carry;
        num->data[i] = (current % 10) + 48;
        carry = current/10;
    }

    return carry == 0? num : string_prepend(num,'1');
}

BigNum* bignum_halfOf(BigNum* num){

    if(num == NULL || num->size == 0){
        return bignum_init(0);
    }

    BigNum* result = string_init(NULL);
    string_reserve(result,num->size);

    int carry = 0;
    int i = 0;
    while(i < num->size){
        char current = num->data[i] - 48 + carry;
        string_append(result,current/2 + 48);
        carry = (current&1) * 10;
        i+=1;
    }

    return result->size > 0 && result->data[0] == '0' ? string_popFront(result) : result;
}