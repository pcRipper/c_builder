#include "..\..\General\Headers\Vector.h"
#include "..\..\General\Headers\VectorFunctions.h"
#include "..\..\General\Headers\Matrix.h"
#include <limits.h>
#include <stdbool.h>

#ifndef LAB8_1_H
#define LAB8_1_H

DEFINE_VECTOR_TYPE(VectorInt,int)
DEFINE_MATRIX_TYPE(MatrixInt,int)
DEFINE_MATRIX_TYPE(Matrix3D,VectorInt)

//task1
int minCoins(VectorInt* values,size_t sum);

//task2
bool in_range(size_t l,size_t r, size_t x);
MatrixInt* spiralOrder(size_t n,size_t m);

//task3
//returns an array with such structure :
//count of years * 2 = pairs of min and max temp of the year
//last two elements  = min and max for the whole period
//example : {-31,+44,0,+50,-31,+50} :
//  -30 and +44 - first year,
//   +0 and +50 - second year,
//  -31 and +50 - most min and max for whole period
VectorInt* statistic(Matrix3D* data);

//task4
size_t sortNumber(size_t num);
bool increasing(int l,size_t li,int r,size_t ri);

bool rubik3(int num);
bool rubik2(int num);
bool rubik1(int num);
bool rubik0(int num);

bool isRubiksCube(int cube[3][3][3]);

    //valuid cube
    // int cube[3][3][3] = {
    //     {
    //         {623,12,625},
    //         {13,1,14},
    //         {634,15,645},
    //     },
    //     {
    //         {23,3,25},
    //         {2,0,4},
    //         {34,5,36},
    //     },
    //     {
    //         {125,45,123},
    //         {46,6,56},
    //         {134,26,145},
    //     }
    // };

#endif