#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

// ������ ������� �������� �� '!'
void replDoubleSymb(char a[], long* size);

void task4()
{
	// 4. ������������ ������ ��� �����, ��������� �������� ��� 
	// ������� ������� �� ������ '!' (�������->���!��)

	// ��� �����
	char name[40];

	// ���� ����� �����
	cout << "Enter file name: ";
	cin.ignore();
	cin.getline(name, 40);

	cout << endl;

	// �������� ����� � ������ ������� ������ 
	FILE* file = fopen(name, "rb");

	// ���� ���� ������ ������
	if (file != nullptr)
	{
		// ��������� ��������� � ����� � �����
		fseek(file, 0, SEEK_END);

		// ����� �����
		long size = ftell(file);
		long buf_size = size + 1;

		// ��������� ��������� � ����� � ������
		fseek(file, 0, SEEK_SET);

		// ����� ��� ���������� �����
		char* buffer = new char[buf_size];

		// ���������� ����� � �����
		fread(buffer, sizeof(char), size, file);

		// �������� �����
		fclose(file);

		// ��������� ������
		replDoubleSymb(buffer, &size);

		// �������� ����� � ������ �������� ������
		file = fopen(name, "wb");

		// ���������� ����� ���������� ������
		fwrite(buffer, sizeof(char), size, file);

		// �������� ������
		delete[] buffer;

		// �������� �����
		fclose(file);

		cout << "Save" << endl;
	}
	// ���� ���� �� ������� �������
	else cout << "File NOT found" << endl;
}

// ������ ������� �������� �� '!'
void replDoubleSymb(char a[], long* size)
{
	for (size_t i = 1; i < *size; i++)
	{
		if (a[i] == a[i-1])
		{
			a[i - 1] = '!';
			for (size_t k = i; k < *size; k++)
			{
				swap(a[k], a[k + 1]);
			}

			*size -= 1;
		}
	}
}