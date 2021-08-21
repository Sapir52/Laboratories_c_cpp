#pragma once

#include<iostream>
#include<string>
#include<cstring>

using namespace std;

#ifndef SHAPE_H
#define SHAPE_H

class Shape
{
private:
	string colorShape;

public:

	Shape(const string& color); 
	string getColor() const;

	virtual double area() const=0;
	virtual string toString() const=0;
	
};

#endif // !SHAPE_H
