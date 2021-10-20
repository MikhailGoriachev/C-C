#include <iostream>

using namespace std;

long sumArr(int* array, long size)
{
	long sum = *array;
	if (size > 0)
	{
		sum += sumArr(array + 1, size - 1);

		return sum;
	}

	return 0;
}

void task1()
{
	// 1. ����������� ������� ��������� ������ ����� � ��� 
	// ������ � ��������� ����� ��������� �������

	srand(time(0));

	// ������ �������
	long* size = new long;

	// ���� ������� �������
	cout << "Enter size array: ";
	cin >> *size;

	// ������
	int* array = new int[*size];

	// ���������� ������� ���������� ������� �� 10 �� 99
	for (int* arr = array; arr < array + *size; arr++)
	{
		// ������� ������� ����������� ��������� ������
		*arr = rand() % 100 + 10;
	}

	// ����� ��������� ������� 
	for (int* arr = array, num = 0, *n = &num; arr < array + *size; arr++, ++*n)
	{
		cout << "array " << "[" << *n << "] : " << *arr << endl;
	}

	// ��������� ������ ��� �����
	long* summer = new long;

	// ����� ��������� �������
	*summer = sumArr(array, *size);

	// ����� ����� ��������� �������
	cout << "Summer: " << *summer << endl;

	// �������� ������
	delete[] array;
	delete size, summer;
}