#include "Shape.h"

#include<iostream>
#include<string>

using namespace std;

Shape::Shape(const string &color)
{
	this->colorShape = color;	
}

string Shape::getColor() const
{
	return this->colorShape;
}
