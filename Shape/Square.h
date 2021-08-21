#pragma once

#include<iostream>
#include<string>
#include<cstring>

using namespace std;

#ifndef SQUARE_H
#define SQUARE_H
#include "Shape.h"


class Square : public Shape
{

private:
	double squareLength;

public:

	Square(const string& color, double length);

	double area() const;
	string toString() const;
	

};
#endif // !SQUARE_H
