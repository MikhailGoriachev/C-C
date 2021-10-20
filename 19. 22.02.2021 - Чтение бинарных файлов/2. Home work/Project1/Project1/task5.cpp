#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

void task5()
{
	// 5. Разработать программу, которая записывает свой исходный 
	// код в файл source.cpp.Копировать из другого файла
	// нельзя.Только писать из программы. (+1 к экзамену)

	// имя файла
	char name[40];
	char nameEXE[40];

	// ввод имени файла
	cout << "Enter name file: ";
	cin.ignore();
	cin.getline(name, 40);

	// ввод имени .exe файла 
	cout << "Enter name EXE: ";
	cin.getline(nameEXE, 40);

	// открытие .cpp файла в режиме бинарного чтения 
	FILE* cpp = fopen(name, "rb");

	// открытие .exe файла в режиме бинарного дополнения
	FILE* exe = fopen(nameEXE, "rb");

	// если файлы успешно открыты
	if (cpp != nullptr && exe != nullptr)
	{
		// перенос указателя в файле cpp в конец
		fseek(cpp, 0, SEEK_END);

		// длина CPP файла
		long sizeCPP = ftell(cpp);

		// перенос указателя в файлем exe в конец
		fseek(exe, 0, SEEK_END);

		// длина файла cpp + exe
		long sizeEXE = ftell(exe);

		// перенос указателя в файле cpp в начало 
		fseek(cpp, 0, SEEK_SET);

		// перенос указателя в файл exe в конец
		fseek(exe, 0, SEEK_SET);

		// буфер 
		char* buffer1 = new char[sizeEXE];

		// считывание exe файла в буфер
		fread(buffer1, sizeof(char), sizeEXE, exe);

		// закрытие exe файла
		fclose(exe);

		// открытие файла exe в режими банарной записи
		exe = fopen(nameEXE, "wb");

		fwrite(buffer1, sizeof(char), sizeEXE, exe);

		delete[] buffer1;

		char* buffer2 = new char[sizeCPP];

		// запись файла cpp в буфер
		fread(buffer2, sizeof(char), sizeCPP, cpp);

		// запись буфера в конец файла exe
		fwrite(buffer2, sizeof(char), sizeCPP, exe);

		// закрытие файла
		fclose(exe);

		fclose(cpp);

		cout << "Save" << endl;
	}
	// если файлы не удалось открыть
	else cout << "File open error" << endl;
}