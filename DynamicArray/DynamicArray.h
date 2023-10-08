#pragma once
#include <iostream>
using namespace std;

class DynamicArray
{
	int* ptr; // ��������� �� �����. ������
	int size;  // ������ ������� 
public:
	DynamicArray();
	DynamicArray(int);
	DynamicArray(const DynamicArray&); // copy constructor
	~DynamicArray();
	void Input();// rand
	void Output() const;// ����� �� �������
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
		
	// ����������� ��������� ������:
	
	//void Sort();// ����������(����� �������� ����������)// ���������� �� �����������
	//int Search(int a); // ����� �������� � �������, ���������� ������ ���������� ��., ���� -1.
	// ���� �������� ����� �� ���� ������� ����� ������ ������������ 
	//void Reverse(); // �������������� ������������������ ��������� � �������� �������, ������� 12345 -> 54321// �� ���������� � ��������������(������ � ������)


};


