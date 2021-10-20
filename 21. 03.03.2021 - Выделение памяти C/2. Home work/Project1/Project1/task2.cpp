#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "head.h"

using namespace std;

void task2()
{
	// 2. ������������ ������ ��� cpp - �����,
	// ��������� ������������ ���������� ������������� ���������� for, while, if ������ �����.

	// ��� ��������� �����
	char name[40];

	// ���� ����� ��������� �����
	cout << "Enter name CPP file: ";
	cin.ignore();
	cin.getline(name, 40);

	cout << endl;

	// ������� for
	size_t count_for = 0;

	// ������� while 
	size_t count_while = 0;

	// ������� if
	size_t count_if = 0;

	// �������� ����� � ������ ������
	FILE* file = fopen(name, "r");

	// ���� ����� ������ �������
	if (file != nullptr)
	{
		// ����� ��� ������ �����
		char buff[200];
		
		// ���� ��������� � ����� �� ������ ����� �����
		while (!feof(file))
		{
			// ���������� �� ������ ����� � �����
			fscanf(file, "%199s", buff);

			// ���� ����� � ������ "for"
			if (!strcmp(buff, "for"))
			{
				count_for++;
			}

			// ���� ����� � ������ "while"
			if (!strcmp(buff, "while"))
			{
				count_while++;
			}

			// ���� ����� � ������ "if"
			if (!strcmp(buff, "if"))
			{
				count_if++;
			}
		}

		// �������� ��������� �����
		fclose(file);

		// ����� ����������
		cout << "Result" << endl;
		cout << "for: " << count_for << endl;
		cout << "while: " << count_while << endl;
		cout << "if: " << count_if << endl;
		cout << endl;
	}
	// ���� ���� �� ������� �������
	else cout << "File NOT found" << endl;
}