#ifndef STRINGLIB_H
#define STRINGLIB_H

#include <stdlib.h>

typedef struct String {
    char* value;
    size_t size;
} String;

String initString(int size);
void setStringValue(String str, const char* value);
void clearString(String str);
String stringCat(String str1, String str2);
String stringCopy(String str);
String getStringBefore(String str, int position);
String getStringAfter(String str, int position);
String scanString();
void printString(String str);

#endif