#include "..\Headers\final_work.h"

VectorInt* findAllOccurrence(String* str,char symbol){
    VectorInt* result = VectorInt_init(0);

    for(size_t i = 0;i < str->size;++i){
        if(str->data[i] == symbol)VectorInt_push(result, i);
    }

    return result;
}

void task1(){
    static const char symbols[] = {'s','h','S','H'};
    String* text = string_init("Maksym Shchehel");

    for(int i = 0;i < sizeof(symbols);++i){
        VectorInt* result = findAllOccurrence(text,symbols[i]);
        if(result->size == 0)continue;
        
        printf("All occurrence of symbol %c ",symbols[i]);
        VectorInt_showVector(result,intOutput);

        VectorInt_free(result);
    }

    string_delete(text);
}

