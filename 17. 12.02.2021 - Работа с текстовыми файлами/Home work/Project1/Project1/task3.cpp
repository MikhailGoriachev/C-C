#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "header.h"

using namespace std;

void task3()
{
	// 3. ������������ ������ ��� �����, ��������� �������� 
	// �� ������ ���� ������ ��������� ����� � ������ �����

	// ���������� ����� ������
	int size = 40;

	// ��� ������� ����� ������ � ����������� 
	char* name_file_1 = new char[size];

	// ��� ������� �����, ������� ����� ���������� ���������� ��������� �� ������ ����� ����� 
	char* name = enterDir(name_file_1, &size);

	// ���� ����� �����
	cout << "Enter file name: ";
	cin >> name;

	cout << endl;

	// �������� ����� �� ������� �/��� �������� ���
	int det = detectFile(name_file_1);

	// ���������� ������ �����
	if (det == 1)
	{
		fill2DArrayComb(name_file_1);
	}	
	else if (det == 3)
	{
		cout << "Exit" << endl;
		return;
	}

	cout << endl;

	// ����������� ����� ������
	size = 40;
	
	// ��� ������� ����� ������ � ����������� 
	char* name_file_2 = new char[size];

	// ��� ������� �����, ������� ����� ���������� ���������� ��������� �� ������ ����� ����� 
	name = enterDir(name_file_2, &size);

	// ���� ����� �����
	cout << "Enter file name: ";
	cin >> name;

	det = detectFile(name_file_2);
	if (det == 1)
	{
		cout << endl;
		cout << "File complete" << endl;
	}
	if (det == 3)
	{
		cout << endl;
		cout << "Exit" << endl;
		return;
	}

	cout << endl;

	// �������� ������� �����
	FILE* file_1 = fopen(name_file_1, "r");

	// �������� ������� ����� 
	FILE* file_2 = fopen(name_file_2, "w");

	// ���������� ������� ����� ������� �� ������� �����
	while (!feof(file_1))
	{
		int num;
		char sym;
		if (fscanf(file_1, "%d", &num) && !feof(file_1))
			fprintf(file_2, "%d ", num);		
		if (fscanf(file_1, "%c", &sym) && !feof(file_1))
			continue;
	}

	// �������� ������� �����
	fclose(file_1);

	// �������� ������� �����
	fclose(file_2);

	cout << "Save" << endl;
}