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



	DynamicArray a(5); // constructor 1 param
	a.Input();
	a.Output();
	DynamicArray b(10);
	b.Input();
	b.Output();
	
	
	DynamicArray rez = a;
	DynamicArray rez0 =a+10;
	cout << "Elemets from array a[]+ 10 elements=a[20]" << endl;
	rez0.Output();

	DynamicArray rez1 = a - 2;
	cout << "Elemets from array a[]-2 elements=a[8]" << endl;
	rez1.Output();



	DynamicArray rez2 = a * 2;
	cout << "Value from array a[]*2" << endl;
	rez2.Output();



	DynamicArray rez3 = a - b;
	cout << "N of elements from array a[]- N of elements from array b[]" << endl;
	rez3.Output();

	DynamicArray rez4 = a + b;
	cout << "N of elements from array a[]+N of elements from array b[]" << endl;
	rez4.Output();
	

	++rez;
	cout << "Add 1 element in array a[5]=a[6]" << endl;
	rez.Output();
	
	--rez;
	cout << "delete 1 element in array a[6]=a[5]" << endl;
	rez.Output();





	/*DynamicArray rez3 = a * 2;
	rez3.Output();*/

	//a.ReSize(2);
	//a.Sort();
	//a.Output();
	//a.Reverse();
	//a.Output();
	//cout << "Result of search:" << a.Search(7) << endl;
	//DynamicArray b(a); // copy constructor
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