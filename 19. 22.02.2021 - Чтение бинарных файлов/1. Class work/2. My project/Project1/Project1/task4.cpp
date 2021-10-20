#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

void task4()
{
	// программа копирует один бинарный файл в другой
	char nameFile1[40], nameFile2[40];

	cout << "Enter name file 1: ";
	cin >> nameFile1;

	cout << "Enter name file 2: ";
	cin >> nameFile2;

	FILE* sourceFile = fopen(nameFile1, "rb");
	FILE* destinationFile = fopen(nameFile2, "wb");

	if (sourceFile != nullptr && destinationFile != nullptr)
	{
		// переместить указатель в файле в самый конец
		fseek(sourceFile, 0, SEEK_END);

		// возвращает значение указателя
		long fileSize = ftell(sourceFile);

		// переместить указатель в файле в самое начало
		fseek(sourceFile, 0, SEEK_SET);

		// выделить память для хранения всех байт исходного файла
		char* buffer = new char[fileSize];

		if (buffer != nullptr)
		{
			// считать содержимое исходного файла
			fread(buffer, sizeof(char), fileSize, sourceFile);

			// считать содержимое исходного файла
			fwrite(buffer, sizeof(char), fileSize, destinationFile);

			// освободить память  из под исходного файла
			delete[] buffer;
		}

		fclose(sourceFile);
		fclose(destinationFile);
	}
	else cout << "Error opening file!!!" << endl;

}