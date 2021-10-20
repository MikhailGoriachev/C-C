#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <io.h>
#include <conio.h>

using namespace std;

void filesOper(unsigned long* count_files, char* path_s, char* path_d, bool* moving, unsigned long* size_min)
{
	// ����� ������ ���������� ����������
	char* path_dest = new char[_MAX_PATH];

	// ����������� ���� ����������
	strcpy(path_dest, path_d);

	// ������� � ���� ������� '\\'
	strcat(path_s, "\\");

	// ��������� �� ������ ����� ���� �������
	char* name_s = path_s + strlen(path_s);

	// ��������� �� ������ ����� ���� ����������
	char* name_d = path_dest + strlen(path_d);

	// ������� � ���� ������� �����
	strcat(path_s, "*");

	// ������ ������
	_finddata_t list;

	// ��������� �� ������ 
	long point = _findfirst(path_s, &list);

	// ��������� �� ����
	FILE* file = nullptr;

	// �����������/����������� ������ �� �����
	do
	{
		// ���� ��� ����� "." ��� ".."
		if (!strcmp(list.name, ".") || !strcmp(list.name, ".."))
		{
			continue;
		}

		// �������� ���� ����� 
		strcpy(name_s, list.name);

		// ����� �����
		cout << "> " << list.name << "     ";

		// ���� ���� �������� ������
		if (list.attrib & _A_SUBDIR)
		{
			// ���������� �������� ���������� �����
			*count_files += 1;

			cout << "<DIR>" << endl << endl;

			// ������� � ���� ������� '\\'
			strcat(name_s, "\\");

			// ����������� ����� �������
			filesOper(count_files, path_s, path_d, moving, size_min);

			cout << endl << endl;
		}

		// ���� ��� ������� ����
		else
		{
			// ���� ������ ����� ������ ������������ ������� ��������� �������������
			if (*size_min > list.size)
			{
				cout << "SMALL SIZE!" << endl;
				
				// ���������� �������� ���������� ������������ �� ������� ������
				*(count_files + 7) += 1;

				// ���������� ������ ������� ������������ �� ������� ������
				*(count_files + 8) += list.size;

				continue;
			}

			// ���������� �������� ���������� ������
			*(count_files + 1) += 1;

			// ���������� ������ ������� ���� ������
			*(count_files + 2) += list.size;

			// ����� ������� �����
			cout << list.size << "     ";

			// �������� ����� ������� � ������ ��������� ������
			file = fopen(path_s, "rb");

			// ���� ���� ������ ������
			if (file != nullptr)
			{
				// ����� ��� ����� ������� 
				char* buff = new char[list.size];

				// ���������� ����� ������� � �����
				fread(buff, sizeof(char), list.size, file);

				// �������� ����� �������
				fclose(file);

				// ����������� ����� � ���� ����������
				strcpy(name_d, list.name);

				// �������� � �������� ����� ���������� � ������ �������� ������
				file = fopen(path_dest, "wb");

				if (file != nullptr)
				{
					// ������ � ���� �� ������
					fwrite(buff, sizeof(char), list.size, file);

					// ��������� ������ �� �������
					if (ftell(file) != list.size)
					{
						cout << "ERROR WRITE DESTINATOIN FILE!" << endl;

						// ���������� �������� ������
						*(count_files + 3) += 1;

						// ���������� ������ ������� ��������� ������
						*(count_files + 6) += list.size;

						continue;
					}

					// �������� ����� ����������
					fclose(file);

					// ���� ������� ����������� 
					if (*moving)
					{
						// ���� ���� ������� �������� �����
						if (remove(path_s) == -1)
						{
							cout << "ERROR REMOVE SOURCE FILE!" << endl;

							*(count_files + 4) += 1;

							// ���������� ������ ������� ��������� ������
							*(count_files + 6) += list.size;

							continue;
						}
					}

					// ���������� �������� ������� ������
					*(count_files + 3) += 1;

					// ���������� ������� ����� � ���������� ������� ������� ������
					*(count_files + 5) += list.size;

					cout << "SAVE" << endl;
				}
				// ���� ���� ���������� ������ � ������ ��������
				else
				{
					cout << "ERROR OPENING DESTINATION FILE!" << endl;

					// ��������� �������� ������
					*(count_files + 4) += 1;

					// ���������� ������ ������� ��������� ������
					*(count_files + 6) += list.size;

					continue;
				}

				// �������� ������
				delete[] buff;

			}
			// ���� ���� ������ ��������
			else
			{
				cout << "ERROR OPENING SOURCE FILE!" << endl;

				// ���������� �������� ������
				*(count_files + 3) += 1;

				// ���������� ������ ������� ��������� ������
				*(count_files + 6) += list.size;
			}
		}
	} while (!_findnext(point, &list));

	// �������� ������
	_findclose(point);
}

