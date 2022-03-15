#pragma once
#ifndef VALUESETLIB_H
#define VALUESETLIB_H

typedef struct varValue {
	char name;
	int value;
} varValue;
typedef varValue* VALUE_SET;

VALUE_SET initValueSet();
int getVarCount(VALUE_SET);
void killValueSet(VALUE_SET);
varValue* getVarPointerByName(VALUE_SET, char);
VALUE_SET addVar(VALUE_SET, varValue);
void scanValueSet(VALUE_SET);
void printValueSet(VALUE_SET);

#include "ValueSetLib.c"

#endif