#include "..\..\General\Headers\Vector.h"

#ifndef LAB7_H
#define LAB7_H

#define VectorInput(VectorType) \
VectorType* inputVector() { \
    size_t size = 0; \
    while(size == 0) { \
        printf("Input amount of elements: "); \
        scanf("%u",&size); \
    } \
    \
    VectorType* vector = VectorType##_init(); \
    VectorType##_reserve(vector,size); \
    \
    printf("Input your numbers: "); \
    \
    int num; \
    for(size_t i = 0;i < size;++i){ \
        scanf("%d",&num); \
        VectorType##_push(vector,num); \
    } \
    return vector; \
} \

#pragma region Functions

void intOutput(int x);
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