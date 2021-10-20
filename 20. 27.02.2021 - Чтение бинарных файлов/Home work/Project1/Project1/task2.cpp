#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

// функция записи части файла 
int creatPart(char buff[], long size, int num, int len, char name[]);

void task2()
{
	// 2. Пользователь вводит имя файла, программа делит его на 
	// N равных частей(последняя часть может быть меньше)
	// и записывает их с расширениями.part1, .part2, ...

	// имя исходного файла
	char name[40];

	// ввод имени файла
	cout << "Enter name file: ";
	cin.ignore();
	cin.getline(name, 40);

	cout << endl;

	// количество частей
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

		// если количество байт в исходном файле меньше количества частей
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
		long sizePart;

		// если есть остаток от деления длины файла на количество частей
		if (size % count > 0)
		{
			// если количество - 1 * 2 меньше длины файла, то мы округляем размер на один
			if ((count - 1) * 2 < size)
				sizePart = (size / count) + 1;
			// если файл маленький
			else
			{
				cout << "The file is too small" << endl;
				cout << "Exit" << endl;
				fclose(file);
				return;
			}
		}
		else sizePart = size / count;

		// длина имени
		int len = strlen(name);

		// цикл разделения частей
		for (size_t i = 0, num = 1; i < count; i++, num++)
		{
			// вычисление длины части
			if (i < count - 1)
			{
				size -= sizePart;
			}
			else sizePart = size;

			// буфер для части файла
			char* buffer = new char[sizePart];

			// считываение из исходного файла определенного количества байт для части в буфер
			fread(buffer, sizeof(char), sizePart, file);

			// функция создания и заполнения файла возвращает: 1 - удачно, 0 - неудачно
			int flag = creatPart(buffer, sizePart, num, len, name);

			// если файл части небыл создан
			if (!flag)
			{
				cout << "Exit" << endl;

				// выход
				return;
			}

			// удаление буфера
			delete[] buffer;
		}

		cout << endl;

		// закрытие исходного файла
		fclose(file);
	}
	// если файл не открыт
	else cout << "NOT found file" << endl;

}

int creatPart(char buff[], long size, int num, int len, char name[])
{
	// указатель на начало цифры в расширении части
	char* Pnum = &name[len - 1];

	// строка для временного хранения цифры
	char temp[40];

	// преобразование номера файла части в строку
	_itoa(num, temp, 10);

	// длина строки с цифрой
	int len_temp = strlen(temp);

	// в окончание имени добавляется 0
	Pnum[len_temp] = 0;

	// вставка номера части в расширение файла
	strcpy(Pnum, temp);

	// открытие файла части
	FILE* file = fopen(name, "wb");

	// если файл удалось открыть
	if (file != nullptr)
	{
		// заполнение файла части буфером
		fwrite(buff, sizeof(char), size, file);

		// закрытие файла части
		fclose(file);

		cout << "Save " << name << endl;

		// функция возвращает один при успешном выполнении
		return 1;
	}
	else
	{
		cout << "File NOT found" << endl;

		// функция возарашает ноль при неудачном открытии файла части
		return 0;
	}
}