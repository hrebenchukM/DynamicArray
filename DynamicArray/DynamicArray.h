#pragma once
#include <iostream>
using namespace std;

class DynamicArray
{
	int* ptr; // указатель на динам. массив
	int size;  // размер массива 
public:
	DynamicArray();
	DynamicArray(int);
	DynamicArray(const DynamicArray&); // copy constructor
	~DynamicArray();
	void Input();// rand
	void Output() const;// вывод на консоль
	int* GetPointer() const;
	int GetSize() const;


	void Sort();
	int Search(int a) const;
	void Reverse();
	void ReSize(int newSize);
	void DownSize(int newSize);



	DynamicArray operator+(int b);
	DynamicArray operator-(int b);
	DynamicArray operator*(int b);


	DynamicArray operator-( DynamicArray&b);
	DynamicArray operator+(DynamicArray b);

	DynamicArray& operator++();
	DynamicArray& operator--();
		
	// реилизовать следующие методы:
	
	//void Sort();// сортировка(любой алгоритм сортировки)// сортировка по возрастанию
	//int Search(int a); // поиск элемента в массиве, возвращает индекс наиденного эл., либо -1.
	// Надо подумать какие из этих методов стоит делать константными 
	//void Reverse(); // перезаписывает последовательность элементов в обратном порядке, напрмер 12345 -> 54321// НЕ показывает а перезаписывает(замена в памяти)


};