void task3()
{
	// 3. ������������ ������ 2 ���� � ������, ��������� �������� 
	// ��� ����� �� ������ ����� �� ������, ���������� ������ �� �����,
	// ������ ������� �� ��������� ������� ��������� ������������� ������
	// (����������: ����������� �� ����� � ��������)

	// ���������� ������� 
	char* source_path = new char[_MAX_PATH];

	// ���� ���� �������
	cout << "Enter source path: ";
	cin.ignore();
	cin.getline(source_path, _MAX_PATH);

	// ����������� � ���� '\\'
	// strcat(source_path, "\\");

	// ���������� ����������
	char* dest_path = new char[_MAX_PATH];

	// ���� ���� ����������
	cout << "Enter destination path: ";
	cin.getline(dest_path, _MAX_PATH);

	// ����������� � ���� '\\'
	strcat(dest_path, "\\");

	// ����� ���������� ��� ���������� �����
	cout << "Copy or moving (C/M): ";


	// ���������� ��� ������
	char* ch = new char;

	// �����������
	bool* moving = new bool;

	// ���� ������
	while (true)
	{
		*ch = _getch();

		// ���� �� 
		if (*ch == 'M' || *ch == 'm')
		{
			cout << "M" << endl;

			*moving = true;

			break;
		}

		// ���� ���
		if (*ch == 'C' || *ch == 'c')
		{
			cout << "C" << endl;

			*moving = false;

			break;
		}
	}

	delete ch;

	// ����������� ������ �����
	unsigned long* size_min = new unsigned long;

	// ������ � ������������ ������������ ������� �����
	cout << "Enter minimum size: ";
	cin >> *size_min;


	// ������� ������; [0] - ���������� �����; [1] - ���������� ������; [2] - ������ ������; [3] - ������� ����; [4] - ������� ������; 
	// [5] - ������ ���� ������� ������; [6] - ������ ���� ��������� ������; [7] - ���������� ������ ������ ���������� ������������ �������;
	// [8] - ����� ������ ������������ �� ������� ������;
	unsigned long* count_files = new unsigned long[8];

	// ������� ���������� �����
	*count_files = 0;

	// ������� ���������� ������
	*(count_files + 1) = 0;

	// ������� ������ ������� ������
	*(count_files + 2) = 0;

	// ������� ���� 
	*(count_files + 3) = 0;

	// ������� ������
	*(count_files + 4) = 0;

	// ������ ���� ������� ������
	*(count_files + 5) = 0;

	// ������ ���� ��������� ������
	*(count_files + 6) = 0;

	// ���������� ������ ������ ���������� ������������ �������
	*(count_files + 7) = 0;

	// ����� ������ ������������ �� ������� ������
	*(count_files + 8) = 0;

	// �������� �������
	system("cls");

	// ����������� ������� �����������/����������� ������
	filesOper(count_files, source_path, dest_path, moving, size_min);

	// ��������� ��������� �����������/�����������, �������� �� ���� ������������
	// � ����������� ������� ������� "Enter", ������� ����� � ������ 
	if (!moving)
		cout << "----------------- MOVE COMPLITED -----------------" << endl;
	else cout << "----------------- COPY COMPLITED -----------------" << endl;

	cout << "Press [enter]" << endl;

	while (_getch() != '\r');

	// �������� �������
	system("cls");

	// ����� ����������
	if (!moving)
		cout << "----------------- RESULT MOVING -----------------" << endl;
	else cout << "----------------- RESULT COPY -----------------" << endl;

	cout << endl;

	// ����� � ����������
	// ����� ������
	cout << "All size: " << *(count_files + 5) << endl;
	// ���������� �����
	cout << "Count folders: " << *count_files << endl;
	// ���������� ������
	cout << "Count files: " << *(count_files + 1) << endl;
	// ���������� ������� ������
	cout << "Count successfully files: " << *(count_files + 3) << "     Size: " << *(count_files + 5) << endl;
	// ���������� ��������� ������
	cout << "Count nosuccessfully files: " << *(count_files + 4) << "     Size: " << *(count_files + 6) << endl;
	// ���������� ������ ������������ �� �������
	cout << "Count small size files: " << *(count_files + 7) << "     Size: " << *(count_files + 8) << endl;

	cout << endl;
}
