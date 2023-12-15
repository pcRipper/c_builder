#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#include "libs/General/Headers/Vector.h"
#include "libs/General/Headers/VectorFunctions.h"


DEFINE_VECTOR_TYPE(VectorInt, int);

int main(int argc,char** argv){ 
    srand(time(NULL));

    // task1();

    VectorInt *vec = VectorInt_init(10);

    VectorInt_showVector(vec, intOutput);
    
    VectorInt_free(vec);
    free(vec);
    return 0;
}

//compile commands :
//  with general libs : 
//      gcc -o main .\main.c .\libs\General\Source\String.c .\libs\General\Source\BigNum.c
//