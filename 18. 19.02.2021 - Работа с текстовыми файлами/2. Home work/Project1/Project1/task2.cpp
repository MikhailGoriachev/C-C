#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "head.h"
#include <stdlib.h>

using namespace std;

void clearingNum(char a[]);

void task2()
{
	// 2. ������������ ������ 2 ����� �����, ��������� ������� 
	// �� ������� ����� ��� ����� � ��������� ���������� ��
	// ������ ����
	
	// ����� ������
	char name_1[40];
	char name_2[40];

	// ��������� �� ����
	FILE* file_1, *file_2;

	// ���� ����� �������� �����
	cout << "Enter name first file: ";
	cin >> name_1;

	cout << endl;

	// �������� ����� �� �������
	int filedetect = fileCreate(name_1);

	// ���� ������ ����� ����
	if (filedetect == 1)
	{
		// ���������� �����
		cout << "Enter strings in file (0 exit): ";

		// �������� ����� � ������ �������������� 
		file_1 = fopen(name_1, "w");

		cin.ignore();

		// ������������ ������ ������ � ����
		while (true)
		{
			char buffer[40];
			cin.getline(buffer, 40);
			if (!strcmp(buffer, "0"))
			{
				cout << endl;
				break;
			}

			detectBackN(buffer);

			fputs(buffer, file_1);
			strcpy(buffer, "");
		}

		// �������� �����
		fclose(file_1);

		cout << endl << name_1 << " save complete" << endl;
		cout << endl;
	}

	// ���� ����� �� ��������� 
	if (filedetect == 0)
	{
		cout << endl;
		cout << "Exit" << endl;
		return;
	}

	// ���� ����� ������� �����
	cout << "Enter name second file: ";
	cin >> name_2;
	
	cout << endl;

	// �������� ����� �� �������
	filedetect = fileCreate(name_2);

	cout << endl;

	// ���� ����� �� ����������
	if (filedetect == 0)
	{
		cout << endl;
		cout << "Exit";
		return;
	}

	// �������� ������� ����� � ������ ������
	file_1 = fopen(name_1, "r");

	// �������� ������� ����� � ������ ������
	file_2 = fopen(name_2, "w");

	// ���������� ������� ����� ���������� �������, �� ��� ����
	while (!feof(file_1))
	{
		// ����� ��� ����� ������
		char buffer[200];

		// ���������� ������ ����� �������� �� ������� �����
		fgets(buffer, 199, file_1);

		// �������� ������ � ������ �� ����
		clearingNum(buffer);

		// �������� �� ������� "\n" � ����� ������
		detectBackN(buffer);

		// ���������� ������� ����� ������� �� ������
		fputs(buffer, file_2);

		// �������� ������
		strcpy(buffer, "");
	}

	// �������� ������
	fclose(file_1);
	fclose(file_2);

	cout << "File copy cmplete!" << endl;
}

// ������� ������ �� ����
void clearingNum(char a[])
{
	for (size_t i = 0; a[i] != 0; i++)
	{
		if (a[i] >= '0' && a[i] <= '9')
		{
			for (size_t k = i; a[k - 1] != 0; k++)
			{
				swap(a[k], a[k + 1]);
			}
			i--;
		}
	}
}