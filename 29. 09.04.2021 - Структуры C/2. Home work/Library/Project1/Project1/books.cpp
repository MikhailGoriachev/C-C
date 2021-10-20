#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <conio.h>
#include "head.h"

using namespace std;

// загрузка данных о книгах
book_t* loadingDataBooks(int** countBooks)
{
	// открытие файла с данными о книгах в режиме бинарного чтения
	FILE* file = fopen("Library\\list.data", "rb");
	
	// если файл открыт успешно 
	if (file != nullptr)
	{
		// установка указаля в конец файла 
		fseek(file, 0, SEEK_END);

		// размер файла
		size_t* size = new size_t;

		*size = ftell(file);

		// установка указателя в начало файла
		fseek(file, 0, SEEK_END);

		// количество книг 
		*countBooks = new int;

		**countBooks = *size / 148;

		// массив структур данных книг
		book_t* books = new book_t[**countBooks];

		// считывание данных в массив структур
		for (book_t* book = books ; book < books + **countBooks; book++)
		{
			// номер книги
			fread((*book).number, sizeof(char), 20, file);

			// название книги
			fread((*book).name, sizeof(char), 40, file);

			// жанр книги
			fread((*book).genre, sizeof(char), 20, file);

			// ФИО автора
			fread((*book).FIO, sizeof(char), 60, file);

			// год выпуска
			fread(&(*book).dateCreate, sizeof(int), 1, file);

			// цена
			fread(&(*book).price, sizeof(int), 1, file);
		}

		// закрытие файла
		fclose(file);

		// отчистка памяти
		delete size;
		
	}
	// если файл не удалось открыть
	else
	{
		cout << "ERROR OPENING FILE \"list.data\"" << endl;
		return nullptr;
	}
}

// 1. Просмотр всех книг
book_t* AllBooks(int** countBooks)
{
	// количество книг
	countBooks = new int*;

	// загрузка данных о книгах
	book_t* books = loadingDataBooks(countBooks);

	// символ
	char* c = new char;

	// вывод всех книг
	for (book_t* book = books;; )
	{
		system("cls");

		outline();

		cout << "ALL BOOKS" << endl;

		outline();

		// вывод информации о книге
		
		// название книги
		cout << "Name: " << (*book).name << endl;

		// ФИО автора
		cout << "Author: " << (*book).name << endl;

		// жанр
		cout << "Genre: " << (*book).genre << endl;

		// номер книги
		cout << "Number book: " << (*book).number << endl;

		// дата выпуска
		cout << "Create date: " << (*book).dateCreate << endl;

		// цена
		cout << "Price: " << (*book).price << endl;

		// управление 
		cout << "\n\n\n\nPRESS: LAST[1] NEXT[2] QUIT[ESC]" << endl;

		// ввод 
		while (true)
		{
			// LAST[1]
			if (*c == '1')
			{
				// если это первая книга
				if (book == books)
					continue;

				book++;
			}

			// NEXT[2]
			if (*c == '2')
			{
				// если это последняя книга
				if (book == books + **countBooks)
					continue;

				book--;
			}

			// QUIT[ESC]
			if ((int)*c == 27)
			{
				delete c;

				return books;
			}
		}
	}
}

