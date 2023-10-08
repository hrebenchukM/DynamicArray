#include "Point.h"
#include "Point.h"
#include<iostream>
using namespace std;

Point::Point(int a, int b)
{
	x = a;
	y = b;
}

void Point::Init(int a, int b)
{
	x = a;
	y = b;
}

void Point::Print()
{
	cout << x << "\t" << y << endl;
}

Point Point::operator+(Point b)
{
	Point rez;
	rez.x = this->x + b.x;
	rez.y = this->y + b.y;
	return rez;

	//return Point(this->x+b.x,this->y+b.y);
}



int Point::operator+(int b)
{
	return x + y + b;
}











int Point::operator-(Point b)
{
	return x - b.x - y - b.y;

}

int Point::operator*(int b)
{
	return x* b*y;

}


int Point::operator*(Point b)
{
	return x *y*b.x*b.y;
}

Point& Point::operator++()
{  
	this->x += 10;
	this->y += 10;
	return *this;
}

Point& Point::operator--()
{
	this->x -= 10;
	this->y -= 10;
	return *this;
}

