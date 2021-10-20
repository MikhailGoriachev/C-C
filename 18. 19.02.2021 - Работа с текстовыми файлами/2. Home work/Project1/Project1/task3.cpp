#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "head.h"

using namespace std;

// переворот строки
void stringRepeat(char a[]);

void task3()
{
	// 3. Пользователь вводит 2 имени файла, программа сохраняет
	// в результат все строки первого файла, но в перевёрнутом
	// виде(hello->olleh)

	// указатели на файл
	FILE* file_1, * file_2;

	// имена файлов
	char name_1[40], name_2[40];

	// ввод имени первого файла 
	cout << "Enter name first file: ";
	cin >> name_1;
	
	int detectFile = fileCreate(name_1);

	// если файл создан
	if (detectFile == 1)
	{
		// ввод в файла 
		cout << "Enter strings in file (0 exit): ";

		// октрытие файла в режиме редактирования
		file_1 = fopen(name_1, "w");

		cin.ignore();

		// ввод файла 
		while (true)
		{
			// ввод втроки
			char buffer[40];
			cin.getline(buffer, 40);

			// если пользователь ввёл ноль, то ввод прекращается
			if (!strcmp(buffer, "0"))
				break;

			// проверка на '\n' в конце строки
			detectBackN(buffer);

			// заполение файла строкой из буфера
			fputs(buffer, file_1);

			// отчистка буфера
			strcpy(buffer, "");
		}

		// закрытие файла
		fclose(file_1);
	}

	// если файла не существует
	if (detectFile == 0)
	{
		cout << endl;
		cout << "Exit" << endl;
		return;
	}

	// ввод имени второго файла 
	cout << "Enter name second file: ";
	cin >> name_2;

	detectFile = fileCreate(name_2);

	// если файла не существует
	if (detectFile == 0)
	{
		cout << endl;
		cout << "Exit" << endl;
		return;
	}
	
	// открытие первого файла в режиме чтения
	file_1 = fopen(name_1, "r");

	// открытие второго файла в режими записи
	file_2 = fopen(name_2, "w");

	// запись второго файла перевёрнутыми строками первого файла
	while (!feof(file_1))
	{
		// буфер для одной строки
		char buffer[200];

		if (detectFile > 100)
		{
			cout << endl;
		}

		// считываение одной строки с файла в буфер
		fgets(buffer, 199, file_1);

		// проверка на наличие '\n' в строке
		//detectBackN(buffer);

		// переворот строки в буфере
		stringRepeat(buffer);

		// запись строки из буфера во второй файл
		fputs(buffer, file_2);

		// отчистка буфера
		strcpy(buffer, "");
	}

	cout << "File copy complete!" << endl;
	
	// закрытие первого и второго файлов
	fclose(file_1);
	fclose(file_2);
}

// переворот строки
void stringRepeat(char a[])
{
	int len = strlen(a);

	if (a[len - 1] == '\n')
		len--;

	for (int i = 0; i < len / 2; i++)
	{
		swap(a[i], a[len - 1 - i]);
	}
}
