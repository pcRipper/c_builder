#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <conio.h>
#include "libs\Labs\Headers\ProductionArea\Employee.h"
#include "libs\Labs\Headers\ProductionArea\ProductionArea.h"

//compile commands :
//  with general libs : 
//      gcc -o main .\main.c .\libs\General\Source\String.c .\libs\General\Source\BigNum.c
//  for labs :
//      gcc -o main .\main.c .\libs\General\Source\String.c .\libs\Labs\Source\lab1.c
//      gcc -o main .\main.c .\libs\General\Source\String.c .\libs\General\Source\BigNum.c .\libs\Labs\Source\module1.c
// recent :
//      gcc -o main .\main.c .\libs\Labs\Source\lab8_1.c .\libs\General\Source\VectorFunctions.c

int main(int argc,char** argv){ 
    srand(time(NULL));

    ProductionArea* area1 = ProductionArea_init();

    VectorEmployee_push(area1->employees,*inputEmployee(0));
    VectorEmployee_push(area1->employees,*inputEmployee(0));

    ProductionArea_showInfo(area1);

    ProductionArea_free(area1);
    printf("\nStatus: OK;\n");

    return 0;
}