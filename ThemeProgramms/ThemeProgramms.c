#include <stdio.h>
#include "BinGraphLib.h"

int main()
{
    BIN_GRAPH fragment1 = initBinGraph(), fragment2 = initBinGraph();
    printf("First fragment: \n");
    scanBinGraph(fragment1);
    printf("\nSecond fragment: \n");
    scanBinGraph(fragment2);
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
            printf("\nNot equal");
            return 0;
        }
        else if (result1 == '\0')
        {
            printf("\nIncorrect data");
            return 0;
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
}