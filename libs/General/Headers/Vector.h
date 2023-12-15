#include "./Math.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef DEFINE_VECTOR_TYPE
#define DEFINE_VECTOR_TYPE(VectorType, ElementType) \
typedef struct { \
    ElementType *data; \
    size_t size; \
    size_t capacity; \
} VectorType; \
 \
 typedef ElementType (*VectorType##_MapFunc)(ElementType, size_t); \
 typedef ElementType (*VectorType##_FillFunc)(size_t); \
 typedef bool        (*VectorType##_Predicate)(ElementType, size_t); \
 typedef bool        (*VectorType##_PairPredicate)(ElementType, size_t, ElementType, size_t); \
 typedef void        (*VectorType##_Output)(ElementType, size_t); \
 typedef bool        (*VectorType##_Equals)(ElementType, ElementType); \
 \
static void VectorType##_reserve(VectorType *vector,const size_t new_capacity) { \
    if(vector->capacity > new_capacity)return; \
    ElementType *new_data = (ElementType *)realloc(vector->data, new_capacity * sizeof(ElementType)); \
    if (new_data == NULL) { \
        fprintf(stderr, "Memory allocation failed\n"); \
        exit(EXIT_FAILURE); \
    } \
    vector->data = new_data; \
    vector->capacity = new_capacity; \
} \
 \
static VectorType* VectorType##_init(const size_t size) { \
    VectorType *vector = (VectorType*)malloc(sizeof(VectorType)); \
    vector->data = NULL; \
    vector->size = size; \
    vector->capacity = size; \
    if(size > 0) { \
        VectorType##_reserve(vector,size); \
    } \
    return vector; \
} \
 \
static VectorType* VectorType##_initData(const ElementType* data,const size_t size) { \
    VectorType *vector = VectorType##_init(size); \
    VectorType##_reserve(vector,size); \
    memcpy(&vector->data[0],&data[0],size * sizeof(ElementType)); \
    vector->size = size; \
    return vector; \
} \
 \
static VectorType* VectorType##_initCopy(const VectorType* vector) { \
    return VectorType##_initData(&vector->data[0],vector->size); \
} \
 \
static void VectorType##_fill(VectorType *vector, const ElementType value) { \
    if(vector == NULL)return; \
    for(size_t i = 0;i < vector->size;++i) { \
        vector->data[i] = value; \
    } \
} \
 \
static void VectorType##_fillWith(VectorType* vector,VectorType##_FillFunc functor) { \
    if(vector == NULL)return; \
    for(size_t i = 0;i < vector->size;++i) { \
        vector->data[i] = functor(i); \
    } \
} \
 \
static void VectorType##_resize(VectorType *vector,size_t new_size) { \
    if(vector == NULL)return; \
    if(vector->capacity < new_size)VectorType##_reserve(vector,new_size); \
    vector->size = new_size; \
} \
 \
static void VectorType##_push(VectorType *vector, ElementType value) { \
    if (vector->size == vector->capacity) { \
        VectorType##_reserve(vector,vector->capacity == 0 ? 1 : vector->capacity * 2); \
    } \
    vector->data[vector->size++] = value; \
} \
 \
static void VectorType##_pop(VectorType *vector) { \
    vector->size = max(vector->size-1,0); \
} \
 \
static VectorType* VectorType##_concat(VectorType * l,VectorType *r) { \
    if(l->size == 0)return r; \
    if(r->size == 0)return l; \
    VectorType *result = VectorType##_init(l->size + r->size); \
    memcpy(&result->data[0],&l->data[0],l->size * sizeof(ElementType)); \
    memcpy(&result->data[l->size],&r->data[0],r->size * sizeof(ElementType)); \
    return result; \
} \
 \
static void VectorType##_map(VectorType* vector,VectorType##_MapFunc functor) { \
    if(vector == NULL)return; \
    for(size_t i = 0;i < vector->size;++i){ \
        vector->data[i] = functor(vector->data[i], i); \
    } \
} \
 \
