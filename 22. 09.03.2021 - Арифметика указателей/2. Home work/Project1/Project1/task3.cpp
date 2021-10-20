#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "head.h"

using namespace std;

// �������� ����� ��� ��������������� �����
FILE* createFile(char name_file[]);

// ���������� ���������� ����� � �������� � ����� ���������� ��������� 
// �� ������ � ����������� �������� ������ ������
// 1 - ���� ������� �������
// 2 - ��������/���� ����
long* sizeStr(long* rows, FILE* file);

// ����������� ����� � ��������� ������. ���������� 0 - ��������, 1 - ������
bool readFile(char** arr, FILE* file, long* rows, long* cols);

// ��������� ���� ����� � ������� ���������� �������
void coupNum(char** arr, long* rows, long* count);

// ������ � ���� �� ���������� �������
bool writeFile(char** array, FILE* file, long* rows);

void task3()
{
	// 3. ������������ ������ ��� ���������� �����, ��������� �������������� 
	// � ����� ��� �����-����� �������� � ���������� ��������� � ����.
	//
	//	� ������� ���� 234 ����.
	//
	//	� ������� ���� 432 ����.

	// ��� ��������� ���������� �����
	char* name = (char*)malloc(sizeof(char) * 40);

	// ���� ����� ��������� ���������� �����
	cout << "Enter source name file: ";
	cin.ignore();
	cin.getline(name, 40);

	cout << endl;

	// �������� ��������� ����� � ������ ������
	FILE* file = fopen(name, "r");

	// ���� ���� ������ �������
	if (file != nullptr)
	{
		// ���������� ��������� �����
		long* count = (long*)malloc(sizeof(long));

		*count = 0;

		// ���������� ���������� ����� � �������� � �����
		// ���������� �����
		long* rows = (long*)malloc(sizeof(long));

		// ���������� ���������� ����� � �������� � �����
		// ���������� ��������� �� ������ � ������� ���� �����
		long* cols = sizeStr(rows, file);

		// ���� ��������� �� ������ � ������� ����� ������� - ���� ����
		if (cols == nullptr)
		{
			cout << "Error! File is empty!" << endl;
			return ;
		}

		// ��������� ������ ��� ����������� �����
		char** array = (char**)malloc(sizeof(char*) * *rows);

		// ��������� �� ����� ������
		long* p_cols = cols;

		// �������� ����� ���������� �������
		for (char** p_ar = array; p_cols < cols + *rows; p_cols++, p_ar++)
		{
			*p_ar = (char*)malloc(sizeof(char) * *p_cols + 1);
		}

		// ����������� ����� � ��������� ������
		if (!readFile(array, file, rows, cols))
		{
			cout << "Error! File NOT read!" << endl;
			return;
		}

		// �������� ��������� �����
		fclose(file);

		// ��������� ���� ����� � ������� ���������� �������
		coupNum(array, rows, count);

		// ��� ��������������� �����
		char* res_name = (char*)malloc(sizeof(char) * 40);

		// ������� ����� ��������������� �����
		file = createFile(name);

		// ���� ���� ������ ��������
		if (file == nullptr)
		{
			cout << "Error! File NOT Found!" << endl;
			return;
		}

		// ������ �� ���������� ������� � �������������� ����
		if (!writeFile(array, file, rows))
		{
			cout << "Error! File NOT write!" << endl;
			return;
		}

		// �������� ������ �� ���������� �������
		for (char** rows_ar = array; rows_ar < array + *rows; rows_ar++)
		{
			free(*rows_ar);
		}

		free(array);

		// �������� ����������� ������
		free(res_name);
		free(rows);
		free(cols);

		// �������� ��������������� �����
		fclose(file);

		cout << "Count number: " << *count << endl;
		cout << endl;
		cout << "Save" << endl;
	}
	// ���� ���� �� ������� �������
	else cout << "Error! File NOT found!" << endl;
	
	// �������� ����������� ������
	free(name);
}

// �������� ����� ��� ��������������� �����
FILE* createFile(char name_file[])
{
	// ������ ��� ������� � ������ �����
	char* result = (char*)malloc(sizeof(char) * 10);

	// ���������� ������ �������
	strcpy(result, "result_");

	// ����� ������ �������
	int* len_result = (int*)malloc(sizeof(int));

	*len_result = strlen(name_file) - 1;

	// �������������� �����
	char* name, * end = name_file + strlen(name_file);

	// ����� ������ �����
	for (name = end; name >= name_file; name--)
	{
		// ���� ��������� ����� ��������� ������ ���� ����������
		if (*name == '\\' || *name == '/')
		{
			// ������ �����
			name++;
			break;
		}
	}

	// ���� ��� ����� ������� ��� ����������
	if (name < name_file)
	{
		name = name_file;
	}

	// �������� ����� ������, ���� ���������� ����� ��� �������
	for (char* orig = name; orig < name + (*len_result - 1); orig++)
	{
		// �������� 
		for (char* point = end; point > orig ; point--)
		{
			swap(*point, *(point - 1));
		}

		// ���������� ����� ������ ����� �� ���� �������
		end++;
	}

	*end = 0;

	// ������� ����� ������ ��������� �����
	for (char* point = result, *p_name = name; *point; point++, p_name++)
	{
		*p_name = *point;
	}

	// ������������ ����������� ������
	free(result);
	free(len_result);

	// �������� ����� � ������ ������
	FILE* file = fopen(name_file, "w");

	return file;
}

