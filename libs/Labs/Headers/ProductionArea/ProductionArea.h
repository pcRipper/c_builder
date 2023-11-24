#include "..\..\..\General\Headers\Vector.h"
#include "..\..\..\General\Headers\VectorFunctions.h"
#include "..\..\..\General\Headers\String.h"
#include "Employee.h"

DEFINE_VECTOR_TYPE(VectorEmployee,Employee);

enum ProductionType{
    UNKNOWN,
    WOOD,
    CONCRETE,
    PAPER,
    GLASS
};

typedef struct {
    //unqiue production area identifier
    uint16_t id;
    //vector of employees,those assigned to this production area
    VectorEmployee* employees;
    //Production type of area
    enum ProductionType type;
} ProductionArea;

ProductionArea* ProductionArea_init    ();
void            ProductionArea_showInfo(ProductionArea* pA);
void            ProductionArea_free    (ProductionArea* pA);