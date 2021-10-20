#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <io.h>
#include <conio.h>

using namespace std;

// сканивароние файлов
void scanFile(char* dir, char* mask, unsigned long* count, FILE* file)
{
	// добавка к пути "\\"
	strcat(dir, "\\");

	// указатель на начало имени в пути
	char* name = dir + strlen(dir);

	// маска для создания списка всех файлов
	strcpy(name, "*");

	// список файлов
	_finddata_t list;

	// указатель на список и создание списка
	long point = _findfirst(dir, &list);

	// если список не создан 
	if (point == -1)
	{
		cout << "ERROR CREATE LIST" << endl;
		return;
	}

	// сканирование списка
	do
	{
		// если файл имеет название "." или ".."
		if (!strcmp(list.name, ".") || !strcmp(list.name, ".."))
		{
			continue;
		}

		// добавка к пути имени файла из списка
		strcpy(name, list.name);

		// переменная для цикла
		int* i = new int;

		// вывод уровня папки
		for ( *i = 0; *i < *(count + 5); ++*i)
		{
			cout << "|";
		}

		// отчистка памяти
		delete i;

		// вывод имени файла
		cout << list.name << "     ";

		// если файл является папкой
		if (list.attrib & _A_SUBDIR)
		{
			// вывод атрибута файла
			cout << "<DIR>" << endl;

			// увеличение счётчика количества папок
			++*count;

			// увеличение уровня папки
			++* (count + 5);

			// вызов этой же функции
			scanFile(dir, mask, count, file);

			// уменьшение уровня папки
			--* (count + 5);

			continue;
		}

		// если файл является обычным файлом
		else
		{
			// вывод размера файла
			cout << list.size << endl;

			// увеличение счётчика всех файлов 
			++*(count + 1);

			// прибавление размера файла из списка к общему размеру всех файлов
			*(count + 2) += list.size;
		}
	} while (!_findnext(point, &list));

	// удаление списка
	_findclose(point);

	// прибавление маски к пути
	strcpy(name, mask);

	// заполнение списка 
	point = _findfirst(dir, &list);

	// если не удалось создать список
	if (point == -1)
	{
		return;
	}

	// сканирование списка 
	do
	{
		// если файл является папкой
		if (list.attrib & _A_SUBDIR)
		{
			continue;
		}

		// вставка имени файла в путь
		strcpy(name, list.name);

		// увеличение счётчика найденных файлов по маске
		++* (count + 3);

		// прибавление размера файла из списка к общему размеру файлов по маске
		*(count + 4) += list.size;

		// ввод в файл имени текущего файла
		fprintf(file, "Path: %s\n", dir);
		// ввод в файл имени файла 
		fprintf(file, "Name: %s\n", list.name);
		// ввод в файл размера файла
		fprintf(file, "Size: %ld\n\n", list.size);
	} while (!_findnext(point, &list));

	// удаление списка 
	_findclose(point);
}

void task4()
{
	// 4. Пользователь вводит название исходной папки и маску файлов.
	// Программа ищет файлы по маске в папке и подпапках и результат
	// поиска записывает в файл результатов find_results.txt

	// путь к папке
	char* dir = new char[_MAX_PATH];

	// ввод пути к папке
	cout << "Enter folder path: ";
	cin.ignore();
	cin.getline(dir, _MAX_PATH);

	cout << endl;

	// маска файлов 
	char* mask = new char[_MAX_FNAME];

	// ввод маски файлов
	cout << "Enter mask: ";
	cin.getline(mask, _MAX_FNAME);

	// путь для сохранения результирующего файла
	char* dir_res = new char[_MAX_PATH];

	// стандартный путь к файлу
	strcpy(dir_res, ".\\find_results.txt");

	// запрос на то нужно ли вводить путь для сохранения
	// результирующего файла или сохранить по текущему пути
	cout << "To enter the path to save the resulting file or save to the current path?(Y/N): ";

	// переменная для содержания ответа
	char* answer = new char[2];

	*(answer + 1) = 0;

	// цикл ввода ответа 
	while (true)
	{
		*answer = _getch();

		// если ответ корректен 
		if (!strcmp(answer, "Y") || !strcmp(answer, "y") || !strcmp(answer, "N") || !strcmp(answer, "n"))
		{
			// успешность создание и открытие файла
			bool successfully = true;

			while (true)
			{
				// если ответ да или не удаётся создать файл с по прошлому пути
				if (!strcmp(answer, "Y") || !strcmp(answer, "y") || !successfully)
				{
					cout << endl;

					// ввод нового пути
					cout << "Enter the path to save the resulting file: ";
					cin.getline(dir_res, _MAX_PATH);

					// добавка к пути имени файла
					strcat(dir_res, "\\find_result.txt");

					cout << endl;
				}

				// если ответ нет
				else if (!strcmp(answer, "N") || !strcmp(answer, "n"))
				{
					cout << endl;
				}

				// создание и открытие файла результата в режиме записи
				FILE* file = fopen(dir_res, "wb");

				// если создан и открыт неуспешно 
				if (file == nullptr)
				{
					cout << "ERROR FILE CREATE!" << endl;

					// показатель успешности создания
					successfully = false;

					continue;
				}

				// ожидание нажатия любой клавиши для начала сканирования
				cout << "\n\n\n\n\nPESS ANY KEY TO START SCAN...";

				// нажатие клавиши
				_getch();

				// отчистка консоли
				system("cls");

				// счётчики: [0] - количество всех подпапок; [1] - количество всех файлов; [2] - размер всех файлов;
				// [3] - количество файлов по маске; [4] - размер файлов по маске; [5] - уровень папки;
				unsigned long* count = new unsigned long[5];

				// [0] - количество всех подпапок
				*count = 0;
				// [1] - количество всех файлов 
				*(count + 1) = 0;
				// [2] - размер всех файлов
				*(count + 2) = 0;
				// [3] - количество файлов по маске
				*(count + 3) = 0;
				// [4] - размер файлов по маске
				*(count + 4) = 0;
				// [5] - уровень папки
				*(count + 5) = 0;

				// запуск функции
				scanFile(dir, mask, count, file);
				
				// закрытие файла
				fclose(file);

				cout << "\n\n\n\n\nFile save..." << endl;

				// ожидание нажатия любой клавиши для вывода отчёта
				cout << "\n\nPRESS ANY KEY TO OUTPUT REPORT...";
				
				// нажатие любой клавиши
				_getch();

				// отчистка консоли
				system("cls");

				// вывод отчёта
				cout << "          Report          " << endl;
				// количество папок
				cout << "> Count subdir: " << *count << endl << endl;
				// количество всех файл 
				cout << "> Count all files: " << *(count + 1) << endl;
				// размер всех файлов
				cout << "> Size all files: " << *(count + 2) << endl << endl;
				// количество файлов по маске
				cout << "> Count mask files: " << *(count + 3) << endl;
				// размер файлов по маске
				cout << "> Size mask files: " << *(count + 4) << endl << endl;

				// ожидение нажатия любой клавиши для выхода из программы
				cout << "\n\n\n\n\nPRESS ANY KEY TO EXIT...";

				// нажатие любой клавиши
				_getch();

				break;
			}
			break;
		}
	}

	// отчистка памяти
	delete[] dir, mask, dir_res, answer;
}