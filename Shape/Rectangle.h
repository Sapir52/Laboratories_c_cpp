#pragma once

#include<iostream>
#include<string>
#include<cstring>

using namespace std;

#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Shape.h"


class Rectangle : public Shape
{
private:

	double rectWidth;
	double rectLenght;

public:

	Rectangle(const string& color, double width, double length);

	double area() const;
	string toString() const;

};
#endif // !RECTANGLE_H
