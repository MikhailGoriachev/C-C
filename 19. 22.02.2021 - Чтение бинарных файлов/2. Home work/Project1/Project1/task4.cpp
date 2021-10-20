#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

// ���������� ����� � ������
void analysis(char buff[], size_t count[], char lett[], long size);

// ����� ����������
void outResult(size_t count[], char lett[]);

void task4()
{
	// 4. ������������ ������ ��� �����, ��������� ������������ ��������� ������� ���� ����� � ������� ��� �� �����
	//  a - 23
	//	b - 3
	//	c - 456
	//	d - 44

	// ��� �����
	char name[40];

	// ���� ����� �����
	cout << "Enter name file: ";
	cin.ignore();
	cin.getline(name, 40);

	// ������ � ����������� ����
	size_t count[52] = { 0 };

	// ������ �� ����� �������
	char lett[53] = "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz";

	// �������� ����� � ������ �������� ������
	FILE* file = fopen(name, "rb");

	// ���� ���� ������ ������� 
	if (file != nullptr)
	{
		// ��������� ��������� � ����� � �����
		fseek(file, 0, SEEK_END);

		// ����� �����
		long size = ftell(file);

		// ����� ��� ���������� ����� 
		char* buff = new char[size];

		// ��������� ��������� � ����� � ������
		fseek(file, 0, SEEK_SET);

		// ����������� ����� � �����
		fread(buff, sizeof(char), size, file);

		// ���������� ������
		analysis(buff, count, lett, size);

		// ����� ����������
		outResult(count, lett);
	}
	// ���� ���� �� ������� �������
	else cout << "Error opening file" << endl;
}

// ���������� ����� � ������
void analysis(char buff[], size_t count[], char lett[], long size)
{
	for (size_t i = 0; i < size; i++)
	{
		for (size_t k = 0; lett[k] != 0; k++)
		{
			if (buff[i] == lett[k])
			{
				count[k]++;
				break;
			}
		}
	}
}

// ����� ���������� 
void outResult(size_t count[], char lett[])
{
	cout << endl;

	cout << "Result" << endl;

	bool n = false;

	for (size_t i = 0; lett[i] != 0; i++)
	{
		if (count[i] > 0)
		{
			cout << lett[i] << " = " << count[i] << endl;
			n = true;
		}
	}

	// ���� ������� ���� �� �������
	if (!n)
		cout << "Letters NOT found!" << endl;
}