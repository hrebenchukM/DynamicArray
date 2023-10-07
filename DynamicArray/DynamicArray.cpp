#include "DynamicArray.h"

#include<Windows.h>

DynamicArray::DynamicArray() :ptr(nullptr), size(0)
{}
DynamicArray::DynamicArray(int S)
{
	cout << "Construct by 1 param\n";
	size = S;
	ptr = new int[S];
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
	Sleep(1000);
}
void DynamicArray::Input()
{
	for (int i = 0; i < size; i++)
	{
		ptr[i] = rand() % 10;
	}
}
void DynamicArray::Output() const
{
	for (int i = 0; i < size; i++)
	{
		cout << ptr[i] << "\t";
	}
	cout << "\n---------------------------------------------------------------------\n";
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

