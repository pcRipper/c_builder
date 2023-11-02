#include ".\Math.h"

#ifndef VECTOR_H
#define VECTOR_H

#define DEFINE_VECTOR_TYPE(VectorType, ElementType) \
typedef struct { \
    ElementType *data; \
    size_t size; \
    size_t capacity; \
} VectorType; \
 \
 typedef ElementType (*MapFunc)(ElementType, size_t); \
 \
VectorType* VectorType##_init() { \
    VectorType *vector = (VectorType*)malloc(sizeof(VectorType)); \
    vector->data = NULL; \
    vector->size = 0; \
    vector->capacity = 0; \
    return vector; \
} \
 \
void VectorType##_reserve(VectorType *vector,const size_t new_capacity) { \
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
VectorType* VectorType##_initData(const ElementType* data,const size_t size) { \
    VectorType *vector = VectorType##_init(); \
    VectorType##_reserve(vector,size); \
    memcpy(&vector->data[0],&data[0],size * sizeof(ElementType)); \
    vector->size = size; \
    return vector; \
} \
 \
void VectorType##_push(VectorType *vector, ElementType value) { \
    if (vector->size == vector->capacity) { \
        VectorType##_reserve(vector,vector->capacity == 0 ? 1 : vector->capacity * 2); \
    } \
    vector->data[vector->size++] = value; \
} \
 \
void VectorType##_pop(VectorType *vector) { \
    vector->size = max(vector->size-1,0); \
} \
 \
VectorType* VectorType##_concat(VectorType * l,VectorType *r){ \
    if(l->size == 0)return r; \
    if(r->size == 0)return l; \
    VectorType *result = VectorType##_init(); \
    result->size = l->size + r->size; \
    VectorType##_reserve(result,result->size); \
    memcpy(&result->data[0],&l->data[0],l->size * sizeof(ElementType)); \
    memcpy(&result->data[l->size],&r->data[0],r->size * sizeof(ElementType)); \
    return result; \
} \
 \
void VectorType##_map(VectorType* vector,MapFunc functor){ \
    for(size_t i = 0;i < vector->size;++i){ \
        vector->data[i] = functor(vector->data[i], i); \
    } \
} \
 \
void VectorType##_free(VectorType *vector) { \
    free(vector->data); \
    vector->data = NULL; \
    vector->size = 0; \
    vector->capacity = 0; \
}

//add findLastOf function

#endif