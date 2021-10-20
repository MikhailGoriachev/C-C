#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "header.h"

using namespace std;

void task1()
{
	srand(time(0));

	// 1. ������������ ������ ��� �����, ��������� ��������� �� 
	// ����� ��������� ������ ����� � ������� �� ����.

	// ��� ����� 
	int size = 40;
	char* name_file = new char[size];

	char* p_name = enterDir(name_file, &size);

	cout << endl;

	// ����� ����� �����
	cout << "Enter file name: ";
	cin.getline(p_name, size);

	cout << endl;

	// �������� �� �� ���������� �� ����
	FILE* file = fopen(name_file, "r");

	if (file == 0)
	{
		char* a = new char[40];
		cout << "File not found. Create file? (Yes/No): ";
		// �������� ���������� ������
		while (true)
		{
			cin.getline(a, 40);
			if (strcmp(a, "Yes") == 0)
				break;
			// ���� ����� �������������, �� ��������� �����������
			if (strcmp(a, "No") == 0)
			{
				cout << endl;
				cout << "Exit" << endl;
				return;
			}
			// ���� ���� ������������ �� ������������ ������ �����, ���� �� ������ ���������
			cout << "Error! Enter Yes or No: ";
		}

		delete[] a;

		// �������� ����� 
		file = fopen(name_file, "w");

		cout << endl;

		cout << "Create Array" << endl;

		cout << endl;
		// �������� �������
		int rows, cols;

		cout << "Enter rows: ";
		cin >> rows;

		cout << "Enter cols: ";
		cin >> cols;

		int** arr = new int* [rows];

		// ����������� ���������� ������� ���������� �������
		for (size_t i = 0; i < rows; i++)
		{
			arr[i] = new int[cols];
			for (size_t k = 0; k < cols; k++)
			{
				arr[i][k] = rand() % 89 + 10;
			}
		}

		cout << endl;

		cout << "Filling file..." << endl;

		cout << endl;

		// � ����� ����������� ������� ���������� �������
		fprintf(file, "%d \n", rows);
		fprintf(file, "%d \n", cols);

		// ���������� ����� ���������� ���������� �������

		for (size_t i = 0; i < rows; i++)
		{
			for (size_t k = 0; k < cols; k++)
			{
				fprintf(file, "%d ", arr[i][k]);
			}
			fprintf(file, "\n");
		}
		
		deleteArr(arr, rows, cols);

		cout << "Completed file filling" << endl << endl;

		cout << "Save " << name_file << endl << endl;

		fclose(file);

		file = fopen(name_file, "r");
	}

	cout << "Loading " << name_file << "... " << endl;

	// ������� ���������� �������
	int rows, cols;

	// ���������� �������� ���������� �������
	fscanf(file, "%d", &rows);
	fscanf(file, "%d", &cols);

	// ��������� ������� ���������� � �����
	int** arr = new int* [rows];

	for (size_t i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
		for (size_t k = 0; k < cols; k++)
		{
			fscanf(file, "%d", &arr[i][k]);
		}
	}

	cout << endl;

	// ����� ���������� ������������� �������
	out2DArray(arr, rows, cols);

	deleteArr(arr, rows, cols);

	delete[] name_file;

	cout << endl;

	// �������� �����
	fclose(file);
}