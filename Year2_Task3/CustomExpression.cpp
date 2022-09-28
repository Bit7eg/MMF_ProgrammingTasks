#include "CustomExpression.h"

#include <iostream>
#include <exception>
#include <map>
#include <utility>

#include "CustomString.h"

Expression* Expression::parseString(CustomString str) {
	std::cout << "\nparseString\n";

	int start = 0, end = str.length(), op = 0;
	if (str[start] == '(' && str[end - 1] == ')')
	{
		start++;
		end--;
	}
	int openBreakets = 0, closeBreakets = 0;
	CustomString beforeOp, afterOp;
	for (int i = start; i < end; i++)
	{
		if (openBreakets == closeBreakets &&
			(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/'))
		{
			beforeOp = afterOp;
			afterOp = "";
			op = i;
		}
		else
		{
			if (str[i] == '(')
				openBreakets++;
			else if (str[i] == ')')
				closeBreakets++;
			afterOp += str[i];
		}
	}

	if (op == 0)
	{
		if (str[start] >= '0' && str[start] <= '9')
			return new Number(atof(afterOp));
		else
			return new Variable(afterOp);
	}
	else
	{
		Expression *left = parseString(beforeOp),
			*right = parseString(afterOp);

		switch (str[op])
		{
			case '+': return new Add(left, right);
			case '-': return new Sub(left, right);
			case '*': return new Mul(left, right);
			case '/': return new Div(left, right);
			default: return new Number();
		}
	}
}

Expression* Expression::diff(CustomString variable) {
	throw std::exception("This is virtual method!");
}

void Expression::print() {
	throw std::exception("This is virtual method!");
}

Number::Number() {
	std::cout << "\nNumber empty constructor\n";

	this->_num = 0.0;
}

Number::Number(double num) {
	std::cout << "\nNumber constructor\n";

	this->_num = num;
}

Expression* Number::diff(CustomString variable) {
	std::cout << "\nNumber diff\n";

	return new Number();
}

void Number::print() {
	std::cout<<this->_num;
}


Variable::Variable(CustomString name) {
	std::cout << "\nVariable constructor\n";

	if(name[0]!='_' && (name[0] < 'A' || name[0] > 'Z') && (name[0] < 'a' || name[0] > 'z'))
		throw std::exception("Variable name is incorrect");
	for(size_t i = 1; i < name.length(); i++){
		if(name[0]!='_' && (name[0] < 'A' || name[0] > 'Z') &&
			(name[0] < 'a' || name[0] > 'z') && (name[0] < '0' || name[0] > '9'))
			throw std::exception("Variable name is incorrect");
	}
	this->_name = name;
}

Expression* Variable::diff(CustomString variable) {
	std::cout << "\nVariable diff\n";

	if(variable == this->_name)
		return new Number(1.0);
	return new Number();
}

void Variable::print() {
	std::cout<<this->_name;
}


Add::Add(Expression* left, Expression* right) {
	std::cout << "\nAdd constructor\n";

	this->_left = left;
	this->_right = right;
}

Add::~Add() {
	delete this->_left;
	delete this->_right;
}

Expression* Add::diff(CustomString variable) {
	std::cout << "\nAdd diff\n";

	return new Add(this->_left->diff(variable), this->_right->diff(variable));
}

void Add::print() {
	std::cout << "(";
	this->_left->print();
	std::cout<<" + ";
	this->_right->print();
	std::cout << ")";
}


Sub::Sub(Expression* left, Expression* right) {
	std::cout << "\nSub constructor\n";

	this->_left = left;
	this->_right = right;
}

Expression* Sub::diff(CustomString variable) {
	std::cout << "\nSub diff\n";

	return new Sub(this->_left->diff(variable), this->_right->diff(variable));
}

void Sub::print() {
	std::cout << "(";
	this->_left->print();
	std::cout << " - ";
	this->_right->print();
	std::cout << ")";
}


Mul::Mul(Expression* left, Expression* right) {
	std::cout << "\nMull constructor\n";

	this->_left = left;
	this->_right = right;
}

Expression* Mul::diff(CustomString variable) {
	std::cout << "\nMull diff\n";

	return new Add(new Mul(this->_left->diff(variable), this->_right), new Mul(this->_left, this->_right->diff(variable)));
}

void Mul::print() {
	std::cout << "(";
	this->_left->print();
	std::cout << " * ";
	this->_right->print();
	std::cout << ")";
}


Div::Div(Expression* left, Expression* right) {
	std::cout << "\nDiv constructor\n";

	this->_left = left;
	this->_right = right;
}

Expression* Div::diff(CustomString variable) {
	std::cout << "\nDiv diff\n";

	return new Div(new Sub(new Mul(this->_left->diff(variable), this->_right),
		new Mul(this->_left, this->_right->diff(variable))), new Mul(this->_right, this->_right));
}

void Div::print() {
	std::cout << "(";
	this->_left->print();
	std::cout << " / ";
	this->_right->print();
	std::cout << ")";
}
