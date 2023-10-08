#pragma once
#include "DynamicArray.h"

#include<iostream>
using namespace std;

DynamicArray GetObj() //возврат по значению
{
	DynamicArray obj(3);
	obj.Input();

	return obj;
}
int main()
{


	









	DynamicArray a(10); // constructor 1 param
	a.Input();
	a.Output();
	DynamicArray b(5);
	b.Input();
	b.Output();
	//DynamicArray b(a);
	
	DynamicArray rez = a+10;
	rez.Output();

	DynamicArray rez1 = a - 2;
	rez1.Output();

	DynamicArray rez2 = a * 2;
	rez2.Output();



	DynamicArray rez3 = a - b;
	rez3.Output();

	DynamicArray rez4 = a + b;
	rez4.Output();
	

	++rez;
	
	--rez;





	/*DynamicArray rez3 = a * 2;
	rez3.Output();*/
	//	int* x = a.GetPointer();
//	a.ReSize(2);
//	cout << *x << endl;

	//a.ReSize(2);
	//a.Sort();
	//a.Output();
	//a.Reverse();
	//a.Output();
	//cout << "Result of search:" << a.Search(7) << endl;
	//DynamicArray b(a); // copy constructor
	//a.GetPointer()[0] = 100;
	//b.Output();

	//DynamicArray rezult = GetObj();


	//system("pause");

	/*
	реилизовать следующие перегрузки:

	\\DynamicArray 
	 rez = a+10 ; // увеличиваем кол-во элементов на 10
	 rez = a-2; // удаляем последние 2 элемента, если размер >2
	 rez = a*2;// значение каждого элемента массива умножаем на 2, возвращаем новый массив!



	 rez = a-b; // разность массивов
	 rez=a+b;  // конкатенация массивов
	 ++rez;  // увеличиваем количество элементов на 1(значение 0).
	 --rez;  // ум. количество элементов на 1, удаляем последний элемент
	*/

}