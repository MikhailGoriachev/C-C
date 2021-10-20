#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <conio.h>
#include <io.h>
#include <direct.h>

#include "head.h"

using namespace std;

extern cypher* sec;
extern account_data* user;
extern int* count_acc;
extern bool admin;

// функция нажатия случайной клавиши
void pressAnyKey()
{
	cout << "\n\n\nPRESS ANY KEY" << endl;

	_getch();
}

// вывод полосы
void line()
{
	cout << "-----------------------------------------------" << endl << endl;
}

// меню
int menu(FILE* file)
{
	// линия
	line();

	// меню 
	cout << "MENU" << endl;

	// линия
	line();

	// вывод списка автомобилей
	cout << "> 1. Auto list" << endl;
	// поиск автомобиля по критерию 
	cout << "> 2. Search auto" << endl;
	// регистрация автомобиля
	cout << "> 3. Registration car" << endl;
	// удаление автомобиля из базы данных (доступно только с учётной записи admin)
	cout << "> 4. Delete auto (admin)" << endl;
	// регистрация пользователя (доступно только с учётной записи admin)
	cout << "> 5. Registration user (admin)" << endl;
	// список пользователей 
	cout << "> 6. User list (admin)" << endl;
	// выход из программы
	cout << "\n\n\n> 0. Exit" << endl;

	// пользователь нажимает цифру в соответствии с номером пункта в меню
	cout << "\n\n\n\n\nPESS KEY [1-6]";

	// пременная для одного символа
	char* ch = new char[2];
	*(ch + 1) = 0;

	// нажатие клавиши
	while (true)
	{
		// нажатие клавиши
		*ch = _getch();

		if (!strcmp(ch, "0"))
		{
			// отчистка консоли
			system("cls");

			return 0;
		}

		if (!strcmp(ch, "1"))
		{
			// отчистка консоли
			system("cls");

			return 1;
		}

		else if (!strcmp(ch, "2"))
		{
			// отчистка консоли
			system("cls");

			return 2;
		}
		
		else if (!strcmp(ch, "3"))
		{
			// отчистка консоли
			system("cls");

			return 3;
		}
		
		else if (!strcmp(ch, "4"))
		{
			// отчистка консоли
			system("cls");

			return 4;
		}
		
		else if (!strcmp(ch, "5"))
		{
			// отчистка консоли
			system("cls");

			return 5;
		}
		
		else if (!strcmp(ch, "6"))
		{
			// отчистка консоли
			system("cls");

			return 6;
		}
	}

	// отчистка консоли
	system("cls");

	return 0;
}

// фукнция добавление в базу данных машины
int newAuto(FILE* file, car_t* database, unsigned long count_car)
{
	// создание структуры для новой машины
	car_t* new_car = new car_t;

	// установка указателя в конец файла
	fseek(file, 0, SEEK_END);

	// показатель уникальности номера
	bool* detect = new bool;

	*detect = true;

	// заполнение структуры пользователем
	while (true)
	{
		// линия
		line();

		cout << "REGISTRATION AUTO" << endl;

		line();

		// номер машины
		cout << "Enter number auto: ";
		cin.getline((*new_car).number, 19);

		// марка машины
		cout << "Enter mark auto: ";
		cin.getline((*new_car).mark, 19);

		// модель 
		cout << "Enter model auto: ";
		cin.getline((*new_car).model, 19);

		// фамилия
		cout << "Enter owner`s surname: ";
		cin.getline((*new_car).surname, 19);

		// имя 
		cout << "Enter owner`s name: ";
		cin.getline((*new_car).name, 19);

		// отчество
		cout << "Enter patronymic: ";
		cin.getline((*new_car).patronymic, 19);

		// год выпуска
		cout << "Enter year of crearion auto: ";
		cin.getline((*new_car).date, 10);

		// цена 
		cout << "Enter price: ";
		cin >> (*new_car).price;

		// проверка структуры на совпадение номера
		for (car_t* base_car = database; base_car < database + count_car; base_car++)
		{
			// если номер совпадает
			if (!strcmp((*new_car).number, (*base_car).number))
			{
				cout << "AUTO NUMBER IS NOT UNIQUE! RE-ENTER THE DATA" << endl;

				*detect = false;

				cin.ignore();

				system("cls");

				break;
			}
		}

		// если номер уникален
		if (*detect)
			break;
		
	}

	system("cls");

	cin.ignore();

	unsigned long df = 12;

	// запись данных в файл
	// номер машины
	fwrite((*new_car).number, sizeof(char), 20, file);
	// марка
	fwrite((*new_car).mark, sizeof(char), 20, file);
	// модель
	fwrite((*new_car).model, sizeof(char), 20, file);
	// фамилия
	fwrite((*new_car).surname, sizeof(char), 20, file);
	// имя
	fwrite((*new_car).name, sizeof(char), 20, file);
	// отчество
	fwrite((*new_car).patronymic, sizeof(char), 20, file);
	// год выпуска
	fwrite((*new_car).date, sizeof(char), 10, file);
	// цена
	fwrite(&(*new_car).price, sizeof(long), 1, file);

	

	return 1;
}

