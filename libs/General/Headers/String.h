#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef STRING_H
#define STRING_H

#define max(a,b) \
({ __typeof__ (a) _a = (a); \
    __typeof__ (b) _b = (b); \
    _a > _b ? _a : _b; })

#define min(a,b) \
({ __typeof__ (a) _a = (a); \
    __typeof__ (b) _b = (b); \
    _a > _b ? _b : _a; })

typedef struct {
    char* data;
    size_t size;
    size_t allocated;
} String;

String*  string_init     (const char* data);
void     string_delete   (String* str);
String*  string_append   (String* str, const char c);
String*  string_insert   (String* str, const char* data);
String*  string_insertAt (String* str,size_t index, const char* data);
String*  string_popBack  (String* str);
String*  string_popFront (String* str);
char*    string_get      (String* str);
String*  string_reverse  (String* str);

#endif