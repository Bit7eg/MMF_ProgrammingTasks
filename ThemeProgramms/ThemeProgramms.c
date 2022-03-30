#include <stdio.h>
#include <string.h>
#include "BinGraphLib.h"

char* executeProgram(const char* fileName1, const char* fileName2) {
    BIN_GRAPH fragment1 = fscanBinGraph(fileName1);
    BIN_GRAPH fragment2 = fscanBinGraph(fileName2);
    VALUE_SET vars = getVariableSet(fragment1), varsBuff = getVariableSet(fragment2);
    if (getVarCount(vars) >= getVarCount(varsBuff))
    {
        killValueSet(varsBuff);
    }
    else
    {
        killValueSet(vars);
        vars = varsBuff;
    }
    int flag = 0, size = getVarCount(vars);
    char result1, result2;
    while ((!flag)||(vars->value))
    {
        result1 = logicalFragmentResult(fragment1, vars);
        result2 = logicalFragmentResult(fragment2, vars);
        if (result1 != result2)
        {
            return "\nNot equal";
        }
        else if (result1 == '\0')
        {
            return "\nIncorrect data";
        }
        for (int i = size-1; i >= 0; i--)
        {
            if (vars[i].value)
            {
                vars[i].value = 0;
            }
            else
            {
                vars[i].value = 1;
                break;
            }
        }
        if (vars->value)
        {
            flag = 1;
        }
    }
    return "\nEqual";
}

int main()
{
    int isPassed = 1;
    if (executeProgram("test1\\fragment1.txt", "test1\\fragment2.txt"))
    {
        printf("Test 1 failed");
        isPassed = 0;
    }

    if (isPassed)
    {
        printf("Testing passed");
    }
}