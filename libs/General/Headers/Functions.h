#include <stdio.h>

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define MAP_IN(array, size, func) \
  for (int i = 0; i < size; i++) { \
    array[i] = func(i, array[i]); \
  }


#define equal_triple(a,b,c) \
({  __typeof__ (a) _a = (a); \
    __typeof__ (b) _b = (b); \
    __typeof__ (c) _c = (c); \
    ((_a == _b) && (_a == _c)) ? true : false; \
})

void cleanSTDIN();

#endif