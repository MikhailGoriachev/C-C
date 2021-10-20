#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <conio.h>
#include <io.h>

using namespace std;

struct count_t
{
	unsigned int countCPP;
	unsigned int countH;
	unsigned long countCymbol;
	unsigned long countLine;
};

// ожидание нажатия любой клавиши 
void pressAnyKey()
{
	cout << "\n\n\nPRESS ANY KEY [..]" << endl;

	_getch();
}


// вывод линии
void outline()
{
	cout << "\n---------------------------------------------------------------------------\n\n";
}

// показатель расширения .cpp, .h
bool expr(char* name, count_t* count)
{
	for (char* n = name + strlen(name); n > name; n--)
	{
		if (*n == '.')
		{
			if (!strcmp(n, ".cpp"))
			{
				count->countCPP++;

				return true;
			}

			else if (!strcmp(n, ".h"))
			{
				count->countH++;

				return true;
			}

			return false;
		}
	}

	return false;
}

void counter(char* path, count_t* count)
{
	// добавление маски к пути
	strcat(path, "\\");

	// указатель на начало имени файла в пути
	char* name = path + strlen(path);

	// добавление маски для создания списка 
	strcpy(name, "*");

	// список файлов
	_finddata_t list;

	// указатель на список и создание его
	long pointer = _findfirst(path, &list);

	if (pointer == -1)
	{
		cout << "ERROR CREATE LIST!" << endl;

		pressAnyKey();

		return;
	}

	// сканирование списка
	do
	{
		// если это файлы с названием "." или ".."
		if (!strcmp(list.name, ".") || !strcmp(list.name, ".."))
		{
			continue;
		}

		// добавление имени файла к пути
		strcpy(name, list.name);

		// если это папка
		if (list.attrib & _A_SUBDIR)
		{
			// запуск рекурсивной функции
			counter(path, count);

			continue;
		}

		// если это файл
		if (expr(name, count))
		{
			cout << list.name << "     ";

			// открытие файла в режиме чтения
			FILE* file = fopen(path, "r");

			// если файл успешно открыт
			if (file != nullptr)
			{
				// размер файла
				cout << list.size << endl;

				// буфер для файла
				char* buffer = new char[list.size + 1];

				// считывание файла
				fread(buffer, sizeof(char), list.size, file);

				long size = list.size;

				for (char* b = buffer; b < buffer + size; b++)
				{
					if (*b == '\n')
					{
						count->countLine++;

						size--;
					}
					else count->countCymbol++;
				}

				count->countLine++;
				// считывание файла
			/*	while (!feof(file))
				{
					// считывание строки
					fgets(buffer, list.size + 1, file);

//					if (strcmp(buffer, ""))
		//			{
						// увеличение счётчика строк
						count->countLine++;

						// увеличение счётчика символов
						count->countCymbol += strlen(buffer);
//					}
					// отчистка буфера
					strcpy(buffer, "");
				}*/

				// закрытие файла
				fclose(file);

				// удаление буфера
				delete[] buffer;
			}
			else cout << "ERROR" << endl;
		}

	} while (!_findnext(pointer, &list));

	// отчистка списка
	_findclose(pointer);
}

void main()
{
	// Пользователь задаёт адрес папки, программа подсчитывает 
	// сколько строк, символов во всех файлах .cpp, .h
	// в этой папке и в подпапках.

	outline();

	cout << "COUNTER" << endl;

	outline();

	// путь к папке
	char* path = new char[_MAX_PATH];

	// путь по умолчанию
	strcpy(path, ".");

	// символ ввода 
	char* c = new char;

	// выбор: вводить имя или выбрать текущий путь
	cout << "Enter path / default path(1/2): ";

	// ввод 
	while (true)
	{
		*c = _getch();

		// Enter path 1
		if (*c == '1')
		{
			cout << "1" << endl;

			// ввод пути
			cout << "Enter path: ";
			cin.getline(path, _MAX_PATH);

			break;
		}

		// Default path 2
		if (*c == '2')
		{
			cout << "2" << endl;

			break;
		}
	}

	system("cls");

	outline();

	cout << "COUNTER" << endl;

	outline();

	// структура счётчиков
	count_t* count = new count_t;

	// обнуление счётчиков
	count->countCPP = 0;
	count->countCymbol = 0;
	count->countH = 0;
	count->countLine = 0;

	// запуск фукнции счётчика
	counter(path, count);

	pressAnyKey();

	system("cls");

	outline();

	cout << "COUNTER" << endl;

	outline();

	// вывод результата
	cout << "RESULT" << endl;
	cout << "All files .cpp and .h: " << count->countCPP + count->countH << endl;
	cout << "Count .cpp files: " << count->countCPP << endl;
	cout << "Count .h files: " << count->countH << endl;

	cout << endl;

	cout << "Count lines: " << count->countLine << endl;
	cout << "Count cumbols: " << count->countCymbol << endl;

	pressAnyKey();

}