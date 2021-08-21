#pragma once
#include<iostream>
#include<string>
#include<cstring>

using namespace std;

#ifndef CIRCLE_H
#define CIRCLE_H
#include "Shape.h"

class Circle : public Shape
{

private:
	double  circleRadius;

public:

	Circle(const string& color, double radius);

	double area() const;
	string toString() const;

};
#endif // !CIRCLE_H