// загрузка базы данных
void loadData(char* path_data)
{
	// количество машин
	unsigned int* count_car;

	// указатель на струкутру
	car_t* car;

	// указатель на файл

	FILE* database;
	// загрузка базы данных в режиме бинарного чтения + записи
	database = fopen(path_data, "rb+");

	// если база данных открыта неуспешно
	if (database == nullptr)
	{
		cout << "DATABASE NOT FOUND" << endl;

		cout << endl;

		// проверка на то существует ли папка "Database"

		// спиской 
		_finddata_t list;

		// создание списка файлов текущего каталога с маской 
		long point = _findfirst(".\\Database", &list);

		// если список создан неуданчо 
		if (point == -1)
		{
			// создание папки Databese
			if (_mkdir(".\\Database") == -1)
			{
				cout << "ERROR CREATE FOLDER \"Database\"" << endl;

				return;
			}
		}

		// отчистка списка
		_findclose(point);

		// создание файла save.base и открытие его в режиме битной записи
		database = fopen(path_data, "wb");

		// если файл создан неуспешно
		if (database == nullptr)
		{
			cout << "ERROR CREATE FILE \"save.base\"" << endl;

			return;
		}

		cout << "FILE CREATE COMPLITE!" << endl;

		// отчистка консоли
		system("cls");

		// вывод линии 
		line();
	}

	// установка указателя в конец файла
	fseek(database, 0, SEEK_END);

	// размер файла
	size_t* size = new size_t;

	*size = ftell(database);

	// установка указателя в начало файла
	fseek(database, 0, SEEK_SET);

	// буфер
	/*char* n = new char[*size];

	// считывание всего файла в буфер 
	fread(n, sizeof(char), *size, database);

	// дешифровка буфера
	decryption(*sec, n, *size);

	// установка указателя в начало файла
	fseek(database, 0, SEEK_SET);

	// запись в файл расшифрованного буфера
	fwrite(n, sizeof(char), *size, database);

	// установка указателя в начало файла
	fseek(database, 0, SEEK_SET);

	delete[] n;
	*/
	// О каждой машине нужно хранить следующую информацию :
	//  - номер машины(кл - 2345т или 1) - 20 элементов - 20 байт
	//	- марка машины(BMW) - 20 элементов - 20 байт
	//	- модель(m5) - 20 элементов - 20 байт
	//	- ФИО владельца - 60 элементов(20 - фамилия, 20 - имя, 20 - отчество) - 60 байт
	//	- год выпуска - 10 элементов - 10 байт
	//	- цена - unsigned long - 4 байта 
	// ВСЕГО БАЙТ: 134 байта

	// количество автомобилей
	count_car = new unsigned int;

	*count_car = *size / 134;

	// если размер данных не делится без остатка на длину данных об одной машине
	if (*count_car != 0)
	{
		if (*size % *count_car != 0)
		{
			cout << "ERROR! THE DATABASE IS CORRUPTED" << endl;

			return;
		}
	}

	// создание массива структур по количеству машин
	car = new car_t[*count_car];

	// считываение файла в структуру
	for (car_t* p_car = car; p_car < car + *count_car; p_car++)
	{
		// номер машины
		fread((*p_car).number, sizeof(char), 20, database);
		// марка машины
		fread((*p_car).mark, sizeof(char), 20, database);
		// модель
		fread((*p_car).model, sizeof(char), 20, database);
		// фамилия
		fread((*p_car).surname, sizeof(char), 20, database);
		// имя 
		fread((*p_car).name, sizeof(char), 20, database);
		// отчество
		fread((*p_car).patronymic, sizeof(char), 20, database);
		// год выпуска
		fread((*p_car).date, sizeof(char), 10, database);
		// цена
		fread(&(*p_car).price, sizeof(unsigned long), 1, database);
	}

	cout << "FILE LOADING COMPLETE" << endl << endl;

	// нажатия любой клавиши для продолжения
	pressAnyKey();

	// отчистка консоли
	system("cls");

	// переменная меню 
	int* m = new int;

	*m = 0;

	// запуск меню
	while (true)
	{
		*m = menu(database);

		// выход из программы
		if (*m == 0)
		{
			return;
		}

		// вывод списка автомобилей
		if (*m == 1)
		{
			outList(car, count_car);
		}

		// поиск автомобиля по номеру
		if (*m == 2)
		{
			searchAuto(car, count_car);
		}

		// регистрация автомобиля
		if (*m == 3)
		{
			// запуск функции регистрации
			newAuto(database, car, *count_car);

			// закрытие файла
			fclose(database);

			// загрузка базы данных
			loadData(path_data);
		}

		// удаление автомобиля из базы данных (доступно только с учётной записи admin)
		if (*m == 4)
		{
			
			// если админ
			if (admin)
			{
				// запуск функции
				deleteCar(database, car, count_car, path_data);
			}

			// если обычный пользователь
			else
			{
				system("cls");

				// вывод линии
				line();

				cout << "Delete auto (admin)" << endl;

				// вывод линии
				line();


				cout << "LOCK! ADMIN REQUIRED" << endl;

				// любая клавиша
				pressAnyKey();

				system("cls");

				continue;
			}
		}

		// регистрация пользователя (доступно только с учётной записи admin)
		if (*m == 5)
		{
			
			// если админ
			if (admin)
			{
				// запуск функции
				regUser(user, count_acc);
			}

			// если обычный пользователь
			else
			{
				system("cls");

				// вывод линии
				line();

				cout << "Delete auto (admin)" << endl;

				// вывод линии
				line();


				cout << "LOCK! ADMIN REQUIRED" << endl;

				// любая клавиша
				pressAnyKey();

				system("cls");

				continue;
			}
		}

		// список пользователей (доступно только с учётной записи admin)
		if (*m == 6)
		{
			// если админ
			if (admin)
			{
				// запуск функции
				listUser(user, count_acc);
			}

			// если обычный пользователь
			else
			{
				system("cls");

				// вывод линии
				line();

				cout << "Delete auto (admin)" << endl;

				// вывод линии
				line();


				cout << "LOCK! ADMIN REQUIRED" << endl;

				// любая клавиша
				pressAnyKey();

				system("cls");

				continue;
			}

		}
		
	}

	/*// установка указателя в конец файла
	fseek(database, 0, SEEK_END);

	// размер файла
	size = new size_t;

	*size = ftell(database);

	// установка указателя в начало файла
	fseek(database, 0, SEEK_SET);

	// буфер
	n = new char[*size];

	// считывание всего файла в буфер 
	fread(n, sizeof(char), *size, database);

	// шифрование буфера
	encryption(*sec, n, *size);

	// установка указателя в начало файла
	fseek(database, 0, SEEK_SET);

	// запись в файл расшифрованного буфера
	fwrite(n, sizeof(char), *size, database);

	// установка указателя в начало файла
	fseek(database, 0, SEEK_SET);

	fclose(database);

	delete[] n;*/
}

