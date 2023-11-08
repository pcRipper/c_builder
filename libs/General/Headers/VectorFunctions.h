#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#ifndef VECTOR_FUNCTIONS_H
#define VECTOR_FUNCTIONS_H

//defines standart functions for Vector.h file

//Predicates
#define GREATER(a,b) (a < b)
#define LESS(a,b) (a > b)

//Fill functions
int randomFill(size_t index);

//Output functions
void intOutput(int x,size_t index);
void charOutput(char x,size_t index);

//Input functions
int intInput(size_t index);

//Equal predicates
bool intEqual(int l,int r);

#endif
