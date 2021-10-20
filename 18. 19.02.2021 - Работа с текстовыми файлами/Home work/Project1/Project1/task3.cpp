#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "head.h"

using namespace std;

// ��������� ������
void stringRepeat(char a[]);

void task3()
{
	// 3. ������������ ������ 2 ����� �����, ��������� ���������
	// � ��������� ��� ������ ������� �����, �� � �����������
	// ����(hello->olleh)

	// ��������� �� ����
	FILE* file_1, * file_2;

	// ����� ������
	char name_1[40], name_2[40];

	// ���� ����� ������� ����� 
	cout << "Enter name first file: ";
	cin >> name_1;
	
	int detectFile = fileCreate(name_1);

	// ���� ���� ������
	if (detectFile == 1)
	{
		// ���� � ����� 
		cout << "Enter strings in file (0 exit): ";

		// �������� ����� � ������ ��������������
		file_1 = fopen(name_1, "w");

		cin.ignore();

		// ���� ����� 
		while (true)
		{
			// ���� ������
			char buffer[40];
			cin.getline(buffer, 40);

			// ���� ������������ ��� ����, �� ���� ������������
			if (!strcmp(buffer, "0"))
				break;

			// �������� �� '\n' � ����� ������
			detectBackN(buffer);

			// ��������� ����� ������� �� ������
			fputs(buffer, file_1);

			// �������� ������
			strcpy(buffer, "");
		}

		// �������� �����
		fclose(file_1);
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
	cin >> name_2;

	detectFile = fileCreate(name_2);

	// ���� ����� �� ����������
	if (detectFile == 0)
	{
		cout << endl;
		cout << "Exit" << endl;
		return;
	}
	
	// �������� ������� ����� � ������ ������
	file_1 = fopen(name_1, "r");

	// �������� ������� ����� � ������ ������
	file_2 = fopen(name_2, "w");

	// ������ ������� ����� ������������ �������� ������� �����
	while (!feof(file_1))
	{
		// ����� ��� ����� ������
		char buffer[200];

		if (detectFile > 100)
		{
			cout << endl;
		}

		// ����������� ����� ������ � ����� � �����
		fgets(buffer, 199, file_1);

		// �������� �� ������� '\n' � ������
		//detectBackN(buffer);

		// ��������� ������ � ������
		stringRepeat(buffer);

		// ������ ������ �� ������ �� ������ ����
		fputs(buffer, file_2);

		// �������� ������
		strcpy(buffer, "");
	}

	cout << "File copy complete!" << endl;
	
	// �������� ������� � ������� ������
	fclose(file_1);
	fclose(file_2);
}

// ��������� ������
void stringRepeat(char a[])
{
	int len = strlen(a);

	if (a[len - 1] == '\n')
		len--;

	for (int i = 0; i < len / 2; i++)
	{
		swap(a[i], a[len - 1 - i]);
	}
}
