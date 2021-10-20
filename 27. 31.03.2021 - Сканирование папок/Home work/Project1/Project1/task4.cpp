#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <io.h>
#include <conio.h>

using namespace std;

// ������������ ������
void scanFile(char* dir, char* mask, unsigned long* count, FILE* file)
{
	// ������� � ���� "\\"
	strcat(dir, "\\");

	// ��������� �� ������ ����� � ����
	char* name = dir + strlen(dir);

	// ����� ��� �������� ������ ���� ������
	strcpy(name, "*");

	// ������ ������
	_finddata_t list;

	// ��������� �� ������ � �������� ������
	long point = _findfirst(dir, &list);

	// ���� ������ �� ������ 
	if (point == -1)
	{
		cout << "ERROR CREATE LIST" << endl;
		return;
	}

	// ������������ ������
	do
	{
		// ���� ���� ����� �������� "." ��� ".."
		if (!strcmp(list.name, ".") || !strcmp(list.name, ".."))
		{
			continue;
		}

		// ������� � ���� ����� ����� �� ������
		strcpy(name, list.name);

		// ���������� ��� �����
		int* i = new int;

		// ����� ������ �����
		for ( *i = 0; *i < *(count + 5); ++*i)
		{
			cout << "|";
		}

		// �������� ������
		delete i;

		// ����� ����� �����
		cout << list.name << "     ";

		// ���� ���� �������� ������
		if (list.attrib & _A_SUBDIR)
		{
			// ����� �������� �����
			cout << "<DIR>" << endl;

			// ���������� �������� ���������� �����
			++*count;

			// ���������� ������ �����
			++* (count + 5);

			// ����� ���� �� �������
			scanFile(dir, mask, count, file);

			// ���������� ������ �����
			--* (count + 5);

			continue;
		}

		// ���� ���� �������� ������� ������
		else
		{
			// ����� ������� �����
			cout << list.size << endl;

			// ���������� �������� ���� ������ 
			++*(count + 1);

			// ����������� ������� ����� �� ������ � ������ ������� ���� ������
			*(count + 2) += list.size;
		}
	} while (!_findnext(point, &list));

	// �������� ������
	_findclose(point);

	// ����������� ����� � ����
	strcpy(name, mask);

	// ���������� ������ 
	point = _findfirst(dir, &list);

	// ���� �� ������� ������� ������
	if (point == -1)
	{
		return;
	}

	// ������������ ������ 
	do
	{
		// ���� ���� �������� ������
		if (list.attrib & _A_SUBDIR)
		{
			continue;
		}

		// ������� ����� ����� � ����
		strcpy(name, list.name);

		// ���������� �������� ��������� ������ �� �����
		++* (count + 3);

		// ����������� ������� ����� �� ������ � ������ ������� ������ �� �����
		*(count + 4) += list.size;

		// ���� � ���� ����� �������� �����
		fprintf(file, "Path: %s\n", dir);
		// ���� � ���� ����� ����� 
		fprintf(file, "Name: %s\n", list.name);
		// ���� � ���� ������� �����
		fprintf(file, "Size: %ld\n\n", list.size);
	} while (!_findnext(point, &list));

	// �������� ������ 
	_findclose(point);
}

