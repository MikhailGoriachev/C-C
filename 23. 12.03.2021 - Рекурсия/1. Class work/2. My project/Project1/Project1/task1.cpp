#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

// ������������ �� ���������� ����������� � �� ���� � �������� �����
bool scanFile(FILE* file, long* count, long* size);

// ���������� ����� � ��������� ������
char** readFile(FILE* file, long* count, long* size);

// ������ � �������������� ����
bool writeFile(FILE* file, char** array, long* rows);

void task1()
{
	// ������������ ������ ��� ����� ��������� ������������ ����� 
	// ������� ��� ������ ����������� ����������� �� ����� ������ (?!.)

	// ��� �����
	char* name = (char*)malloc(sizeof(char) * 40);

	// ���� ����� �����
	cout << "Enter file name: ";
	cin.ignore();
	cin.getline(name, 40);

	cout << endl;

	// �������� ��������� ����� 
	FILE* file = fopen(name, "r");

	// ���� ���� ������� ������
	if (file != nullptr)
	{
		// ���� ����� ��������������� �����
		cout << "Enter name result file: ";
		cin.getline(name, 40);

		// ��������� �� ������ � ������� �����������
		long* size = nullptr;

		// ��������� �� ���������� �����������
		long* count = nullptr;

		// ����������� ������� ����� �� ���������� ����������
		if (!scanFile(file, count, size))
		{
			cout << "Error! File NO read" << endl;
			return;
		}

		// ����������� ����� � ��������� ������. ������� ���������� ��������� �� ��������� ������
		char** array = readFile(file, count, size);
		
		// �������� ��������� �����
		fclose(file);

		// �������� � �������� ��������������� ����� � ������ ������
		file = fopen(name, "w");

		// ������ ���������� ������� � �������������� ���� 
		if (!writeFile(file, array, count))
		{
			cout << "Error! File NO write" << endl;
			return;
		}

		// �������� ��������������� �����
		fclose(file);
	}
	// ���� ���� �� ������� �������
	else cout << "Error! File NOT found" << endl;
}

// ������������ �� ���������� ����������� � �� ���� � �������� �����
bool scanFile(FILE* file, long* count, long* size)
{
	// ������� ��������� � ����� �� ������
	fseek(file, 0, SEEK_SET);

	// ��������� ������ ��� ��������� count
	count = (long*)malloc(sizeof(long));

	*count = 0;

	long* p_count = count;

	// ����� ����� ������
	char* buff = (char*)malloc(sizeof(char) * 400);

	// ���������� ���������� �����������
	while (!feof(file))
	{
		fgets(buff, 400, file);

		for (char* p_buf = buff; *p_buf; p_buf++)
		{
			if (*p_buf == '.' || *p_buf == '!' || *p_buf == '?')
			{
				*p_count += 1;
			}
		}
	}

	// ���� ���������� ����������� ����� ����
	if (*count == 0)
	{
		cout << "Error! Sentence NOT found!" << endl;
		return false;
	}

	// ��������� ������ ��� ��������� �� ������ ���� �����������
	size = (long*)malloc(sizeof(long) * *count);

	*size = 0;

	// ������� ��������� � ����� �� ������
	fseek(file, 0, SEEK_SET);

	// ����� �����������
	for (long* p_size = size; !feof(file);)
	{
		fgets(buff, 400, file);

		for (char* p_buf = buff; *p_buf; p_buf++)
		{
			// ���� ������� �� �������� '\n'
			if (*p_buf != '\n')
			{
				*p_size += 1;
			}

			if (*p_buf == '.' || *p_buf == '!' || *p_buf == '?')
			{
				// ������� �� ��������� ������� ������� ���� �����
				p_size++;

				*p_size = 0;
			}
		}
	}

	// ������� ��������� � ����� �� ������
	fseek(file, 0, SEEK_SET);


	return true;
}

// ���������� ����� � ��������� ������
char** readFile(FILE* file, long* count, long* size)
{
	// ������� ��������� � ����� �� ������
	fseek(file, 0, SEEK_SET);


	// �������� ���������� �������
	char** array = (char**)malloc(sizeof(char) * *count);

	for (char** arr = array, *buff = (char*)malloc(sizeof(char)*400); feof(file) != 0;)
	{
		// ���������� ����� ������ � �����
		fgets(buff, 400, file);

		// ������ � ��������� ������
		for (char* p_buff = buff; arr < array + *count && *p_buff; arr++, size++)
		{
			// �������� ������ � ��������� �������
			*array = (char*)malloc(sizeof(char) * *size + 1);

			// ������ ����������� � ������
			for (char* cols = *arr; cols < *arr + *size - 1; p_buff++)
			{
				// ���� ������� �� �������� '\n'
				if (*cols != '\n')
				{
					*cols = *p_buff;

					cols++;
				}
			}
		}
	}

	// ������� '\n' � ����� ������� ������ ���������� �������
	for (char** arr = array; arr < array + *count; arr++)
	{
		*(*arr + *count) = '\n';
	}

	// ������� ��������� � ����� �� ������
	fseek(file, 0, SEEK_SET);

	return array;
}

// ������ � �������������� ����
bool writeFile(FILE* file, char** array, long* rows)
{
	for (char** ar = array; ar < array + *rows; ar++)
	{
		fputs(*ar, file);
	}

	if (file == file - *rows)
		return true;

	return false;
}
