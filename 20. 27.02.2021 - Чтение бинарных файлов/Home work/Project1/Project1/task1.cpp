#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

// ������ ���� ���� �� '!'
void numDel(char a[], long size);

void task1()
{
	// 1. ������������ ������ ��� �����, ��������� �������� ��� �������� ������� �� '!'

	// ��� �����
	char name[40];

	// ���� ����� �����
	cout << "Enter file name: ";
	cin.ignore();
	cin.getline(name, 40);

	cout << endl;

	// �������� ����� � ������ ������� ������
	FILE* file = fopen(name, "rb");

	// ���� ���� ������� ������
	if (file != nullptr)
	{
		// ��������� ��������� � ����� � ����� 
		fseek(file, 0, SEEK_END);

		// ����� �����
		long size = ftell(file);

		// ��������� ��������� � ������ �����
		fseek(file, 0, SEEK_SET);

		// ����� ��� ����������� �����
		char* buffer = new char[size];

		// ���������� ����� � �����
		fread(buffer, sizeof(char), size, file);

		// �������� �����
		fclose(file);

		// ������ ���� ���� � ������ �� '!'
		numDel(buffer, size);

		// �������� ����� � ������ ������ ������
		file = fopen(name, "wb");

		// ������ � ���� � ������
		fwrite(buffer, sizeof(char), size, file);

		// �������� ������
		delete[] buffer;

		// �������� �����
		fclose(file);

		cout << "Save" << endl;
	}
	// ���� ����� �� ������� ������� 
	else cout << "File NOT found" << endl;
}

// ������ ���� ���� �� '!'
void numDel(char a[], long size)
{
	for (size_t i = 0; i < size; i++)
	{
		if (a[i] >= '0' && a[i] <= '9')
			a[i] = '!';
	}
}