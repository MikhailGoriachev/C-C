#include <iostream>

// ����������� ����� ����������
#include "myio.h"
using namespace std;

// ������� 1
int numRevers(float a);

// ������� 2
void task2();

// ������� 3
void task3();

void main()
{
	int num;

	cout << "Enter Task: ";
	cin >> num;

	if (num == 1)
	{
		// ����� ���������������
		float n;

		cout << "Enter num: ";
		cin >> n;

		n = numRevers(n);

		cout << "Result: " << n << endl;
	}

	// ��������� ������������ �������
	if (num == 2)
	{
		task2();
	}

	if (num == 3)
	{
		task3();
	}
}

// ������� 1
int numRevers(float num)
{
	// ����� �����
	int size = 0;

	int temp = num;

	for (size_t i = 0; ; i++)
	{
		if ((int)temp != 0)
		{
			temp /= 10;
			size++;
		}
		else
			break;
	}

	temp = num;

	// ������� �����
	int n = 0;

	int num1 = 0;

	for (size_t i = 0; i < size; i++)
	{
		temp = num;

		for (size_t k = 0;;k++)
		{
			if (temp / 10 != 0)
				temp /= 10;
			if (temp / 10 == 0)
			{
				if (i == 0)
					k++;
				n = temp;
				if (i >= 1)
				{
					for (size_t j = 0; j < i; j++)
					{
						n *= 10;
					}
				}


				num1 += n;

				for (size_t w = 1; w < i; w++)
				{
					n /= 10;
				}
					

				for (size_t j = 0; j < k; j++)
				{
					n *= 10;
				}

				

				num -= n;

				break;
			}
			
		}
		
	}

	return num1;
}

// ������� 2
void task2()
{
	// ��������� ������������ �������
	size_t rows;
	size_t cols;

	// ���� ������� ���������� �������

	cout << "Enter rows number: ";
	cin >> rows;

	cout << "Enter cols number: ";
	cin >> cols;

	// �������� ���������� ������������� �������

	// �������� ���������� �����
	int** a = new int* [rows];

	// ������ ������ ��� ���������� ������

	for (size_t i = 0; i < rows; i++)
	{
		// �������� ���������� �������� ������ ������
		a[i] = new int[cols];
	}

	cout << "Enter Array: " << endl;

	enter2DArray(a, rows, cols);

	cout << endl;

	cout << "Array" << endl;

	print2DArray(a, rows, cols);

	for (size_t i = 0; i < rows; i++)
	{
		delete[] a[i];
	}

	delete[] a;
}

// ������� 3
void task3()
{
	// ��������� ������������ ������ � ��������� ������ �����

	// ��������� ������������ �������
	size_t rows;
	size_t cols;

	// ���� ������� ���������� �������

	cout << "Enter rows number: ";
	cin >> rows;


	// �������� ���������� ������������� �������

	// �������� ���������� �����
	int** a = new int* [rows];

	// ������ ������ ��� ���������� ������

	for (size_t i = 0; i < rows; i++)
	{
		// �������� ���������� �������� ������ ������
		a[i] = new int[i+1];

		// ���������� ������ ������
		for (size_t k = 0; k < i+1; k++)
		{
			a[i][k] = k + 1;
		}
	}

	for (size_t i = 0; i < rows; i++)
	{
		for (size_t k = 0; k < i + 1; k++)
		{
			cout << a[i][k] << " ";
		}
		cout << endl;
	}

	/*cout << "Enter Array: " << endl;

	enter2DArray(a, rows, cols);

	cout << endl;

	cout << "Array" << endl;

	print2DArray(a, rows, cols);
	*/
	for (size_t i = 0; i < rows; i++)
	{
		delete[] a[i];
	}

	delete[] a;
}
