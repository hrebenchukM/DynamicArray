#pragma once
#include "DynamicArray.h"



DynamicArray GetObj() //возврат по значению
{
	DynamicArray obj(3);
	obj.Input();

	return obj;
}
void main()
{
	DynamicArray a(5); // constructor 1 param
	a.Input();
//	int* x = a.GetPointer();
	a.ReSize(2);
//	cout << *x << endl;
	a.Output();
	a.Sort();
	a.Output();
	a.Reverse();
	a.Output();
	cout << "Result of search:" << a.Search(7) << endl;
	DynamicArray b(a); // copy constructor
	//a.GetPointer()[0] = 100;
	b.Output();
	
	
	
	
	

	//DynamicArray rezult = GetObj();


	//system("pause");
	
}