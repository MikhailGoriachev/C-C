#include <iostream>

#include "head.h"

using namespace std;

void EnterArr(int* arr, int size)
{
	for (int* p_arr = arr, i = 0; p_arr < arr + size; p_arr++, i++)
	{
		system("cls");

		cout << "Enter array[" << i << "]: ";
		cin >> *p_arr;
	}


}

void PrintArr(int* arr, int size)
{
	cout << "Array" << endl;

	for (int* p_arr = arr, i = 0; p_arr < arr + size; p_arr++, i++)
	{
		cout << *p_arr << " " << endl;
	}


}


void task1()
{
	// ������ 1 (7 ������)

	// ������������ ������ ������ ������� � ��� ��� ��������.��������� ������������ ��� ���������� ������� :
	//  �	������� �������������� ���� ���������
	//	�	����� �������� ������������� ���������
	//	�	���������� ���������, ������� ������������ ������� �� 3 � �� 5

	int size;

	cout << "Enter size array: ";
	cin >> size;

	int* arr = new int[size];

	EnterArr(arr, size);

	PrintArr(arr, size);

	pressAnyKey();

	system("cls");

	// ������� �������������� 
	int avg = 0;
	int summNeg = 0;
	int count = 0;

	for (int* p_arr = arr, i = 0; p_arr < arr + size; p_arr++, i++)
	{
		avg += *p_arr;

		if (*p_arr % 2 == -1 && *p_arr < 0)
			summNeg += *p_arr;

		if (*p_arr % 3 == 0 && *p_arr % 5 == 0)
			count++;
	}

	avg /= size;

	// �������� ������
	delete[] arr;

	cout << "Result" << endl;

	cout << "AVG = " << avg << endl;

	cout << "Summer negative odd number = " << summNeg << endl;

	cout << "Count divisor 3 and 5 = " << count << endl;

	pressAnyKey();

	return;
}