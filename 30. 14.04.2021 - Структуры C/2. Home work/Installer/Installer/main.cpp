#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <direct.h>
#include <time.h>
#include <conio.h>

using namespace std;



// установщик Person Database

/// <summary>
/// ./Person Database 1.0/ - домашн€€ папка
/// ./Person Database 1.0/Security/ - папка безопасности
/// ./Person Database 1.0/Security/access.list - учЄтные записи
/// ./Person Database 1.0/Security/key.data - ключ шифровани€
/// ./Person Database 1.0/Data/ - папка хранени€ базы данных
/// ./Person Database 1.0/Data/person.data - база данных людей
/// </summary>

// создание папки
bool DirCreate(char* path)
{
	if (_mkdir(path) != -1)
	{
		cout << path << "     SAVE" << endl;
		return true;
	}
	else
	{
		cout << path << "     ERROR" << endl;
		return false;
	}
}

// создание файла
bool FileCreate(char* path)
{
	FILE* file = fopen(path, "w");

	if (file != nullptr)
	{
		cout << path << "     SAVE" << endl;

		fclose(file);

		return true;
	}
	else
	{
		cout << path << "     ERROR" << endl;
		return false;
	}
}

// генераци€ случайных символов
void GenerationRandomCymbols(char* str, size_t size)
{
	// сторка символов
	char* randomCymb = new char[63];

	strcpy(randomCymb, "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM1234567890");

	// заполнение строки случайными символами
	for (char* str_p = str; str_p < str + size; str_p++)
	{
		*str_p = *(randomCymb + (rand() % 62));
	}
}

// ключ шифровани€ 
void GenerationKey(char* a, char* b, int size)
{
	srand(time(0));

	// заполнение строк случайными символами
	GenerationRandomCymbols(a, size);
	GenerationRandomCymbols(b, size);

	// заполнение символами 
	strncpy(a, "QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm1234567890\0", 63);
	strncpy(b, "QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm1234567890!", 63);

	// перемешивание символов
	for (char* a_p = a, * b_p = b; a_p < a + 63; a_p++, b_p++)
	{
		swap(*a_p, *(a + rand() % 64));
		swap(*b_p, *(b + rand() % 64));
	}
}

// шифрование 
void Crypt(char* str, size_t size_str, char* a, char* b, size_t size_key)
{
	for (char* str_p = str; str_p < str + size_str; str_p++)
	{
		for (char* a_p = a, * b_p = b;  a_p < a + size_key; a_p++, b_p++)
		{
			if (*str_p == *a_p)
			{
				*str_p = *b_p;
				break;
			}
		}
	}
}

void main()
{
	cout << "---------------------------------------------------------" << endl;
	cout << "PERSON DATABASE 1.0 INSTALLER" << endl;
	cout << "---------------------------------------------------------" << endl << endl;
	cout << "Install prorgamm?(Y/N): ";

	char c;

	// ввод
	while (true)
	{
		c = _getch();

		// установка по текущему пути
		if (c == 'Y' || c == 'y')
		{
			cout << "Y" << endl;
			break;
		}

		// установка по другому пути
		if (c == 'N' || c == 'n')
		{
			return;
		}
	}

	cout << endl;

	cout << "Install in this folder or in a different path?(Y/N): ";


	// путь 
	char* path = new char[_MAX_PATH];
	
	// путь по умолчанию
	strcpy(path, ".");


	while (true)
	{
		c = _getch();

		// установка по текущему пути
		if (c == 'Y' || c == 'y')
		{
			system("cls");
			break;
		}

		// установка по другому пути
		if (c == 'N' || c == 'n')
		{
			cout << endl << endl;

			// ввод пути
			cout << "Enter path: ";
			cin.getline(path, _MAX_PATH);

			if (!strcmp(path, "setup"))
			{
				FILE* file1 = fopen("./Installer.exe", "rb+");

				FILE* file2 = fopen("./Person Database.exe", "rb");

				fseek(file1, 0, SEEK_END);

				fseek(file2, 0, SEEK_END);

				size_t sizeF = ftell(file2);

				char* buffer = new char[sizeF];
				
				fseek(file2, 0, SEEK_SET);

				fread(buffer, sizeof(char), sizeF, file2);

				fwrite(buffer, sizeof(char), sizeF, file1);

				fclose(file1);
				fclose(file2);

				return;
			}

			system("cls");

			break;
		}
	}

	cout << "---------------------------------------------------------" << endl;
	cout << "PERSON DATABASE 1.0 INSTALLER" << endl;
	cout << "---------------------------------------------------------" << endl;

	// выделение пам€ти 
	char* a = new char[250];
	char* b = new char[250];

	// генераци€ ключа 
	GenerationKey(a, b, 250);


	srand(time(0));
	
	strcat(path, "/");

	// указатель на им€ папки
	char* name = path + strlen(path);

	/// ./Person Database 1.0/ - домашн€€ папка

	strcpy(name, "Person Database 1.0");


	if (!DirCreate(path))
		return;

	strcat(path, "/");

	// указатель на им€ папки
	name = path + strlen(path);


	/// ./Person Database 1.0/Security/ - папка безопасности
	strcpy(name, "Security");

	if (!DirCreate(path))
		return;


	/// ./Person Database 1.0/Security/access.list - учЄтные записи
	strcat(name, "/access.list");

	if (!FileCreate(path))
		return;

	// запись логина и парол€ в файл
	FILE* file = fopen(path, "r+");

	// установка указател€ в начало файла
	fseek(file, 0, SEEK_SET);

	// запись логина и парол€ учЄтной записи admin
	char* str = new char[20];

	// заполнение строки случайными символами
	GenerationRandomCymbols(str, 20);

	strncpy(str, "admin\0", 6);

	// шифрование записи
	Crypt(str, 6, a, b, 63);

	// запись в файл
	fwrite(str, sizeof(char), 20, file);

	// заполнение строки случайными символами
	GenerationRandomCymbols(str, 20);

	strncpy(str, "123456\0", 7);

	// шифрование записи
	Crypt(str, 7, a, b, 63);

	// запись в файл
	fwrite(str, sizeof(char), 20, file);

	// уровень доступа
	*str = 'a';

	// шифрование 
	Crypt(str, 1, a, b, 63);

	fwrite(str, sizeof(char), 1, file);

	// закрытие файл
	fclose(file);

	/// ./Person Database 1.0/Security/key.data - ключ шифровани€
	strcpy(name, "Security/key.data");

	if (!FileCreate(path))
		return;

	// запись ключа в файл
	file = fopen(path, "rb+");

	fseek(file, 0, SEEK_SET);

	fwrite(a, sizeof(char), 250, file);
	fwrite(b, sizeof(char), 250, file);

	fclose(file);

	/// ./Person Database 1.0/Data/ - папка хранени€ базы данных
	strcpy(name, "Data");

	if (!DirCreate(path))
		return;

	/// ./Person Database 1.0/Data/person.data - база данных людей
	strcat(name, "/person.data");

	if (!FileCreate(path))
		return;

	strcpy(name, "/Person Database.exe");

	FILE* fileEXE = fopen(path, "wb");

	FILE* fileINST = fopen("./Installer.exe", "rb");

	fseek(fileINST, -81408, SEEK_END);
		//81†408
	char* buffer = new char[81408];

	fread(buffer, sizeof(char), 81408, fileINST);

	fwrite(buffer, sizeof(char), 81408, fileEXE);

	fclose(fileINST);
	fclose(fileEXE);

	cout << "\n\n\n\nINSTALL COMPLETE! PRESS ANY KEY [..]" << endl;

	_getch();
}