#include "..\Headers\String.h"

#define SIZE_INCREMENTATION_CONSTANT 10

String* string_init(const char* data){
    String *str = (String*)malloc(sizeof(String));

    str->size = data == NULL ? 0 : strlen(data);
    str->allocated = str->size + SIZE_INCREMENTATION_CONSTANT;
    str->data = (char*)malloc(str->allocated * sizeof(char));

    if(data != NULL)memcpy(str->data,data,str->size * sizeof(char));
    return str;
}

String*  string_copy(String* str){
    return string_init(str->data);
}

String* string_reserve(String* str, uint64_t to_size){
    if(to_size <= str->allocated)return str;

    str->allocated = to_size;
    str->data = (char*)realloc(str->data,str->allocated);

    return str;
}

void string_delete(String* str){
    free(str->data);
    free(str);
}

String* string_append(String* str,const char c){
    if(str->allocated == str->size){
        str->allocated += SIZE_INCREMENTATION_CONSTANT;
        str->data = (char*)realloc(str->data,str->allocated);
    }
    str->data[str->size++] = c;
    return str;
}

String* string_prepend(String* str, const char c){
    if(str->allocated == str->size){
        str->allocated += SIZE_INCREMENTATION_CONSTANT;
        str->data = (char*)realloc(str->data,str->allocated);
    }
    for(uint64_t i = str->size++;0 < i;--i){
        str->data[i] = str->data[i-1];
    }
    str->data[0] = c;
    return str;
}

String* string_insert(String* str, const char* data){
    const uint64_t len = strlen(data);
    if(str->allocated - str->size < len){
        str->allocated = str->size + len;
        str->data = (char*)realloc(str->data,str->allocated);
    }

    uint64_t i = 0;
    while(i < len){
        str->data[str->size++] = data[i++];
    }
    return str;
}

String* string_insertAt(String* str, uint64_t index, const char* data){
    const uint64_t len = strlen(data);
    if(str->allocated - str->size < len){
        str->allocated = str->size + len;
        str->data = (char*)realloc(str->data,str->allocated);
    }
    index = min(index,str->size);
    
    long long int r = str->size + len - 1;
    long long int l = str->size - 1;

    while(index <= l && 0 <= l){
        str->data[r--] = str->data[l--];
    }

    memcpy(&str->data[index],data,len);
    str->size += len;
    return str;
}

String* string_popBack(String* str){
    if(str->size != 0)--str->size;
    return str;
}

String* string_popFront(String* str){
    if(str->size != 0){
        for(uint64_t i = 1;i < str->size;++i){
            str->data[i - 1] = str->data[i];
        }
        --str->size;
    }
    return str;
}

char* string_get(String* str){
    char* result = (char*)malloc((str->size + 1) * sizeof(char));
    memcpy(result,str->data,str->size*sizeof(char));
    result[str->size] = '\0';
    return result;
}

String* string_reverse(String* str){
    int l = -1,r = str->size;
    while(++l < --r){
        char c = str->data[l];
        str->data[l] = str->data[r];
        str->data[r] = c;
    }
    return str;
}

String* string_filter (String* str, bool(*predicate)(const char)){
    String* result = string_init(NULL);

    for(uint64_t i = 0;i < str->size; ++i){
        if(predicate(str->data[i])){
            string_append(result,str->data[i]);
        }
    }

    return result;
}