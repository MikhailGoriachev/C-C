#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

// ������� ������� � ������
long countVowels(char a[]);

void task1()
{
	// 1. ������������ ������ ��� �����, ��������� ������������
	// ���������� ������� ���� � �����(fread)

	// ����� ������
	char name1[40];

	// ��������� �� ����
	FILE* file;

	// ���������� ������� ���� � �����
	long countVow = 0;

	// ���� ����� ������� �����
	cout << "Enter name file 1: ";
	cin.ignore();
	cin.getline(name1, 40);

	// �������� ������� ����� � ������ ������ ��������� �����
	file = fopen(name1, "rb");

	// ���� ������ � ������ ���� ������� �������
	if (file != nullptr)
	{
		// ������� ��������� � ����� �����		
		fseek(file, 0, SEEK_END);
		
		// ������� ������� ��������� � ����� 
		long size = ftell(file);

		cout << "Size: " << size << endl;

		// ��������� � ����� ��������� �� ������
		fseek(file, 0, SEEK_SET);

		// ����� ������ ���� ���� � �����
		char* buffer = new char[size];

		// ����������� ��������� ���������� ����� � �����
		fread(buffer, sizeof(char), size, file);

		// ���������� ������ ���������� ���������� ������� ����
		countVow = countVowels(buffer);

		for (size_t i = 0; i < size; i++)
		{
			cout << buffer[i];
		}

		cout << endl;
	}

	else
	{
		cout << "File NOT found!" << endl;
		return;
	}

	// �������� �����
	fclose(file);

	cout << "Count vowels: " << countVow << endl;
}


// ������� ������� ���� � ������
long countVowels(char a[])
{
	char b[40] = "EeYyUuIiOoAa";

	long count = 0;

	for (size_t i = 0; a[i] != 0; i++)
	{
		for (size_t k = 0; b[k] != 0; k++)
		{
			if (a[i] == b[k])
			{
				count++;
				break;
			}
		}
	}

	return count;
}