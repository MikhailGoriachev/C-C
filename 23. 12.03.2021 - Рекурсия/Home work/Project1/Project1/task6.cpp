#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

// ������������ �� ���������� ����������� � �� ���� � �������� �����
bool countSentence(FILE* file, long* count);

// ���������� ����� � ��������� ������
char** readFile(FILE* file, long* count, long* size);

// ������ � �������������� ����
void writeFile(FILE* file, char** array, long* rows);

// ����� ������ ������
void sizeSentence(FILE* file, long* size);

void task6()
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

		// ��������� �� ���������� �����������
		long* count = (long*)malloc(sizeof(long));

		// ����������� ������� ����� �� ���������� ����������
		if (!countSentence(file, count))
		{
			cout << "Error! File NO read" << endl;
			return;
		}

		// ��������� �� ������ � ������� �����������
		long* size = (long*)malloc(sizeof(long) * *count);

		sizeSentence(file, size);

		// ����������� ����� � ��������� ������. ������� ���������� ��������� �� ��������� ������
		char** array = readFile(file, count, size);

		// �������� ��������� �����
		fclose(file);

		// �������� � �������� ��������������� ����� � ������ ������
		file = fopen(name, "w");

		// ������ ���������� ������� � �������������� ���� 
		writeFile(file, array, count);

		// �������� ��������������� �����
		fclose(file);
	}
	// ���� ���� �� ������� �������
	else cout << "Error! File NOT found" << endl;
}

// ������������ �� ���������� ����������� � �� ���� � �������� �����
bool countSentence(FILE * file, long* count)
{
	// ������� ��������� � ����� �� ������
	fseek(file, 0, SEEK_SET);

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

	free(buff);

	// ���� ���������� ����������� ����� ����
	if (*count == 0)
	{
		cout << "Error! Sentence NOT found!" << endl;
		return false;
	}

	return true;
}

void sizeSentence(FILE* file, long* size)
{
	// ��������� ������ ��� ��������� �� ������ ���� �����������
	*size = 0;

	// ������� ��������� � ����� �� ������
	fseek(file, 0, SEEK_SET);

	char* buff = (char*)malloc(sizeof(char) * 400);

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
				*p_size += 2;

				//p_size -= 1;
				p_buf++;

				if (*p_buf == 0)
					break;

				// ������� �� ��������� ������� ������� ���� �����
				p_size++;

				*p_size = 0;
			}

		}
	}

	// ������� ��������� � ����� �� ������
	fseek(file, 0, SEEK_SET);

	free(buff);
}

// ���������� ����� � ��������� ������
char** readFile(FILE * file, long* count, long* size)
{
	// ������� ��������� � ����� �� ������
	fseek(file, 0, SEEK_SET);

	// �������� ���������� �������
	char** array = (char**)malloc(sizeof(char) * *count);

	// ������ ������
	*array = (char*)malloc(sizeof(char) * *size + 1);

	long* p_size = (long*)malloc(sizeof(size));

	p_size = size;

	for (char** arr = array, *buff = (char*)malloc(sizeof(char) * 400), *cols = *arr; feof(file) == 0;)
	{
		// ���������� ����� ������ � �����
		fgets(buff, 400, file);

		// ������ � ��������� ������
		char* p_buff = buff; 


		// ������ ����������� � ������
		for (; cols <= *arr + *p_size; p_buff++)
		{
			// ���� ������� �� �������� '\n'
			if (*p_buff == '\n')
			{
				break;
			}

			if (*p_buff == '.')
			{
				arr++;

				p_size++;

				// �������� ������ � ��������� �������
				*arr = (char*)malloc(sizeof(char) * *size + 1);

				*cols = *p_buff;

				cols = *arr;


				break;
			}

			*cols = *p_buff;
			cols++;
		}
	}

	p_size = size;

	// ������� '\n' � ����� ������� ������ ���������� �������
	for (char** arr = array; arr < array + *count; arr++, p_size)
	{
		*(*arr + *p_size) = 0;
		*(*arr + *p_size - 1) = '\n';
	}

	// ������� ��������� � ����� �� ������
	fseek(file, 0, SEEK_SET);

	return array;
}

// ������ � �������������� ����
void writeFile(FILE * file, char** array, long* rows)
{
	for (char** ar = array; ar < array + *rows; ar++)
	{
		fputs(*ar, file);
	}
}
