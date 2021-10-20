#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "head.h"

using namespace std;

// �������� ��������
bool detectSymb(char a[]);

void task4()
{
	// 4. ������������ ������ ��� �����, ��������� ������� 
	// �� ����� ��� �����, ���������� ����� �������, ����� 
	// ��������� � ��������� ���������� � ������ ����.

	// ����� ������
	char name_1[40], name_2[40];

	// ��������� �� ����
	FILE* file_1, * file_2;

	// ���� ����� ������� �����
	cout << "Enter name first file: ";
	cin.ignore();
	cin.getline(name_1, 40);

	cout << endl;

	// �������� �����
	int detectFile = fileCreate(name_1);

	cout << endl;

	// ���� ���� ������
	if (detectFile == 1)
	{
		// ���� � ����
		cout << "Enter strings in file: ";
		cout << endl;

		cin.ignore();

		file_1 = fopen(name_1, "w");

		while (true)
		{
			cout << "/ ";

			// ����� ��� ����� ������ �� �����
			char buffer[40];

			// ���� ������
			cin.getline(buffer, 40);

			if (!strcmp(buffer, "0"))
			{
				break;
				cout << endl;
			}

			// �������� �� '\n'
			detectBackN(buffer);

			// ���� ������ �� ������ � ����
			fputs(buffer, file_1);

			// �������� ������
			strcpy(buffer, "");

			cout << endl;
		}

		// �������� ������� �����
		fclose(file_1);

		cout << name_1 << "save" << endl;
	}

	// ���� ����� �� ����������
	if (detectFile == 0)
	{
		cout << endl;
		cout << "Exit" << endl;
		return;
	}

	// ���� ����� ������� �����
	cout << "Enter name second file: ";
	cin.getline(name_2, 40);

	cout << endl;

	// ���� ����� �� ����������
	if (!fileCreate(name_2))
	{
		cout << endl;
		cout << "Exit" << endl;
		return;
	}

	cout << endl;

	// �������� ������� ����� � ������ ������
	file_1 = fopen(name_1, "r");

	// �������� ������� ����� � ������ ������
	file_2 = fopen(name_2, "w");

	// ���������� ������� ����� ������� ��� �������� ����� ���� �� ������ �����
	while (!feof(file_1))
	{
		// ������ �����
		char buffer[200];

		// ���������� ������ ����� � ����� � �����
		fscanf(file_1, "%s", buffer);

		// �������� ����� �� ������ �� ������� ������������ ��������
		if (detectSymb(buffer))
			fprintf(file_2, "%s", buffer);

		// �������� ������
		strcpy(buffer, "");
	}

	// �������� ������ �����
	fclose(file_1);
	// �������� ������� �����
	fclose(file_2);
}

// �������� ��������
bool detectSymb(char a[])
{
	for (size_t i = 0; a[i] != 0; i++)
	{
		if (!(a[i] >= 'A' && a[i] <= 'z'))
			return false;
	}

	return true;
}