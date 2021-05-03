#include<iostream>
#include<conio.h>
#include<stdlib.h>

using namespace std;

class distance
{
	int feet;
	float inches;

public:

	distance()
	{
		feet = 0;
		inches = 0.0;
	}

	distance setter(distance f, distance s)
	{
		distance temp;
		temp.feet = feet + f.feet + s.feet;
		temp.inches = inches + f.inches + s.inches;
		while (temp.inches >= 12)
		{
			temp.feet++;
			temp.inches -= 12;
		}
		return temp;
	}
	void getter();
	void display();
}d1, d2, d3, d4;

void distance::getter()
{
	cout << "\n\tEnter the Value of Feet And Inches respectively:";
	cin >> feet >> inches;
}

void distance::display()
{
	cout << "\n\tFeet=" << feet;
	cout << "\tInches=" << inches;
}

void main()
{
	system("cls");
	d1.getter();
	d2.getter();
	d3.getter();
	d4 = d1.setter(d2,d3);
	d4.display();
	_getch();
}
