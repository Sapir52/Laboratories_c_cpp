#include "Shape.h"

#include <iostream>
#include <iomanip>
#include<fstream> 

using namespace std;

#define SIZE 3

Shape* getShape();

/***** Auxiliary functions *****/
void funcOut(Shape *shapes[SIZE]);
Shape* swapFunc(Shape *shapes[SIZE]);
void shapeFile();

int main()
{
	Shape *shapes[SIZE];

	int i{};

	for (i = 0; shapes[i] != nullptr && i < SIZE; i++)
	{
		shapes[i] = getShape();
	}
	cout << fixed << setprecision(2);
	cout <<endl<<"The list of shapes entered...\n";

	funcOut(shapes);

	cout <<endl<< "Sorting shapes into order by area..." << endl;
	cout << "The sorted list of shapes..." << endl;

	*shapes =swapFunc(shapes);
	funcOut(shapes);
	shapeFile();

	/***** delete shapes *****/
	for (i = 0; shapes[i] != nullptr&& i < SIZE; i++)
	{
		delete shapes[i];
	}
	return 0;
}

/***************************************************************/
/***** swap function *****/
Shape* swapFunc(Shape *shapes[SIZE])
{
	Shape *temp;
	int i{};
	int j{};
	for (i = 0; shapes[i] != nullptr && i < SIZE; i++)
	{
		for (j = 0; j <= i; j++)
		{
			if (shapes[i]->area() <= shapes[j]->area())
			{
				temp = shapes[i];
				shapes[i] = shapes[j];
				shapes[j] = temp;
			}
		}
	}
	return *shapes;
}
/***************************************************************/
/***** A function that prints a list of shapes *****/

void funcOut(Shape *shapes[SIZE])
{
	int i{};
	for (i = 0; shapes[i] != nullptr && i<SIZE; i++)
	{
		cout << shapes[i]->toString() << endl;
	}
}

/***************************************************************/
/***** function bunus *****/
void shapeFile()
{

	ofstream ofs("shapeFile.txt", ios::app);
	if (!ofs)
	{
		cerr << "Error of open file shapeFile.txt";
		exit(1);
	}


	string shape;
	string color;

	double rectWidth;
	double rectLenght;
	double squareLength;
	double  circleRadius;

	cout <<endl<< "Test Date" << endl;
	cout << "Use the following test data values" << endl;
	int i{};
	do {
		cout << "Enter color and shape into file" << endl;
		cin >> color >> shape;

		if (strcmp(shape.c_str(), "rectangle") == 0)
		{
			ofs << color << " " << shape << " ";
			cout << "Enter longht and width into file" << endl;
			cin >> rectLenght >> rectWidth;
			ofs << rectLenght << " " << rectWidth << endl;
		}
		else if (strcmp(shape.c_str(), "circle") == 0)
		{
			ofs << color << " " << shape << " ";
			cout << "Enter radius into file " << endl;
			cin >> circleRadius;
			ofs << circleRadius << endl;

		}

		else if (strcmp(shape.c_str(), "square") == 0)
		{
			ofs << color << " " << shape << " ";
			cout << "Enter the length into file" << endl;
			cin >> squareLength;
			ofs << squareLength << endl;
		}
		else
		{
			ofs << color << " " << "NULL" << " ";
		}
		i++;
	} while (i < SIZE);
	ofs.close();

}