// 2. Найти книгу
void SearchBook(book_t* books, int* countBook)
{
	// данные об искомой книге 
	book_t* searchBook = new book_t;

	// заполнение данных пустыми строками
	(*searchBook).dateCreate = 0;
	(*searchBook).price = 0;
	strcpy((*searchBook).FIO, "");
	strcpy((*searchBook).genre, "");
	strcpy((*searchBook).name, "");
	strcpy((*searchBook).number, "");

	// символ
	char* c = new char;

	// поиск книги
	while (true)
	{
		// заполнение данных пустыми строками
		(*searchBook).dateCreate = 0;
		(*searchBook).price = 0;
		strcpy((*searchBook).FIO, "");
		strcpy((*searchBook).genre, "");
		strcpy((*searchBook).name, "");
		strcpy((*searchBook).number, "");

		system("cls");
		
		outline();

		cout << "SEARCH BOOK" << endl;

		outline();

		// выбор критерия поиска

		// поиск по названию
		cout << "* 1. SEARCH BY NAME BOOK *" << endl;

		// поиск по жанру
		cout << "* 2. SEARCH BY GENRE *" << endl;

		// поиск по автору
		cout << "* 3. SEARCH BY AUTHOR *" << endl;

		// поиск по году выпуска
		cout << "* 4. SEARCH BY DATE CREATE *" << endl;

		// поиск по цене
		cout << "* 5. SEARCH BY PRICE *" << endl;

		// поиск по номеру
		cout << "* 6. SEARCH BY NUMBER *" << endl;

		cout << "\n\n\n\nPRESS [1-6] QUIT[ESC]" << endl;

		// ввод
		while (true)
		{
			*c = _getch();

			// [1] SEARCH BY NAME
			if (*c == '1')
			{
				system("cls");

				outline();

				cout << "SEARCH BOOK" << endl;

				outline();

				cout << "Enter name book: ";

				cin.getline((*searchBook).name, 40);

				// вывод списка 
				system("cls");

				outline();

				cout << "LIST" << endl;

				outline();

				SearchBook(books, searchBook, countBook);

				// нажатие любой клавиши
				pressAnyKey();

			}

			// [2] SEARCH BY GENRE
			if (*c == '2')
			{
				system("cls");

				outline();

				cout << "SEARCH BOOK" << endl;

				outline();

				cout << "Enter genre: ";

				cin.getline((*searchBook).genre, 20);

				// вывод списка 
				system("cls");

				outline();

				cout << "LIST" << endl;

				outline();

				SearchBook(books, searchBook, countBook);

				// нажатие любой клавиши
				pressAnyKey();
			}

			// [3] SEARCH BY AUTHOR
			if (*c == '3')
			{
				system("cls");

				outline();

				cout << "SEARCH BOOK" << endl;

				outline();

				cout << "Enter author: ";

				cin.getline((*searchBook).FIO, 60);

				// вывод списка 
				system("cls");

				outline();

				cout << "LIST" << endl;

				outline();

				SearchBook(books, searchBook, countBook);

				// нажатие любой клавиши
				pressAnyKey();
			}

			// [4] SEARCH BY DATE CREATE
			if (*c == '4')
			{
				system("cls");

				outline();

				cout << "SEARCH BOOK" << endl;

				outline();

				cout << "Enter date create: ";

				cin >> (*searchBook).dateCreate;

				// вывод списка 
				system("cls");

				outline();

				cout << "LIST" << endl;

				outline();

				SearchBook(books, searchBook, countBook);

				// нажатие любой клавиши
				pressAnyKey();
			}

			// [5] SEARCH BY PRICE
			if (*c == '5')
			{
				system("cls");

				outline();

				cout << "SEARCH BOOK" << endl;

				outline();

				cout << "Enter price: ";

				cin >> (*searchBook).price;

				// вывод списка 
				system("cls");

				outline();

				cout << "LIST" << endl;

				outline();

				SearchBook(books, searchBook, countBook);

				// нажатие любой клавиши
				pressAnyKey();
			}

			// [6] SEARCH BY NUMBER
			if (*c == '6')
			{
				system("cls");

				outline();

				cout << "SEARCH BOOK" << endl;

				outline();

				cout << "Enter number book: ";

				cin.getline((*searchBook).number, 20);

				// вывод списка 
				system("cls");

				outline();

				cout << "LIST" << endl;

				outline();

				SearchBook(books, searchBook, countBook);

				// нажатие любой клавиши
				pressAnyKey();
			}

			// [ESC] QUIT
			if ((int)*c == 27)
			{
				system("cls");

				delete searchBook, c;

				return;
			}
		}
		
	}
}

