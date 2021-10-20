#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

long countSentence(char* buff, long size);

void writeNewBuff(char* a, char* b, long size_a, long size_b);

void task7()
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
	FILE* file = fopen(name, "rb");

	// ���� ���� ������� ������
	if (file != nullptr)
	{
		//���� ����� ��������������� �����
		cout << "Enter name result file: ";
		cin.getline(name, 40);

		// ��������� ����� � �����
		fseek(file, 0, SEEK_END);

		// ����� �����
		long size = ftell(file);

		// ��������� � ����� � ������
		fseek(file, 0, SEEK_SET);

		// ����� ��� �����
		char* buff = (char*)malloc(sizeof(char) * size);

		// ���������� � ����� �����
		fread(buff, sizeof(char), size, file);

		// �������� ��������� �����
		fclose(file);

		// ����� ����� ������
		long new_size = countSentence(buff, size);

		// ����� �����
		char* new_buff = (char*)malloc(sizeof(char) * size);

		// ���������� ������ ������ ���������� ����������� ������� ������
		writeNewBuff(buff, new_buff, size, new_size);

		// �������� ������ �����
		file = fopen(name, "wb");

		// ������ � ����� ����
		fwrite(new_buff, sizeof(char), new_size, file);

		// �������� �����
		fclose(file);

		cout << "File save" << endl;

	}
	// ���� ���� �� ������� �������
	else cout << "Error! File NOT found" << endl;


}

long countSentence(char* buff, long size)
{
	long* new_size = (long*)malloc(sizeof(long));

	*new_size = size;

	for (char* buffer = buff; buffer < buff + size; buffer++)
	{
		if (*buffer == '.' && *(buffer + 1) != '.')
			++*new_size;
		if (*buffer == '\n')
			--* new_size;
	}

	size = *new_size;

	free(new_size);

	return size;
}

void writeNewBuff(char* a, char* b, long size_a, long size_b)
{
	bool dot = false;

	long size = 0;

	for (char* aa = a, *bb = b; aa < a + size_a; aa++)
	{
		if (*aa == '\n')
			continue;

		if (*aa == '.' && *(aa - 1) != '.')
		{
			for (char* p_b = bb + 1; p_b > bb - size; p_b--)
			{
				swap(*p_b, *(p_b - 1));
			}

			*(bb - size) = '\n';

			size = -1;

			bb++;
		}

		size++;

		*bb = *aa;
		bb++;
	}
}