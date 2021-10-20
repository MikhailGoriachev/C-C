#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

#include "head.h"

using namespace std;

// загрузка ключа шифрования по пути ./Person Database 1.0/Security/key.data
bool LoadingKey(key_t* key, int sizeKey)
{
	// открытие файла в режиме банарного чтения
	FILE* file = fopen("./Security/key.data", "rb");

	// если файл открыт успешно
	if (file != nullptr)
	{
		// установка указателя в конец файла
		fseek(file, 0, SEEK_END);

		// длина файла 
		size_t* sizeFile = new size_t;

		*sizeFile = ftell(file);

		// если длина файла не равняется 500, то файл битый
		if (*sizeFile != 500)
		{
			cout << "ERROR! BROKEN FILE \"key.data\"";

			// закрытие файла
			fclose(file);

			pressAnyKey();

			return false;
		}

		// установка указателя в начало файл
		fseek(file, 0, SEEK_SET);

		// буфер для половины ключа
		char* buffer = new char[250];

		// считывание файла в структуру
		fread(buffer, sizeof(char), 250, file);

		
		for (char* buf = buffer, * cr = (key->decrypt); buf < buffer + 63; buf++, cr++)
		{
			*cr = *buf;
		}

		// считывание файла в структуру
		fread(buffer, sizeof(char), 250, file);

		strncpy(key->crypt, buffer, sizeKey);

		delete[] buffer;

		// закрытие файла
		fclose(file);

		return true;
	}

	cout << "FILE \"key.data\" NOT FOUND!" << endl;

	pressAnyKey();

	return false;

}

// шифрование и дешифрование; mode = 1 - шифрование, mode = 2 - дешифрование 
void CryptOrDecrypt(char* str, int len, key_t* key, int mode, int sizeKey)
{
	// строка первого набора символов ключа
	char* a = new char[sizeKey];

	// строка второго набора символов ключа
	char* b = new char[sizeKey];

	// если шифрование 
	if (mode == 1)
	{
		a = key->decrypt;
		b = key->crypt;
	}

	// если дешифрование 
	if (mode == 2)
	{
		a = key->crypt;
		b = key->decrypt;
	}

	// замена сиволов
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