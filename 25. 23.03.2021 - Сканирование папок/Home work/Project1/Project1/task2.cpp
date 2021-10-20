#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <io.h>

using namespace std;

// �������� ���������� �����
bool detectExp(char* name)
{
	// ������ � ����������� 
	char* exp = new char[5];

	// ���������� ������ ��������
	strcpy(exp, ".txt");

	// ����� ������ ����� �����
	size_t len = strlen(name);

	// ���� ��� ������ ����� ��������
	if (len < 5)
	{
		delete[] exp;
		return false;
	}

	for (char* name_p  = name + strlen(name) - 4,*p = exp; *p; name_p++, p++)
	{
		// ���� �������� ����� �� ���������
		if (*p != *name_p)
		{
			delete[] exp;
			return false;
		}
	}

	delete[] exp;

	// ���� ���������� ����������
	return true;
}

void task2()
{
	// 2. ������������ ������ ���� � �����, ��������� ����������
	// ��� ��������� ����� � ���� �������������� ����

	// ����������
	char* dir = new char[80];

	// ���� ����������
	cout << "Enter directory: ";
	cin.ignore();
	cin.getline(dir, 80);

	// ���������� � ���� ������� '\'
	strcat(dir, "\\");

	// ��� �����
	char* name = new char[255];

	// ���������� ���� � ��� ��������������� �����
	strcpy(name, dir);

	// ���������� � ���� ����� ��������������� �����
	strcat(name, "result.txt");

	// �������� � �������� ��������������� ����� � ������ �������� ������
	FILE* result = fopen(name, "wb");

	// ����������� ����
	strcpy(name, dir);

	// ���������� � ���� ������� ����� ���������� .txt
	strcat(name, "*.*");

	cout << endl;

	// ������ ��������� ������ � �����
	_finddata_t list_TXT;

	// ��������� �� ������
	long point = _findfirst(name, &list_TXT);

	// ��������� �� ����
	FILE* file = nullptr;

	// ��������� ������ ���������������
	unsigned long* sum = new unsigned long;

	*sum = 0;

	// ���������� ������
	unsigned long* count = new unsigned long;

	*count = 0;

	// ������������ ����� � ��������� ����� � ����������� �� 
	// � ��������������
	while (!_findnext(point, &list_TXT))
	{
		// ���� ���� �������� ���������
		if (!(list_TXT.attrib & _A_SUBDIR) && detectExp(list_TXT.name))
		{
			cout << list_TXT.name << "      size: " << list_TXT.size << endl;

			// ����������� ���� � ����� � ������ ������� ����� ����� � ����
			strcpy(name, dir);

			// ���������� � ���� � ����� ����� ����� 
			strcat(name, list_TXT.name);

			// �������� �������� ����� � ����� ��������� ������
			file = fopen(name, "rb");

			// ���� ����� ������� ������
			if (file != nullptr)
			{
				// ���������� �������� ������
				*count += 1;

				// ����������� ������� ����� � ������� ��������������� �����
				*sum += list_TXT.size;

				// ����� ��� �����
				char* buffer = new char[list_TXT.size];

				// ���������� ����� � �����
				fread(buffer, sizeof(char), list_TXT.size, file);

				// ������ �� ������ � �������������� ����
				fwrite(buffer, sizeof(char), list_TXT.size, result);

				// �������� ������
				delete[] buffer;
				 
				// �������� �������� ����� 
				fclose(file);
			}

			// ���� �� ������� ������� ����
			else cout << list_TXT.name << "      Failed to open the file" << endl;
		}
	}

	// �������� ������
	_findclose(point);

	cout << endl;

	// �������� � ���������� ��������������� �����
	fclose(result);

	cout << "Count files = " << *count << "     All size: " << *sum << endl;

	cout << endl;

	cout << "Save result.txt" << endl;

	delete[] dir, name, sum;
}