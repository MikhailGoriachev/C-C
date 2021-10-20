#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

void task3()
{
	// 3. ������������ ������ N ���� ������, ��������� ���������� �� � ���� ����

	char name[40];

	int quan = 0;

	// ���� ���������� ������ 
	cout << "Enter the number of files: ";
	cin >> quan;

	cout << endl;

	// ���� ���������� ������ ������ �������
	if (quan < 1)
	{
		cout << "Number must be greater than zero!" << endl;
		return;
	}

	// ���� ����� ����� ��� ����������
	cout << "Enter the filename to save: ";
	cin.ignore();
	cin.getline(name, 40);

	cout << endl;

	// �������� ����� ��� ���������� � ������ ������
	FILE* file = fopen(name, "wb");

	// ������ ����� �������
	for (size_t i = 0; i < quan; i++)
	{
		// ���� ����� �����
		cout << "Enter name file: " << i + 1 << " : ";
		cin.getline(name, 40);

		// �������� �����
		FILE* part = fopen(name, "rb");

		// ���� ���� ����� ������� ������
		if (part != nullptr)
		{
			// ��������� ��������� � ����� ����� �����
			fseek(part, 0, SEEK_END);

			// ����� ����� �����
			long size = ftell(part);

			// �������� ������ �� ����� �����
			char* buff = new char[size];

			// ��������� ��������� � ������ ����� �����
			fseek(part, 0, SEEK_SET);

			// ����������� ����� ����� � �����
			fread(buff, sizeof(char), size, part);

			// ���������� ����� ��� ���������� �������
			fwrite(buff, sizeof(char), size, file);

			// �������� ������ �� ����������� ������
			delete[] buff;

			// ��������� ����� �����
			fclose(part);
		}
		else
		{
			cout << "File NOT found!" << endl;
			return;
		}
	}

	cout << endl;

	cout << "Save" << endl;

	cout << endl;

	fclose(file);

}