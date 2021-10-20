#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <io.h>

using namespace std;

void task1()
{
	// 1. ������������ ������ ���� � ����� � ����� ������, 
	// ��������� ������������ ���������� ������ � �����
	// ���������� ���� � ������ � ��������� ������ � �����

	// ���� � �����
	char* dir = new char[_MAX_PATH];

	// ���� ���� 
	cout << "Enter path: ";
	cin.ignore();
	cin.getline(dir, _MAX_PATH);

	cout << endl;

	// ����� ��� ������ ����� 
	char* mask = new char[_MAX_PATH];

	// ���� ����� 
	cout << "Enter mask: ";
	cin.getline(mask, _MAX_PATH);

	cout << endl;

	// ����������� ���� � ���� � �����
	strcat(dir, "\\");

	// ����������� ����� � ����
	strcat(dir, mask);

	// ������ ������ � �����
	_finddata_t list;

	// ��������� �� ������ � �������� ������
	long point = _findfirst(dir, &list);

	// ����� ���������� ���� � �����
	unsigned long* count_lett = new unsigned long;

	*count_lett = 0;

	// ���������� ������ 
	unsigned long* count_files = new unsigned long;

	*count_files = 0;

	// ������ ���� ������ 
	unsigned long* count_size = new unsigned long;

	*count_size = 0;

	// ������������ ������
	if (point != -1)
	{
		do
		{
			// ���� ���� �� �������� ������
			if (!(list.attrib & _A_SUBDIR))
			{
				// ���������� �������� ��������� ���� � ����� 
				*count_lett += strlen(list.name);

				// ���������� �������� ������
				++* count_files;

				// ����� ����� ���� � ��� �������
				cout << list.name << "     " << list.size << endl;

				// ����������� �������� ������ ������� ���� ������
				*count_size += list.size;
			}
			else cout << list.name << "     <DIR>" << endl;
		} while (!_findnext(point, &list));
	}

	cout << endl;

	// �������� ������
	_findclose(point);

	// ����� �������� ������ 
	cout << "Count files = " << *count_files << endl;

	// ����� ���������� ���� � �����
	cout << "Count letters = " << *count_lett << endl;

	// ����� ������ ������� �����
	cout << "All size = " << *count_size << endl;

	// �������� ������
	delete[] dir, mask;
	delete count_lett, count_files, count_size;
}