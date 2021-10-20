#define _CRT_SECURE_NO_WARNINGS


#include <iostream>
#include "header.h"

using namespace std;

void task4()
{
	// 4. ������������ ������ ��� �����, ��������� �������� ��� 
	// �� ������ ����, �� ������ ����� � ��������� ����: ������ 
	// ������ ������ ���������, ������ - ������������� � �.�.
	int size = 40;

	// ������ ��� ����� �����
	char* file_name_1 = new char[size];

	// ���� ����������
	char* name = enterDir(file_name_1, &size);

	// ���� �����
	cout << "Enter name file: ";
	cin >> name;

	// �������� �/��� �������� �����
	int det = detectFile(file_name_1);

	// ���� ������ ������ ����, �� �� ����������� �������� �� ���������� ��������
	if (det == 1)
	{
		fill2DArrayComb(file_name_1);
		cout << endl;
	}

	// ���� ������������ ��������� ��������� ����, �� ����� �� ���������
	if (det == 3)
	{
		cout << "Exit" << endl;
		return;
	}

	// ����������� ����� ������
	size = 40;
	
	// ������ ��� ������� �����
	char* file_name_2 = new char[size];

	// ���� ����������
	name = enterDir(file_name_2, &size);

	// ���� ����� ����� 
	cout << "Enter name file: ";
	cin >> name;

	// �������� ������� ����� � ������ ������
	FILE* file = fopen(file_name_1, "r");

	// ���������� ����� � ��������� ��� ���������� ������������� �������
	int rows = 0;
	int cols = 1;

	// ������� ���������� �����
	char* buffer = new char[400];
	while (!feof(file))
	{
		if (!feof(file))
		{
			fgets(buffer, 200, file);
			// ������� �����
			rows++;
		}
		
		// ����� ������� ������
		int max = strlen(buffer);

		// ���� ����� ������ ������, ��� � ���������� �����
		if (max > cols)
			cols = max;

		// ������� ������
		strcpy(buffer, "");
	}
	delete[] buffer;

	fclose(file);
	file = fopen(file_name_1, "r");
	// ���������� ������� �������� �� �����
	char** content = new char* [rows];
	for (size_t i = 0; i < rows; i++)
	{
		content[i] = new char[cols + 1];
		strcpy(content[i], "");
		fgets(content[i], cols + 1, file);
	}

	// �������� ������� �����
	fclose(file);

	// �������� ������� ����� � ������ ������
	file = fopen(file_name_2, "w");

	// ������ ����� � ����������� ����
	for (int i = rows-1; i >= 0; i--)
	{
		fputs(content[i], file);
	}

	// �������� ���������� ������������� �������
	deleteArr(content, rows, cols);

	// �������� ������� �����
	fclose(file);

	cout << endl;

	cout << "Save" << endl;
}