// вывод списка автомобилей
void outList(car_t* car, unsigned int* count_car)
{
	// переменная для цикла
	int* i = new int;

	// символ клавиши
	char* ch = new char[2];

	*(ch + 1) = 0;

	// вывод по две машины на страницу
	for (car_t* car_p = car; car_p < car + *count_car; )
	{
		// вывод линии
		line();

		cout << "AUTO LIST" << endl << endl;

		line();

		// номер машины
		cout << "> Number auto: " << (*car_p).number << endl;

		// марка машины
		cout << "> Mark auto: " << (*car_p).mark << endl;

		// модель 
		cout << "> Model auto: " << (*car_p).model << endl;

		// фамилия
		cout << "> Owner`s surname: " << (*car_p).surname << endl;

		// имя 
		cout << "> Owner`s name: " << (*car_p).name << endl;

		// отчество
		cout << "> Patronymic: " << (*car_p).patronymic << endl;

		// год выпуска
		cout << "> Year of crearion auto: " << (*car_p).date << endl;

		// цена 
		cout << "> Price: " << (*car_p).price << endl;

		cout << endl;

		cout << "\n\n\n\nPRESS: [1] - left, [2] - right, [ESC] - exit";

		// нажатие клавиши
		*ch = _getch();
		
		// если пользователь нажимает esc то выход
		if ((int)*ch == 27)
		{
			// отчистка консоли
			system("cls");

			return;
		}

		// если пользователь нажимает стрелку влево, то предыдущая анкета
		if (!strcmp(ch, "1"))
		{
			// если это не первая анкета 
			if (car_p != car)
			{
				car_p--;

				system("cls");

				continue;
			}
		}
		
		// если пользователь нажимает стрелку вправо, то следующая анкета
		if (!strcmp(ch, "2"))
		{
			// если это не последняя анкета 
			if (car_p < (car + *count_car - 1))
			{
				car_p++;

				system("cls");

				continue;
			}
		}

		system("cls");
	}
}

