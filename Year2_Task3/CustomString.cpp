#include "CustomString.h"

#include <iostream>

CustomString::CustomString() {
	this->_data = new char;
	*this->_data = '\0';
	this->_length = 0;
}

CustomString::CustomString(const char* data) {
	this->_length = 0;
	for (size_t i = 0; data[i] != '\0'; i++)
	{
		this->_length++;
	}
	this->_data = new char[this->_length + 1];
	for (size_t i = 0; i < this->_length + 1; i++)
	{
		this->_data[i] = data[i];
	}
}

CustomString::CustomString(const CustomString& str) {
	this->_length = str._length;
	this->_data = new char[this->_length + 1];
	for (size_t i = 0; i < this->_length + 1; i++)
	{
		this->_data[i] = str._data[i];
	}
}

CustomString::~CustomString() {
	delete[] this->_data;
}

unsigned int CustomString::length() {
	return this->_length;
}

void CustomString::setString(char* value) {
	this->_length = 0;
	for (size_t i = 0; value[i] != '\0'; i++)
	{
		this->_length++;
	}
	delete[] this->_data;
	this->_data = new char[this->_length + 1];
	for (size_t i = 0; i < this->_length + 1; i++)
	{
		this->_data[i] = value[i];
	}
}

CustomString CustomString::operator=(CustomString str) {
	this->_length = str._length;
	delete[] this->_data;
	this->_data = new char[this->_length + 1];
	for (size_t i = 0; i < this->_length + 1; i++)
	{
		this->_data[i] = str._data[i];
	}
	return *this;
}

CustomString::operator const char* () const {
	return this->_data;
}

CustomString CustomString::operator+(CustomString str) {
	CustomString sum = *this;
	sum += str._data;
	return sum;
}

CustomString CustomString::operator+(const char* data) {
	CustomString sum = *this;
	for (size_t i = 0; data[i] != '\0'; i++)
	{
		sum += data[i];
	}
	return sum;
}

CustomString CustomString::operator+(const char character) {
	CustomString sum;
	sum._length = this->_length + 1;
	sum._data = new char[sum._length + 1];
	sum._data[sum._length] = '\0';
	for (size_t i = 0; i < this->_length; i++)
	{
		sum._data[i] = this->_data[i];
	}
	sum._data[sum._length-1] = character;
	return sum;
}

CustomString CustomString::operator+=(CustomString str) {
	*this = *this + str;
	return *this;
}

CustomString CustomString::operator+=(const char* data) {
	*this = *this + data;
	return *this;
}

CustomString CustomString::operator+=(const char character) {
	*this = *this + character;
	return *this;
}

bool CustomString::operator==(const char* data) {
	return this->_data == data;
}

bool CustomString::operator==(CustomString str) {
	return this->_data == str._data;
}

bool CustomString::operator!=(const char* data) {
	return this->_data != data;
}

bool CustomString::operator!=(CustomString str) {
	return this->_data != str._data;
}

char& CustomString::operator[](const int index) {
	return this->_data[index];
}