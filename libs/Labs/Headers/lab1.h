#pragma once
#include "..\..\General\Headers\String.h"
#include <math.h>

#ifndef LAB1_H
#define LAB1_H

String* decimalConverter(int num,char (*func)(int*));
String* floatConverter(double num,size_t system,int precision);

char asHex(int* num);
char asBinary(int *num);

char asHexFloating(double* num);

#endif