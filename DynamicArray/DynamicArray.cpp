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

void DynamicArray::ReSize(int newSize)//void ReSize(int size);// изменение размера массива //передаем еще 2 элемента в конец добавить и получается массив из 7 и указатель перенаправляет
	//Надо подумать как это реализовать именно перед созданием
{
	int *newPtr = new int[size+newSize];//создали новый пустой на 7 єлементов массив 

	for (int i = 0; i <size; i++)
	{
		newPtr[i] = ptr[i];//заполнили новый массив старыми 5 элементами
	}

	for (int i = 0; i < newSize; i++)
	{
		newPtr[size+i] = 0;
	}

	delete[] ptr;
    ptr=newPtr;//перезаписали старый указатель на новый указатель 
	size = size+newSize;// перезаписали старый размер на новый

	
}
 
void DynamicArray::Sort()
{
		int temp;

		for (int j = 0; j < size-1; j++)//n-1  раз
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

