#include "Rectangle.h"
#include "Square.h"
#include "circle.h"

#include<iostream>
#include <iomanip>
#include<string>
#include<cstring>

using namespace std;

Shape* getShape()
{
	string shape;
	string color;
	Shape* temp;

	double rectWidth;
	double rectLenght;
	double squareLength;
	double  circleRadius;

	/***** Select a shape's color *****/
	cout << "Enter the shape's color (or'done')..." << endl;
	cin >> color;

	if (strcmp("done", color.c_str()) == 0)
	{
		return nullptr;
	}
	else
	{
		/***** Select a shape type *****/
		do {
			cout << "Enter shape type..." << endl;
			cin >> shape;

		} while (strcmp(shape.c_str(), "square") == 1 && strcmp(shape.c_str(), "circle") == 1 && strcmp(shape.c_str(), "rectangle") == 1);

		if (strcmp(shape.c_str(), "rectangle") == 0)
		{
			cout << "Enter the length and width... " << endl;
			cin >> rectLenght >> rectWidth;
			temp = new Rectangle(color, rectWidth, rectLenght);

		}
		else if (strcmp(shape.c_str(), "circle") == 0)
		{

			cout << "Enter the radius... " << endl;
			cin >> circleRadius;
			temp = new Circle(color, circleRadius);

		}

		else if (strcmp(shape.c_str(), "square") == 0)
		{
			cout << "Enter the length of a side..." << endl;
			cin >> squareLength;
			temp = new Square(color, squareLength);
		}
		else
		{
			return nullptr;
		}
		return temp;

	}
}