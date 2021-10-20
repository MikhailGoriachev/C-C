#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

void comb(char** board, const int size, int count)
{
	// ���������� ����������� ���������
	bool* flag = new bool;

	*flag = true;


	// ��������� �����
	for (char** y = board; *y < board[size]; y++)
	{
		for (char* x = *y; x < *y + size; x++)
		{
			// �������� ���������� �� �������� �� ����� ��� ���� ������ ������
			// �������� �� �����������
			for (char* x_pr = *y; x_pr < *y + size; x_pr++)
			{
				// ���� ������� ������ 'W'
				if (*x_pr == 'W')
				{
					*flag = false;

					break;
				}
					
			}

			// �������� �� ���������
			for (char** y_pr = board; y_pr < board + size; y_pr++)
			{
				// ���� ������� ������ 'W'
				if (**y_pr == 'W')
				{
					*flag = false;

					break;

				}
			}

			int* i = new int;

			*i = 0;

			// �������� ��������� � ����� ����� 
			for (char** y_pr = y, * x_pr = x; ; y_pr--, *y_pr -= 1)
			{
				// ���� ������� ������ 'W'
				if (**y_pr == 'W')
				{
					*flag = false;

					break;
				}

				// ���� �� x ��� ��������� �������
				if (x_pr == *y_pr || y_pr == board)
				{
					break;
				}
			}

			// ���� ���������� ��������
			if (*flag)
			{
				*x = 'W';

				// ���� ������� ����� �� �������� �� ����� �������
				// ������ ������� ����������
				if (count < 8)
				{
					comb(board, size, ++count);
				}
			}
		}
	}

	
}

void main()
{
	// 8 ������ ��������� ����������� �� ��������� �����, ���� ��� ���� ����� �� ����. ���������� ������� ��� ����������.

	const int size = 8;

	// ��������� ������ ��������� �����
	char** board = new char*[size];
	
	// ������� ��� �����
	int* color = new int;

	*color = 0;

	// ���������� ��������� ����� ������
	for (char** b = board; b < board + size; b++)
	{
		*b = new char[size + 1];
		for (char* n = *b; n < *b + size; n++, ++*color)
		{
			// ���� ������ �� X
			if (*color % 2 == 0)
			{
				*n = (int)'X';
			}

			// ���� ����� �� O
			if (*color % 2 == 1)
			{
				*n = (int)'O';
			}
		}
	}

	// ����� �������
	comb(board, size, 0);
}