#include "Square.h"

#include<iostream>
#include<string>
#include<sstream>
#include <iomanip>

using namespace std;

Square::Square(const string & color, double length): Shape(color)
{
	this->squareLength = length;
}

double Square::area() const
{

	return ((this->squareLength)*(this->squareLength));
}

string Square::toString() const
{
	ostringstream out;
	string str;

	out << getColor();
	out << " square with side length of " << this->squareLength;
	out<< " and area of " << area();


	str = out.str();

	return str;
}
