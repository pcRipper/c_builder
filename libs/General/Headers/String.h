#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include ".\Math.h"

#ifndef STRING_H
#define STRING_H

typedef struct {
    char* data;
    size_t size;
    size_t allocated;
} String;

String*  string_init       (const char* data);
String*  string_init_input (size_t maxSize);
String*  string_copy       (String* str);
String*  string_reserve    (String* str, size_t to_size);
void     string_delete     (String* str);
String*  string_append     (String* str, const char c);
String*  string_prepend    (String* str, const char c);
String*  string_insert     (String* str, const char* data);
String*  string_insertAt   (String* str, size_t index, const char* data);
String*  string_popBack    (String* str);
String*  string_popFront   (String* str);
char*    string_get        (String* str);
String*  string_reverse    (String* str);
String*  string_filter     (String* str, bool(*predicate)(const char));

#endif