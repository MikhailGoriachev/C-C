#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <conio.h>
#include "head.h"

using namespace std;

// �������� ������ � ������
book_t* loadingDataBooks(int** countBooks)
{
	// �������� ����� � ������� � ������ � ������ ��������� ������
	FILE* file = fopen("Library\\list.data", "rb");
	
	// ���� ���� ������ ������� 
	if (file != nullptr)
	{
		// ��������� ������� � ����� ����� 
		fseek(file, 0, SEEK_END);

		// ������ �����
		size_t* size = new size_t;

		*size = ftell(file);

		// ��������� ��������� � ������ �����
		fseek(file, 0, SEEK_END);

		// ���������� ���� 
		*countBooks = new int;

		**countBooks = *size / 148;

		// ������ �������� ������ ����
		book_t* books = new book_t[**countBooks];

		// ���������� ������ � ������ ��������
		for (book_t* book = books ; book < books + **countBooks; book++)
		{
			// ����� �����
			fread((*book).number, sizeof(char), 20, file);

			// �������� �����
			fread((*book).name, sizeof(char), 40, file);

			// ���� �����
			fread((*book).genre, sizeof(char), 20, file);

			// ��� ������
			fread((*book).FIO, sizeof(char), 60, file);

			// ��� �������
			fread(&(*book).dateCreate, sizeof(int), 1, file);

			// ����
			fread(&(*book).price, sizeof(int), 1, file);
		}

		// �������� �����
		fclose(file);

		// �������� ������
		delete size;
		
	}
	// ���� ���� �� ������� �������
	else
	{
		cout << "ERROR OPENING FILE \"list.data\"" << endl;
		return nullptr;
	}
}

