#pragma once
#ifndef CLASS_BIGINTEGER_H
#define CLASS_BIGINTEGER_H
#include <iostream>

class BigInteger
{
private:
	char* number;

	char* swapFunc(char *str, int end);
	char* connectionFunc(char* str, int size1, int size2, int ind1, int  ind2, const BigInteger&);
	char* subtractionFunc(char* str, int size1, int size2, int ind1, int  ind2,int temp,const BigInteger&);


public:
	BigInteger();
	BigInteger(int);
	BigInteger(const char*);
	BigInteger(const BigInteger&);
	BigInteger(BigInteger&&);
	~BigInteger();

	void setValue(int);
	void setValue(const char*);
	void setValue(const BigInteger&);

	static BigInteger fromString(const char*);

	const BigInteger operator+(const BigInteger&) const;
	const BigInteger operator-(const BigInteger&) const;
	const BigInteger operator*(const BigInteger&) const;
	const BigInteger operator/(const BigInteger&) const;

	BigInteger& operator=(const BigInteger&);
	BigInteger& operator=(BigInteger&&);

	int operator[](int) const;

	BigInteger& operator+=(const BigInteger&);
	BigInteger& operator-=(const BigInteger&);
	BigInteger& operator*=(const BigInteger&);
	BigInteger& operator/=(const BigInteger&);

	bool operator==(const BigInteger&) const;
	bool operator!=(const BigInteger&) const;
	bool operator<(const BigInteger&) const;
	bool operator>(const BigInteger&) const;
	bool operator<=(const BigInteger&) const;
	bool operator>=(const BigInteger&) const;

	BigInteger& operator++();
	BigInteger operator++(int);

	friend std::ostream& operator<<(std::ostream&, const BigInteger&);
	friend std::istream& operator >> (std::istream&, BigInteger&);

};

#endif