#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

void task1()
{
	// открытие текстового файла дл€ записи, если файла нет то он создаетс€
	// FILE* указатель на файл, функци€ fopen возвращает адрес открытого файла
	// FILE* file = fopen("mytext.txt", "w");

	/*// вывод на экран строки
	puts("Hello world");
	// %s - вставка строки, %d - вставка числа. \т - переход на следующую строку
	printf("My name is %s, I`m %d yars old.", "Dima", 43);*/

	// вывод в файл
	/*fputs("Hello world\n", file);
	fprintf(file, "My name is %s, I`m %d years old.\nend.", "Dima", 43);

	// закрытие файла
	fclose(file);*/

	// вользователь вводит им€ файла числа, пока не введЄт 0.
	// все числа, кроме 0, сохран€ютс€ в файл в столбик

	char name[40];
	int num = 1;

	cout << "Enter name file: ";
	cin.getline(name, 40);

	int len = strlen(name);

	name[len++] = '.';
	name[len++] = 't';
	name[len++] = 'x';
	name[len++] = 't';
	name[len++] = 0;
	

	FILE* file = fopen(name, "w");

	for (;;)
	{
		cout << "Enter number: ";
		cin >> num;
		if (num == 0)
			break;
		fprintf(file, "%d \n", num);
	}
	
	// закрытие файла
	fclose(file);

	cin.ignore();
}

