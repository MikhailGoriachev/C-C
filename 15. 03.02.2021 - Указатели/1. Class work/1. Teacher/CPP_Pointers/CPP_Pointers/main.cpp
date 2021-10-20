#include <iostream>

using namespace std;

void main()
{
	int a;
	a = 3;

	// вывести адрес переменной a
	cout << &a << endl;

	// создать указатель и поместить в него адрес переменной a
	int* p = &a;

	// вывести адрес, который хранится в указателе p
	cout << p << endl;

	// вывести значение, на которое указывает указатель
	cout << *p << endl;

	// объявить массив (константный указатель на 0 ячейку массива)
	int b[5] = { 1, 2, 3, 4, 5 };
	cout << b[0] << endl;

	// вывод адреса массива
	cout << b << endl;

	// объявить указатель p2 и поместить в него адрес массива b
	int* p2 = b;

	// изменение массива b через указатель p2
	p2[0] = 12;
	
	for (size_t i = 0; i < 5; i++)
	{
		cout << b[i] << " ";
	}
	cout << endl;

	// помещение в указатель p2 адреса, взятого из указателя p
	p2 = p;

	// работа с динамическим массивом
	cout << "Enter size of array: ";
	int arrSize;
	cin >> arrSize;

	float* arr = new float[arrSize];

	for (size_t i = 0; i < arrSize; i++)
	{
		arr[i] = i + 1;
		cout << arr[i] << " ";
	}
	cout << endl;

	delete[] arr;
}