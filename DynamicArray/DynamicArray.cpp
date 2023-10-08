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
 
void DynamicArray::DownSize(int newSize)//void ReSize(int size);// изменение размера массива // отнимаем еще 2 элемента =3 и указатель перенаправляет
//Надо подумать как это реализовать именно перед созданием
{

	if (newSize >= size)
	{
		return;
	}
	else {
		int* newPtr = new int[size - newSize];//создали новый пустой на 3 єлементов массив 

		for (int i = 0; i < size - newSize; i++)
		{
			newPtr[i] = ptr[i];//заполнили новый массив старыми 3 элементами
		}


		delete[] ptr;
		ptr = newPtr;//перезаписали старый указатель на новый указатель 
		size = size- newSize;// перезаписали старый размер на новый

	}
	

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

	//ReSize(b);//ресайзит (себя)динамик массив и ничего не возвращает 
	//return *this;//resize делает операции на текущем  this (точка обращения к экзмепляру/обьекту класса на который вызываются методы)
	
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

	//DownSize(b);//ресайзит (себя)динамик массив и ничего не возвращает 
	//return *this;//resize делает операции на текущем  this (точка обращения к экзмепляру/обьекту класса на который вызываются методы)

}

DynamicArray DynamicArray::operator*(int b)
{
	DynamicArray rez(*this);//копия а
	for (int i = 0; i < size; i++)
	{
		rez.ptr[i]*=b;
	}
	return rez;

}



	
DynamicArray DynamicArray::operator-(DynamicArray& b)
{
	DynamicArray rez(*this);//копия а
	
		if (b.size > rez.size)//10>5
		{
			rez.size = b.size - rez.size;//5=10-5
			rez.ptr = new int[rez.size];//5
			for (int i = 0; i < rez.size; i++) //5
			{
				rez.ptr[i] = b.ptr[i];//arrA[5]=arrB[10-5];
			}
			return rez;
		}
		else if (b.size == rez.size)//5=5 (10=10)
		{
			delete[] rez.ptr;
			rez.ptr = nullptr;
			rez.size = 0;
			return rez;
		}
		else if (rez.size>b.size) //10>5
		{



			b.size = rez.size - b.size;//5=10-5
			b.ptr = new int[b.size];//5
			for (int i = 0; i < b.size; i++) //5
			{
				b.ptr[i] = rez.ptr[i];
			}
			return rez;
		}
	return rez;
}





//
//DynamicArray DynamicArray::operator-(DynamicArray &b)
//{
//
//	//size=5,b.size=10
//	if (b.size > size) {//10>5
//		DynamicArray rez(b.size);//[10]
//		for (int i = 0;i < b.size; i++)//10
//		{
//			rez.ptr[i] = b.ptr[i];//copy big array
//		}
//		for (int i = 0; i < size; i++)//5
//		{
//			rez.ptr[i] = rez.ptr[i] - ptr[i];// b.ptr[i]-ptr[i]
//
//		}
//		return rez;
//	}
//	//size=10,b.size=5
//	else if (size>b.size) {//10>5
//		DynamicArray rez(size);//[10]
//		for (int i = 0; i < size; i++)//10
//		{
//			rez.ptr[i] = ptr[i];//copy big array
//		}
//		for (int i = 0; i < b.size; i++)//10
//		{
//			rez.ptr[i] = rez.ptr[i] -b.ptr[i];// ptr[i]-b.ptr[i]
//
//		} 
//		return rez;
//	}
//	else //(size ==b.size)
//	{
//		DynamicArray rez(b.size);
//		for (int i = 0; i < size; i++)
//		{
//			
//			rez.ptr[i] =  b.ptr[i]-ptr[i];
//		}
//		return rez;
//	}
//		
//
//}

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
	return *this;
}




