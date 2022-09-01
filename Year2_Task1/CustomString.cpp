#include "CustomString.h"

#include <iostream>

CustomString::CustomString() {
	std::cout << "\nINFO::CustomString::Constructor()\n";

	this->_data = new char;
	*this->_data = '\0';
	this->_length = 0;
}

CustomString::CustomString(const char* data) {
	std::cout << "\nINFO::CustomString::Constructor(char*)\n";
	
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
	std::cout << "\nINFO::CustomString::Constructor(const CustomString&)\n";

	this->_length = str._length;
	this->_data = new char[this->_length + 1];
	for (size_t i = 0; i < this->_length + 1; i++)
	{
		this->_data[i] = str._data[i];
	}
}

CustomString::~CustomString() {
	std::cout << "\nINFO::CustomString::Destructor()\n";

	delete[] this->_data;
}

unsigned int CustomString::length() {
	std::cout << "\nINFO::CustomString::length()\n";

	return this->_length;
}

void CustomString::setString(char* value) {
	std::cout << "\nINFO::CustomString::setString(char*)\n";

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
	std::cout << "\nINFO::CustomString::operator{=CustomString}\n";

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
	std::cout << "\nINFO::CustomString::operator(const char*)\n";

	return this->_data;
}

CustomString CustomString::operator+(CustomString str) {
	std::cout << "\nINFO::CustomString::operator{+CustomString}\n";

	CustomString sum = *this;
	sum += str._data;
	return sum;
}

CustomString CustomString::operator+(const char* data) {
	std::cout << "\nINFO::CustomString::operator{+const char*}\n";

	CustomString sum = *this;
	for (size_t i = 0; data[i] != '\0'; i++)
	{
		sum += data[i];
	}
	return sum;
}

CustomString CustomString::operator+(const char character) {
	std::cout << "\nINFO::CustomString::operator{+const char}\n";

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
	std::cout << "\nINFO::CustomString::operator{+=CustomString}\n";

	*this = *this + str;
	return *this;
}

CustomString CustomString::operator+=(const char* data) {
	std::cout << "\nINFO::CustomString::operator{+=const char*}\n";

	*this = *this + data;
	return *this;
}

CustomString CustomString::operator+=(const char character) {
	std::cout << "\nINFO::CustomString::operator{+=const char}\n";

	*this = *this + character;
	return *this;
}

char& CustomString::operator[](const int index) {
	std::cout << "\nINFO::CustomString::operator[const int]\n";
	
	return this->_data[index];
}