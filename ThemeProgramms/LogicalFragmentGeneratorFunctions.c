#include "StringLib.h"
#include "LogicalFragmentGeneratorFunctions.h"

const int maxFormula = 3;
const int maxConjunction = 5;
const int maxMultiplier = 7;

int formulaCount = 0;
int conjunctionCount = 0;
int multiplierCount = 0;

String initLogicalFormula()
{
	formulaCount++;
	String conjunction = initConjunction();
	if ((rand() % 2 == 0) || (formulaCount > maxFormula))
	{
		return conjunction;
	}
	else
	{
		String strOr = initString(2), spaces = initSpaces(), formula = initLogicalFormula();
		setStringValue(strOr, "OR");
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
	conjunctionCount++;
	String multiplier = initMultiplier();
	if ((rand() % 2 == 0) || (conjunctionCount > maxConjunction))
	{
		return multiplier;
	}
	else
	{
		String strAnd = initString(3), spaces = initSpaces(), conjunction = initConjunction();
		setStringValue(strAnd, "AND");
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
	multiplierCount++;
	int chose = rand() % 5;
	if (((formulaCount > maxFormula || conjunctionCount > maxConjunction || multiplierCount > maxMultiplier) && (chose == 0)) ||
		(formulaCount > maxFormula && chose == 2))
	{
		chose++;
	}
	switch (chose)
	{
	case 0: {
		String strNot = initString(3), spaces = initSpaces(), multiplier = initMultiplier();
		setStringValue(strNot, "NOT");
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
		setStringValue(lBracket, "(");
		setStringValue(rBracket, ")");
		String lFormula = stringCat(lBracket, formula);
		clearString(lBracket);
		clearString(formula);
		String res = stringCat(lFormula, rBracket);
		clearString(rBracket);
		clearString(lFormula);
		return res;
		break;
	}
	case 3: {
		String strTrue = initString(4), spaces = initSpaces();
		setStringValue(strTrue, "TRUE");
		String res = stringCat(strTrue, spaces);
		clearString(strTrue);
		clearString(spaces);
		return res;
		break;
	}
	default: {
		String strFalse = initString(5), spaces = initSpaces();
		setStringValue(strFalse, "FALSE");
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
	String letter = initString(1), spaces = initSpaces();
	letter.value[0] = (char)(rand() % ((int)('Z' - 'A') + 1) + (int)'A');
	String variable = stringCat(letter, spaces);
	clearString(letter);
	clearString(spaces);
	return variable;
}

String initSpaces()
{
	int count = rand() % 10 + 1;
	String space = initString(1), res = initString(0), buff;
	setStringValue(space, " ");
	for (int i = 0; i < count; i++)
	{
		buff = stringCopy(res);
		clearString(res);
		res = stringCat(buff, space);
		clearString(buff);
	}
	clearString(space);
	return res;
}