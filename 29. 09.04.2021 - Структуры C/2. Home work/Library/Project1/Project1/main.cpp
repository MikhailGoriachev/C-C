#include <iostream>
#include <conio.h>
#include "head.h"



using namespace std;

// 1. Разработать программу - базу данных о книгах. О каждой книге нужно хранить следующую информацию:
//  - номер книги(кл - 2345т или 1)
//  - название книги
//  - жанр книги
//  - ФИО автора
//  - год выпуска
//  - цена
//
// Программа имеет следующие функции :
//  - данные хранить в динамическом массиве структур
//  - пользовательское меню
//  - добавление книги
//  - удаление книги
//  - просмотр всех книг
//  - редактирование книги
//  - поиск по цене
//  - сохр / загр в файл всех данных
//  - выход из программы

void main()
{
	// режим запуска службы login: mode == 0 - вход в аккаунт, mode == 1 - управление пользователями, mode == 2 - выход;
	int* mode = new int;

	*mode = 0;

	// вход в аккаунт
	UserData* user = login(mode);
	
	// если указатель нулевой, это означает, что вход не выполнен
	if (user == nullptr)
		return;

	// пункт меню:
	// 1. Просмотр всех книг; 
	// 2. Найти книгу; 
	// 3. Скачать книгу;
	// 4. Добавить книгу(Группа администраторов); 
	// 5. Удалить книгу(группа администраторов);
	// 6. Управление аккаунтами; 
	// 0. Выход из программы;

	int* modeMenu = new int;

	*modeMenu = -1;

	// количество книг
	int** countBooks = new int*;

	// база книг
	book_t* books = loadingDataBooks(countBooks);

	// меню 
	while (*modeMenu != 0)
	{
		system("cls");

		menu(modeMenu);

		// 1. Просмотр всех книг; 
		if (*modeMenu == (int)'1')
		{
			AllBooks(countBooks);
		}

		// 2. Найти книгу; 
		else if (*modeMenu == (int)'2')
		{
			SearchBook(books, *countBooks);
		}

		// 3. Скачать книгу;
		else if (*modeMenu == (int)'3')
		{
			DownloadBook(books, countBooks);
		}

		// 4. Добавить книгу(Группа администраторов); 
		else if (*modeMenu == (int)'4')
		{
			// если пользователь входит в группу администраторов
			if ((*user).accessLevel == 1)
			{
				// указатель на базу данных книг
				books = AddBook(books, countBooks);
			}
			else
			{
				cout << "YOU ARE NOT A MEMBER OF THE ADMINISTRATION GROUP!" << endl;

				pressAnyKey();
			}
		}

		// 5. Удалить книгу(группа администраторов);
		else if (*modeMenu == (int)'5')
		{
			// если пользователь входит в группу администраторов
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

		// 6. Управление аккаунтами; 
		else if (*modeMenu == (int)'6')
		{
			// если пользователь входит в группу администраторов
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
		// 0. Выход из программы;
	}


	// отчистка памяти
	delete mode, user, modeMenu, * countBooks, countBooks;
	delete[] books;
}
