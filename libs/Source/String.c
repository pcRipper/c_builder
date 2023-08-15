#include "..\\Headers\\String.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE_INCREMENTATION_CONSTANT 10

struct String {
    char* data;
    size_t size;
    size_t allocated;
};

String* initString(){
    String *str;
    str->size = 0;
    str->allocated = SIZE_INCREMENTATION_CONSTANT;
    str->data = (char*)malloc(str->allocated * sizeof(char));
    return str;
}

void deleteString(String* restrict str){
    free(str->data);
}

void appendString(String* restrict str,const char c){
    if(str->allocated == str->size){
        str->allocated += SIZE_INCREMENTATION_CONSTANT;
        str->data = (char*)realloc(str->data,str->allocated);
    }
    str->data[str->size++] = c;
}

void insertString(String* restrict str, const char* restrict data){
    const size_t len = strlen(data);
    if(str->allocated - str->size < len){
        str->allocated = str->size + len;
        str->data = (char*)realloc(str->data,str->allocated);
    }

    size_t i = 0;
    while(i < len){
        str->data[str->size++] = data[i++];
    }
}

char* getString(String* restrict str){
    char* result = (char*)malloc((str->size + 1) * sizeof(char));
    memcpy(result,str->data,str->size*sizeof(char));
    result[str->size] = '\0';
    return result;
}

void reverse(String* restrict str){
    int l = -1,r = str->size;
    while(++l < --r){
        char c = str->data[l];
        str->data[l] = str->data[r];
        str->data[r] = c;
    }
}