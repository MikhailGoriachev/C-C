#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <io.h>
#include <conio.h>

using namespace std;

// �������� ����������. 0 - �� �������; 1 - jpg, bmp, gif; 2 - txt;
int exprFile(char* name)
{
	char* expr = name + strlen(name) - 4;

	if (!strcmp(expr, ".jpg") || !strcmp(expr, ".bmp") || !strcmp(expr, ".gif"))
		return 1;
	if (!strcmp(expr, ".txt"))
		return 2;
	return 0;
}

void task2()
{
	// 2. ������������ ������ ���� � �����, ��������� ���������
	// ����� � �������� ��� ��������(jpg, bmp, gif) � �����
	// Images, � ��� ��������� ����� ���������� � ����� Txt

	// ����
	char* dir = new char[_MAX_PATH];

	// ���� ���� � �����
	cout << "Enter path: ";
	cin.ignore();
	cin.getline(dir, _MAX_PATH);

	cout << endl;

	// ���� � ����� Images - ��� ��������
	char* images_path = new char[_MAX_PATH];

	// ���� � ����� �� ���������
	strcpy(images_path, ".\\Images\\");

	// ���� � ����� Txt - ��� ��������� ������
	char* txt_path = new char[_MAX_PATH];

	// ���� � ����� �� ���������
	strcpy(txt_path, ".\\Txt\\");

	// �����: ������� ���� � ������ ��� ���
	bool* path = new bool;

	// �����
	cout << "Enter the path to images and txt?(Y/N): ";

	// ���������� ��� ������
	char* ch = new char;

	// ���� ������
	while (true)
	{
		*ch = _getch();

		// ���� �� 
		if (*ch == 'Y' || *ch == 'y')
		{
			cout << "Y" << endl;

			*path = true;

			break;
		}

		// ���� ���
		if (*ch == 'N' || *ch == 'n')
		{
			cout << "N" << endl;

			*path = false;

			break;
		}
	}

	cout << endl;

	// ���� ������������ ������ ���� ����� ����� � ������ Images � Txt
	if (*path)
	{
		// ���� ������ ���� � Images
		cout << "Enter path Images: ";
		cin.getline(images_path, _MAX_PATH);

		// ���������� � ���� '\\'
		strcat(images_path, "\\");

		// ���� ������ ���� � Txt
		cout << "Enter path Txt: ";
		cin.getline(txt_path, _MAX_PATH);

		// ���������� � ���� '\\'
		strcat(txt_path, "\\");

		cout << endl;
	}

	// ����� ���������� ��� ���������� �����
	cout << "Copy or moving (C/M): ";

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

	// ���������� � ���� '\'
	strcat(dir, "\\");

	// ��������� �� ������ ����� ����� � ����
	char* name = dir + strlen(dir);

	// ��������� �� ������ ����� � ���� � ����� � ����� Images
	char* images = images_path + strlen(images_path);

	// ��������� �� ������ ����� � ���� � ������ � ����� Txt
	char* txt = txt_path + strlen(txt_path);

	// �������� � ���� ����� ����� 
	strcat(name, "*");

	// ������ 
	_finddata_t list;

	// ��������� �� ������ � �������� ������
	long point = _findfirst(dir, &list);

	// �������� �������
	system("cls");

	// ��������� �� ���� ������� 
	FILE* file = nullptr;

	// ������ ��������� ��� ������ images; [0] - ����� ������, [1] - ������, [3] - ��������; [4] - ����� ������;
	unsigned long* count_images = new unsigned long[4];

	*count_images = 0;
	*(count_images + 1) = 0;
	*(count_images + 2) = 0;
	*(count_images + 3) = 0;

	// ������ ��������� ��� ������ txt; [0] - ����� ������, [1] - ������, [3] - ��������; [4] - ����� ������;
	unsigned long* count_txt = new unsigned long[4];

	*count_txt = 0;
	*(count_txt + 1) = 0;
	*(count_txt + 2) = 0;
	*(count_txt + 3) = 0;

	// ����� ���������� ���� �����
	do
	{
		// ���� ���� �� �������� ������
		if (!(list.attrib & _A_SUBDIR))
		{
			// jpg, bmp, gif,
			if (exprFile(list.name) == 1)
			{
				// ����� ����� ����� � ��� �������
				cout << list.name << "     " << list.size << "     ";

				*count_images += 1;

				// ------- ����������� 

				// ���������� ����� ����� � ����
				strcpy(name, list.name);

				// �������� ����� ������� � ������ ��������� ������
				file = fopen(dir, "rb");

				// ���� ���� ������� ������ �������
				if (file != nullptr)
				{
					// �����
					char* buff = new char[list.size];

					// ���������� ����� ������� � �����
					fread(buff, sizeof(char), list.size, file);

					// �������� ����� ������� 
					fclose(file);

					// ���������� ����� � ���� ����������
					strcpy(images, list.name);

					// �������� � �������� ����� ���������� � ������ �������� ������
					file = fopen(images_path, "wb");

					// ���� ���� ���������� ������ �������
					if (file != nullptr)
					{
						// ������ � ���� ���������� �� ������
						fwrite(buff, sizeof(char), list.size, file);

						// �������� ������ �� �������
						if (ftell(file) != list.size)
						{
							cout << "ERROR WRITE" << endl;

							// �������� ����� 
							fclose(file);

							// �������� �������� ����������� �����
							remove(images_path);

							continue;
						}

						// �������� ����� ������� 
						fclose(file);

						// �������� ����� ������� (���� ������� �����������)
						if (moving)
						{
							// �������� ��������� �����
							if (remove(dir) == -1)
							{
								cout << "ERROR DELETE SOURCE FILE!" << endl;

								// ���������� �������� �������� ������������ ������
								*(count_images + 2) += 1;

								// �������� ����� �����
								remove(images_path);

								continue;
							}
						}

						// ���������� �������� ������� ���������� ������
						*(count_images + 1) += 1;

						delete[] buff;

						cout << "SAVE" << endl;

						// ���������� ���������� ������� 
						*(count_images + 3) += list.size;
					}
					// ���� ������ ��������
					else
					{
						cout << "ERROR CREATE DESTINATION FILE!" << endl;
						*(count_images + 2) += 1;
					}
				}
				// ���� ���� ������ �������� 
				else
				{
					cout << "ERROR OPENING SOURCE FILE!" << endl;
					*(count_images + 2) += 1;
				}
			}

			// txt
			if (exprFile(list.name) == 2)
			{
				// ����� ����� ����� � ��� �������
				cout << list.name << "     " << list.size << "     ";

				*count_txt += 1;

				// ------- ����������� 

				// ���������� ����� ����� � ����
				strcpy(name, list.name);

				// �������� ����� ������� � ������ ��������� ������
				file = fopen(dir, "rb");

				// ���� ���� ������� ������ �������
				if (file != nullptr)
				{
					// �����
					char* buff = new char[list.size];

					// ���������� ����� ������� � �����
					fread(buff, sizeof(char), list.size, file);

					// �������� ����� ������� 
					fclose(file);

					// ���������� ����� � ���� ����������
					strcpy(txt, list.name);

					// �������� � �������� ����� ���������� � ������ �������� ������
					file = fopen(txt_path, "wb");

					// ���� ���� ���������� ������ �������
					if (file != nullptr)
					{
						// ������ � ���� ���������� �� ������
						fwrite(buff, sizeof(char), list.size, file);

						// �������� ������ �� �������
						if (ftell(file) != list.size)
						{
							cout << "ERROR WRITE" << endl;

							// �������� ����� 
							fclose(file);

							// �������� �������� ����������� �����
							remove(txt_path);

							continue;
						}

						// �������� ����� ������� 
						fclose(file);

						// �������� ����� ������� (���� ������� �����������)
						if (moving)
						{
							// �������� ��������� �����
							if (remove(dir) == -1)
							{
								cout << "ERROR DELETE SOURCE FILE!" << endl;

								// ���������� �������� �������� ������������ ������
								*(count_txt + 2) += 1;

								// �������� ����� �����
								remove(txt_path);

								continue;
							}
						}

						// ���������� �������� ������� ���������� ������
						*(count_txt + 1) += 1;

						delete[] buff;

						cout << "SAVE" << endl;

						// ���������� ���������� ������� 
						*(count_txt + 3) += list.size;
					}
					// ���� ������ ��������
					else
					{
						cout << "ERROR CREATE DESTINATION FILE!" << endl;

						*(count_txt + 2) += 1;
					}
				}
				// ���� ���� ������ �������� 
				else
				{
					cout << "ERROR OPENING SOURCE FILE!" << endl;

					*(count_txt + 2) += 1;
				}
			}
		}
	} while (!_findnext(point, &list));

	cout << endl;

	// �������� ������
	_findclose(point);

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

	// ����� ������ 
	cout << "All files: " << *count_images + *count_txt << endl;

	// ����� ������
	cout << "All successfully: " << *(count_images + 1) + *(count_txt + 1) << "     " << "Size: " << *(count_images + 3) + *(count_txt + 3) << endl;

	// ����� ��������
	cout << "All nosuccessfully: " << *(count_images + 2) + *(count_txt + 2) << endl;

	cout << endl;

	// ����� �� ������������
	cout << "Images files: " << *count_images << endl;

	// ������ 
	cout << "Images successfully: " << *(count_images + 1) << "     " << "Size: " << *(count_images + 3) << endl;

	// �������� 
	cout << "Images nosuccessfully: " << *(count_images + 2) << endl;

	cout << endl;

	// ����� �� ��������� ������
	cout << "Text files: " << *count_txt << endl;

	// ������ 
	cout << "Text file successfully: " << *(count_txt + 1) << "     " << "Size: " << *(count_txt + 3) << endl;

	// ��������
	cout << "Text file nosuccessfully: " << *(count_txt + 2) << endl;
}