// поиск книги
void SearchBook(book_t* books, book_t* searcBook, int* countBook)
{
	for (book_t* book = books; book < book + *countBook; book++)
	{
		// если есть совпадение
		if (!strcmp((*book).FIO, (*searcBook).FIO) || !strcmp((*book).genre, (*searcBook).genre) ||
			!strcmp((*book).name, (*searcBook).name) || !strcmp((*book).number, (*searcBook).number) ||
			(*book).dateCreate == (*searcBook).dateCreate || (*book).price == (*searcBook).price)
		{
			// название книги
			cout << "Name: " << (*book).name << endl;

			// ФИО автора
			cout << "Author: " << (*book).name << endl;

			// жанр
			cout << "Genre: " << (*book).genre << endl;

			// номер книги
			cout << "Number book: " << (*book).number << endl;

			// дата выпуска
			cout << "Create date: " << (*book).dateCreate << endl;

			// цена
			cout << "Price: " << (*book).price << endl;

			cout << endl << endl;

		}
	}
}

// 4. Добавление книги
book_t* AddBook(book_t* books, int** countBooks)
{

	// структура для новой книги
	book_t* newBook = new book_t;

	bool* flag = new bool;

	char* pathEPUB = new char[_MAX_PATH];
	char* pathPDF = new char[_MAX_PATH];

	// ввод данных о книге 
	while (true)
	{
		system("cls");

		outline();

		cout << "ADD BOOK" << endl;

		outline();

		// название книги
		cout << "Name: ";
		cin.getline((*newBook).name, 40);

		// ФИО автора
		cout << "Author: ";
		cin.getline((*newBook).FIO, 60);

		// жанр
		cout << "Genre: ";
		cin.getline((*newBook).genre, 20);

		// номер книги
		cout << "Number book: ";
		cin.getline((*newBook).number, 20);

		// дата выпуска
		cout << "Create date: ";
		cin >> (*newBook).dateCreate;

		// цена
		cout << "Price: ";
		cin >> (*newBook).price;

		cin.ignore();

		// путь к файлу книги
		cout << "Book path (EPUB): ";
		cin.getline(pathEPUB, _MAX_PATH);

		// путь к файлу книги
		cout << "Book path (PDF): ";
		cin.getline(pathPDF, _MAX_PATH);

		// проверка книги в базе данных на совпадение по номеру книги
		for (book_t * book = books; book < books + **countBooks; book++)
		{
			// если совпадают номера 
			if (!strcmp((*book).number, (*newBook).number))
			{
				cout << "BOOK WITH SUCH NUMBER EXISTS!" << endl;

				*flag = true;
			}
		}

		// если номер книги уникален
		if (!*flag)
		{
			char* pathDest = new char[_MAX_PATH];
			
			// путь к файлу для создания
			strcpy(pathDest, ".\\Library\\Books\\");
			strcat(pathDest, (*newBook).number);

			// загрузка EPUB
			CpyBook(pathEPUB, pathDest, 1);

			// загрузка PDF
			CpyBook(pathPDF, pathDest, 1);

			delete flag;
			delete[] pathDest;
			// запись информации о книге в файла о книгах
			// открытие файла данных о книгах в режиме бинарного дополнения
			FILE* file = fopen("Library\\list.data", "ab");

			// если файл удалось открыть
			if (file != nullptr)
			{
				// добавление в файл данных структуры новой книги
				// номер книги
				fwrite((*newBook).number, sizeof(char), 20, file);

				// название книги
				fwrite((*newBook).name, sizeof(char), 40, file);

				// жанр книги
				fwrite((*newBook).genre, sizeof(char), 20, file);

				// ФИО автора
				fwrite((*newBook).FIO, sizeof(char), 60, file);

				// год выпуска
				fwrite(&(*newBook).dateCreate, sizeof(int), 1, file);

				// цена
				fwrite(&(*newBook).price, sizeof(int), 1, file);

				// закрытие файла 
				fclose(file);

				cout << "Book save" << endl;

				pressAnyKey();

				// обновление базы данных
				return loadingDataBooks(countBooks);
			}
		}
	}

	delete flag;
}

