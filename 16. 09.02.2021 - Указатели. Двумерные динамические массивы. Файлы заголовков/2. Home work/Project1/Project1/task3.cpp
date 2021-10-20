#include <iostream>

using namespace std;

// ���� ���������� ������������� �������
void enter2DArray(int** a, size_t rows, size_t cols);

// ����� ���������� ������������� �������
void out2DArray(int** a, size_t rows, size_t cols);

// ������� ���������� ���������� ������� �� 90 �������� 
void coup2DArray(int** a, int** b, size_t rows, size_t cols);

void task3()
{
	// 3. ������������ ����� ������� � ��� ��������� ������������ 
	// ������.��������� ������������ ��� �� 90 �������� �� �������
	// ������� � ��������� �������� � ������ ������ : 3�4 = > 4x3

	int rows, cols;

	// ���� ��������� �����
	cout << "Enter rows: ";
	cin >> rows;

	// ���� ���������� �����
	cout << "Enter cols: ";
	cin >> cols;

	// �������� ������� ���������� �������
	int** a = new int* [rows];

	// �������� ������� ���������� �������
	int** b = new int* [cols];

	for (size_t i = 0; i < cols; i++)
	{
		b[i] = new int[rows];
	}


	// ���� �������
	enter2DArray(a, rows, cols);

	cout << endl;

	// ����� �������
	out2DArray(a, rows, cols);

	cout << endl;

	// ���������� ������� ������� ������������ �� 90 �������� ������
	coup2DArray(a, b, rows, cols);

	cout << "Result" << endl;

	cout << endl;

	// ����� ������� ������ 
	out2DArray(b, cols, rows);
	
	cout << endl;

	delete[] a, b;
}

// ���� ���������� ������������� �������
void enter2DArray(int** a, size_t rows, size_t cols)
{
	for (size_t i = 0; i < rows; i++)
	{
		a[i] = new int[cols];
		for (size_t k = 0; k < cols; k++)
		{
			cout << "Enter element [" << i << "][" << k << "]: ";
			cin >> a[i][k];
		}
		cout << endl;
	}
}

// ����� ���������� ������������� �������
void out2DArray(int** a, size_t rows, size_t cols)
{
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t k = 0; k < cols; k++)
		{
			cout << a[i][k] << " ";
		}
		cout << endl;
	}
}

// ������� ���������� ���������� ������� �� 90 �������� 
void coup2DArray(int** a, int** b, size_t rows, size_t cols)
{
	// ���������� ������� ������� ����������� �� 90 �������� ������
	for (size_t i = 0, n = 0; i < cols; i++)
	{
		for (size_t k = 0, n = rows-1, m = i; k < rows; k++)
		{
			b[i][k] = a[n--][m];
		}
	}
}