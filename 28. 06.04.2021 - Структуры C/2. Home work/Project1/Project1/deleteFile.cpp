#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <windows.h>
#include <time.h>
#include "head.h"

using namespace std;

//extern cypher sec;

void deleteFile(const char path[])
{
	srand(time(0));

	// �������� ����� � ������ ������� ������ + ������
	FILE* file = fopen(path, "rb+");

	// ��������� ��������� � ����� � �����
	fseek(file, 0, SEEK_END);

	// ����� �����
	size_t* size = new size_t;

	*size = ftell(file);

	// ��������� ��������� � ������
	fseek(file, 0, SEEK_END);

	// ����� 
	char* buffer = new char[*size];

	// ���������� ��� �����
	int* k = new int;

	// ���������� ���� ���
	for (*k = 0; *k < 7; ++ * k)
	{
		// ��������� ������ ���������� ���������
		for (char* i = buffer; i < buffer + *size; i++)
		{
			*k == (char)(rand() % ((int)'\\' - (int)'!' + 1) + (int)'!');
		}

		// ������ � ���� �� ������
		fwrite(buffer, sizeof(char), *size, file);

		// ��������� ��������� � ������ �����
		fseek(file, 0, SEEK_SET);
	}

	// �������� �����
	fclose(file);

	// �������� ����� ����������
	remove(path);
}