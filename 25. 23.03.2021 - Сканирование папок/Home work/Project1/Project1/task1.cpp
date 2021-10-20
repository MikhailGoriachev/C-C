#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <io.h>
using namespace std;

void task1()
{
	// 1. ������������ ������ ���� � �����, ���������
	// ������������ ����� ������ ������ � �����

	// ����������
	char* dir = new char[80];

	// ���� ����������
	cout << "Enter dir: ";
	cin.ignore();
	cin.getline(dir, 80);

	strcat(dir, "\\*.*");

	cout << endl;

	// ������ ������ � ����������
	_finddata_t list;

	// ��������� �� ������ ������� ������
	long point = _findfirst(dir, &list);

	// ����� ������� ���� ������
	unsigned long* sum = new unsigned long;

	*sum = 0;

	// ���������� ������
	unsigned long* count = new unsigned long;

	*count = 0;

	cout << "File list" << endl;

	// ������� ������ � ����������� �� �������
	while (!_findnext(point, &list))
	{
		// ���� ���� �������� �����������
		if (list.attrib & _A_SUBDIR)
		{
			continue;
		}

		// ����� ����� ����� � ��� �������
		cout << list.name << "      " << list.size << endl;

		// ����������� � �������� ������
		*count += 1;

		// ����������� ������� �������� �����, ������� �� ��������� ������
		*sum += list.size;
	}

	cout << endl;
	
	// �������� ������
	_findclose(point);

	// ����� ����������
	cout << "Count files = " << *count << "     All size = " << *sum << endl;

	delete[] dir, sum;
}