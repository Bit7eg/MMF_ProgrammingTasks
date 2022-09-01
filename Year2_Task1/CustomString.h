#pragma once
class CustomString
{
private:
	char* _data;
	unsigned int _length;
public:
	CustomString();
	CustomString(const char* data);
	CustomString(const CustomString& str);

	~CustomString();

	unsigned int length();

	void setString(char* value);

	CustomString operator=(CustomString str);

	operator const char* () const;

	CustomString operator+(CustomString str);
	CustomString operator+(const char* data);
	CustomString operator+(const char character);

	CustomString operator+=(CustomString str);
	CustomString operator+=(const char* data);
	CustomString operator+=(const char character);

	char& operator[](const int index);
};