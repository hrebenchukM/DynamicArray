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
	a.Output();
	//a.ReSize(2);
	//a.Reverse();
	//a.Sort();
	//a.Search(6);
	DynamicArray b = a; // copy constructor
	b.Output();
	

	//DynamicArray rezult = GetObj();


	system("pause");
	
}