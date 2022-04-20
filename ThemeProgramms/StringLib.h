#ifndef STRINGLIB_H
#define STRINGLIB_H

#include <stdlib.h>
#include <stdio.h>

typedef struct String {
    char* value;
    size_t size;
} String;

String initString(int size)
{
    String str;
    if (size <= 0)
    {
        str.size = 0;
        str.value = NULL;
    }
    else
    {
        str.size = size;
        str.value = (char*)calloc(size, sizeof(char));
    }
    return str;
}

void clearString(String str) {
    free(str.value);
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
        res.value[str1.size + i] = str1.value[i];
    }
    return res;
}

String getStringBefore(String str, int position)
{
    String res = initString(position + 1);
    for (size_t i = 0; i < res.size; i++)
    {
        res.value[i] = str.value[i];
    }
    return res;
}

String getStringAfter(String str, int position)
{
    String res = initString(str.size - position);
    for (size_t i = 0; i < res.size; i++)
    {
        res.value[i] = str.value[position + i];
    }
    return res;
}

String scanString()
{
    String symb = initString(1), res = initString(0);
    scanf("%c", symb.value);
    while (*symb.value != '\n')
    {
        res = stringCat(res, symb);
        scanf("%c", symb.value);
    }
    return res;
}

void printString(String str)
{
    printf("%s", str.value);
}

#endif