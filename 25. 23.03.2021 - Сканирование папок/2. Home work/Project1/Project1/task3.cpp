#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <io.h>

using namespace std;

void task3()
{
	// 3. ������������ ������ 2 ���� � ������, ���������
	// �������� ��� ����� �� ������ ����� �� ������

	// ���� � ���������� �������
	char* source = new char[80];

	// ���� � ���������� ����������
	char* destination = new char[80];

	// ���� ��������� ������
	int moving = 1;
	
	// ����� ������: �����������/�����������
	cout << "Select copy(1)/moving(2): ";
	cin >> moving;

	cout << endl;

	// ���� ���� �������
	cout << "Enter source: ";
	cin.ignore();
	cin.getline(source, 80);

	// ���������� � ���� '\'
	strcat(source, "\\");

	// ������ ���� � ������� �������� �������� � ������ ����������
	strcpy(destination, source);

	// ���������� � ����� ���������� "*.*", ������� �������� �������� � ������ ����������
	strcat(destination, "*.*"); /// ��������

	// ������ ������ � ����� �������
	_finddata_t list;

	// ��������� �� ������ ������� ������
	long point = _findfirst(destination, &list);

	// ���� ���� ��������� 
	cout << "Enter destination: ";
	cin.getline(destination, 80);

	// ���������� � ���� '\'
	strcat(destination, "\\");


	// ��� � ���� ����� �������
	char* name_s = new char[255];

	// ��� � ���� ����� ����������
	char* name_d = new char[255];

	// ��������� �� ���� �������
	FILE* file_s = nullptr;

	// ��������� �� ���� ����������
	FILE* file_d = nullptr;

	// ��������� ������ ������
	long* sum = new long;

	*sum = 0;

	// ���������� ������ 
	long* count = new long;

	*count = 0;

	// ����������� ������
	while (!_findnext(point, &list))
	{
		// ���� ���� �� �������� �����������
		if (!(list.attrib & _A_SUBDIR))
		{
			// ���� �����������
			if (moving == 1)
				cout << "Copy " << list.name << "     ";
			else cout << "Moving " << list.name << "     ";

			// ����������� ���� ����� �������
			strcpy(name_s, source);

			// ���������� � ���� ����� ����� �������
			strcat(name_s, list.name);

			// ���������� ���� ����� ����������
			strcpy(name_d, destination);

			// ���������� � ���� ����� ����� �������
			strcat(name_d, list.name);

			// �������� ����� � ������� � ������ ��������� ������
			file_s = fopen(name_s, "rb");

			// ���� ���� ������� ������� �������
			if (file_s != nullptr)
			{
				// �������� � �������� ����� ���������� � ������ �������� ������
				file_d = fopen(name_d, "wb");

				// ���� ���� ���������� ������� �������
				if (file_d != nullptr)
				{
					// ����� ��� �����
					char* buffer = new char[list.size];

					// ����������� � ���������� ������
					++*count;

					// ������������ ������� ����� � ���������� �������
					*sum += list.size;

					// ���������� ����� ������� � �����
					fread(buffer, sizeof(char), list.size, file_s);

					// ������ � ���� ���������� �� ������
					fwrite(buffer, sizeof(char), list.size, file_d);

					// �������� ������
					delete[] buffer;

					// �������� ����� �������
					fclose(file_s);

					if (moving == 2)
						remove(name_s);

					// �������� ����� ����������
					fclose(file_d);

					cout << "save" << endl;
				}
				// ���� ���� ���������� �� ������� ������� �/��� �������
				else cout << "ERROR CREATE FILE" << endl;
			}
			// ���� ���� ������� �� ������� �������
			else cout << "ERROR OPEN FILE" << endl;
		}
	}

	cout << endl;

	cout << "The end" << endl;

	cout << endl;

	cout << "Result" << endl;
	cout << "Count files = " << *count << "      " << "All size = " << *sum << endl;

}