#include <iostream>
#include <conio.h>

#include "head.h"

using namespace std;

// меню
void menu(char* c)
{
	while (true)
	{
		system("cls");

		outLine();

		cout << "MENU" << endl;

		outLine();

		// пункты меню
		// 1. Все люди
		// 2. Найти человека
		// 3. Добавить человека(admin group)
		// 4. Удалить человека(admin group)
		// 5. Управление аккаунтами(admin group)
		// 6. Перешифровать данные(admin group)

		// 1. Все люди
		cout << "1. LIST PERSON" << endl;
		// 2. Найти человека
		cout << "2. SEARCH PERSON" << endl;
		// 3. Добавить человека(admin group)
		cout << "3. ADD PERSON (ADMIN GROUP)" << endl;
		// 4. Удалить человека(admin group)
		cout << "4. DELETE PERSON (ADMIN GROUP)" << endl;
		// 5. Управление аккаунтами(admin group)
		cout << "5. ACCOUNT MANAGEMENT (ADMIN GROUP)" << endl;
		// 6. Перешифровать данные(admin group)
		cout << "6. DATA ENCRYPTION (ADMIN GROUP)" << endl;
		// выход из программы
		cout << "\n\n\n\n\n[ESC] EXIT" << endl;
		// ввод 
		while (true)
		{
			*c = _getch();

			if ((*c >= '0' && *c <= '9') || *c == (char)27)
			{
				return;
			}
		}
	}
}