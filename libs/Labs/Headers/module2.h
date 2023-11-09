#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <wchar.h>
#include <io.h>
#include <fcntl.h>
#include "..\..\General\Headers\Vector.h"

#ifndef MODULE2_H
#define MODULE2_H

DEFINE_VECTOR_TYPE(VectorUTF,wchar_t)

//Output functions
void outputWCHAR(wchar_t x,size_t index);
void outputWCHAR_X16(wchar_t x,size_t index);
void outputWCHAR_x10(wchar_t x,size_t index);

//Compare functions
bool utfComparer(wchar_t l,wchar_t r);

void task();

#endif
