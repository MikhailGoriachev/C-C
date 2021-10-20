#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "head.h"

using namespace std;

// �������� �� ������ �����
size_t delNum(char buff[]);

// ��������� ������
void coupStr(char buff[], size_t size);

void task3()
{
	// 3. ������������ ������ ��� �����, ��������� ���������
	// ���� � ����������� ����, ��� �����.	(abc 123 cde = > edc cba)

	// ��� ��������� �����
	char name[40];

	// ���� ����� ��������� �����
	cout << "Enter name source file: ";
	cin.ignore();
	cin.getline(name, 40);

	// �������� ����� � ������ ������
	FILE* file = fopen(name, "r");

	// ���� ���� ������� ������� �������
	if (file != nullptr)
	{
		// ����� ��� ����� ������
		char* buff = (char*)malloc(sizeof(char) * 200);

		// ���������� �����
		size_t rows = 0;

		// ���������� ��������
		size_t cols = 0;

		// ������� ���������� ����� � ����� 
		while (!feof(file))
		{
			fgets(buff, 199, file);

			if (ftell(file) == 0)
			{
				cout << "Error! File is empty!" << endl;
				return;
			}

			rows++;
		}

		// ������� ��������� � ����� �� ������
		fseek(file, 0, SEEK_SET);

		// �������� ������ 
		strcpy(buff, "");

		// ��������� ������ ��� ���������� �����
		char** content = (char**)malloc(sizeof(char*) * rows);

		// ���� ��������� � ����� �� ������ ����� �����
		for (size_t i = 0; i < rows; i++)
		{
			// ���������� ����� ������ ����� � �����
			fgets(buff, 199, file);

			// �������� �� ������ ����� 
			size_t size = delNum(buff);

			// ��������� ������
			coupStr(buff, size);
			
			// �������� ������ � ��������� �������
			content[i] = (char*)malloc(sizeof(char) * size + 1);

			// ���������� ������ ����� ���������� ������ ����� ������
			strcpy(content[i], buff);

			// �������� ������
			strcpy(buff, "");
		}

		// �������� ������ ��� ����� ������
		free(buff);

		// �������� �����
		fclose(file);

		// �������� ��������� ����� � ������ ������
		file = fopen(name, "w");


		// ���������� ����� �������� �� ������
		for (size_t i = 0; i < rows; i++)
		{
			fputs(content[i], file);

			// �������� ����� �� ���������� �������
			free(content[i]);
		}

		// �������� ���������� �������
		free(content);

		// �������� �����
		fclose(file);

		cout << "Save file" << endl;
	}
	// ���� ���� �� ������� �������
	else cout << "File NOT found" << endl;
}

// �������� �� ������ �����
size_t delNum(char buff[])
{
	// ����� ������
	long len = strlen(buff);

	// �������� ������ �� �����
	for (int i = 0; i < len; i++)
	{
		// ���� ������� � ������ �������� ������ 
		if (buff[i] >= '0' && buff[i] <= '9')
		{
			// ����� ������� ����� �� ���� �������
			for (size_t k = i; k < len; k++)
			{
				swap(buff[k], buff[k + 1]);
			}

			i--;

			// ���������� ����� ������
			len--;
		}
	}

	return len;
}

// ��������� ������
void coupStr(char buff[], size_t size)
{
	// �������� ���������� ���������� ��� �����
	size_t len = size;
	


	// ��������� ������ 
	for (size_t i = 0, k = len - 1; i < len / 2; i++)
	{
		if (buff[k - i] == '\n')
		{
			k--;

			if (k < 2)
				break;
		}
		swap(buff[i], buff[k - i]);
	}

}
