#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <conio.h>
#include "head.h"

using namespace std;

void task1()
{
	// 1. Пользователь вводит имя файла, программа подсчитывает 
	// общуюю сумму чисел в файле(числа - отдельные слова)

	// имя файла
	char name[40];

	// указатель на файл
	FILE* file;

	// ввод имени файла
	cout << "Enter name file: ";
	cin >> name;

	cout << endl;

	// функция проверяет существует ли файл и при необходимости его создаёт.
	// она возвращает значение 0/1/2
	int fileOp = fileCreate(name);

	// если файл не создан
	if (fileOp == 0)
	{
		cout << endl;
		cout << "Exit" << endl;
		return;
	}

	// если файл создан
	if (fileOp == 1)
	{
		cout << endl;

		// ввод чисел в файл через пробел
		cout << "Enter number into file (press Esc - exit): ";

		// открытие файла в режиме записи
		file = fopen(name, "w");
		
		// цикл заполнения файла
		for (size_t i = 0;; i++)
		{
			char enter = _getch();
			if (enter == (char)27)
			{
				break;
			}
			
			if (enter == (char)13)
			{
				fprintf(file, "\n");
				cout << endl;
				continue;
			}

			if (enter >= '0' && enter <= 'z' || enter == ' ')
			{
				cout << enter;
				fprintf(file, "%c", enter);
			}
		}

		fclose(file);

		cout << endl << endl;

		cout << "File save" << endl;
	}
	
	file = fopen(name, "r");

	int sum = 0;
	
	
	while (!feof(file))
	{
		char buffer[200];
		fscanf(file, "%s", buffer);
		sum += atoi(buffer);
		strcpy(buffer, "");
	}

	while (!feof(file))
	{
		char buffer[200];
		fgets(buffer, 200, file);
		puts(buffer);
	}

	fclose(file);

	cout << "Sym = " << sum << endl;
}