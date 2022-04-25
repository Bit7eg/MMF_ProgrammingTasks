#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "StringLib.h"
#include "LogicalFragmentAnaliserFunctions.h"
#include "LogicalFragmentGeneratorFunctions.h"

#define DEBUG 1;

int main()
{
#if DEBUG
	srand(time(NULL));
	String str = initLogicalFormula();
	printString(str);
#else
	String str = scanString();
#endif //DEBUG

	if (isLogicalFormula(str))
	{
		printf("\nIt is logical formula");
	}
	else
	{
		printf("\nIt isn't logical formula");
	}
}