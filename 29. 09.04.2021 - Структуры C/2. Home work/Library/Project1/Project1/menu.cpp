#include <iostream>
#include <conio.h>
#include "head.h"

using namespace std;

// меню
void menu(int* mode)
{
	// выбор пунктов меню
	while (true)
	{
		system("cls");

		outline();

		cout << "MENU" << endl;

		outline();

		// пункты меню

		// 1. Просмотр всех книг
		cout << "* 1. ALL BOOKS *" << endl;

		// 2. Найти книгу
		cout << "* 2. SEARCH BOOK *" << endl;

		// 3. Скачать книгу 
		cout << "* 3. DOWNLOAD BOOK *" << endl;

		// 4. Добавить книгу(Группа администраторов)
		cout << "* 4. ADD BOOK(ADMIN GROUP) *" << endl;

		// 5. Удалить книгу(группа администраторов)
		cout << "* 5. DELETE BOOK(ADMIN GROUP) *" << endl;

		// 6. Управление аккаунтами
		cout << "* 6. ACCOUNT MANAGEMENT(ADMIN GROUP)" << endl;

		// выход из программы
		cout << "* EXIT[ESC] *" << endl;

		// ввод 
		*mode = (int)_getch();

		// если была нажата цифра от 1 до 6
		if ((char)*mode > '0' && (char)*mode < '7')
			return;

		// если была нажата клавишу esc
		if (*mode == 27)
		{
			*mode = 0;
		}
	}
}