#include "./String.h"
#include <math.h>
#include <stdint.h>

#ifndef BIGNUM_H
#define BIGNUM_H

typedef String BigNum;

BigNum* bignum_init      (uint64_t x);
BigNum* bignum_add       (BigNum* left, BigNum* right);
BigNum* bignum_doubleIt  (BigNum* num);
BigNum* bignum_halfOf    (BigNum* num);

#endif