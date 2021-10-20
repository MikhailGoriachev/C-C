#define  _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <io.h>

using namespace std;

void task2()
{
	// ������������ ������ ��� ����� ��������� ������������ 
	// ����� ������ ������

	// ���������� 
	char dir[40];

	// ���� ����������
	cout << "Enter dir: ";
	cin.ignore();
	cin.getline(dir, 40);

	// ���������� � ����� ���������� *.*
	strcat(dir, "\\*.*");

	// ������ ������ � �����
	// ���������� ���� ���������
	_finddata_t list;

	// ��������� �� ������
	long point;

	// ������� ��������� ������ ������ � ����� � ���������� ��� � ������,
	// ���������� ��������� �� ������
	point = _findfirst(dir, &list);

	// ������ ������
	long size = 0;

	// ���� ������ �� 
	while (_findnext(point, &list) == 0)
	{
		// ���� ��� �� ��������
		if (!(list.attrib & _A_SUBDIR))
		{
			// ����������� � ������ ������� ������ ������ �� ���������
			size += list.size;
		}
	}

	// ����� ����������
	cout << "Size: " << size << endl;
}