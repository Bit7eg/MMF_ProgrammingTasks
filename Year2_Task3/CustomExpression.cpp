#include "CustomExpression.h"

#include <iostream>
#include <exception>
#include <map>
#include <utility>

#include "CustomString.h"
#include "CustomList.h"

CustomString Expression::getStringNumber(CustomString expression, int& position) {
	CustomString number = "";
	bool dotFlag = true;

	for (char num; position < expression.length(); position++)
	{
		num = expression[position];
		if (num >= '0' && num <= '9')
		{
			number += num;
		}
		else if (dotFlag && num == '.')
		{
			dotFlag = false;
			number += num;
		}
		else
		{
			position--;
			break;
		}
	}

	return number;
}

CustomString Expression::getStringVariable(CustomString expression, int& position) {
	CustomString variable = "";

	for (char ch; position < expression.length(); position++)
	{
		ch = expression[position];
		if (ch == '_' || (ch >= 'A' && ch <= 'Z') ||
			(ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
		{
			variable += ch;
		}
		else
		{
			position--;
			break;
		}
	}

	return variable;
}

Expression Expression::execOperation(char op, Expression left, Expression right) {
	switch (op)
	{
	case '+': return Add(left, right);
	case '-': return Sub(left, right);
	case '*': return Mul(left, right);
	case '/': return Div(left, right);
	default:
		throw std::exception("No such operation");
	}
}

Expression Expression::parseString(CustomString str) {
	std::map<char, int> operationPriority({
		std::pair<char, int>('(', 0),
		std::pair<char, int>('+', 1),
		std::pair<char, int>('-', 1),
		std::pair<char, int>('*', 2),
		std::pair<char, int>('/', 2),
		std::pair<char, int>('~', 3),
		});

	CustomString postfixExpression = "";
	CustomList<char> stack;
	char ch, buff;
	for (int i = 0; i < postfixExpression.length(); i++)
	{
		ch = str[i];

		if (ch >= '0' && ch <= '9')
		{
			postfixExpression += Expression::getStringNumber(str, i) + " ";
		}
		else if (ch == '_' || (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
		{
			i++;
			postfixExpression += (CustomString() + ch) + Expression::getStringVariable(str, i) + " ";
		}
		else if (ch == '(')
		{
			stack.push(ch);
		}
		else if (ch == ')')
		{
			if (stack.length() > 0)
			{
				buff = stack.pop();
			}
			while (stack.length() > 0 && buff != '(') {
				postfixExpression += buff;
				buff = stack.pop();
			}
		}
		else if (operationPriority.find(ch) != operationPriority.end())
		{
			if (ch == '-' && (i == 0 || (i > 0 && (operationPriority.find(str[i - 1]) != operationPriority.end()))))
			{
				ch = '~';
			}
			else
			{
				if (stack.length() > 0)
				{
					buff = stack.pop();
				}
				while (operationPriority[buff] >= operationPriority[ch])
				{
					postfixExpression += buff;
					if (stack.length() == 0)
					{
						buff = '\0';
						break;
					}
					buff = stack.pop();
				}
				if (buff != '\0')
				{
					stack.push(buff);
				}
			}
			stack.push(ch);
		}
	}
	while (stack.length() > 0)
	{
		postfixExpression += stack.pop();
	}

	Expression exprBuff;
	CustomList<Expression> exprStack;
	ch = '\0';
	for (int i = 0; i < postfixExpression.length(); i++)
	{
		ch = postfixExpression[i];
		if (operationPriority.find(ch) != operationPriority.end())
		{
			if (ch == '~')
			{
				if (exprStack.length() > 0)
				{
					exprStack.push(execOperation('-', Number(0.0), exprStack.pop()));
				}
				else
				{
					exprStack.push(execOperation('-', Number(0.0), Number(0.0)));
				}
				continue;
			}
			
			if (exprStack.length() > 0)
			{
				exprBuff = exprStack.pop();
			}
			else
			{
				exprBuff = Number(0.0);
			}

			if (exprStack.length() > 0)
			{
				exprStack.push(execOperation(ch, exprStack.pop(), exprBuff));
			}
			else
			{
				exprStack.push(execOperation(ch, Number(0.0), exprBuff));
			}
		}
		else if (ch >= '0' && ch <= '9')
		{
			exprStack.push(Number(atof(Expression::getStringNumber(postfixExpression, i))));
		}
		else if (ch == '_' || (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
		{
			i++;
			exprStack.push(Variable((CustomString() + ch) + Expression::getStringVariable(postfixExpression, i)));
		}
	}

	return exprStack.pop();
	//TODO: complite string parsing https://habr.com/ru/post/596925/
}

Expression Expression::diff(CustomString variable) {
	throw std::exception("This is virtual method!");
}

void Expression::print() {
	throw std::exception("This is virtual method!");
}

Number::Number() {
	this->_num = 0.0;
}

Number::Number(double num) {
	this->_num = num;
}

Expression Number::diff(CustomString variable) {
	return Number();
}

void Number::print() {
	std::cout<<this->_num;
}


Variable::Variable(CustomString name) {
	if(name[0]!='_' && (name[0] < 'A' || name[0] > 'Z') && (name[0] < 'a' || name[0] > 'z'))
		throw std::exception("Variable name is incorrect");
	for(size_t i = 1; i < name.length(); i++){
		if(name[0]!='_' && (name[0] < 'A' || name[0] > 'Z') &&
			(name[0] < 'a' || name[0] > 'z') && (name[0] < '0' || name[0] > '9'))
			throw std::exception("Variable name is incorrect");
	}
	this->_name = name;
}

Expression Variable::diff(CustomString variable) {
	if(variable == this->_name)
		return Number(1.0);
	return Number();
}

void Variable::print() {
	std::cout<<this->_name;
}


Add::Add(Expression left, Expression right) {
	this->_left = left;
	this->_right = right;
}

Expression Add::diff(CustomString variable) {
	return Add(this->_left.diff(variable), this->_right.diff(variable));
}

void Add::print() {
	this->_left.print();
	std::cout<<" + ";
	this->_right.print();
}


Sub::Sub(Expression left, Expression right) {
	this->_left = left;
	this->_right = right;
}

Expression Sub::diff(CustomString variable) {
	return Sub(this->_left.diff(variable), this->_right.diff(variable));
}

void Sub::print() {
	this->_left.print();
	std::cout << " - ";
	this->_right.print();
}


Mul::Mul(Expression left, Expression right) {
	this->_left = left;
	this->_right = right;
}

Expression Mul::diff(CustomString variable) {
	return Add(Mul(this->_left.diff(variable), this->_right), Mul(this->_left, this->_right.diff(variable)));
}

void Mul::print() {
	this->_left.print();
	std::cout << " * ";
	this->_right.print();
}


Div::Div(Expression left, Expression right) {
	this->_left = left;
	this->_right = right;
}

Expression Div::diff(CustomString variable) {
	return Div(Sub(Mul(this->_left.diff(variable), this->_right),
		Mul(this->_left, this->_right.diff(variable))), Mul(this->_right, this->_right));
}

void Div::print() {
	this->_left.print();
	std::cout << " / ";
	this->_right.print();
}
