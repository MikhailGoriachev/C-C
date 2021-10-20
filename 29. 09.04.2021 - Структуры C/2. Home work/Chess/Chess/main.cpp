#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <conio.h>

using namespace std;

// ����� ��������� �����
void printBoard(int** board);

void comb(int** board, int y, int* count, FILE** file);

// ���������� ������� ����� � ����
void saveBoard(FILE** file, int** board, int* count);

void main()
{
	// ��������� ��������� ��� ���������� ����������� ������ ������
	// �� ��������� ����� ����� �������, ���� ��� �� ���������� ���� 
	// �����

	// ��������� ����� ����� �������
	int* size = new int;

	*size = 8;

	// ��������� ������������ ������ - ��������� �����
	int** board = new int* [*size];

	int** temp_board = new int* [*size];

	// �������
	int* i = new int;

	*i = 1;
	// �������� ���������� �������� ��� ���������� �������
	for (int** _board = board, ** _temp_board = temp_board; _board < board + *size; _board++, _temp_board++)
	{

		*_board = new int[*size];
		*_temp_board = new int[*size];

		// ���������� �����: 1 - �����, 0 - ������
		for (int* x = *_board, *temp_x = *_temp_board; x < *_board + *size; x++, temp_x++)
		{
			// ���� ������� ��� ������� ������� �� 8
			if (*i % 9 == 0)
				++* i;

			// ���� �������� �������� ��� ������� ������� �� ��� - ������(0)
			if (*i % 2 == 0)
			{
				*x = 0;
				*temp_x = 0;
			}

			// ���� �������� �������� ������� � �������� �� ��� - �����(1)
			if (*i % 2 == 1)
			{
				*x = 1;
				*temp_x = 1;
			}
			++* i;
		}
	}

	int count = 0;

	int* size_base = new int;

	*size_base = 0;

	// �������� � �������� ����� 
	FILE** file = new FILE*;

	*file = fopen(".\\result.txt", "w");

	comb(board, 0, &count, file);

	// �������� �����
	fclose(*file);

	cout << endl;

	cout << "\n\n\n\nPRESS ANY KEY..." << endl;

	_getch();
}

// ����� ��������� �����
void printBoard(int** board)
{
	for (int** _board = board; _board < board + 8; _board++)
	{
		for (int* x_board = *_board; x_board < *_board + 8; x_board++)
		{
			// ���� �������� 1
			if (*x_board == 1)
			{
				cout << " O ";
			}

			// ���� �������� 0
			if (*x_board == 0)
			{
				cout << " X ";
			}

			// ���� �������� 3
			if (*x_board == 3)
			{
				cout << " W ";
			}
		}

		cout << endl << endl;
	}

}

// ���������� ������� ����� � ����
void saveBoard(FILE** file, int** board, int* count)
{
	fprintf(*file, "------------------ %i -------------------\n\n", *count);

	for (int** y = board; y < board + 8; y++)
	{
		for (int* x = *y; x < *y + 8; x++)
		{
			// ���� �������� 1
			if (*x == 1)
				fprintf(*file, "  O  ");

			// ���� �������� 2 
			else if (*x == 0)
				fprintf(*file, "  X  ");

			// ���� �������� 3
			else if (*x == 3)
				fprintf(*file, "  W  ");
		}

		fprintf(*file, "\n\n");
	}

	fprintf(*file, "\n\n\n");
}

// ����� ����������
void comb(int** board, int y, int* count, FILE** file)
{
	// ���� 
	bool flag = true;
	
	// ������� �� x
	int x = -1;

	// ��������� �������� �������� ������ �����
	int temp;

	while (true)
	{
		// ����� goto
		point:

		if (x == 7)
		{
			return;
		}

		// ���������� ������� �� x
		x++;

		int yy, xx;

		// �������� �� ���������
		for ( yy = 0; yy < 8; yy++)
		{
			// ���� ����� ����� �� ���������
			if (board[yy][x] == 3)
			{
				flag = false;

				// ������� �� �����
				goto point;

				break;
			}
		}

		// �������� �� �����������
		for ( xx = 0; xx < 8; xx++)
		{
			// ���� ������ ����� �� �����������
			if (board[y][xx] == 3)
			{
				flag = false;

				// ������� �� �����
				goto point;

				break;
			}
		}


		// �������� �� ������� ������� � ������ �������� ����
		for ( xx = x, yy = y; xx > -1 && yy > -1; xx--, yy--)
		{
			// ���� ������ �����
			if (board[yy][xx] == 3)
			{
				flag = false;

				// ������� �� �����
				goto point;

				break;
			}
		}


		// �������� �� ������� ������� � ������� ������� ����
		for ( xx = x, yy = y; xx < 8 && yy < 8; xx++, yy++)
		{
			// ���� ������ �����
			if (board[yy][xx] == 3)
			{
				flag = false;

				// ������� �� �����
				goto point;

				break;
			}
		}

		// �������� �� ������� ������� � ������ ������� ����
		for ( xx = x, yy = y; xx > -1 && yy < 8; xx--, yy++)
		{
			// ���� ������ �����
			if (board[yy][xx] == 3)
			{
				flag = false;

				// ������� �� �����
				goto point;

				break;
			}
		}

		// �������� �� ������� ������� � ������� �������� ����
		for ( xx = x, yy = y; xx < 8 && yy > -1; xx++, yy--)
		{
			// ���� ������ ����� 
			if (board[yy][xx] == 3)
			{
				flag = false;

				// ������� �� �����
				goto point;

				break;
			}
		}

		
		// ���������� �������� ����� � �����
		temp = board[y][x];

		// ��������� W �� ������� �����
		board[y][x] = 3;

		// ���� ��� �� ��������� ���
		if (y < 7)
		{
			// ����������� ������ �������
			comb(board, y + 1, count, file);
		}

		// ���������� �������� ������� ����������
		else
		{
			++* count;
			
			system("cls");

			printBoard(board);

			cout << "Count: " << *count << endl;

			saveBoard(file, board, count);
		}

		// �������� ����� � ������� �������
		board[y][x] = temp;
	}
}