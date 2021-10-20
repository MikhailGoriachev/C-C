#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

// функция записи части файла 
int creatPart(char buff[], long size, int num, int len, char name[]);

void task1()
{
	// пользователь указывает количество частей на которые нужно разделить файл

	// имя исходного файла
	char name[40];

	// ввод имени файла
	cout << "Enter name file: ";
	cin.ignore();
	cin.getline(name, 40);

	cout << endl;

	int count = 0;

	// ввод количества частей
	cout << "Enter the number of part: ";
	cin >> count;

	cout << endl;

	// имена файлов 
	char exp[40];
	// открытие исходного файла в режиме бинарного чтения 
	FILE* file = fopen(name, "rb");

	// отделение имени файла от расширения
	for (int i = strlen(name) - 1; i >= 0; i--)
	{
		if (name[i] == '.')
		{
			name[i + 1] = 'p';
			name[i + 2] = 'a';
			name[i + 3] = 'r';
			name[i + 4] = 't';
			name[i + 5] = ' ';
			name[i + 6] = 0;
			break;
		}
	}


	// если файл успешно открыт
	if (file != nullptr)
	{
		// установка указателя в конец
		fseek(file, 0, SEEK_END);

		// длина исходного файла
		long size = ftell(file);

		if (size < count)
		{
			cout << "The file is too small" << endl;
			cout << "Exit" << endl;
			fclose(file);
			return;
		}

		// возвращение указателя в начало файла
		fseek(file, 0, SEEK_SET);

		// длина одной части
		long sizePart = size / count;

		// длина имени
		int len = strlen(name);

		// цикл разделения частей
		for (size_t i = 0, num = 1; i < count; i++, num++)
		{
			if (i < count - 1)
			{
				size -= sizePart;
			}
			else sizePart = size;

			// буфер для части файла
			char* buffer = new char[sizePart];
			
			fread(buffer, sizeof(char), sizePart, file);

			int flag = creatPart(buffer, sizePart, num, len, name);

			if (!flag)
			{
				cout << "Exit" << endl;
				return;
			}

			delete[] buffer;
		}

		// закрытие исходного файла
		fclose(file);
	}
	// если файл не открыт
	else cout << "NOT found file" << endl;
}

int creatPart(char buff[], long size, int num, int len, char name[])
{
	// создание файла части
	char* Pnum = &name[len-1];

	char temp[40];

	_itoa(num, temp, 10);

	int len_temp = strlen(temp);

	Pnum[len_temp] = 0;

	strcpy(Pnum, temp);

	// открытие файла части
	FILE* file = fopen(name, "w");

	if (file != nullptr)
	{
		fwrite(buff, sizeof(char), size, file);

		fclose(file);

		return 1;
	}
	else
	{
		cout << "File NOT found" << endl;
		return 0;
	}
}