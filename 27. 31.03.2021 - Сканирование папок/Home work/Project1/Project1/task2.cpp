#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <io.h>
#include <conio.h>

using namespace std;

// ������������ ����� � ��������
void scanFile(char* dir, unsigned long* min_size, unsigned long* count)
{
	// ������� � ���� '\'
	strcat(dir, "\\");

	// ��������� �� ������ ����� � ����
	char* name = dir + strlen(dir);

	// ����� ���������� ����� '*'
	strcpy(name, "*");

	// ������ ������ 
	_finddata_t list;

	// ��������� �� ������ � �������� ���������� ������ ������
	long point = _findfirst(dir, &list);

	// ������������ ������ 
	do
	{
		// ���� ���� �������� ������ � ������ "." ��� ".."
		if ((list.attrib & _A_SUBDIR) && (!strcmp(list.name, ".") || !strcmp(list.name, "..")))
			continue;

		// ���������� ��� ��������
		int* i = new int;

		// ����� ������ '>' �� ����� ������ �����
		for (*i = 0; *i < *(count + 9);  ++*i)
		{
			cout << "|";
		}

		// �������� ������ 
		delete i;

		// ������� ����� �������� ����� � ����
		strcpy(name, list.name);

		// ����� ����� �����
		cout << list.name << "     ";

		// ���� ���� �������� ������ 
		if (list.attrib & _A_SUBDIR)
		{
			// ����� ��������
			cout << "<DIR>" << endl;

			// ���������� �������� ���������� ��������
			++*count;

			// ���������� ������ �����
			++* (count + 9);

			// ������ ���� �� �������
			scanFile(dir, min_size, count);

			// ���������� ������ �����
			--* (count + 9);

			continue;
		}

		// ���� ����
		else
		{
			// ����� ������� �����
			cout << list.size << endl;
			
			// ���������� �������� ���� ������
			++*(count + 1);

			// ����������� ������� �������� ����� � ����� ����� ���� ������
			*(count + 2) += list.size;

			// ���� ������ ����� ������ ���������� ������������ �������
			if (list.size < *min_size)
			{
				// ���������� �������� ������ ������, ������� ������ ���������� ������������ ������� 
				++*(count + 3);

				// ����������� ������� �������� ����� � ������ ������� ���� ������, ������ ������� ������ 
				// ��������
				++* (count + 4) += list.size;

				// �������� �����; ���� ���� ����� ��������
				if (remove(dir) == -1)
				{
					// ���������� �������� ���������� �������� �������� ������
					++* (count + 7);

					// ����������� ������� ����� � ������ ������� ���� �������� �������� ������
					*(count + 8) += list.size;

					continue;
				}

				// ���������� �������� ���������� ������ �������� ������
				++*(count + 5);

				// ����������� ������� ����� � ������ ������� ���� ������ �������� ������
				*(count + 6) += list.size;
			}
		}

	} while (!_findnext(point, &list));

	// �������� ������ 
	_findclose(point);
}

void task2()
{
	// 2. ������������ ������ ���� � ����� � ������ ������,
	// ��������� ��������� ����� � �������� � ������� ��� �����,
	// ������� ������ ���������� �������(������������ ������� remove(filename))

	// ���� � �����
	char* dir = new char[_MAX_PATH];

	// ���� ����
	cout << "Enter folder path: ";
	cin.ignore();
	cin.getline(dir, _MAX_PATH);

	cout << endl;

	// ����������� ������ �����
	unsigned long* min_size = new unsigned long;

	// ���� ������������ ������� �����
	cout << "Enter minimum size: ";
	cin >> *min_size;

	// �������� ������� ����� �������
	cout << "\n\n\n\n\nPRESS ANY KEY TO START...";

	// ������� ����� �������
	_getch();

	// �������� �������
	system("cls");

	// ��������: [0] - ����� ��������; [1] - ����� ������; [2] - ����� ������ ���� �����; 
	// [3] - ���������� ������ ������ ������������ �������; [4] - ������ ������ ������ 
	// ������������ �������; [5] - ���������� ������ ������� ������; [6] - ������ ������ 
	// �������� ������; [7] - ���������� �������� �������� ������; [8] - ������ �������� 
	// �������� ������; [9] - ������� �����;
	unsigned long* count = new unsigned long[10];

	// [0] - ����� ��������
	*count = 0;
	// [1] - ����� ������
	*(count + 1) = 0;
	// [2] - ����� ������ ���� �����
	*(count + 2) = 0;
	// [3] - ���������� ������ ������ ������������ ������� 
	*(count + 3) = 0;
	// [4] - ������ ������ ������ ������������ �������
	*(count + 4) = 0;
	// [5] - ���������� ������ ������� ������ 
	*(count + 5) = 0;
	// [6] - ������ ������ �������� ������
	*(count + 6) = 0;
	// [7] - ���������� �������� �������� ������
	*(count + 7) = 0;
	// [8] - ������ �������� �������� ������
	*(count + 8) = 0;
	// [9] - ������� �����
	*(count + 9) = 0;

	// ������ ������ ������������
	scanFile(dir, min_size, count);

	// �������� ������� ����� ������� ��� ����� ������
	cout << "\n\n\n\n\nPRESS ANY KEY TO OUTPUT THE REPORT..." << endl;

	// �������� ������� �������
	_getch();

	// �������� �������
	system("cls");

	// ����� ������ � ����������
	cout << "          REPORT          " << endl << endl;
	cout << "> Count all subdir: " << *count << endl << endl;
	// ����� ���������� ���� ������
	cout << "> Count all file: " << *(count + 1) << endl;
	// ����� ������ ������� ���� ������
	cout << "> Size all files: " << *(count + 2) << endl << endl;
	// ����� ���������� ������ ������, ������� ������ ���������� ����������
	cout << "> Count files size less minimum: " << *(count + 3) << endl;
	// ������ ���� ������ ������, ������� ������ ���������� ����������
	cout << "> Size all files size less minimum: " << *(count + 4) << endl << endl;
	// ���������� ������ �������� ������
	cout << "> Count of successfully delete files: " << *(count + 5) << endl;
	// ������ ������ �������� ������ 
	cout << "> Size all successfully delete files: " << *(count + 6) << endl << endl;
	// ���������� �������� �������� ������
	cout << "> Count of unsuccessfully delete files: " << *(count + 7) << endl;
	// ������ �������� �������� ������
	cout << "> Size all unsuccessfully delete files: " << *(count + 8) << endl << endl;

	// �������� ������
	delete[] dir;
	delete count;

	// �������� ������� ����� ������� ��� ������ �� ���������
	cout << "\n\n\n\n\nPRESS ANY KEY TO EXIT..." << endl;
	_getch();
}