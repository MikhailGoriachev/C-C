#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "header.h"

using namespace std;

// ������� �� �������� ����� �/��� �������� �����
int detectFile(char name_file[]);

void task2()
{
	// 2. ������������ ������ 2 ����� ��������� ������, 
	// ��������� �������� ������ ���� �� ������
	
	int size_1 = 40;
	int size_2 = 40;

	// ����� ������
	char* name_file_1 = new char[size_1];
	char* name_file_2 = new char[size_2];

	// ��������� �� �����
	FILE* file_1 = 0, * file_2 = 0;
	cout << endl;

	char* name_file = enterDir(name_file_1, &size_1);

	// ���� ����� ������� �����
	cout << "Enter name first  file: ";
	cin >> name_file;

	cout << endl;

	// ���� ����������� ��� ��������� � ����������, ���� ����������� ������ 
	// �������� ������ �����, ����� �� ���������
	int ot = detectFile(name_file_1);
	if (ot == 1)
	{
		int anw;
		cout << endl << "Create a file with random symbols or random numbers? (1/2): ";
		cin >> anw;

		if (anw == 1)
			randomSym(name_file_1);
		if (anw == 2)
			randomNum(name_file_1);
	}
	else if (ot == 3)
	{
		cout << endl;
		cout << "Exit" << endl;
		return;
	}

	cout << endl;

	// ���� ����� ������� �����

	name_file = enterDir(name_file_2, &size_2);

	cout << endl;

	cout << "Enter name second file: ";
	cin >> name_file;

	cout << endl;

	// ���� ����������� ��� ��������� � ����������, ���� ����������� ������ 
	// �������� ������ �����, ����� �� ���������
	ot = detectFile(name_file_2);
	if (ot == 3)
	{
		cout << endl;
		cout << "Exit" << endl;
		return;
	}

	cout << endl;

	file_1 = fopen(name_file_1, "r");
	file_2 = fopen(name_file_2, "w");

	while (!feof(file_1))
	{
		// ������ �������
		
		char buffer[200];
		strcpy(buffer, "");
		fgets(buffer, 200, file_1);
		fputs(buffer, file_2);
		
		// ������ ������

		/*char sym;

		if (fscanf(file_1, "%c", &sym));
		{
			fprintf(file_2, "%c", sym);
		}*/

	}

	cout << "Save" << endl;

	delete[] name_file_1, name_file_2;

	fclose(file_1);
	fclose(file_2);
	
}

