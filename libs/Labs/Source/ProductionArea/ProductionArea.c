#include "..\..\Headers\ProductionArea\ProductionArea.h"

char* getProductionName(enum ProductionType type){
    switch (type)
    {
    case WOOD:
        return "WOOD";
    case CONCRETE:
        return "CONCRETE";
    case PAPER:
        return "PAPER";
    case GLASS:
        return "GLASS";
    default:
        return "UNKNOWN";
    }
}

ProductionArea* ProductionArea_init(){
    ProductionArea* result = (ProductionArea*)malloc(sizeof(ProductionArea));
    result->employees = VectorEmployee_init(0);
    result->id = 0;
    result->type = UNKNOWN;
    return result;
}

void ProductionArea_showInfo(ProductionArea* pA){
    printf("Production Area {\n\t");
    printf("ID = %u;\n\t",pA->id);
    printf("Type = %s;\n\t",getProductionName(pA->type));
    printf("Employees:{\n\t\t");
    VectorEmployee_showVector(pA->employees,outputEmployee);
    printf("\n\t}");
    printf("\n}\n");
}

void ProductionArea_free(ProductionArea* pA){
    if(pA == NULL)return;
    VectorEmployee_free(pA->employees);
}