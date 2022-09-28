#include <iostream>

#include "CustomExpression.h"
#include "CustomString.h"

int main(){
	CustomString strExpr;
	char ch = getchar();
	while (ch != '\n')
	{
		strExpr += ch;
		ch = getchar();
	}
	Expression* expr = Expression::parseString(strExpr);
	Expression* difExpr = expr->diff(CustomString("x"));
	expr->print();
	std::cout << std::endl;
	difExpr->print();
	std::cout << std::endl;

	return 0;
}