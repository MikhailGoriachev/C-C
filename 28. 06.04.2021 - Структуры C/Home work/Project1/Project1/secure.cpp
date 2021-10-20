#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <io.h>
#include <conio.h>
#include <direct.h>

#include "struct.h"
#include "head.h"

// безопасность

using namespace std;

extern cypher* sec;

// шифрование строки; получает: vocab - словарь, str - строка;
void encryption(cypher vocab, char* string, unsigned long size)
{
	// шифрование 
	for (char* str = string; str < string + size; str++)
	{
		// перебор символов шифрования
		for (char* cyp = vocab.cyp, *decyp = vocab.decyp; *decyp; cyp++, decyp++)
		{
			// если элемент строки совпадает с символом шифровки
			if (*str == *cyp)
			{
				*str = *decyp;
			}
		}
	}
}

// дешифрование строки
void decryption(cypher vocab, char* string, unsigned long size)
{
	// дешифрование 
	for (char* str = string; str < string + size; str++)
	{
		// перебор символов шифрования
		for (char* cyp = vocab.cyp, *decyp = vocab.decyp; *decyp; cyp++, decyp++)
		{
			// если элемент строки совпадает с символом шифровки
			if (*str == *decyp)
			{
				*str = *cyp;
			}
		}
	}

}