void task4()
{
	// 4. ������������ ������ �������� �������� ����� � ����� ������.
	// ��������� ���� ����� �� ����� � ����� � ��������� � ���������
	// ������ ���������� � ���� ����������� find_results.txt

	// ���� � �����
	char* dir = new char[_MAX_PATH];

	// ���� ���� � �����
	cout << "Enter folder path: ";
	cin.ignore();
	cin.getline(dir, _MAX_PATH);

	cout << endl;

	// ����� ������ 
	char* mask = new char[_MAX_FNAME];

	// ���� ����� ������
	cout << "Enter mask: ";
	cin.getline(mask, _MAX_FNAME);

	// ���� ��� ���������� ��������������� �����
	char* dir_res = new char[_MAX_PATH];

	// ����������� ���� � �����
	strcpy(dir_res, ".\\find_results.txt");

	// ������ �� �� ����� �� ������� ���� ��� ����������
	// ��������������� ����� ��� ��������� �� �������� ����
	cout << "To enter the path to save the resulting file or save to the current path?(Y/N): ";

	// ���������� ��� ���������� ������
	char* answer = new char[2];

	*(answer + 1) = 0;

	// ���� ����� ������ 
	while (true)
	{
		*answer = _getch();

		// ���� ����� ��������� 
		if (!strcmp(answer, "Y") || !strcmp(answer, "y") || !strcmp(answer, "N") || !strcmp(answer, "n"))
		{
			// ���������� �������� � �������� �����
			bool successfully = true;

			while (true)
			{
				// ���� ����� �� ��� �� ������ ������� ���� � �� �������� ����
				if (!strcmp(answer, "Y") || !strcmp(answer, "y") || !successfully)
				{
					cout << endl;

					// ���� ������ ����
					cout << "Enter the path to save the resulting file: ";
					cin.getline(dir_res, _MAX_PATH);

					// ������� � ���� ����� �����
					strcat(dir_res, "\\find_result.txt");

					cout << endl;
				}

				// ���� ����� ���
				else if (!strcmp(answer, "N") || !strcmp(answer, "n"))
				{
					cout << endl;
				}

				// �������� � �������� ����� ���������� � ������ ������
				FILE* file = fopen(dir_res, "wb");

				// ���� ������ � ������ ��������� 
				if (file == nullptr)
				{
					cout << "ERROR FILE CREATE!" << endl;

					// ���������� ���������� ��������
					successfully = false;

					continue;
				}

				// �������� ������� ����� ������� ��� ������ ������������
				cout << "\n\n\n\n\nPESS ANY KEY TO START SCAN...";

				// ������� �������
				_getch();

				// �������� �������
				system("cls");

				// ��������: [0] - ���������� ���� ��������; [1] - ���������� ���� ������; [2] - ������ ���� ������;
				// [3] - ���������� ������ �� �����; [4] - ������ ������ �� �����; [5] - ������� �����;
				unsigned long* count = new unsigned long[5];

				// [0] - ���������� ���� ��������
				*count = 0;
				// [1] - ���������� ���� ������ 
				*(count + 1) = 0;
				// [2] - ������ ���� ������
				*(count + 2) = 0;
				// [3] - ���������� ������ �� �����
				*(count + 3) = 0;
				// [4] - ������ ������ �� �����
				*(count + 4) = 0;
				// [5] - ������� �����
				*(count + 5) = 0;

				// ������ �������
				scanFile(dir, mask, count, file);
				
				// �������� �����
				fclose(file);

				cout << "\n\n\n\n\nFile save..." << endl;

				// �������� ������� ����� ������� ��� ������ ������
				cout << "\n\nPRESS ANY KEY TO OUTPUT REPORT...";
				
				// ������� ����� �������
				_getch();

				// �������� �������
				system("cls");

				// ����� ������
				cout << "          Report          " << endl;
				// ���������� �����
				cout << "> Count subdir: " << *count << endl << endl;
				// ���������� ���� ���� 
				cout << "> Count all files: " << *(count + 1) << endl;
				// ������ ���� ������
				cout << "> Size all files: " << *(count + 2) << endl << endl;
				// ���������� ������ �� �����
				cout << "> Count mask files: " << *(count + 3) << endl;
				// ������ ������ �� �����
				cout << "> Size mask files: " << *(count + 4) << endl << endl;

				// �������� ������� ����� ������� ��� ������ �� ���������
				cout << "\n\n\n\n\nPRESS ANY KEY TO EXIT...";

				// ������� ����� �������
				_getch();

				break;
			}
			break;
		}
	}

	// �������� ������
	delete[] dir, mask, dir_res, answer;
}