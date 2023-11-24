#include "..\..\Headers\ProductionArea\Employee.h"

Employee* Employee_init(){
    Employee* result = (Employee*)malloc(sizeof(Employee));
    result->name = string_init("");
    return result;
}

Employee* inputEmployee(size_t index){
    Employee* result = Employee_init();
    string_reserve(result->name,50);

    printf("Age = ");
    scanf("%u",&result->age);

    cleanSTDIN();
    printf("Name = ");
    result->name->size = getline(&result->name->data,&result->name->size,stdin) - 1;

    printf("Experience(in months) = ");
    scanf("%u",&result->experience);
    
    return result;
}

void outputEmployee(Employee emp, size_t index){
    printf("\n\t\tEmployee{Name:%s, age:%u, exeprience:%u}",string_get(emp.name),emp.age,emp.experience);
}

void Employee_free(Employee* emp){
    if(emp == NULL)return;
    string_delete(emp->name);
}