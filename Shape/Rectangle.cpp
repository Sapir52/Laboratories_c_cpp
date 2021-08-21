#include "Rectangle.h"

#include<iostream>
#include<string>
#include<sstream>
#include <iomanip>

using namespace std;

Rectangle::Rectangle(const string & color, double width, double length) : Shape(color)
{
	this->rectWidth = width;
	this->rectLenght = length;
}

double Rectangle::area() const
{
	return (this->rectWidth * this->rectLenght);
}

string Rectangle::toString() const
{
	ostringstream out;
	string str;

	out << getColor();
	out << " rectangle with length of " << rectLenght;
	out << " and width of " << this->rectWidth;
	out << " and area of " << area();

	str = out.str();

	return str;
}
