#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef STRING_H
#define STRING_H

typedef struct String String;

String*  string_init     ();
void     string_delete   (String* str);
String*  string_append   (String* str, const char c);
String*  string_insert   (String* str, const char* data);
String*  string_popBack  (String* str);
String*  string_popFront (String* str);
char*    string_get      (String* str);
String*  string_reverse  (String* str);

#endif