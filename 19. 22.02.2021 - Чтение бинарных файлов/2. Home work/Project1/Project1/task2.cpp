#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

// �������� ����� � �����������
void nameFileEdit(char name[], char source[], char exp[]);

// �������� ����� ��� ����� ��������
void nameFileEdit(char name[], char source[]);

void task2()
{
	// 2. ������������ ������ ��� �����, ��������� ����� ��� ��
	// 2 ������ ����� � ���������� �� � ������������ .part1, .part2

	char source[40], name1[40], name2[40];

	char copy[40] = "copy";

	// ������ � ������������ ��� ������� � ������� �����
	char exp1[10] = ".part1";
	char exp2[10] = ".part2";

	// ���� ����� ��������� �����
	cout << "Enter source file name: ";
	cin >> source;

	cout << endl;

	// �������� ����� � ����������� ��� ������� �����
	nameFileEdit(name1, source, exp1);

	// �������� ����� � ����������� ��� ������� �����
	nameFileEdit(name2, source, exp2);

	// �������� ����� � ����������� ��� ����� ��������
	nameFileEdit(copy, source);

	// �������� ��������� ����� � ������ ��������� ������
	FILE* fsource = fopen(source, "rb");

	// �������� ������� ����� � ������ �������� ������
	FILE* file1 = fopen(name1, "wb");

	// �������� ������� ����� � ������ �������� ������
	FILE* file2 = fopen(name2, "wb");

	if (fsource != nullptr && file1 != nullptr && file2 != nullptr)
	{
		// �������� � �������� ����� ��������������� � ����� 
		fseek(fsource, 0, SEEK_END);

		// ���������� ������ � �������� ����� 
		long size_source = ftell(fsource);

		// ��������� � �������� ����� ��������������� � ������
		fseek(fsource, 0, SEEK_SET);

		// ���������� ���� ��� ������� �����
		int size1 = size_source / 2;

		// ���������� ���� ��� ������� �����
		int size2 = size_source - size1;

		// ����� ��� ������� �����
		char* buff1 = new char[size1];

		// ����� ��� ������� �����
		char* buff2 = new char[size2];

		// ���������� ������ ����� ��������� ����� � ����� ��� ������� �����
		fread(buff1, sizeof(char), size1, fsource);

		// ���������� ������ ����� ��������� ����� � ����� ��� ������� �����
		fread(buff2, sizeof(char), size2, fsource);

		// �������� ��������� �����
		fclose(fsource);

		// ������ �� ������ ��� ������� ����� � ������ �����
		fwrite(buff1, sizeof(char), size1, file1);

		// ������ �� ������ ��� ������� ����� �� ������ ����
		fwrite(buff2, sizeof(char), size2, file2);

		delete[] buff1, buff2;
		
		// �������� ������� �����
		fclose(file1);

		// �������� ������� �����
		fclose(file2);

		// �������� ������ � ������ ��� ������ 
		file1 = fopen(name1, "rb");
		file2 = fopen(name2, "rb");

		// ��������� ��������� � ������ ����� � �����
		fseek(file1, 0, SEEK_END);

		// ����� ������� �����
		size1 = ftell(file1);

		// ��������� ��������� � ������ ����� �� ������
		fseek(file1, 0, SEEK_SET);

		// ��������� ��������� �� ������ ����� � �����
		fseek(file2, 0, SEEK_END);

		// ����� ������� �����
		size2 = ftell(file2);

		// ��������� ��������� �� ������ ����� � ������
		fseek(file2, 0, SEEK_SET);

		// ����� ������ ��� ������������ �����
		int size_buf = size1;

		// ���� ����� ������� ����� ������ ����� ������� �����
		if (size2 > size1)
			size_buf = size2;

		// ����� ��� ����� �������� ������ �� ���� �������� ����
		char* buffer = new char[size_buf];

		// �������� ����� �������� � ������ ������
		FILE* copyFile = fopen(copy, "wb");

		// ���������� ������� ����� � �����
		fread(buffer, sizeof(char), size1, file1);

		// ������ ������� ����� � ���� ��������		
		fwrite(buffer, sizeof(char), size1, copyFile);

		// �������� ������� �����
		fclose(file1);

		// ���������� ������� ����� � �����
		fread(buffer, sizeof(char), size2, file2);

		// ������ ������� ����� � ���� ��������
		fwrite(buffer, sizeof(char), size2, copyFile);

		// �������� ������� �����
		fclose(file2);

		// �������� ����� ��������
		fclose(copyFile);

		cout << "Files save" << endl;
	}

	else
	{
		cout << "Error opening file" << endl;
		return;
	}
}

// �������� ����� � �����������
void nameFileEdit(char name[], char source[], char exp[])
{
	// ����� �����
	int size = strlen(source);

	// ���������� ����� ���������� ��������� �����
	for (size_t i = 0; source[i] != 0; i++)
	{
		if (source[i] == '.')
			size = i;
	}

	// ��������� ����� ����� ������ ��������� �����
	for (int i = 0; i < size; i++)
	{
		name[i] = source[i];
	}

	name[size] = 0;

	// ������� ���������� 
	char* pName = &name[strlen(name)];

	//int len = strlen(name);

	for (size_t i = 0; exp[i - 1] != 0; i++)
	{
		pName[i] = exp[i];
	}

}

// �������� ����� ��� ����� ��������
void nameFileEdit(char name[], char source[])
{
	// ��������� �� ��� ��������� �����
	char* pSource = &source[0];

	int size = 0;

	// ����� ���� ����� 
	for (size_t i = 0; source[i] != 0; i++)
	{
		if (source[i] == '/')
		{
			pSource = &source[i + 1];
			size = i;
		}
	}

	// ����� �����
	int len = strlen(name);

	char* pName = &name[len+1];

	strcpy(pName, name);

	for (size_t i = len-1, k = 0; k < len; i++, k++)
	{
		swap(name[i], name[i + 1]);
	}

	len *= 2;

	name[len] = 0;

	// �������� ����� �� ���������� ��������� ����� ���� ����� 
	// ���������� ���������� ����� ����� ����� ����� �� �����
	for (size_t i = 0; i <= size; i++)
	{
		name[i] = source[i];
	}

	name[len] = 0;

	// ����� �����
	pName = &name[strlen(name)];

	// ����������� ����� ��������� �����
	for (size_t i = 0; pSource[i - 1] != 0; i++)
	{
		pName[i] = pSource[i];
	}

	name[strlen(name)] = 0;
}