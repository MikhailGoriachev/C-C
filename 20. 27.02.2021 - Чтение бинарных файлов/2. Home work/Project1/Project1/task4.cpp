#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

// замена двойных символов на '!'
void replDoubleSymb(char a[], long* size);

void task4()
{
	// 4. Пользователь вводит имя файла, программа заменяет все 
	// двойные символы на символ '!' (длинный->дли!ый)

	// имя файла
	char name[40];

	// ввод имени файла
	cout << "Enter file name: ";
	cin.ignore();
	cin.getline(name, 40);

	cout << endl;

	// открытие файла в режиме битного чтения 
	FILE* file = fopen(name, "rb");

	// если файл открыт удачно
	if (file != nullptr)
	{
		// установка указателя в файле в конец
		fseek(file, 0, SEEK_END);

		// длина файла
		long size = ftell(file);
		long buf_size = size + 1;

		// установка указателя в файле в начало
		fseek(file, 0, SEEK_SET);

		// буфер для содержание файла
		char* buffer = new char[buf_size];

		// считывание файла в буфер
		fread(buffer, sizeof(char), size, file);

		// закрытие файла
		fclose(file);

		// обработка буфера
		replDoubleSymb(buffer, &size);

		// открытие файла в режиме бинарной записи
		file = fopen(name, "wb");

		// заполнение файла содержимым буфера
		fwrite(buffer, sizeof(char), size, file);

		// удаление буфера
		delete[] buffer;

		// закрытие файла
		fclose(file);

		cout << "Save" << endl;
	}
	// если файл не удалось открыть
	else cout << "File NOT found" << endl;
}

// замена двойных символов на '!'
void replDoubleSymb(char a[], long* size)
{
	for (size_t i = 1; i < *size; i++)
	{
		if (a[i] == a[i-1])
		{
			a[i - 1] = '!';
			for (size_t k = i; k < *size; k++)
			{
				swap(a[k], a[k + 1]);
			}

			*size -= 1;
		}
	}
}