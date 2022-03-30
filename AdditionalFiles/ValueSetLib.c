#include <stdio.h>
#include <stdlib.h>
#include "ValueSetLib.h"

VALUE_SET initValueSet() {
	VALUE_SET set = malloc(sizeof(varValue));
	set->name = '\0';
	set->value = 0;
}

int getVarCount(VALUE_SET vars) {
	unsigned int length = 0;
	while ((vars[length].name != '\0') || (vars[length].value != 0))
	{
		length++;
	}
	return length;
}

void killValueSet(VALUE_SET vars) {
	free(vars);
}

varValue* getVarPointerByName(VALUE_SET vars, char name) {
	int size = getVarCount(vars);
	for (size_t i = 0; i < size; i++)
	{
		if (vars[i].name == name)
		{
			return vars + i;
		}
	}
	return NULL;
}

VALUE_SET addVar(VALUE_SET vars, varValue variable) {
	int size = getVarCount(vars);
	vars = realloc(vars, (size + 1) * sizeof(varValue));
	vars[size - 1] = variable;
	vars[size].name = '\0';
	vars[size].value = 0;
	return vars;
}

void scanValueSet(VALUE_SET vars) {
	varValue* varPointer;
	char name;
	int value;
	scanf("%c%i", &name, &value);
	while ((name >= 'A') && (name <= 'Z'))
	{
		varPointer = getVarPointerByName(vars, name);
		if (varPointer == NULL)
		{
			addVar(vars, *varPointer);
		}
		else
		{
			varPointer->value = value;
		}
		scanf("%c%i", &name, &value);
	}
}

void printValueSet(VALUE_SET vars) {
	int size = getVarCount(vars);
	for (size_t i = 0; i < size; i++)
	{
		printf("%c = %i\n", vars[i].name, vars[i].value);
	}
}