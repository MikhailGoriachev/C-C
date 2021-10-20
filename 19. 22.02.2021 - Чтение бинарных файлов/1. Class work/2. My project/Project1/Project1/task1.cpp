#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

void task1()
{
	// программа сохраняет код файла 

	/*char nameFile1[40];

	// ввод имени файла
	cout << "Enter name file: ";
	cin.ignore();
	cin.getline(nameFile1, 40);

	// открытие файла с кодом в режиме чтения 
	FILE* fcode = fopen("project.exe", "r");

	// открытие файла для копирования в режиме записи
	FILE* fcopy = fopen("fileCode.txt", "w");

	// копирование
	while (!feof(fcode))
	{
		// буфер для хранения строки
		char buff[400];

		// заполнение буфера строкой из файла
		fgets(buff, 400, fcode);

		// заполнение файла для копирования строкой из буфера
		fputs(buff, fcopy);

		// отчистка буфера
		strcpy(buff, "");
	}

	// закрытие первого файла
	fclose(fcode);

	// закрытие второго файла
	fclose(fcopy);*/
}