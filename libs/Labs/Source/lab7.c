#include "..\Headers\lab7.h"

DEFINE_VECTOR_TYPE(VectorInt,int)

void intOutput(int x){
    printf("%d",x);
}

bool predicate_task1(int x,size_t index){
    return x > 0;
}

void task1() {
    size_t size = 0;
    while(size == 0){
        printf("Input amount of numbers: ");
        scanf("%u",&size);
    }
        
    VectorInt* vector = VectorInt_init();
    VectorInt_reserve(vector,size);

    printf("Input your numbers: ");

    int num;    
    for(size_t i = 0;i < size;++i){    
        scanf("%d",&num);
        VectorInt_push(vector,num);
    }

    VectorInt* filtered = VectorInt_filter(vector,predicate_task1);

    printf("Result -> ");
    VectorInt_showVector(filtered,intOutput);

    VectorInt_free(filtered);
    VectorInt_free(vector);
}

void task2() {

}

void task3() {

}

void taskI8_1() {

}
void taskI8_2() {

}