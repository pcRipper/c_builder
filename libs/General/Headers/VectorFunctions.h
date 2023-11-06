#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef VECTOR_FUNCTIONS_H
#define VECTOR_FUNCTIONS_H

//defines standart functions for Vector.h file

//Fill functions
int randomFill(size_t index);

//Output functions
void intOutput(int x,size_t index);
void charOutput(char x,size_t index);

//Input functions
int intInput(size_t index);

#endif