// загрузка книги в папку; flag - 1 шифрование, 2 расшифарование, 3 без шифрования;
void CpyBook(char* pathSource, char* pathDestination, int flag)
{
	// открытие файла книги в режиме бинарного чтения
	FILE* file = fopen(pathSource, "rb");

	// если файл успешно открыт
	if (file != nullptr)
	{
		// установка указателя в начало исходного файла
		fseek(file, 0, SEEK_END);

		// размер исходного файла
		size_t* size = new size_t;

		*size = ftell(file);

		// буфер для исходного файла
		char* buffer = new char[*size];

		// считываение исходного файла в буфер
		fread(buffer, sizeof(char), *size, file);

		// закрытие исходного файла
		fclose(file);

		if (flag == 1)
			// шифрование буфера
			Crypt(buffer, *size);
		else if (flag == 2)
			// дешифрование буфера
			deCrypt(buffer, *size);

		// расширение исходного файла
		char* expr = new char[10];

		// поиск расширения в пути к файлу
		for (char* p = pathSource + strlen(pathSource); p > pathSource; p--)
		{
			// если найдена точка 
			if (*p == '.')
			{
				// копирование расширения файла
				strcpy(expr, p);

				break;
			}
		}

		// добавление расширения
		strcat(pathDestination, expr);

		delete[] expr;

		// создание файла и открытие в режиме бинарной записи
		file = fopen(pathSource, "wb");

		// если файл открыт успешно
		if (file != nullptr)
		{
			// запись буфера в файл
			fwrite(buffer, sizeof(char), *size, file);

			// закрытие файла
			fclose(file);


			delete[] buffer, pathSource;
			delete size;
			return;
		}
		else
		{
			cout << "FILE BOOK CREATE ERROR!" << endl;

			delete[] buffer, pathSource;
			delete size;

			pressAnyKey();

			return;
		}
	}
	else
	{
		cout << "FILE BOOK NOT FOUND!" << endl;

		delete[] pathSource;

		pressAnyKey();

		return;
	}

}

// 3. Загрузка книги
void DownloadBook(book_t* books, int** countBooks)
{
	char* searchBook = new char[40];

	// символ
	int* c = new int;

	char* pathSource = new char[_MAX_PATH];
	char* pathDestination = new char[_MAX_PATH];


	// ввод номера книги или имени
	while (true)
	{
		system("cls");

		outline();

		cout << "DOWNLOAD BOOK" << endl;

		outline();

		// ввод номера книги или названия
		cout << "Enter number or name book: ";
		cin.getline(searchBook, 40);


		// поиск книги в базе 
		for (book_t* book = books; book < books + **countBooks; book++)
		{
			// если есть совпадения
			if (!strcmp((*book).number, searchBook))
			{
				// название книги
				cout << "Name: " << (*book).name << endl;

				// ФИО автора
				cout << "Author: " << (*book).name << endl;

				// жанр
				cout << "Genre: " << (*book).genre << endl;

				// номер книги
				cout << "Number book: " << (*book).number << endl;

				// дата выпуска
				cout << "Create date: " << (*book).dateCreate << endl;

				// цена
				cout << "Price: " << (*book).price << endl;

				cout << "\n\n\n\n\nPRESS: EPUB[1] PDF[2] CANCEL[ECS]" << endl;

				// ввод  
				while (true)
				{
					*c = (int)_getch();

					// EPUB[1]
					if (*c == (int)'1')
					{
						system("cls");

						outline();

						cout << "DOWNLOAD BOOK" << endl;

						outline();

						// ввод пути для сохранения файла
						cout << "Path save: ";
						cin.getline(pathDestination, _MAX_PATH);

						// путь ресурса
						strcpy(pathSource, ".\\Library\\Books\\");
						strcat(pathSource, (*book).number);
						strcat(pathSource, ".epub");

						// путь сохранения
						strcat(pathDestination, "\\");
						strcat(pathDestination, (*book).name);

						// загрузка файла
						CpyBook(pathSource, pathDestination, 2);

						pressAnyKey();

						delete[] pathDestination, pathSource;

						delete c;

						return;
					}

					// PDF[2]
					if (*c == (int)'2')
					{
						system("cls");

						outline();

						cout << "DOWNLOAD BOOK" << endl;

						outline();

						// ввод пути для сохранения файла
						cout << "Path save: ";
						cin.getline(pathDestination, _MAX_PATH);

						// путь ресурса
						strcpy(pathSource, ".\\Library\\Books\\");
						strcat(pathSource, (*book).number);
						strcat(pathSource, ".pdf");

						// путь сохранения
						strcat(pathDestination, "\\");
						strcat(pathDestination, (*book).name);

						// загрузка файла
						CpyBook(pathSource, pathDestination, 2);

						pressAnyKey();

						delete[] pathDestination, pathSource;

						delete c;

						return;
					}

					// CANCEL[ECS]
					if (*c == 27)
					{
						return;
					}
				}
			}
		}

		cout << "Book not found!" << endl;

		cout << "\n\n\n\n\nPRESS: RE-ENTER[ANY KEY] QUIT[ECS]" << endl;

		// ввод
		*c = (int)_getch();

		if (*c == 27)
		{
			delete[] pathDestination, pathSource;

			delete c;

			return;
		}
	}
}

