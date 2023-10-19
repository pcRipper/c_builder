#include "..\..\General\Headers\String.h"
#include "..\..\General\Headers\Math.h"
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

#ifndef LAB6_H
#define LAB6_H

#define equal_triple(a,b,c) \
({  __typeof__ (a) _a = (a); \
    __typeof__ (b) _b = (b); \
    __typeof__ (c) _c = (c); \
    ((_a == _b) && (_a == _c)) ? true : false; \
})

bool isOctal(double N,int precision);

void taskI19_1();
void taskI19_2();
void taskI19_3();
void taskI19_4();
void taskI19_5();
void taskI19_6();
void taskI19_7();
void taskI19_8();
void taskI19_9();

void lab6_test();

#endif