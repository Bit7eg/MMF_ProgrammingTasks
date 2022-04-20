#include <stdio.h>

#include "StringLib.h"
#include "LogicalFragmentAnaliserFunctions.c"
#include "LogicalFragmentGeneratorFunctions.c"

#define DEBUG 1;

int main()
{
#if DEBUG
	String str = initLogicalFormula();
#else
	String str = scanString();
#endif

	if (isLogicalFormula(str))
	{
		printf("It is logical formula");
	}
	else
	{
		printf("It isn't logical formula");
	}
}