// ���������� ���������� ����� � �������� � ����� ���������� ��������� �� 
// ������ ���������� �������� ������ ������
// 1 - ���� ������� �������
// 2 - ��������/���� ����
long* sizeStr(long* rows, FILE* file)
{
	// �����������������
	*rows = 0;

	// ��������� ��������� � ����� �� ������
	fseek(file, 0, SEEK_SET);

	// ����� ��� ���������� �������� ������
	char* buffer = (char*)malloc(sizeof(char) * 400);

	// ������� ���������� �����
	while (!feof(file))
	{
		// ���������� � �����
		char* s = fgets(buffer, 399, file);

		// ���� ��������� �� ��������� ����� �������
		if (s == nullptr)
		{
			return nullptr;
		}

		*rows += 1;
	}

	// ��������� ��������� � ����� �� ������
	fseek(file, 0, SEEK_SET);

	// ������ ��� �������� ���� ������ ������
	long* cols = (long*)malloc(sizeof(long) * *rows);

	// ���������� ������� ���� �����
	while (!feof(file))
	{
		// ���������� ������ � �����
		fgets(buffer, 399, file);

		// ����� ������
		*cols = strlen(buffer) + 1;

		// ������� �� ��������� ��������
		cols++;

		// �������� ������ 
		strcpy(buffer, "");
	}

	// ������ ��������� � ������� ���� ����� � ������
	cols -= *rows;

	// ������� ��������� � ������ 
	fseek(file, 0, SEEK_END);

	// �������� ����������� ������
	free(buffer);

	// ����������� ��������� �� ����� 
	return cols;
}

// ����������� ����� � ��������� ������. ���������� 0 - ��������, 1 - ������
bool readFile(char** arr, FILE* file, long* rows, long* cols)
{
	// ��������� ��������� � ����� � ������
	fseek(file, 0, SEEK_SET);

	// ������� ��������� �����
	long* count = (long*)malloc(sizeof(long));

	*count = 0;

	// ��������� �� ������ � ������� �����
	long* size = cols;

	// ���������� � ������ ���������
	for (char** rows_ar = arr; rows_ar < arr + *rows ; rows_ar++, cols++)
	{
		// ���������� ������ �� ����� � ������ ���������� �������
		fgets(*rows_ar, *cols, file);

		// ���������� �������� ��������� �����
		*count += 1;
	}

	// ���� ���������� ��������� ����� �� ��������� � ����������� ����� � �����
	if (*count != *rows)
	{
		// �������� ������ 
		free(count);

		return false;
	}

	return true;
}

// ��������� ���� ����� � ������� ���������� �������
void coupNum(char** arr, long* rows, long* count)
{
	// ������������ �������
	for (char** rows_ar = arr; rows_ar < arr + *rows ; rows_ar++)
	{
		// ������������ ������
		for (char* cols_ar = *rows_ar, *start = nullptr, *end = nullptr; *cols_ar; cols_ar++)
		{
			// ���� ������� ������ �������� ������
			if (*cols_ar >= '0' && *cols_ar <= '9')
			{
				// ���� ��������� �� ������ ����� ����� ���� �/��� �������� ������� ������ ��� �������
				// ������� �������� ��������
				if (start == nullptr && (*(cols_ar - 1) == ' ' || cols_ar == *rows_ar))
				{
					start = cols_ar;
				}

				// ���� ��������� �� ������ ����� �� ��������� ����
				if (start != nullptr)
				{
					// ��������� �� ��������� �����
					end = cols_ar;

					// ���� ��������� ������� �� �����
					if (*(cols_ar + 1) < '0' || *(cols_ar + 1) > '9')
					{
						// ���������� �������� ��������� �����
						*count += 1;

						// ���� ����� ������� �� ����� �����
						if (end == nullptr)
						{
							start = nullptr;
							continue;
						}

						// ��������� �����
						for (; start < end; start++, end--)
						{
							swap(*start, *end);
						}

						// ��������� ����������
						start = nullptr;
						end = nullptr;

						continue;
					}
				}
			}
		}
	}
}

// ������ � ���� �� ���������� �������
bool writeFile(char** array, FILE* file, long* rows)
{
	// ��������� ��������� � ����� �� ������
	fseek(file, 0, SEEK_SET);

	long* count = (long*)malloc(sizeof(long));

	*count = 0;

	// ������ � ����
	for (char** rows_ar = array; rows_ar < array + *rows; rows_ar++)
	{
		// ������ ������ �� ���������� ������� � ����
		fputs(*rows_ar, file);

		// ���������� ��������
		*count += 1;
	}

	// �������� �������� ���������� �����, � ����������� ����� ���������� �������
	if (*count != *rows)
	{
		// �������� ������
		free(count);

		return false;
	}

	free(count);

	return true;
}