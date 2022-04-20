#ifndef LFGENERATOR_C
#define LFGENERATOR_C

#include <time.h>

#include "StringLib.h"

String initLogicalFormula()
{
	srand(time(NULL));
	String conjunction = initConjunction();
	if (rand() % 2 == 0)
	{
		return conjunction;
	}
	else
	{
		String strOr = initString(2), spaces = initSpaces(), formula = initLogicalFormula();
		strOr.value = "OR";
		String conjunctionOr = stringCat(conjunction, strOr), spacesFormula = stringCat(spaces, formula);
		clearString(conjunction);
		clearString(strOr);
		clearString(spaces);
		clearString(formula);
		String logicalFormula = stringCat(conjunctionOr, spacesFormula);
		clearString(conjunctionOr);
		clearString(spacesFormula);
		return logicalFormula;
	}
}

String initConjunction()
{
	srand(time(NULL));
	String multiplier = initMultiplier();
	if (rand() % 2 == 0)
	{
		return multiplier;
	}
	else
	{
		String strAnd = initString(3), spaces = initSpaces(), conjunction = initConjunction();
		strAnd.value = "AND";
		String multiplierAnd = stringCat(multiplier, strAnd), spacesConjunction = stringCat(spaces, conjunction);
		clearString(conjunction);
		clearString(strAnd);
		clearString(spaces);
		clearString(multiplier);
		String res = stringCat(multiplierAnd, spacesConjunction);
		clearString(multiplierAnd);
		clearString(spacesConjunction);
		return res;
	}
}

String initMultiplier()
{
	srand(time(NULL));
	switch (rand() % 5)
	{
	case 0: {
		String strNot = initString(3), spaces = initSpaces(), multiplier = initMultiplier();
		strNot.value = "NOT";
		String notSpaces = stringCat(strNot, spaces);
		clearString(strNot);
		clearString(spaces);
		String res = stringCat(notSpaces, multiplier);
		clearString(notSpaces);
		clearString(multiplier);
		return res;
		break;
	}
	case 1: {
		return initVariable();
		break;
	}
	case 2: {
		String lBracket = initString(1), formula = initLogicalFormula(), rBracket = initString(1);
		lBracket.value = "(";
		rBracket.value = ")";
		String lFormula = stringCat(lBracket, formula);
		clearString(lBracket);
		clearString(formula);
		String res = stringCat(lFormula, rBracket);
		return res;
		break;
	}
	case 3: {
		String strTrue = initString(4), spaces = initSpaces();
		strTrue.value = "TRUE";
		String res = stringCat(strTrue, spaces);
		clearString(strTrue);
		clearString(spaces);
		return res;
		break;
	}
	default: {
		String strFalse = initString(5), spaces = initSpaces();
		strFalse.value = "FALSE";
		String res = stringCat(strFalse, spaces);
		clearString(strFalse);
		clearString(spaces);
		return res;
		break;
	}
	}
}

String initVariable()
{
	srand(time(NULL));
	String letter = initString(1), spaces = initSpaces();
	letter.value[0] = (char)(rand() % ((int)('Z' - 'A') + 1) + (int)'A');
	String variable = stringCat(letter, spaces);
	clearString(letter);
	clearString(spaces);
	return variable;
}

String initSpaces()
{
	srand(time(NULL));
	int count = rand() % 10 + 1;
	String space = initString(1), res = initString(0), buff;
	space.value = " ";
	for (int i = 0; i < count; i++)
	{
		buff = res;
		clearString(res);
		res = stringCat(buff, space);
		clearString(buff);
	}
	clearString(space);
	return res;
}

#endif