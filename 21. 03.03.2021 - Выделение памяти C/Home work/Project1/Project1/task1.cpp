#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "head.h"

using namespace std;

// �������� � ���������� ������� ����� (��������)
void fileCreate(char buff[], long size, char name[]);

// �������� � ���������� ������� ����� (���������)
void fileCreate(char** source, char name[], long rows, long cols[]);


void task1()
{
	// 1. ������������ ������ ��� �����, ��������� ����������� 
	// ��� �����-����� �� 1 � ��������� ��������� � ������ ����.

	// ��� �����
	char name[40];

	// ���� ����� �����
	cout << "Enter file name: ";
	cin.ignore();
	cin.getline(name, 40);

	cout << endl;

	FILE* source = nullptr;

	// �������� ��������� ����� � ������ ���������� �����
	source = fopen(name, "r");


	// ���� ����� ������� 
	if (source != nullptr)
	{
		// ���������� ����� 
		long rows = 0;

		// ������� ���������� ����� � ��������
		while (!feof(source))
		{
			char* buff = (char*)malloc(sizeof(char) * 200);
			fgets(buff, 199, source);

			rows++;

			free(buff);
		}

		fseek(source, 0, SEEK_SET);

		long* cols = (long*)malloc(sizeof(long) * rows);

		// ��������� ������ �� ���������� �����
		char** buff = (char**)malloc(sizeof(char*) * rows);

		for(size_t i = 0; i < rows; i++)
		{
			// ����� ��� ����� ������
			char* temp = (char*)malloc(sizeof(char) * 200);

			// ������ ����� ������ � �����
			fgets(temp, 199, source);

			// ����� ������
			cols[i] = strlen(temp);

			// �������� ������ ���������� ������� �� ����� ������ �� ������
			buff[i] = (char*)malloc(sizeof(char) * cols[i] + 1);

			// ������ ������ �� ������ � ������ ���������� �������
			strcpy(buff[i], temp);

			// �������� ������
			free(temp);
		}

		fileCreate(buff, name, rows, cols);
		
		// �������� ��������� �����
		fclose(source);
	}

	else cout << "File NOT found" << endl;
}