static VectorType* VectorType##_filter(VectorType* vector,VectorType##_Predicate predicate) { \
    VectorType* result = VectorType##_init(0); \
    if(vector == NULL)return result; \
    VectorType##_reserve(result,vector->size); \
    for(size_t i = 0;i < vector->size;++i) { \
        if(predicate(vector->data[i],i)) { \
            VectorType##_push(result,vector->data[i]); \
        } \
    } \
    return result; \
} \
 \
static int VectorType##_lastOf(VectorType* vector, VectorType##_Predicate predicate) { \
    if(vector == NULL)return -1; \
    int result = -1; \
    for(int i = 0;i < vector->size;++i) { \
        if(predicate(vector->data[i],i)){ \
            result = i; \
        } \
    } \
    return result; \
} \
 \
static int VectorType##_find(VectorType* vector, VectorType##_PairPredicate predicate) { \
    if(vector == NULL)return -1; \
    int result = 0; \
    for(size_t i = 1;i < vector->size;++i) { \
        if(predicate(vector->data[result],result,vector->data[i],i)) { \
            result = i; \
        } \
    } \
    return result; \
} \
 \
static int VectorType##_indexOf(VectorType* vector,const ElementType x, VectorType##_Equals predicate) { \
    if(vector == NULL)return -1; \
    for(size_t i = 0;i < vector->size;++i) { \
        if(predicate(vector->data[i],x)) { \
            return i; \
        } \
    } \
    return -1; \
} \
 \
static void VectorType##_popAt(VectorType* vector,size_t index) { \
    if(vector == NULL)return; \
    if(vector->size <= index)return; \
    while(index < vector->size - 1) { \
        vector->data[index] = vector->data[index+1]; \
    } \
    --vector->size; \
 \
} \
 \
static bool* VectorType##_compare(VectorType* l,VectorType* r,VectorType##_Equals predicate){ \
    bool* result = (bool*)malloc(max(l->size,r->size)); \
    memset(&result[0], 0,max(l->size,r->size)); \
    const size_t SIZE = min(l->size,r->size); \
    for(size_t i = 0;i < SIZE;++i){ \
        result[i] = predicate(l->data[i],r->data[i]); \
    } \
    return result; \
 \
} \
 \
static void VectorType##_bubbleSort(VectorType* vector,VectorType##_PairPredicate predicate) { \
    if(vector == NULL)return; \
    for(size_t i = 0;i < vector->size;++i) { \
        for(size_t j = 1;j < vector->size;++j) { \
            if(predicate(vector->data[j],j,vector->data[j-1],j-1)) { \
                ElementType temp = vector->data[j]; \
                vector->data[j] = vector->data[j-1]; \
                vector->data[j-1] = temp; \
            } \
        } \
    } \
} \
 \
static void VectorType##_showVector(VectorType* vector,VectorType##_Output output) { \
    if(vector == NULL)return; \
    if(vector->size == 0) { \
        printf("Vector is empty!"); \
        return; \
    } \
 \
    printf("%lu: {",vector->size); \
    for(size_t i = 0;i < vector->size;++i) { \
        output(vector->data[i], i); \
        printf(", "); \
    } \
    printf("\b\b};\n"); \
} \
 \
static VectorType* VectorType##_inputVector(VectorType##_FillFunc functor) { \
    size_t size = 0; \
    while(size == 0) { \
        printf("Input amount of elements: "); \
        scanf("%lu",&size); \
    } \
    \
    VectorType* vector = VectorType##_init(size); \
    \
    printf("Input your elements: "); \
    \
    for(size_t i = 0;i < size;++i){ \
        vector->data[i] = functor(i); \
    } \
    return vector; \
} \
 \
static void VectorType##_free(VectorType *vector) { \
    free(vector->data); \
    vector->data = NULL; \
    vector->size = 0; \
    vector->capacity = 0; \
} \

#endif