#include "Vector.h"

#ifndef MATRIX_H
#define MATRIX_H

#define DEFINE_MATRIX_TYPE(MatrixType,ElementType) \
 \
DEFINE_VECTOR_TYPE(MatrixRow, ElementType) \
DEFINE_VECTOR_TYPE(MatrixType, MatrixRow) \
 \
MatrixType* MatrixType##_initMatrix(const size_t rows,const size_t columns) { \
    MatrixType* result = MatrixType##_init(rows); \
    for(size_t r = 0;r < rows;++r) { \
        result->data[r] = *MatrixRow##_init(columns); \
    } \
    return result; \
} \
 \
void MatrixType##_freeMatrix(MatrixType* matrix) { \
    if(matrix == NULL)return; \
    for(size_t i = 0;i < matrix->size;++i) { \
        MatrixRow_free(&matrix->data[i]); \
    } \
\
} \
void MatrixType##_showMatrix(MatrixType* matrix, MatrixRow##_Output output) { \
    if(matrix == NULL)return; \
    if(matrix->size == 0) { \
        printf("matrix is empty\n"); \
        return; \
    } \
    for(size_t r = 0;r < matrix->size;++r) { \
        MatrixRow##_showVector(&matrix->data[r],output); \
    } \
} \

#endif