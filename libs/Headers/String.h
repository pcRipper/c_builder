#ifndef STRING_H
#define STRING_H

typedef struct String String;

String* initString();
void deleteString(String* str);
void appendString(String* str,const char c);
void insertString(String* str, const char* data);
char* getString(String*  str);
void reverse(String* str);

#endif