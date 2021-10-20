#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <io.h>
#include <conio.h>

using namespace std;

// ������������ ������ � ����� �� ����� 
void scanFile(char* dir, char* mask, unsigned long* count)
{
	// ���������� � ���� '\\'
	strcat(dir, "\\");

	// ��������� �� ������ ����� � ����
	char* name = dir + strlen(dir);

	// ����� ��� ���������� ���� ������
	strcpy(name, "*");

	// ������ ����� � �����
	_finddata_t list;

	// ��������� �� ������
	long point = _findfirst(dir, &list);

	// ������������ ������ ���� ������
	do
	{
		if (!strcmp(list.name, ".") || !strcmp(list.name, ".."))
		{
			continue;
		}

		// ���������� ����� �������� ����� � ����
		strcpy(name, list.name);

		// ���������� ��� ����� 
		int* i = new int;

		// ����� �������� '|' ��� ����������� ������ ����������
		for (*i = 0; *i < *(count + 5); ++ * i)
		{
			cout << "|";
		}
		delete i;

		// ����� �������� ���� � ������
		cout << name << "     ";

		// ���� ���� �������� ������
		if (list.attrib & _A_SUBDIR)
		{
			cout << "<DIR>" << endl;

			// ���������� �������� �����
			++* (count + 4);

			// ���������� ������ �����
			++* (count + 5);

			// ����� ���� �� �������
			scanFile(dir, mask, count);
			
			// ���������� ������ �����
			--* (count + 5);

			continue;
		}

		// ���� ��� ������� ����
		else 
		{
			// ����� ������� �����
			cout << list.size << endl;

			// ���������� ������ �������� ������
			++* count;

			// ����������� ������� ����� � ������ ������� ��������� ������
			*(count + 2) += list.size;
		}
	} while (!_findnext(point, &list));

	_findclose(point);

	// � ���� � ����� ����������� ����� 
	strcpy(name, mask);
	
	_finddata_t list_mask;

	// �������� �������� ������ ������ �� �����
	long point_mask = _findfirst(dir, &list_mask);

	if (point_mask == -1)
	{
		_findclose(point_mask);

		return;
	}

	// ������������ ������
	do
	{
		if (!(list_mask.attrib & _A_SUBDIR))
		{
			// ���������� �������� ���������� ������ �� �����
			++* (count + 1);

			// ��������� ������ ������� ���� ������ �� �����
			*(count + 3) += list_mask.size;
		}
	} while (!_findnext(point_mask, &list_mask));

	_findclose(point_mask);
}

void task1()
{
	// 1. ������������ ������ ���� � ����� � ����� ������, 
	// ��������� ������������ ����� ������ ������, ���������
	// � ����� � � ���������

	// ���� � �����
	char* dir = new char[_MAX_PATH];

	// �����
	char* mask = new char[_MAX_FNAME];

	// ���� ���� � �����
	cout << "Enter folder path: ";
	cin.ignore();
	cin.getline(dir, _MAX_PATH);

	cout << endl;

	// ���� �����
	cout << "Enter mask: ";
	cin.getline(mask, _MAX_FNAME);

	// ������������ �������� ����� ������� ��� ������ ���������� ������������
	cout << "\n\n\n\n\nPRESS ANY KEY TO START..." << endl;

	// ������� ����� �������
	_getch();

	// �������� �������
	system("cls");

	// ������ ������ 
	_finddata_t list;

	// ��������� �� ������ � �������� ������ ������
	long point = _findfirst(dir, &list);

	// ������ ���������; [0] - ����� ���������� ������ � �����; [1] - ���������� ������ �� �����; 
	// [2] - ����� ������ ���� ������; [3] - ������ ���� ������ �� �����; [4] - ����� ���������� �����;
	// [5] - ������� ������� �����;
	unsigned long* count = new unsigned long[6];

	// [0] - ����� ���������� ������ 
	*count = 0;
	// [1] - ���������� ������ �� �����
	*(count + 1) = 0;
	// [2] - ����� ������ ���� ������
	*(count + 2) = 0;
	// [3] - ������ ���� ������ �� �����
	*(count + 3) = 0;
	// [4] - ����� ���������� �����
	*(count + 4) = 0;
	// [5] - ������� ������� �����
	*(count + 5) = 0;

	// ������ ������� ������������
	scanFile(dir, mask, count);

	// ������� ����� ������� ��� ������ ������ 
	cout << "\n\n\n\n\nPRESS ANY KEY TO OUTPUT THE REPORT..." << endl;

	// ������� ����� �������
	_getch();
	
	// �������� �������
	system("cls");

	// ����� ������ 
	cout << "            REPORT            " << endl;
	// ���� ���������� �����
	cout << "> Count all subdir: " << *(count + 4) << endl;
	// ����� ���������� ������
	cout << "> Count all file: " << *count << endl;
	// ������ ���� ������ 
	cout << "> Size all file: " << *(count + 2) << endl;
	// ���������� ������ �� �����
	cout << "> Count mask file: " << *(count + 1) << endl;
	// ������ ������ �� ����� 
	cout << "> Size mask file: " << *(count + 3) << endl;

	cout << "\n\n\n\n\nPRESS ANY KEY TO CLOSE THE PROGRAMM..." << endl;

	delete[] dir, count;

	// �������� ������� ����� �������
	_getch();
}