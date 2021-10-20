#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <io.h>
#include <direct.h>

using namespace std;

// ������� ������������ � �������� ����� debug � .vs
void removeFolder(char* dir, unsigned long* count)
{
	// ����������� ����
	char* path = new char[_MAX_PATH];

	strcpy(path, dir);

	// ���������� � ���� '\\'
	strcat(path, "\\");

	// ��������� �� ������ ����� ����� � ����
	char* name = path + strlen(path);
	
	// ��� ��� ������������
	strcpy(name, "*");

	// �������� ������
	_finddata_t list;

	// ��������� �� ������ � �������� ������
	long point = _findfirst(path, &list);

	// ������������ ������
	do
	{
		// ���������� � ���� ����� �������� �����
		strcpy(name, list.name);

		// ���� ��� ����� � ��������� .vs ��� debug
		if (!strcmp(list.name, ".vs") || !strcmp(list.name, "debug") || !strcmp(list.name, "x64"))
		{ 
			cout << path << "     " << list.size << "     ";

			// �������� �����
			if (rmdir(path) == -1)
			{
				cout << "ERROR REMOVE FOLDER!" << endl;

				continue;
			}
		
			cout << "REMOVE COMPLITE!" << endl;

			++*count;

			continue;
		}

		// ���� ���� �������� ������
		if (list.attrib & _A_SUBDIR && strcmp(list.name, ".") != 0 && strcmp(list.name, "..") != 0)
		{
			removeFolder(path, count);
		}

	} while (!_findnext(point, &list));


	// �������� ����
	delete[] path;


}

void task1()
{
	// ��������� �������� ����� debug � .vs 

	// ���� � �����
	char* dir = new char[_MAX_PATH];

	// ���� ���� � �����
	cout << "Enter folder path: " << endl;
	cin.ignore();
	cin.getline(dir, _MAX_PATH);

	// ���������� '\\'
	// strcat(dir, "\\");

	// ��������� �� ������ �����
	// char* name = dir + strlen(dir);

	// ��������
	unsigned long* count = new unsigned long[2];

	// ���������� �������� �����
	*count = 0;

	// ����� ������ �������� �����
	*(count + 1) = 0;

	removeFolder(dir, count);

	cout << endl;

	cout << "Folder count: " << *count << endl;

	cout << "All size: " << *(count + 1) << endl;
}