// удаление машины
void deleteCar(FILE* file, car_t* list, unsigned int* count_car, char* path)
{
	while (true)
	{
		// вывод линии
		line();

		cout << "Delete auto (admin)" << endl;

		// вывод линии
		line();

		// строка для номера 
		char* number = new char[19];

		// ввод номера 
		cout << "Enter number car: ";
		cin.getline(number, 19);

		cout << endl;

		// показатель на существование номера в базе данных
		bool* flag = new bool;

		*flag = false;

		// посик номера по базе данных
		for (car_t* car = list; car < list + *count_car; car++)
		{
			// если номер совпал
			if (!strcmp(number, (*car).number))
			{
				*flag = true;

				size_t len = strlen(number);

				// шифрование номера 
				//encryption(*sec, number, len);

				// поиск этого номера в файле 
				if (scanFileDelete(number, len, 134, path))
				{
					loadData(path);

					return;
				}


				break;
			}
		}

		// символ ввода
		char* ch = new char[2];

		*(ch + 1) = 0;

		// если номера не существует
		if (!(*flag))
		{
			cout << "ERROR! NUMBER NOT FOUND! RE-ENTER NUMBER(ESC - exit, ANY KEY - re-enter)" << endl;

			// ввод клавиши
			while (true)
			{
				*ch = _getch();

				// если ESC
				if (*ch == (char)27)
				{
					return;
				}

				break;
			}

			continue;
		}

		break;
	}

	system("cls");
}

// нахождение в файле и удаление принимает начало данных
// и длину их и указатель на файл
int scanFileDelete(char* str, size_t s_size, unsigned long size, char* path)
{
	// открытие файла в режиме битного чтения
	FILE* file = fopen(path, "rb");

	// если файл успешно открыт
	if (file != nullptr)
	{
		// установка указателя в конец файла 
		fseek(file, 0, SEEK_END);

		// длина файла
		unsigned long* f_size = new unsigned long;

		*f_size = ftell(file);

		// установка указателя в файле в начало
		fseek(file, 0, SEEK_SET);

		// буфер
		char* buffer = new char[*f_size + 1];

		// считывание файла в буфер
		fread(buffer, sizeof(char), *f_size, file);

		// закрытие файла
		fclose(file);
		
		// показатель равности
		bool* flag = new bool;

		// сканирование буфера
		for (char* buf = buffer; buf < buffer + *f_size; buf += 134)
		{
			// по умолчанию показатель равности правильный
			*flag = true;

			// если строка совпадает с началом отрывка
			for (char* s = str, * b = buf; s < str + s_size; s++, b++)
			{
				// если не совпадают символы
				if (*s != *b)
				{
					*flag = false;

					break;
				}
			}

			// если симолы совпали
			if (*flag)
			{
				unsigned long* j = new unsigned long;

				*j = 1;

				// удаление нужных символов из буфера
				for (char* b = buf; *j < size + 1; ++*j)
				{
					// перемщение элементов влево
					for (char* n = b; n <= buffer + *f_size; n++)
					{
						swap(*n, *(n + 1));
					}
				}

				delete j, flag;

				// открытие файла в режиме бинарной записи
				file = fopen(path, "wb");

				// запись в файл из буфера
				fwrite(buffer, sizeof(char), *f_size - size, file);

				// закрытие файла
				fclose(file);

				return 1;
			}
		}

	}
	// если файл не открыт
	else
	{
		cout << "ERROR OPEN FILE" << endl;

		return 0;
	}
}

