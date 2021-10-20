#include <iostream>
#include <conio.h>
#include "head.h"



using namespace std;

// 1. ����������� ��������� - ���� ������ � ������. � ������ ����� ����� ������� ��������� ����������:
//  - ����� �����(�� - 2345� ��� 1)
//  - �������� �����
//  - ���� �����
//  - ��� ������
//  - ��� �������
//  - ����
//
// ��������� ����� ��������� ������� :
//  - ������ ������� � ������������ ������� ��������
//  - ���������������� ����
//  - ���������� �����
//  - �������� �����
//  - �������� ���� ����
//  - �������������� �����
//  - ����� �� ����
//  - ���� / ���� � ���� ���� ������
//  - ����� �� ���������

void main()
{
	// ����� ������� ������ login: mode == 0 - ���� � �������, mode == 1 - ���������� ��������������, mode == 2 - �����;
	int* mode = new int;

	*mode = 0;

	// ���� � �������
	UserData* user = login(mode);
	
	// ���� ��������� �������, ��� ��������, ��� ���� �� ��������
	if (user == nullptr)
		return;

	// ����� ����:
	// 1. �������� ���� ����; 
	// 2. ����� �����; 
	// 3. ������� �����;
	// 4. �������� �����(������ ���������������); 
	// 5. ������� �����(������ ���������������);
	// 6. ���������� ����������; 
	// 0. ����� �� ���������;

	int* modeMenu = new int;

	*modeMenu = -1;

	// ���������� ����
	int** countBooks = new int*;

	// ���� ����
	book_t* books = loadingDataBooks(countBooks);

	// ���� 
	while (*modeMenu != 0)
	{
		system("cls");

		menu(modeMenu);

		// 1. �������� ���� ����; 
		if (*modeMenu == (int)'1')
		{
			AllBooks(countBooks);
		}

		// 2. ����� �����; 
		else if (*modeMenu == (int)'2')
		{
			SearchBook(books, *countBooks);
		}

		// 3. ������� �����;
		else if (*modeMenu == (int)'3')
		{
			DownloadBook(books, countBooks);
		}

		// 4. �������� �����(������ ���������������); 
		else if (*modeMenu == (int)'4')
		{
			// ���� ������������ ������ � ������ ���������������
			if ((*user).accessLevel == 1)
			{
				// ��������� �� ���� ������ ����
				books = AddBook(books, countBooks);
			}
			else
			{
				cout << "YOU ARE NOT A MEMBER OF THE ADMINISTRATION GROUP!" << endl;

				pressAnyKey();
			}
		}

		// 5. ������� �����(������ ���������������);
		else if (*modeMenu == (int)'5')
		{
			// ���� ������������ ������ � ������ ���������������
			if ((*user).accessLevel == 1)
			{
				books = DeleteBook(books, countBooks);
			}
			else
			{
				cout << "YOU ARE NOT A MEMBER OF THE ADMINISTRATION GROUP!" << endl;

				pressAnyKey();
			}

		}

		// 6. ���������� ����������; 
		else if (*modeMenu == (int)'6')
		{
			// ���� ������������ ������ � ������ ���������������
			if ((*user).accessLevel == 1)
			{
				*mode = 1;

				while (*mode == 1)
				{
					login(mode);
				}
			}
			else
			{
				cout << "YOU ARE NOT A MEMBER OF THE ADMINISTRATION GROUP!" << endl;

				pressAnyKey();
			}
		}
		// 0. ����� �� ���������;
	}


	// �������� ������
	delete mode, user, modeMenu, * countBooks, countBooks;
	delete[] books;
}
