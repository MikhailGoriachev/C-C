#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

void task2()
{
	// соединение частей в файл

	char name[40];

	int quan = 0;

	// ввод количества частей 
	cout << "Enter the number of files: ";
	cin >> quan;

	// ввод имени файла для сохранения
	cout << "Enter the filename to save: ";
	cin.ignore();
	cin.getline(name, 40);

	cout << endl;

	FILE* file = fopen(name, "wb");

	for (size_t i = 0; i < quan; i++)
	{
		cout << "Enter name file: " << i + 1 << " : ";
		cin.getline(name, 40);

		FILE* part = fopen(name, "rb");

		if (part != nullptr)
		{
			fseek(file, 0, SEEK_END);

			long size = ftell(part);

			char* buff = new char[size];

			fread(buff, sizeof(char), size, part);

			fwrite(buff, sizeof(char), size, file);

			delete[] buff;

			fclose(part);
		}
	}

	fclose(file);
}