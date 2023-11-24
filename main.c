#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <conio.h>
// #include "libs\Labs\Headers\final_work.h"
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
// final_task :
//      gcc -o main .\main.c .\libs\Labs\Source\final_work.c .\libs\General\Source\String.c .\libs\General\Source\VectorFunctions.c
// ProductionArea:
//      gcc -o main .\main.c .\libs\Labs\Source\ProductionArea\Employee.c .\libs\General\Source\String.c .\libs\General\Source\Functions.c .\libs\General\Source\Vector.c .\libs\Labs\Source\ProductionArea\ProductionArea.c

int main(int argc,char** argv){ 
    srand(time(NULL));

    // task1();

    ProductionArea* area1 = ProductionArea_init();
    area1->type = WOOD;
    area1->id = 222;
    VectorEmployee_push(area1->employees,*inputEmployee(0));
    VectorEmployee_push(area1->employees,*inputEmployee(0));

    ProductionArea_showInfo(area1);

    ProductionArea_free(area1);
    printf("\nStatus: OK;\n");

    return 0;
}