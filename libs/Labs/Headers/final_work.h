#include "..\..\General\Headers\Vector.h"
#include "..\..\General\Headers\VectorFunctions.h"
#include "..\..\General\Headers\String.h"

#ifndef FINAL_H
#define FINAL_H

DEFINE_VECTOR_TYPE(VectorInt,int)

VectorInt* findAllOccurrence(String* str,char symbol);
void task1();

#endif