#pragma once
#include "DynamicArray.h"

#include<iostream>
using namespace std;

DynamicArray GetObj() //������� �� ��������
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
	����������� ��������� ����������:

	\\DynamicArray 
	 rez = a+10 ; // ����������� ���-�� ��������� �� 10
	 rez = a-2; // ������� ��������� 2 ��������, ���� ������ >2
	 rez = a*2;// �������� ������� �������� ������� �������� �� 2, ���������� ����� ������!



	 rez = a-b; // �������� ��������
	 rez=a+b;  // ������������ ��������
	 ++rez;  // ����������� ���������� ��������� �� 1(�������� 0).
	 --rez;  // ��. ���������� ��������� �� 1, ������� ��������� �������
	*/

}