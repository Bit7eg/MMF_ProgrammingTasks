#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "StringLib.h"

String initString(int size)
{
    String str;
    if (size <= 0)
    {
        str.size = 0;
        str.value = (char*)malloc(sizeof(char));
    }
    else
    {
        str.size = size;
        str.value = (char*)calloc(size + 1, sizeof(char));
    }
    str.value[str.size] = '\0';
    return str;
}

void setStringValue(String str, const char* value)
{
    int valueSize = strlen(value);
    for (size_t i = 0; (i < valueSize) && (i < str.size); i++)
    {
        str.value[i] = value[i];
    }
}

void clearString(String str)
{
    if (str.value)
    {
        free(str.value);
        str.value = NULL;
        str.size = 0;
    }
}

String stringCat(String str1, String str2)
{
    String res = initString(str1.size + str2.size);
    for (size_t i = 0; i < str1.size; i++)
    {
        res.value[i] = str1.value[i];
    }
    for (size_t i = 0; i < str2.size; i++)
    {
        res.value[str1.size + i] = str2.value[i];
    }
    res.value[res.size] = '\0';
    return res;
}

String stringCopy(String str)
{
    String res = initString(str.size);
    for (int i = 0; i < str.size; i++)
    {
        res.value[i] = str.value[i];
    }
    res.value[res.size] = '\0';
    return res;
}

String getStringBefore(String str, int position)
{
    String res = initString(position + 1);
    for (size_t i = 0; i < res.size; i++)
    {
        res.value[i] = str.value[i];
    }
    res.value[res.size] = '\0';
    return res;
}

String getStringAfter(String str, int position)
{
    String res = initString(str.size - position);
    for (size_t i = 0; i < res.size; i++)
    {
        res.value[i] = str.value[position + i];
    }
    res.value[res.size] = '\0';
    return res;
}

String scanString()
{
    String symb = initString(1), res = initString(0), buff;
    scanf("%c", symb.value);
    while (*symb.value != '\n')
    {
        buff = stringCopy(res);
        clearString(res);
        res = stringCat(buff, symb);
        clearString(buff);
        scanf("%c", symb.value);
    }
    res.value[res.size] = '\0';
    return res;
}

void printString(String str)
{
    printf("%s\n", str.value);
}