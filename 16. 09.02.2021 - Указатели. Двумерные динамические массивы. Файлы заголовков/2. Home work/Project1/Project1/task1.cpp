#include <iostream>
#include <time.h>

using namespace std;

// ������� ������ ���������� ������� (������� 1)
void out2DArrayTask1(int** a, size_t rows, size_t cols);


void task1()
{
	srand(time(0));
	// 1. ������������ ������ ���������� ����� ���������� ������������� �������, ��������� ������� ������ ����� �����:
	//	5 5 5 5 5
	//	5 5 5 5
	//	5 5 5
	//	5 5
	//	5

	//	��������� ���������� �������

	size_t rows;

	cout << "Enter rows: ";
	cin >> rows;

	cout << endl;

	// �������� ������������� ���������� ������� 
	int** a = new int* [rows];

	// �������� ����� ����� 
	for (size_t i = 0, j = rows; i < rows; i++, j--)
	{
		a[i] = new int[j];
		// ���������� ������ ���������� �������
		for (size_t k = 0; k < j; k++)
		{
			a[i][k] = rand() % 10;
		}
	}

	// ����� ���������� ������������� �������
	out2DArrayTask1(a, rows, rows);

	delete[] a;
}

// ������� ������ ���������� �������
void out2DArrayTask1(int** a, size_t rows, size_t cols)
{
	for (size_t i = 0, j = rows; i < rows; i++, j--)
	{
		for (size_t k = 0; k < j; k++)
		{
			cout << a[i][k] << " ";
		}
		cout << endl;
	}
}