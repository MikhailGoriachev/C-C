#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

void task3()
{
	// 3. ������������ ������ 2 ����� �����, ��������� ���������� �� � ���� ����

	// ����� ������� � ������� �����
	char name1[40], name2[40], name3[40];

	// ���� ����� ������� �����
	cout << "Enter first file name: ";
	cin.ignore();
	cin.getline(name1, 40);

	cout << endl;

	// ���� ����� ������� �����
	cout << "Enter second file name: ";
	cin.getline(name2, 40);

	cout << endl;

	// ���� ����� ����� ��� ����������
	cout << "Enter save file name: ";
	cin.getline(name3, 40);

	cout << endl;

	// �������� ������� � ������� ����� � ������ ������� ������
	FILE* file1 = fopen(name1, "rb");
	FILE* file2 = fopen(name2, "rb");

	// �������� ����� ��� ���������� � ������ ������ ������ 
	FILE* save = fopen(name3, "wb");

	// ���� ��� ����� ������� �������
	if (file1 != nullptr && file2 != nullptr && save != nullptr)
	{
		// ��������� � ������ ����� ��������������� � �����
		fseek(file1, 0, SEEK_END);

		// ��������� �� ������ ����� ��������������� � �����
		fseek(file2, 0, SEEK_END);

		// ����� ������� �����
		long size1 = ftell(file1);

		// ����� ������� �����
		long size2 = ftell(file2);

		// ��������� � ������ ����� ��������������� � ������ 
		fseek(file1, 0, SEEK_SET);

		// ��������� �� ������ ����� ��������������� � ������
		fseek(file2, 0, SEEK_SET);

		// ����� ������
		size_t size = size1;

		// ���� ����� ������� ����� ������ ����� ������� �����
		if (size2 > size1)
			size = size2;

		// ����� 
		char* buffer = new char[size];

		// ����������� ������� ����� � �����
		fread(buffer, sizeof(char), size1, file1);

		// ���� ��� ���������� ����������� ���������� ������ 
		fwrite(buffer, sizeof(char), size1, save);

		// �������� ������ 
		strcpy(buffer, "");

		// ���������� ������� ����� � �����
		fread(buffer, sizeof(char), size2, file2);

		// ���� ��� ���������� ����������� ���������� ������
		fwrite(buffer, sizeof(char), size2, save);

		// �������� ������� �����
		fclose(file1);

		// �������� ������� �����
		fclose(file2);

		// �������� ����� ��� ����������
		fclose(save);

		cout << "Save" << endl;
	}

	// ���� ����(�) �� ������� �������
	else cout << "Error opening file!" << endl;
}