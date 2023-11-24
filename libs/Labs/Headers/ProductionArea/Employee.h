#include "..\..\..\General\Headers\Functions.h"
#include "..\..\..\General\Headers\String.h"
#include <stdlib.h>
#include <stdio.h>

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

typedef struct{
    //whole name of the Employee
    String* name;
    //full years
    uint16_t age;
    //in months
    uint16_t experience;
} Employee;

Employee* Employee_init();
Employee* inputEmployee(size_t index);
void outputEmployee(Employee emp, size_t index);
void Employee_free(Employee* emp);

#endif