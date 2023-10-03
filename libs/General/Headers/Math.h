#ifndef MATH_CONSTANTS
#define MATH_CONSTANTS

#define MATH_PI 3.14159265359
#define E 2.7182818284590452353

#define max(a,b) \
({ __typeof__ (a) _a = (a); \
    __typeof__ (b) _b = (b); \
    _a > _b ? _a : _b; })

#define min(a,b) \
({ __typeof__ (a) _a = (a); \
    __typeof__ (b) _b = (b); \
    _a > _b ? _b : _a; })

#endif