// тихая загрузка книги
void DownloadBook(book_t* book)
{
	// символ
	int* c = new int;

	char* pathSource = new char[_MAX_PATH];
	char* pathDestination = new char[_MAX_PATH];

	system("cls");

	outline();

	cout << "DOWNLOAD BOOK" << endl;

	outline();

	// название книги
	cout << "Name: " << (*book).name << endl;

	// ФИО автора
	cout << "Author: " << (*book).name << endl;

	// жанр
	cout << "Genre: " << (*book).genre << endl;

	// номер книги
	cout << "Number book: " << (*book).number << endl;

	// дата выпуска
	cout << "Create date: " << (*book).dateCreate << endl;

	// цена
	cout << "Price: " << (*book).price << endl;

	cout << "\n\n\n\n\nPRESS: EPUB[1] PDF[2] CANCEL[ECS]" << endl;
	// ввод  
	while (true)
	{
		*c = (int)_getch();

		// EPUB[1]
		if (*c == (int)'1')
		{
			system("cls");

			outline();

			cout << "DOWNLOAD BOOK" << endl;

			outline();

			// ввод пути для сохранения файла
			cout << "Path save: ";
			cin.getline(pathDestination, _MAX_PATH);

			// путь ресурса
			strcpy(pathSource, ".\\Library\\Books\\");
			strcat(pathSource, (*book).number);
			strcat(pathSource, ".epub");

			// путь сохранения
			strcat(pathDestination, "\\");
			strcat(pathDestination, (*book).name);

			// загрузка файла
			CpyBook(pathSource, pathDestination, 2);

			pressAnyKey();

			delete[] pathDestination, pathSource;

			delete c;

			return;
		}

		// PDF[2]
		if (*c == (int)'2')
		{
			system("cls");

			outline();

			cout << "DOWNLOAD BOOK" << endl;

			outline();

			// ввод пути для сохранения файла
			cout << "Path save: ";
			cin.getline(pathDestination, _MAX_PATH);

			// путь ресурса
			strcpy(pathSource, ".\\Library\\Books\\");
			strcat(pathSource, (*book).number);
			strcat(pathSource, ".pdf");

			// путь сохранения
			strcat(pathDestination, "\\");
			strcat(pathDestination, (*book).name);

			// загрузка файла
			CpyBook(pathSource, pathDestination, 2);

			pressAnyKey();

			delete[] pathDestination, pathSource;

			delete c;

			return;
		}

		// CANCEL[ECS]
		if (*c == 27)
		{
			return;
		}
	}
}

