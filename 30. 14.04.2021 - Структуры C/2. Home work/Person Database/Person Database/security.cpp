#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

#include "head.h"

using namespace std;

// �������� ����� ���������� �� ���� ./Person Database 1.0/Security/key.data
bool LoadingKey(key_t* key, int sizeKey)
{
	// �������� ����� � ������ ��������� ������
	FILE* file = fopen("./Security/key.data", "rb");

	// ���� ���� ������ �������
	if (file != nullptr)
	{
		// ��������� ��������� � ����� �����
		fseek(file, 0, SEEK_END);

		// ����� ����� 
		size_t* sizeFile = new size_t;

		*sizeFile = ftell(file);

		// ���� ����� ����� �� ��������� 500, �� ���� �����
		if (*sizeFile != 500)
		{
			cout << "ERROR! BROKEN FILE \"key.data\"";

			// �������� �����
			fclose(file);

			pressAnyKey();

			return false;
		}

		// ��������� ��������� � ������ ����
		fseek(file, 0, SEEK_SET);

		// ����� ��� �������� �����
		char* buffer = new char[250];

		// ���������� ����� � ���������
		fread(buffer, sizeof(char), 250, file);

		
		for (char* buf = buffer, * cr = (key->decrypt); buf < buffer + 63; buf++, cr++)
		{
			*cr = *buf;
		}

		// ���������� ����� � ���������
		fread(buffer, sizeof(char), 250, file);

		strncpy(key->crypt, buffer, sizeKey);

		delete[] buffer;

		// �������� �����
		fclose(file);

		return true;
	}

	cout << "FILE \"key.data\" NOT FOUND!" << endl;

	pressAnyKey();

	return false;

}

// ���������� � ������������; mode = 1 - ����������, mode = 2 - ������������ 
void CryptOrDecrypt(char* str, int len, key_t* key, int mode, int sizeKey)
{
	// ������ ������� ������ �������� �����
	char* a = new char[sizeKey];

	// ������ ������� ������ �������� �����
	char* b = new char[sizeKey];

	// ���� ���������� 
	if (mode == 1)
	{
		a = key->decrypt;
		b = key->crypt;
	}

	// ���� ������������ 
	if (mode == 2)
	{
		a = key->crypt;
		b = key->decrypt;
	}

	// ������ �������
	for (char* str_p = str; str_p < str + len; str_p++)
	{
		for (char* a_p = a, * b_p = b; a_p < a + sizeKey; a_p++, b_p++)
		{
			if (*str_p == *a_p)
			{
				*str_p = *b_p;
				break;
			}
		}
	}
}