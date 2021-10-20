#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <conio.h>
#include "head.h"

using namespace std;

void task1()
{
	// 1. ������������ ������ ��� �����, ��������� ������������ 
	// ������ ����� ����� � �����(����� - ��������� �����)

	// ��� �����
	char name[40];

	// ��������� �� ����
	FILE* file;

	// ���� ����� �����
	cout << "Enter name file: ";
	cin >> name;

	cout << endl;

	// ������� ��������� ���������� �� ���� � ��� ������������� ��� ������.
	// ��� ���������� �������� 0/1/2
	int fileOp = fileCreate(name);

	// ���� ���� �� ������
	if (fileOp == 0)
	{
		cout << endl;
		cout << "Exit" << endl;
		return;
	}

	// ���� ���� ������
	if (fileOp == 1)
	{
		cout << endl;

		// ���� ����� � ���� ����� ������
		cout << "Enter number into file (press Esc - exit): ";

		// �������� ����� � ������ ������
		file = fopen(name, "w");
		
		// ���� ���������� �����
		for (size_t i = 0;; i++)
		{
			char enter = _getch();
			if (enter == (char)27)
			{
				break;
			}
			
			if (enter == (char)13)
			{
				fprintf(file, "\n");
				cout << endl;
				continue;
			}

			if (enter >= '0' && enter <= 'z' || enter == ' ')
			{
				cout << enter;
				fprintf(file, "%c", enter);
			}
		}

		fclose(file);

		cout << endl << endl;

		cout << "File save" << endl;
	}
	
	file = fopen(name, "r");

	int sum = 0;
	
	
	while (!feof(file))
	{
		char buffer[200];
		fscanf(file, "%s", buffer);
		sum += atoi(buffer);
		strcpy(buffer, "");
	}

	while (!feof(file))
	{
		char buffer[200];
		fgets(buffer, 200, file);
		puts(buffer);
	}

	fclose(file);

	cout << "Sym = " << sum << endl;
}