#pragma once
class Point
{
	int x;
	int y;
public:
	Point() = default;

	Point(int a, int b);
	void Init(int a, int b);
	void Print();

	Point operator+(Point b);
	int operator+(int b);
	
	
	int operator-(Point b);
	int operator*(int b);
	int operator*(Point b);

	Point& operator ++();
	Point& operator --();
};

