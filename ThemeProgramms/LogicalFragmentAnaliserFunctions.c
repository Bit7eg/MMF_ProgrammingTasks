#ifndef LFANALISER_C
#define LFANALISER_C

#include "StringLib.h"

int isLogicalFormula(String str)
{
	size_t i;
	for (i = 1; (i < str.size) && !(str.value[i - 1] == 'O' && str.value[i] == 'R'); i++);
	if (i < str.size - 2)
	{
		String strBefore = getStringBefore(str, i - 2);
		String strAfter = getStringAfter(str, i + 1);
		clearString(str);
		size_t j;
		for (j = 0; j < strAfter.size; j++)
		{
			if (strAfter.value[i] != ' ')
			{
				break;
			}
		}
		String spaces = getStringBefore(strAfter, j - 1);
		String formula = getStringAfter(strAfter, j);
		clearString(strAfter);
		return isConjunction(strBefore) && isSpaces(spaces) && isLogicalFormula(formula);
	}
	else
	{
		return isConjunction(str);
	}
}

int isConjunction(String str)
{
	size_t i;
	for (i = 2; (i < str.size) && !(str.value[i - 2] == 'A' && str.value[i - 1] == 'N' && str.value[i] == 'D'); i++);
	if (i < str.size - 2)
	{
		String strBefore = getStringBefore(str, i - 3);
		String strAfter = getStringAfter(str, i + 1);
		clearString(str);
		size_t j;
		for (j = 0; i < strAfter.size; i++)
		{
			if (strAfter.value[i] != ' ')
			{
				break;
			}
		}
		String spaces = getStringBefore(strAfter, j - 1);
		String conjuction = getStringAfter(strAfter, j);
		return isMultiplier(strBefore) && isSpaces(spaces) && isConjunction(conjuction);
	}
	else
	{
		return isMultiplier(str);
	}
}

int isMultiplier(String str)
{
	if (str.size < 1)
	{
		clearString(str);
		return 0;
	}
	if (str.value[0] == 'N')
	{
		if ((str.size < 5) || !(str.value[1] == 'O' && str.value[2] == 'T'))
		{
			clearString(str);
			return 0;
		}
		String strAfter = getStringAfter(str, 3);
		clearString(str);
		size_t i;
		for (i = 0; i < strAfter.size; i++)
		{
			if (strAfter.value[i] != ' ')
			{
				break;
			}
		}
		String spaces = getStringBefore(strAfter, i - 1);
		String multiplier = getStringAfter(strAfter, i);
		clearString(strAfter);
		return isSpaces(spaces) && isMultiplier(multiplier);
	}
	else if (str.value[0] == '(')
	{
		if ((str.size < 3) || (str.value[str.size - 1] != ')'))
		{
			clearString(str);
			return 0;
		}
		String strBefore = getStringBefore(str, str.size - 2);
		clearString(str);
		String formula = getStringAfter(strBefore, 1);
		clearString(strBefore);
		return isLogicalFormula(formula);
	}
	else if (str.value[0] == 'T')
	{
		if ((str.size < 5) || !(str.value[1] == 'R' && str.value[2] == 'U' && str.value[3] == 'E'))
		{
			clearString(str);
			return 0;
		}
		String spaces = getStringAfter(str, 4);
		clearString(str);
		return isSpaces(spaces);
	}
	else if (str.value[0] == 'F')
	{
		if ((str.size < 6) || !(str.value[1] == 'A' && str.value[2] == 'L' && str.value[3] == 'S' && str.value[4] == 'E'))
		{
			clearString(str);
			return 0;
		}
		String spaces = getStringAfter(str, 5);
		clearString(str);
		return isSpaces(spaces);
	}
	else
	{
		return isVariable(str);
	}
	clearString(str);
	return 0;
}

int isVariable(String str)
{
	if (str.size < 2)
	{
		clearString(str);
		return 0;
	}
	String spaces = getStringAfter(str, 1);
	int condition = (str.value[0] >= 'A') && (str.value[0] <= 'Z');
	clearString(str);
	return condition && isSpaces(spaces);
}

int isSpaces(String str) {
	if (str.size < 1)
	{
		clearString(str);
		return 0;
	}
	for (size_t i = 0; i < str.size; i++)
	{
		if (str.value[i] != ' ')
		{
			clearString(str);
			return 0;
		}
	}
	clearString(str);
	return 1;
}

#endif