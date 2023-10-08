#include "DynamicArray.h"

#include<Windows.h>

DynamicArray::DynamicArray() :ptr(nullptr), size(0)
{}
DynamicArray::DynamicArray(int S)
{
	cout << "Construct by 1 param\n";
	size = S;
	ptr = new int[S]{ 0 };
}

DynamicArray::DynamicArray(const DynamicArray& a)// copy constructor
{
	cout << "Copy construct\n";
	size = a.size;
	ptr = new int[size];
	for (int i = 0; i < size; i++)
	{
		ptr[i] = a.ptr[i];
	}
}
DynamicArray::~DynamicArray()
{
	cout << "Destruct\n";
	if (ptr != 0)
	{
		delete[] ptr;
	}
	
}
void DynamicArray::Input()
{
	for (int i = 0; i < size; i++)
	{
		ptr[i] = rand() % 20;
	}
}
void DynamicArray::Output() const
{
	if (ptr == nullptr) {
		cout << "Array is empty\n\n";
	}
	else {
		for (int i = 0; i < size; i++)
		{
			cout << ptr[i] << "\t";
		}
		cout << "\n-------------------------------------------------------------------------------------------------------------------------\n";
	}
}
int* DynamicArray::GetPointer() const
{
	return ptr;
}
int DynamicArray::GetSize() const
{
	return size;
}

void DynamicArray::ReSize(int newSize)//void ReSize(int size);// ��������� ������� ������� //�������� ��� 2 �������� � ����� �������� � ���������� ������ �� 7 � ��������� ��������������
	//���� �������� ��� ��� ����������� ������ ����� ���������
{
	int *newPtr = new int[size+newSize];//������� ����� ������ �� 7 ��������� ������ 

	for (int i = 0; i <size; i++)
	{
		newPtr[i] = ptr[i];//��������� ����� ������ ������� 5 ����������
	}

	for (int i = 0; i < newSize; i++)
	{
		newPtr[size+i] = 0;
	}

	delete[] ptr;
    ptr=newPtr;//������������ ������ ��������� �� ����� ��������� 
	size = size+newSize;// ������������ ������ ������ �� �����

	
}
 
void DynamicArray::DownSize(int newSize)//void ReSize(int size);// ��������� ������� ������� // �������� ��� 2 �������� =3 � ��������� ��������������
//���� �������� ��� ��� ����������� ������ ����� ���������
{

	if (newSize >= size)
	{
		return;
	}
	else {
		int* newPtr = new int[size - newSize];//������� ����� ������ �� 3 ��������� ������ 

		for (int i = 0; i < size - newSize; i++)
		{
			newPtr[i] = ptr[i];//��������� ����� ������ ������� 3 ����������
		}


		delete[] ptr;
		ptr = newPtr;//������������ ������ ��������� �� ����� ��������� 
		size = size- newSize;// ������������ ������ ������ �� �����

	}
	

}










void DynamicArray::Sort()
{
		int temp;

		for (int j = 0; j < size-1; j++)//n-1  ���
		{
			bool allSorted = true;
			for (int i = 0; i < size-1; i++) {
				if (ptr[i] > ptr[i + 1]) {
					temp = ptr[i];
					ptr[i] = ptr[i + 1];
					ptr[i + 1] = temp;
					allSorted = false;
				}
			}
			if (allSorted) {
				break;
			}
		}

}

int DynamicArray::Search(int a) const {
	for (int i = 0; i < size; ++i) {
		if (ptr[i] == a) {
			return i; 
		}
	}
	return -1; 
}

void DynamicArray::Reverse()
{
	for (int i = 0; i < size/2; ++i) {
		int temp = ptr[size - i - 1];
		ptr[size - i - 1] = ptr[i];
		ptr[i] = temp;
	
	}
}


DynamicArray DynamicArray::operator+(int b)
{
	int newSize = size + b;
	DynamicArray rez(newSize);

	for (int i = 0; i < size; i++)
	{
		rez.ptr[i] = ptr[i];
	}

	for (int i = 0; i < b; i++)
	{
		rez.ptr[size+i] = 0;
	}
	return rez;

	//ReSize(b);//�������� (����)������� ������ � ������ �� ���������� 
	//return *this;//resize ������ �������� �� �������  this (����� ��������� � ����������/������� ������ �� ������� ���������� ������)
	
}


DynamicArray DynamicArray::operator-(int b)
{

	int newSize = size - b;
	DynamicArray rez(newSize);

	for (int i = 0; i < newSize; i++)
	{
		rez.ptr[i] = ptr[i];
	}
	
	return rez;

	//DownSize(b);//�������� (����)������� ������ � ������ �� ���������� 
	//return *this;//resize ������ �������� �� �������  this (����� ��������� � ����������/������� ������ �� ������� ���������� ������)

}

DynamicArray DynamicArray::operator*(int b)
{
	DynamicArray rez(*this);//����� �
	for (int i = 0; i < size; i++)
	{
		rez.ptr[i]*=b;
	}
	return rez;

}

DynamicArray DynamicArray::operator-(DynamicArray b)
{
	DynamicArray rez(size);
	if (size > b.size) {

		for (int i = 0; i < size; ++i) {
			rez.ptr[i] = ptr[i] - b.ptr[i];
		}

		return rez;
	}
	else if (size < b.size) {

		for (int i = 0; i <b.size; ++i) {
			rez.ptr[i] = b.ptr[i] - ptr[i];
		}

		return rez;
	}
	else
	{
		return 0;
	}

	
	
}

DynamicArray DynamicArray::operator+(DynamicArray b)
{
	int newSize = this->size + b.size;
	DynamicArray rez(newSize);

	for (int i = 0; i < size; i++)
	{
		rez.ptr[i] = ptr[i];
	}


	for (int i = 0; i < b.size; i++)
	{
		rez.ptr[size + i] = b.ptr[i];
	}
	return rez;
}

DynamicArray& DynamicArray::operator++()
{
	int newSize = size + 1;
	int* rez = new int[newSize];


	for (int i = 0; i < size; ++i) {
		rez[i] = ptr[i];
	}

	rez[size]=0;

	delete[] ptr;

	ptr = rez;
	size = newSize;

		return *this;
}

DynamicArray& DynamicArray::operator--()
{
	int newSize = size - 1;
	int* rez = new int[newSize];

	for (int i = 0; i < newSize; ++i) {
		rez[i] = ptr[i];
	}
	delete[] ptr;

	ptr = rez;
	size = newSize;
	//ptr[size] = 0;
	return *this;
}




//
//
//Point Point::operator+(Point b)
//{
//	Point rez;
//	rez.x = this->x + b.x;
//	rez.y = this->y + b.y;
//	return rez;
//
//	//return Point(this->x+b.x,this->y+b.y);
//}
//
//
//
//int Point::operator+(int b)
//{
//	return x + y + b;
//}
//
//
//
//
//
//int Point::operator-(Point b)
//{
//	return x - b.x - y - b.y;
//
//}
//
//int Point::operator*(int b)
//{
//	return x * b * y;
//
//}
//
//
//int Point::operator*(Point b)
//{
//	return x * y * b.x * b.y;
//}
//
//Point& Point::operator++()
//{
//	this->x += 10;
//	this->y += 10;
//	return *this;
//}
//
//Point& Point::operator--()
//{
//	this->x -= 10;
//	this->y -= 10;
//	return *this;
//}
//
//
//
