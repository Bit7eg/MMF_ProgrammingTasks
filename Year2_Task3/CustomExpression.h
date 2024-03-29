#pragma once

#include "CustomString.h"

class Expression {
	public:
		static Expression* parseString(CustomString str);
		virtual Expression* diff(CustomString variable);
		virtual void print();
};

class Number : public Expression {
	private:
		double _num;
	public:
		Number();
		Number(double num);
		Expression* diff(CustomString variable);
		void print();
};

class Variable : public Expression {
	private:
 		CustomString _name;
	public:
		Variable(CustomString name);
		Expression* diff(CustomString variable);
		void print();
};

class Add : public Expression {
	private:
		Expression* _left;
		Expression* _right;
	public:
		Add(Expression* left, Expression* right);
		~Add();
		Expression* diff(CustomString variable);
		void print();
};

class Sub : public Expression {
	private:
		Expression* _left;
		Expression* _right;
	public:
		Sub(Expression* left, Expression* right);
		~Sub();
		Expression* diff(CustomString variable);
		void print();
};

class Mul : public Expression {
	private:
		Expression* _left;
		Expression* _right;
	public:
		Mul(Expression* left, Expression* right);
		~Mul();
		Expression* diff(CustomString variable);
		void print();
};

class Div : public Expression {
	private:
		Expression* _left;
		Expression* _right;
	public:
		Div(Expression* left, Expression* right);
		~Div();
		Expression* diff(CustomString variable);
		void print();
};