// �������� � ���������� ������� ����� (��������)
void fileCreate(char** source, char name[], long rows, long cols[])
{
	// ���������� ������ �������� �� ����
	bool symb = false;

	// ���������� ����-�����
	long num_count = 0;


	// ���������� ����� � ������
	long* num_count_str = (long*)malloc(sizeof(long) * rows);

	// ����� ����-����� � ������ ��������� �����
	for (size_t i = 0; i < rows; i++)
	{
		// ��������� �������� ����� ������� ������
		num_count_str[i] = 0;

		for (size_t k = 0; k < cols[i] + 1; k++)
		{
			// ������
			if (source[i][k] == ' ')
			{
				// ��������� ���������� ��������
				symb = false;
			}

			// �����
			if (source[i][k] >= '0' && source[i][k] <= '9')
			{
				// ���� ��������� ������ ������ �� ������������� ���������� ����-�����
				if (source[i][k + 1] < '0' || source[i][k + 1] > '9')
				{
					// ���������� ����� � ������� ������
					num_count_str[i]++;

					// ����� ������� �����
					num_count++;
				}
				continue;
			}

			// ������� (�� ����� � �� �����)
			if (source[i][k] != '.')
			{
				symb = true;
			}
		}
	}

	// ����� ���������� ����-����� � �������
	cout << "Count number = " << num_count << endl;

	cout << endl;

	// ���������� ����
	bool num = false;

	// ���������� �����
	bool dot = false;

	// ���������� ������ �������� �� ����
	symb = false;

	// ����� �����
	long size_num = 0;

	// ��������� ����� ��� ������ �����
	char* temp = (char*)malloc(sizeof(char) * 200);

	// �������� ������ ��� ������� ����� ������ � ��������� ����������� �� ���������� ����� 
	char** buff = (char**)malloc(sizeof(char*) * rows);



	// ���������� �������� ������ 
	for (size_t i = 0; i < rows; i++)
	{
		// �������� ������ ���������� �������
		buff[i] = (char*)malloc(sizeof(char) * ++cols[i] + 1 + num_count_str[i]);
		for (size_t k = 0; k < cols[i]; k++)
		{
			buff[i][k] = source[i][k];
			if (k + 1 == cols[i])
			{
				buff[i][k + 1] = 0;
			}
		}
	}


	for (size_t i = 0, poz_Y = 0, poz_X = 0, len = 0; i < rows; i++)
	{
		// ����� 
		long len_line = strlen(buff[i]);
		for (size_t k = 0; k < cols[i]; k++)
		{
			// ������
			if (buff[i][k] == ' ' || k + 1 == cols[i])
			{
				// ���� ��� �����-�����
				if (num && strlen(temp) > 0)
				{
					// ���� ����� ��������� ����� ������, ��� ���������
					if (len < strlen(temp))
					{
						// ���������� ����� �����
						cols[i]++;

						// ����� ������ �� ���� ������� ��� ������������ �����
						for (int k = cols[i]; k >= poz_X + 1; k--)
						{
							swap(buff[i][k], buff[i][k - 1]);
						}
					}

					buff[i][cols[i]] = 0;

					// ��������� ������ ����� � ������ 
					char* p = &buff[poz_Y][poz_X];

					// ����������� ������ � ������ � ����� 
					for (size_t k = 0; temp[k] != 0; k++)
					{
						p[k] = temp[k];
					}

					// ��������� ����� ��������� �����
					len = 0;

					// �������� ������ 
					strcpy(temp, "");
				}

				// ��������� ���������� ����
				num = false;

				// ��������� ���������� �����
				dot = false;

				// ��������� ���������� ��������
				symb = false;

				// ��������� ����� �����
				size_num = 0;

				continue;
			}

			// �����
			if (buff[i][k] >= '0' && buff[i][k] <= '9' && !symb && !dot)
			{
				// ������� ������ �����
				if (num == false)
				{
					poz_Y = i;
					poz_X = k;
				}

				// ���������� ���������� ������ ������ ����� �������� �����
				temp[size_num++] = buff[i][k];

				// ���� ��������� ������ ������ �� ������������� ���������� ����-�����
				if (buff[i][k + 1] < '0' || buff[i][k + 1] > '9' || buff[i][k + 1] == 0)
				{
					// ������ ���������� ������
					temp[size_num] = 0;

					// ����� ��������� �����
					len = strlen(temp);

					// ����� ������������� �� 1
					long numb = atoi(temp) + 1;

					// ��������������� ����������� ����� ������� � ������
					_itoa(numb, temp, 10);
				}

				num = true;

				continue;
			}

			// �����
			if (buff[i][k] == '.')
				dot = true;

			// ������� (�� ����� � �� �����)
			if (buff[i][k] != '.')
			{
				symb = true;
			}
		}
	}

	// �������� ����� ����� ��� ����������
	
	// ����� ��������� �����
	size_t len = strlen(name);

	// ������� �����
	int poz = 0;

	// ����� ������� ���������� ����� ����
	for (int i = len - 1; i >= 0; i--)
	{
		if (name[i] == '/' || name[i] == '\\')
		{
			poz = i + 1;
			break;
		}
	}

	// ����� ����� �� ������ ��������
	for (size_t i = 0; i < 4; i++)
	{
		for (int k = len; k > poz; k--)
		{
			swap(name[k], name[k - 1]);
		}
		len++;
	}

	name[len] = 0;

	// ���������� ������ ����� ������ "copy"
	name[poz] = 'c';
	name[poz + 1] = 'o';
	name[poz + 2] = 'p';
	name[poz + 3] = 'y';

	// �������� � �������� ����� ��� ���������� � ������ �������� ������ 
	FILE* file = fopen(name, "wb");

	// ���� ���� ������ � ������ �������
	if (file != nullptr)
	{
		// ������ � ����
		for (size_t i = 0; i < rows; i++)
		{
			fputs(buff[i], file);
			free(buff[i]);
		}

		free(buff);

		// ���������� �����
		fclose(file);

		cout << "File save" << endl;

		cout << endl;

	}
	else cout << "Error create file" << endl;
}