// поиск авто
void searchAuto(car_t* list, unsigned int* count_user)
{
	while (true)
	{
		// вывод линии
		line();

		cout << "Search auto" << endl;

		line();

		// номер
		char* number = new char[20];

		// ввод номера
		cout << "Enter number: ";
		cin.getline(number, 20);

		// отчистка консоли
		system("cls");

		// вывод линии
		line();

		cout << "RESULT:" << endl;

		line();

		// поиск номера по базе данных
		for (car_t* car_p = list; car_p < list + *count_user; car_p++)
		{
			// если номер совпал
			if (!strcmp(number, (*car_p).number))
			{	
				// вывод информации об авто
						// номер машины
				cout << "> Number auto: " << (*car_p).number << endl;

				// марка машины
				cout << "> Mark auto: " << (*car_p).mark << endl;

				// модель 
				cout << "> Model auto: " << (*car_p).model << endl;

				// фамилия
				cout << "> Owner`s surname: " << (*car_p).surname << endl;

				// имя 
				cout << "> Owner`s name: " << (*car_p).name << endl;

				// отчество
				cout << "> Patronymic: " << (*car_p).patronymic << endl;

				// год выпуска
				cout << "> Year of crearion auto: " << (*car_p).date << endl;

				// цена 
				cout << "> Price: " << (*car_p).price << endl;

				// нажатие любой клавиши
				pressAnyKey();

				// отчистка консоли
				system("cls");

				delete[] number;

				return;
			}
		}

		// если авто не найдено в базе 
		cout << "NO CAR FOUND! PRESS ANY KEY TO RE-ENTER NUMBER OR EXIT[ESC]" << endl;
		
		// символ 
		char* ch = new char[2];

		*(ch + 1) = 0;

		// сравнение
		while (true)
		{
			*ch = _getch();

			if (*ch == (char)27)
			{
				delete[] number;

				system("cls");

				return;
			}

			break;
		}

		system("cls");

		continue;
	}
}

// регистрация пользователя
void regUser(account_data* user, int* count_acc)
{
	// структура для новой записи
	account_data* new_user = new account_data;

	// проверка на уникаольность
	bool* flag = new bool;

	*flag = true;

	while (true)
	{
		system("cls");

		// вывод линии
		line();

		cout << "Registration user" << endl;

		// вывод линии
		line();

		// ввод логина 
		cout << "> Enter new login: ";
		cin.getline((*new_user).login, 19);

		// ввод пароля
		cout << "Enter new password: ";
		cin.getline((*new_user).password, 19);

		// проверка на наличие такого же логина в базе
		for (account_data* us = user; us < user + *count_acc; us++)
		{
			// если логин совпадает
			if (!strcmp((*new_user).login, (*us).login))
			{
				cout << "ERROR! LOGIN IS NOT UNIQUE!" << endl;

				*flag = false;

				break;
			}
		}

		// если не уникальный 
		if (!*flag)
		{
			system("cls");

			continue;
		}

		// тихая регистрация
		createAccount((*new_user).login, (*new_user).password);

		system("cls");

		break;
	}
}

// список пользователей
void listUser(account_data* user, int* count_acc)
{
	// символ клавиши
	char* ch = new char[2];

	*(ch + 1) = 0;

	for (account_data* us = user; us < user + *count_acc;)
	{
		// вывод линии
		line();

		cout << "User list (admin)" << endl;

		// вывод линии
		line();

		cout << "> Login: " << (*us).login << endl;
		cout << "> Password: " << (*us).password << endl;

		cout << "\n\n\n\n\n\n\nPRESS: [1] - left, [2] - right, [ESC] - exit";

		// нажатие клавиши
		*ch = _getch();

		// если пользователь нажимает esc то выход
		if ((int)*ch == 27)
		{
			// отчистка консоли
			system("cls");

			return;
		}

		// если пользователь нажимает стрелку влево, то предыдущая анкета
		if (!strcmp(ch, "1"))
		{
			// если это не первая анкета 
			if (us != user)
			{
				us--;

				system("cls");

				continue;
			}
		}

		// если пользователь нажимает стрелку вправо, то следующая анкета
		if (!strcmp(ch, "2"))
		{
			// если это не последняя анкета 
			if (us < (user + *count_acc - 1))
			{
				us++;

				system("cls");

				continue;
			}
		}

		system("cls");
	}
}