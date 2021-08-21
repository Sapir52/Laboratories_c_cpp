#include "circle.h"

#include<iostream>
#include<string>
#include<sstream>
#include <iomanip>

using namespace std;

Circle::Circle(const string & color, double radius):Shape(color)
{
	this->circleRadius = radius;
}

double Circle::area() const
{
	double pie{ 3.1415926535 };
	double scope =  pie * (this->circleRadius)* (this->circleRadius);
	return scope;
}

string Circle::toString() const 
{
	ostringstream out;
	string str;

	out << getColor();
	out << " circle with radius of " << this->circleRadius;
	out << " and area of " << area();

	str = out.str();

	return str;
}