// 5. Удаление книги 
book_t* DeleteBook(book_t* books, int** countBooks)
{
	// номер книги 
	char* number = new char[20];

	// путь к файлу
	char* path = new char[_MAX_PATH];

	int* c = new int;

	// ввод номера
	while (true)
	{
		system("cls");

		outline();

		cout << "DELETE BOOK" << endl;

		outline();

		cout << "Enter number book: ";

		cin.getline(number, 20);

		// удаление файлов книг
		for (book_t* book_p = books; book_p < books + **countBooks; book_p++)
		{
			// если номер книги совпал 
			if (!strcmp(number, (*book_p).number))
			{
				// путь к файлу
				strcpy(path, ".\\Library\\Books\\");

				strcat(path, (*book_p).number);

				// указатель на начало расширения
				char* expr = &path[strlen(path)];

				strcpy(expr, ".epub");

				// удаление файла epub
				remove(path);

				strcpy(expr, ".pdf");

				// удаление файла pdf
				remove(path);

				// запись информации о книге в файла о книгах
				// открытие файла данных о книгах в режиме бинарной записи
				FILE* file = fopen("Library\\list.data", "wb");

				// если файл удалось открыть
				if (file != nullptr)
				{
					// удаление информации о книге
					for (book_t* book = books; book < books + **countBooks; book++)
					{
						// если номер книги совпал 
						if (!strcmp(number, (*book).number))
						{
							continue;
						}
						// добавление в файл данных структуры новой книги
						// номер книги
						fwrite((*book).number, sizeof(char), 20, file);

						// название книги
						fwrite((*book).name, sizeof(char), 40, file);

						// жанр книги
						fwrite((*book).genre, sizeof(char), 20, file);

						// ФИО автора
						fwrite((*book).FIO, sizeof(char), 60, file);

						// год выпуска
						fwrite(&(*book).dateCreate, sizeof(int), 1, file);

						// цена
						fwrite(&(*book).price, sizeof(int), 1, file);
					}

					// закрытие файла 
					fclose(file);

					cout << "FILE DELETE COMPLETE!" << endl;

					return loadingDataBooks(countBooks);
				}
			}
		}

		cout << "Book not found!" << endl;

		cout << "\n\n\n\n\nPRESS: RE-ENTER[ANY KEY] QUIT[ECS]" << endl;

		// ввод
		*c = (int)_getch();

		if (*c == 27)
		{
			delete[] number, path;

			delete c;

			return books;
		}
	}
}

// тихое удаление 
book_t* DeleteBook(book_t* books, book_t book_p, int** countBooks)
{
	// путь к файлу
	char* path = new char[_MAX_PATH];

	system("cls");

	outline();

	cout << "DELETE BOOK" << endl;

	outline();

	// путь к файлу
	strcpy(path, ".\\Library\\Books\\");

	strcat(path, (book_p).number);

	// указатель на начало расширения
	char* expr = &path[strlen(path)];

	strcpy(expr, ".epub");

	// удаление файла epub
	remove(path);

	strcpy(expr, ".pdf");

	// удаление файла pdf
	remove(path);

	// запись информации о книге в файла о книгах
	// открытие файла данных о книгах в режиме бинарной записи
	FILE* file = fopen("Library\\list.data", "wb");

	// если файл удалось открыть
	if (file != nullptr)
	{
		// удаление информации о книге
		for (book_t* book = books; book < books + **countBooks; book++)
		{
			// если номер книги совпал 
			if (!strcmp((*book).number, (book_p).number))
			{
				continue;
			}
			// добавление в файл данных структуры новой книги
			// номер книги
			fwrite((*book).number, sizeof(char), 20, file);

			// название книги
			fwrite((*book).name, sizeof(char), 40, file);

			// жанр книги
			fwrite((*book).genre, sizeof(char), 20, file);

			// ФИО автора
			fwrite((*book).FIO, sizeof(char), 60, file);

			// год выпуска
			fwrite(&(*book).dateCreate, sizeof(int), 1, file);

			// цена
			fwrite(&(*book).price, sizeof(int), 1, file);
		}

		// закрытие файла 
		fclose(file);

		cout << "FILE DELETE COMPLETE!" << endl;

		return loadingDataBooks(countBooks);
	}
}