// 1. �������� ���� ����
book_t* AllBooks(int** countBooks)
{
	// ���������� ����
	countBooks = new int*;

	// �������� ������ � ������
	book_t* books = loadingDataBooks(countBooks);

	// ������
	char* c = new char;

	// ����� ���� ����
	for (book_t* book = books;; )
	{
		system("cls");

		outline();

		cout << "ALL BOOKS" << endl;

		outline();

		// ����� ���������� � �����
		
		// �������� �����
		cout << "Name: " << (*book).name << endl;

		// ��� ������
		cout << "Author: " << (*book).name << endl;

		// ����
		cout << "Genre: " << (*book).genre << endl;

		// ����� �����
		cout << "Number book: " << (*book).number << endl;

		// ���� �������
		cout << "Create date: " << (*book).dateCreate << endl;

		// ����
		cout << "Price: " << (*book).price << endl;

		// ���������� 
		cout << "\n\n\n\nPRESS: LAST[1] NEXT[2] QUIT[ESC]" << endl;

		// ���� 
		while (true)
		{
			// LAST[1]
			if (*c == '1')
			{
				// ���� ��� ������ �����
				if (book == books)
					continue;

				book++;
			}

			// NEXT[2]
			if (*c == '2')
			{
				// ���� ��� ��������� �����
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

// 2. ����� �����
void SearchBook(book_t* books, int* countBook)
{
	// ������ �� ������� ����� 
	book_t* searchBook = new book_t;

	// ���������� ������ ������� ��������
	(*searchBook).dateCreate = 0;
	(*searchBook).price = 0;
	strcpy((*searchBook).FIO, "");
	strcpy((*searchBook).genre, "");
	strcpy((*searchBook).name, "");
	strcpy((*searchBook).number, "");

	// ������
	char* c = new char;

	// ����� �����
	while (true)
	{
		// ���������� ������ ������� ��������
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

		// ����� �������� ������

		// ����� �� ��������
		cout << "* 1. SEARCH BY NAME BOOK *" << endl;

		// ����� �� �����
		cout << "* 2. SEARCH BY GENRE *" << endl;

		// ����� �� ������
		cout << "* 3. SEARCH BY AUTHOR *" << endl;

		// ����� �� ���� �������
		cout << "* 4. SEARCH BY DATE CREATE *" << endl;

		// ����� �� ����
		cout << "* 5. SEARCH BY PRICE *" << endl;

		// ����� �� ������
		cout << "* 6. SEARCH BY NUMBER *" << endl;

		cout << "\n\n\n\nPRESS [1-6] QUIT[ESC]" << endl;

		// ����
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

				// ����� ������ 
				system("cls");

				outline();

				cout << "LIST" << endl;

				outline();

				SearchBook(books, searchBook, countBook);

				// ������� ����� �������
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

				// ����� ������ 
				system("cls");

				outline();

				cout << "LIST" << endl;

				outline();

				SearchBook(books, searchBook, countBook);

				// ������� ����� �������
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

				// ����� ������ 
				system("cls");

				outline();

				cout << "LIST" << endl;

				outline();

				SearchBook(books, searchBook, countBook);

				// ������� ����� �������
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

				// ����� ������ 
				system("cls");

				outline();

				cout << "LIST" << endl;

				outline();

				SearchBook(books, searchBook, countBook);

				// ������� ����� �������
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

				// ����� ������ 
				system("cls");

				outline();

				cout << "LIST" << endl;

				outline();

				SearchBook(books, searchBook, countBook);

				// ������� ����� �������
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

				// ����� ������ 
				system("cls");

				outline();

				cout << "LIST" << endl;

				outline();

				SearchBook(books, searchBook, countBook);

				// ������� ����� �������
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

// ����� �����
void SearchBook(book_t* books, book_t* searcBook, int* countBook)
{
	for (book_t* book = books; book < book + *countBook; book++)
	{
		// ���� ���� ����������
		if (!strcmp((*book).FIO, (*searcBook).FIO) || !strcmp((*book).genre, (*searcBook).genre) ||
			!strcmp((*book).name, (*searcBook).name) || !strcmp((*book).number, (*searcBook).number) ||
			(*book).dateCreate == (*searcBook).dateCreate || (*book).price == (*searcBook).price)
		{
			// �������� �����
			cout << "Name: " << (*book).name << endl;

			// ��� ������
			cout << "Author: " << (*book).name << endl;

			// ����
			cout << "Genre: " << (*book).genre << endl;

			// ����� �����
			cout << "Number book: " << (*book).number << endl;

			// ���� �������
			cout << "Create date: " << (*book).dateCreate << endl;

			// ����
			cout << "Price: " << (*book).price << endl;

			cout << endl << endl;

		}
	}
}

// 4. ���������� �����
book_t* AddBook(book_t* books, int** countBooks)
{

	// ��������� ��� ����� �����
	book_t* newBook = new book_t;

	bool* flag = new bool;

	char* pathEPUB = new char[_MAX_PATH];
	char* pathPDF = new char[_MAX_PATH];

	// ���� ������ � ����� 
	while (true)
	{
		system("cls");

		outline();

		cout << "ADD BOOK" << endl;

		outline();

		// �������� �����
		cout << "Name: ";
		cin.getline((*newBook).name, 40);

		// ��� ������
		cout << "Author: ";
		cin.getline((*newBook).FIO, 60);

		// ����
		cout << "Genre: ";
		cin.getline((*newBook).genre, 20);

		// ����� �����
		cout << "Number book: ";
		cin.getline((*newBook).number, 20);

		// ���� �������
		cout << "Create date: ";
		cin >> (*newBook).dateCreate;

		// ����
		cout << "Price: ";
		cin >> (*newBook).price;

		cin.ignore();

		// ���� � ����� �����
		cout << "Book path (EPUB): ";
		cin.getline(pathEPUB, _MAX_PATH);

		// ���� � ����� �����
		cout << "Book path (PDF): ";
		cin.getline(pathPDF, _MAX_PATH);

		// �������� ����� � ���� ������ �� ���������� �� ������ �����
		for (book_t * book = books; book < books + **countBooks; book++)
		{
			// ���� ��������� ������ 
			if (!strcmp((*book).number, (*newBook).number))
			{
				cout << "BOOK WITH SUCH NUMBER EXISTS!" << endl;

				*flag = true;
			}
		}

		// ���� ����� ����� ��������
		if (!*flag)
		{
			char* pathDest = new char[_MAX_PATH];
			
			// ���� � ����� ��� ��������
			strcpy(pathDest, ".\\Library\\Books\\");
			strcat(pathDest, (*newBook).number);

			// �������� EPUB
			CpyBook(pathEPUB, pathDest, 1);

			// �������� PDF
			CpyBook(pathPDF, pathDest, 1);

			delete flag;
			delete[] pathDest;
			// ������ ���������� � ����� � ����� � ������
			// �������� ����� ������ � ������ � ������ ��������� ����������
			FILE* file = fopen("Library\\list.data", "ab");

			// ���� ���� ������� �������
			if (file != nullptr)
			{
				// ���������� � ���� ������ ��������� ����� �����
				// ����� �����
				fwrite((*newBook).number, sizeof(char), 20, file);

				// �������� �����
				fwrite((*newBook).name, sizeof(char), 40, file);

				// ���� �����
				fwrite((*newBook).genre, sizeof(char), 20, file);

				// ��� ������
				fwrite((*newBook).FIO, sizeof(char), 60, file);

				// ��� �������
				fwrite(&(*newBook).dateCreate, sizeof(int), 1, file);

				// ����
				fwrite(&(*newBook).price, sizeof(int), 1, file);

				// �������� ����� 
				fclose(file);

				cout << "Book save" << endl;

				pressAnyKey();

				// ���������� ���� ������
				return loadingDataBooks(countBooks);
			}
		}
	}

	delete flag;
}

// �������� ����� � �����; flag - 1 ����������, 2 ��������������, 3 ��� ����������;
void CpyBook(char* pathSource, char* pathDestination, int flag)
{
	// �������� ����� ����� � ������ ��������� ������
	FILE* file = fopen(pathSource, "rb");

	// ���� ���� ������� ������
	if (file != nullptr)
	{
		// ��������� ��������� � ������ ��������� �����
		fseek(file, 0, SEEK_END);

		// ������ ��������� �����
		size_t* size = new size_t;

		*size = ftell(file);

		// ����� ��� ��������� �����
		char* buffer = new char[*size];

		// ����������� ��������� ����� � �����
		fread(buffer, sizeof(char), *size, file);

		// �������� ��������� �����
		fclose(file);

		if (flag == 1)
			// ���������� ������
			Crypt(buffer, *size);
		else if (flag == 2)
			// ������������ ������
			deCrypt(buffer, *size);

		// ���������� ��������� �����
		char* expr = new char[10];

		// ����� ���������� � ���� � �����
		for (char* p = pathSource + strlen(pathSource); p > pathSource; p--)
		{
			// ���� ������� ����� 
			if (*p == '.')
			{
				// ����������� ���������� �����
				strcpy(expr, p);

				break;
			}
		}

		// ���������� ����������
		strcat(pathDestination, expr);

		delete[] expr;

		// �������� ����� � �������� � ������ �������� ������
		file = fopen(pathSource, "wb");

		// ���� ���� ������ �������
		if (file != nullptr)
		{
			// ������ ������ � ����
			fwrite(buffer, sizeof(char), *size, file);

			// �������� �����
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

// 3. �������� �����
void DownloadBook(book_t* books, int** countBooks)
{
	char* searchBook = new char[40];

	// ������
	int* c = new int;

	char* pathSource = new char[_MAX_PATH];
	char* pathDestination = new char[_MAX_PATH];


	// ���� ������ ����� ��� �����
	while (true)
	{
		system("cls");

		outline();

		cout << "DOWNLOAD BOOK" << endl;

		outline();

		// ���� ������ ����� ��� ��������
		cout << "Enter number or name book: ";
		cin.getline(searchBook, 40);


		// ����� ����� � ���� 
		for (book_t* book = books; book < books + **countBooks; book++)
		{
			// ���� ���� ����������
			if (!strcmp((*book).number, searchBook))
			{
				// �������� �����
				cout << "Name: " << (*book).name << endl;

				// ��� ������
				cout << "Author: " << (*book).name << endl;

				// ����
				cout << "Genre: " << (*book).genre << endl;

				// ����� �����
				cout << "Number book: " << (*book).number << endl;

				// ���� �������
				cout << "Create date: " << (*book).dateCreate << endl;

				// ����
				cout << "Price: " << (*book).price << endl;

				cout << "\n\n\n\n\nPRESS: EPUB[1] PDF[2] CANCEL[ECS]" << endl;

				// ����  
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

						// ���� ���� ��� ���������� �����
						cout << "Path save: ";
						cin.getline(pathDestination, _MAX_PATH);

						// ���� �������
						strcpy(pathSource, ".\\Library\\Books\\");
						strcat(pathSource, (*book).number);
						strcat(pathSource, ".epub");

						// ���� ����������
						strcat(pathDestination, "\\");
						strcat(pathDestination, (*book).name);

						// �������� �����
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

						// ���� ���� ��� ���������� �����
						cout << "Path save: ";
						cin.getline(pathDestination, _MAX_PATH);

						// ���� �������
						strcpy(pathSource, ".\\Library\\Books\\");
						strcat(pathSource, (*book).number);
						strcat(pathSource, ".pdf");

						// ���� ����������
						strcat(pathDestination, "\\");
						strcat(pathDestination, (*book).name);

						// �������� �����
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

		// ����
		*c = (int)_getch();

		if (*c == 27)
		{
			delete[] pathDestination, pathSource;

			delete c;

			return;
		}
	}
}

// ����� �������� �����
void DownloadBook(book_t* book)
{
	// ������
	int* c = new int;

	char* pathSource = new char[_MAX_PATH];
	char* pathDestination = new char[_MAX_PATH];

	system("cls");

	outline();

	cout << "DOWNLOAD BOOK" << endl;

	outline();

	// �������� �����
	cout << "Name: " << (*book).name << endl;

	// ��� ������
	cout << "Author: " << (*book).name << endl;

	// ����
	cout << "Genre: " << (*book).genre << endl;

	// ����� �����
	cout << "Number book: " << (*book).number << endl;

	// ���� �������
	cout << "Create date: " << (*book).dateCreate << endl;

	// ����
	cout << "Price: " << (*book).price << endl;

	cout << "\n\n\n\n\nPRESS: EPUB[1] PDF[2] CANCEL[ECS]" << endl;
	// ����  
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

			// ���� ���� ��� ���������� �����
			cout << "Path save: ";
			cin.getline(pathDestination, _MAX_PATH);

			// ���� �������
			strcpy(pathSource, ".\\Library\\Books\\");
			strcat(pathSource, (*book).number);
			strcat(pathSource, ".epub");

			// ���� ����������
			strcat(pathDestination, "\\");
			strcat(pathDestination, (*book).name);

			// �������� �����
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

			// ���� ���� ��� ���������� �����
			cout << "Path save: ";
			cin.getline(pathDestination, _MAX_PATH);

			// ���� �������
			strcpy(pathSource, ".\\Library\\Books\\");
			strcat(pathSource, (*book).number);
			strcat(pathSource, ".pdf");

			// ���� ����������
			strcat(pathDestination, "\\");
			strcat(pathDestination, (*book).name);

			// �������� �����
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

// 5. �������� ����� 
book_t* DeleteBook(book_t* books, int** countBooks)
{
	// ����� ����� 
	char* number = new char[20];

	// ���� � �����
	char* path = new char[_MAX_PATH];

	int* c = new int;

	// ���� ������
	while (true)
	{
		system("cls");

		outline();

		cout << "DELETE BOOK" << endl;

		outline();

		cout << "Enter number book: ";

		cin.getline(number, 20);

		// �������� ������ ����
		for (book_t* book_p = books; book_p < books + **countBooks; book_p++)
		{
			// ���� ����� ����� ������ 
			if (!strcmp(number, (*book_p).number))
			{
				// ���� � �����
				strcpy(path, ".\\Library\\Books\\");

				strcat(path, (*book_p).number);

				// ��������� �� ������ ����������
				char* expr = &path[strlen(path)];

				strcpy(expr, ".epub");

				// �������� ����� epub
				remove(path);

				strcpy(expr, ".pdf");

				// �������� ����� pdf
				remove(path);

				// ������ ���������� � ����� � ����� � ������
				// �������� ����� ������ � ������ � ������ �������� ������
				FILE* file = fopen("Library\\list.data", "wb");

				// ���� ���� ������� �������
				if (file != nullptr)
				{
					// �������� ���������� � �����
					for (book_t* book = books; book < books + **countBooks; book++)
					{
						// ���� ����� ����� ������ 
						if (!strcmp(number, (*book).number))
						{
							continue;
						}
						// ���������� � ���� ������ ��������� ����� �����
						// ����� �����
						fwrite((*book).number, sizeof(char), 20, file);

						// �������� �����
						fwrite((*book).name, sizeof(char), 40, file);

						// ���� �����
						fwrite((*book).genre, sizeof(char), 20, file);

						// ��� ������
						fwrite((*book).FIO, sizeof(char), 60, file);

						// ��� �������
						fwrite(&(*book).dateCreate, sizeof(int), 1, file);

						// ����
						fwrite(&(*book).price, sizeof(int), 1, file);
					}

					// �������� ����� 
					fclose(file);

					cout << "FILE DELETE COMPLETE!" << endl;

					return loadingDataBooks(countBooks);
				}
			}
		}

		cout << "Book not found!" << endl;

		cout << "\n\n\n\n\nPRESS: RE-ENTER[ANY KEY] QUIT[ECS]" << endl;

		// ����
		*c = (int)_getch();

		if (*c == 27)
		{
			delete[] number, path;

			delete c;

			return books;
		}
	}
}

// ����� �������� 
book_t* DeleteBook(book_t* books, book_t book_p, int** countBooks)
{
	// ���� � �����
	char* path = new char[_MAX_PATH];

	system("cls");

	outline();

	cout << "DELETE BOOK" << endl;

	outline();

	// ���� � �����
	strcpy(path, ".\\Library\\Books\\");

	strcat(path, (book_p).number);

	// ��������� �� ������ ����������
	char* expr = &path[strlen(path)];

	strcpy(expr, ".epub");

	// �������� ����� epub
	remove(path);

	strcpy(expr, ".pdf");

	// �������� ����� pdf
	remove(path);

	// ������ ���������� � ����� � ����� � ������
	// �������� ����� ������ � ������ � ������ �������� ������
	FILE* file = fopen("Library\\list.data", "wb");

	// ���� ���� ������� �������
	if (file != nullptr)
	{
		// �������� ���������� � �����
		for (book_t* book = books; book < books + **countBooks; book++)
		{
			// ���� ����� ����� ������ 
			if (!strcmp((*book).number, (book_p).number))
			{
				continue;
			}
			// ���������� � ���� ������ ��������� ����� �����
			// ����� �����
			fwrite((*book).number, sizeof(char), 20, file);

			// �������� �����
			fwrite((*book).name, sizeof(char), 40, file);

			// ���� �����
			fwrite((*book).genre, sizeof(char), 20, file);

			// ��� ������
			fwrite((*book).FIO, sizeof(char), 60, file);

			// ��� �������
			fwrite(&(*book).dateCreate, sizeof(int), 1, file);

			// ����
			fwrite(&(*book).price, sizeof(int), 1, file);
		}

		// �������� ����� 
		fclose(file);

		cout << "FILE DELETE COMPLETE!" << endl;

		return loadingDataBooks(countBooks);
	}
}