#include "..\Headers\lab7.h"

DEFINE_VECTOR_TYPE(VectorInt,int)

#pragma region Functions

bool predicate_task1(int x,size_t index){
    return x > 0;
}
bool predicate_task2(int l,size_t l_index,int r,size_t r_index) {
    if(l == r)return l_index < r_index;
    return l > r;
}
bool sort_predicate(int l,size_t l_index,int r,size_t r_index){
    return l < r;
}

int functor_taskI1(int x,size_t index){
    return x < 0 && x%2 == -1 ? 1 : x;
}
bool predicate_taskI2(int l,size_t l_index,int r,size_t r_index) {
    if(l <= 0 && r > 0)return true;
    if(r <= 0 || r%2 == 1)return false;
    if(l%2 == 1)return true;
    if(l == r)return l_index < r_index;
    return l > r;
}

#pragma endregion

void task1() {
    VectorInt* vector = inputVector(intInput);
    VectorInt* filtered = VectorInt_filter(vector,predicate_task1);

    printf("Result -> ");
    VectorInt_showVector(filtered,intOutput);

    VectorInt_free(filtered);
    VectorInt_free(vector);
}

void task2() {
    VectorInt* vector = inputVector(intInput);
    int index = VectorInt_find(vector,predicate_task2);

    printf("Smallest element at index -> %d\n",index);
    VectorInt_showVector(vector,intOutput);

    if(index != 2 && vector->size > 2){
        int temp = vector->data[index];
        vector->data[index] = vector->data[2];
        vector->data[2] = temp;
    }

    VectorInt_showVector(vector,intOutput);

    VectorInt_free(vector);
}

void task3() {
    static const size_t SIZE = 15;
    VectorInt* vector = VectorInt_init(SIZE);
    VectorInt_fillWith(vector,randomFill);

    VectorInt_showVector(vector,intOutput);    
    VectorInt_bubbleSort(vector,sort_predicate);
    VectorInt_showVector(vector,intOutput);

    VectorInt_free(vector);
}

void taskI8_1() {
    VectorInt* vector = inputVector(intInput);

    VectorInt_showVector(vector,intOutput);
    VectorInt_map(vector,functor_taskI1);
    VectorInt_showVector(vector,intOutput);
    
    VectorInt_free(vector);
}

void taskI8_2() {
    VectorInt* vector = inputVector(intInput);

    VectorInt_showVector(vector,intOutput);
    int index = VectorInt_find(vector,predicate_taskI2);

    if(index == 0 && predicate_taskI2(vector->data[0],0,2,0)){
        printf("There is no such element in array!\n");
    }
    else {
        printf("Last Min even element at index -> %d",index);
    }

    VectorInt_free(vector);
}