#include "..\..\General\Headers\Vector.h"
#include "..\..\General\Headers\VectorFunctions.h"
#include <time.h>
#include <stdlib.h>

#ifndef LAB7_H
#define LAB7_H

#pragma region Functions

int randomFill(size_t index);
bool predicate_task1(int x,size_t index);
bool predicate_task2(int l,size_t l_index,int r,size_t r_index);
bool sort_predicate(int l,size_t l_index,int r,size_t r_index);

int functor_taskI1(int x,size_t index);
bool predicate_taskI2(int l,size_t l_index,int r,size_t r_index);

#pragma endregion

void task1();
void task2();
void task3();

void taskI8_1();
void taskI8_2();

#endif