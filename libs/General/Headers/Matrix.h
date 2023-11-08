#include "Vector.h"

#ifndef MATRIX_H
#define MATRIX_H

#define DEFINE_MATRIX_TYPE(MatrixType,ElementType) \
 \
DEFINE_VECTOR_TYPE(MatrixType##_MatrixRow, ElementType) \
DEFINE_VECTOR_TYPE(MatrixType, MatrixType##_MatrixRow) \
 \
static MatrixType* MatrixType##_initMatrix(const size_t rows,const size_t columns) { \
    MatrixType* result = MatrixType##_init(rows); \
    for(size_t r = 0;r < rows;++r) { \
        result->data[r] = *MatrixType##_MatrixRow##_init(columns); \
    } \
    return result; \
} \
static void MatrixType##_freeMatrix(MatrixType* matrix) { \
    if(matrix == NULL)return; \
    for(size_t i = 0;i < matrix->size;++i) { \
        MatrixType##_MatrixRow_free(&matrix->data[i]); \
    } \
\
} \
static void MatrixType##_showMatrix(MatrixType* matrix, MatrixType##_MatrixRow##_Output output) { \
    if(matrix == NULL)return; \
    if(matrix->size == 0) { \
        printf("matrix is empty\n"); \
        return; \
    } \
    for(size_t r = 0;r < matrix->size;++r) { \
        MatrixType##_MatrixRow##_showVector(&matrix->data[r],output); \
    } \
} \
static void MatrixType##_fillMatrix(MatrixType* matrix,const ElementType value) { \
    if(matrix == NULL)return; \
    const size_t COLUMNS = matrix->data[0].size; \
    for(size_t r = 0;r < matrix->size;++r) { \
        for(size_t c = 0;c < COLUMNS;++c){ \
            matrix->data[r].data[c] = value; \
        } \
    }\
} \

#endif