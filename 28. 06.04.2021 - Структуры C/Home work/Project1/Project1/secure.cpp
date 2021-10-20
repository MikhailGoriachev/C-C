#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <io.h>
#include <conio.h>
#include <direct.h>

#include "struct.h"
#include "head.h"

// ������������

using namespace std;

extern cypher* sec;

// ���������� ������; ��������: vocab - �������, str - ������;
void encryption(cypher vocab, char* string, unsigned long size)
{
	// ���������� 
	for (char* str = string; str < string + size; str++)
	{
		// ������� �������� ����������
		for (char* cyp = vocab.cyp, *decyp = vocab.decyp; *decyp; cyp++, decyp++)
		{
			// ���� ������� ������ ��������� � �������� ��������
			if (*str == *cyp)
			{
				*str = *decyp;
			}
		}
	}
}

// ������������ ������
void decryption(cypher vocab, char* string, unsigned long size)
{
	// ������������ 
	for (char* str = string; str < string + size; str++)
	{
		// ������� �������� ����������
		for (char* cyp = vocab.cyp, *decyp = vocab.decyp; *decyp; cyp++, decyp++)
		{
			// ���� ������� ������ ��������� � �������� ��������
			if (*str == *decyp)
			{
				*str = *cyp;
			}
		}
	}

}