#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <io.h>
#include <conio.h>

#include "head.h"

using namespace std;

// вход в аккаунт; mode == 0 - вход в аккаунт, mode == 1 - управление пользователями, mode == 2 - выход;
UserData* login(int* mode)
{
	// указатель на ключ шифрования
	CryptKey** key = new CryptKey*;

	// количество пользователей
	int* count_users = new int;

	/// загрузка учётных данных польователей
	UserData* users = loadingUserData(count_users, key);

	// если данные не получилось загрузить
	if (users == nullptr)
		return nullptr;

	// если нужен просмотр списка (администратор)
	if (*mode == 1)
	{
		char* c = new char;

		for (UserData* user = users;; )
		{
			outline();

			// вывод данных пользователя
			cout << "USERS LIST" << endl;

			outline();

			// всего пользователь
			cout << "Count all users: " << *count_users << endl;

			// фамилия
			cout << "Surname: " << (*user).surname << endl;
			// имя 
			cout << "Name: " << (*user).name << endl;
			// логин
			cout << "Login: " << (*user).login << endl;
			// пароль
			cout << "Password: " << (*user).password << endl;
			// уровень доступа
			cout << "Acces level: ";
			// если уровень доступа администраторский
			if ((*user).accessLevel == 1)
				cout << "admin group" << endl;
			else cout << "prime user" << endl;

			// управление 
			cout << "\n\n\nPRESS: LAST[1] NEXT[2] NEW USER[4] DELETE[3] QUIT[ESC]" << endl;

			// ввод 
			while (true)
			{
				*c = _getch();

				// LAST[1]
				if (!strcmp(c, "1"))
				{
					// если анкета является первой
					if (user == users + *count_users - 1)
					{
						continue;
					}

					user++;

					break;
				}

				// NEXT[2]
				if (!strcmp(c, "2"))
				{
					// если последней
					if (user == users)
					{
						continue;
					}

					user--;

					break;
				}

				// создание нового пользователя
				if (!strcmp(c, "3"))
				{
					createUser(users, count_users, key);

					delete c, count_users;

					delete[] users;

					return nullptr;
				}

				// удаление пользователя
				if (!strcmp(c, "4"))
				{
					deleteToFile((*user).login, "Users\\user.data", 84);

					cout << "DELETE USER COMPLETE!" << endl;

					delete c, count_users;

					delete[] users;

					return nullptr;
				}

				// выход из управления аккаунтами
				if (*c == (char)27)
				{
					// переключение режима на выход
					*mode = 2;

					delete c, count_users;

					delete[] users;

					return nullptr;
				}
			}
		}
	}

	// логин
	char* login = new char[20];

	// пароль
	char* password = new char[20];

	// ввод учётных данных
	while (true)
	{
		system("cls");

		outline();

		cout << "LOGIN" << endl;

		outline();

		// ввод логина 
		cout << "Enter login: ";
		cin.getline(login, 20);

		// ввод пароля
		cout << "Enter password: ";
		cin.getline(password, 20);

		// проверка по базе данных
		for (UserData* user = users; user < users + *count_users; user++)
		{
			// если введённый логин совпадает с логином в базе данных
			if (!strcmp((*user).login, login))
			{
				// если введённый пароль совпадает с паролем в базе данных
				if (!strcmp((*user).login, login))
				{
					// создание UserData для текущего пользователя
					UserData* us = new UserData;

					// копирование данных между текущего пользователя из базы данных пользователей
					// в созданную UserData на одного пользователя
					// логин
					strcpy((*us).login, (*user).login);
					strcpy((*us).password, (*user).password);
					strcpy((*us).surname, (*user).surname);
					strcpy((*us).name, (*user).name);
					(*us).accessLevel = (*user).accessLevel;

					// отчистка памяти
					delete[] users, login, password;

					// переключение режима на выход
					*mode = 2;

					// возвращение данных текущего пользователя в главную функцию
					return us;
				}
			}
		}

		cout << endl;

		cout << "USERNAME OR PASSWORD ENTERED INCORRECTLY! RE-ENTER!" << endl;

		// нажатие любой клавиши
		pressAnyKey();
	}
}

// загрузка ключа шифрования
CryptKey* loadingKey()
{
	// создание структуры шифрования
	CryptKey *key = new CryptKey;

	/// считывание ключа из файла в папке Security/sec.data

	// открытие файла ключа безопасности в режиме бинарного чтения
	FILE* file = fopen("Security\\key.data", "rb");

	// если файл открыт успешно
	if (file != nullptr)
	{
		// установка указателя в конец файла 
		fseek(file, 0, SEEK_END);

		// длина файла 
		int* size_key = new int;

		*size_key = ftell(file);

		// установка указателя в конец файла
		fseek(file, 0, SEEK_END);

		// считываение половины файла в структуру в раздел "a"
		fread((*key).a, sizeof(char), *size_key / 2, file);

		// считываение половины файла в структуру в раздел "b"
		fread((*key).b, sizeof(char), *size_key / 2, file);

		// закрытие файла
		fclose(file);

		return key;
	}
	// если файл безопасности не удалось открыть
	else
	{
		cout << "ERROR OPENING FILE \"key.data\"!" << endl;

		// очистка памяти
		delete key;

		pressAnyKey();

		return nullptr;
	}
}

// загрузка учётных данных пользователей
UserData* loadingUserData(int* count_users, CryptKey** key)
{
	// загрузка ключа шифрования
	*key = loadingKey();

	// если ключ загружен удачно
	if (key != nullptr)
	{
		// открытие файла Users/users.data в режиме бинарного чтения
		FILE* file = fopen("Users\\user.data", "rb");

		// если файл успешно открыт
		if (file != nullptr)
		{
			// установка указателя в конец файла
			fseek(file, 0, SEEK_END);

			// длина файла
			size_t* size = new size_t;

			*size = ftell(file);

			// установка указателя в начало файла
			fseek(file, 0, SEEK_SET);

			// количество пользователей
			*count_users = *size / 84;

			// массив пользователей
			UserData* users = new UserData[*count_users];

			// считывание файла в структуру
			for (UserData* us = users; us < users + *count_users; us++)
			{
				// логин 
				fread((*us).login, sizeof(char), 20, file);

				// расшифровка
				deCrypt((*us).login, 20);

				// пароль 
				fread((*us).password, sizeof(char), 20, file);

				// расшифровка
				deCrypt((*us).password, 20);
				
				// фамилия пользователя
				fread((*us).surname, sizeof(char), 20, file);

				// расшифровка
				deCrypt((*us).surname, 20);

				// имя пользователя
				fread((*us).name, sizeof(char), 20, file);

				// расшифровка
				deCrypt((*us).name, 20);

				// уровень доступа
				fread(&(*us).accessLevel, sizeof(int), 1, file);
			}

			// закрытие файла
			fclose(file);

			// отчистка памяти
			delete size;

			return users;
		}

		cout << "ERROR OPENING FILE \"user.data\"" << endl;

		pressAnyKey();

		// если неудачно
		return nullptr;
	}

	// если неудачно
	return nullptr;
}

// дешифрование содержимого
void deCrypt(char* str, unsigned long size)
{
	// загрузка ключа шифрования
	CryptKey* key = loadingKey();

	for (char* str_p = str; str_p < str + size; str_p++)
	{
		for (char* key_a = (*key).a, * key_b = (*key).b; key_a < (*key).a + 255; key_a++, key_b++)
		{
			if (*key_a == *str_p)
			{
				*str_p = *key_b;

				break;
			}
		}
	}
}

// шифрование содержимого
void Crypt(char* str, unsigned long size)
{
	// загрузка ключа шифрования
	CryptKey* key = loadingKey();

	for (char* str_p = str; str_p < str + size; str_p++)
	{
		for (char* key_a = (*key).a, *key_b = (*key).b; key_a < (*key).a + 255; key_a++, key_b++)
		{
			if (*key_b == *str_p)
			{
				*str_p = *key_a;

				break;
			}
		}
	}
}

// дописывание в файл
int writingToFile(void* buffer, const char nameFile[], unsigned int countByte)
{
	// открытие файла в режиме бинарного чтения/записи
	FILE* file = fopen(nameFile, "rb+");

	// если файл открыт удачно
	if (file != nullptr)
	{
		// установка указателя в конец файла
		fseek(file, 0, SEEK_END);

		// запись в файл
		fwrite(buffer, 1, countByte, file);

		// закрытие файла 
		fclose(file);

		return 1;
	}

	// если файл открыт неудачно
	else return 0;
}

// удаление из файла
int deleteToFile(char* buffer, const char nameFile[], unsigned int countByte)
{
	// открытие файла в режиме бинарного чтения/записи
	FILE* file = fopen(nameFile, "rb+");

	// если файл открыт удачно
	if (file != nullptr)
	{
		// установка указателя в конец файла
		fseek(file, 0, SEEK_END);

		// длина файла
		size_t* size = new size_t;

		*size = ftell(file);

		// буфер для файла
		char* buf = new char[*size];

		// считывание файла в буфер
		fread(buf, sizeof(char), *size, file);

		// закрытие файла
		fclose(file);

		// сканирование буфера
		for (char* point_a = buf; point_a < buf + *size; point_a++)
		{
			if (!strncmp(point_a, buffer, countByte))
			{
				// смещение массива влево
				for (char* a = point_a; a < point_a + *size; a++)
				{
					swap(*a, *(a + 1));
				}

				break;
			}
		}

		// уменьшение общей длины 
		*size -= countByte;

		// открытие файла в режиме бинарного записи
		FILE* file = fopen(nameFile, "wb");

		// перезапись файла содержимым из буфера
		fwrite(buffer, sizeof(char), *size, file);

		// отчистка памяти
		delete[] buf;
		delete size;

		// закрытие файла 
		fclose(file);

		return 1;
	}

	// если файл открыт неудачно
	else return 0;

}

// создание пользователя
void createUser(UserData* users, int* count_user, CryptKey** key)
{
	// флаг уникальности логина
	bool* flag = new bool;

	*flag = false;

	while (true)
	{
		system("cls");

		outline();

		cout << "CREATE NEW USER" << endl;

		outline();

		// структура для нового пользователя
		UserData* newUser = new UserData;

		// фамилия
		cout << "Enter surname: ";
		cin.getline((*newUser).surname, 20);

		// имя 
		cout << "Enter name: ";
		cin.getline((*newUser).name, 20);

		// логин
		cout << "Enter login: ";
		cin.getline((*newUser).login, 20);
		// пароль
		cout << "Enter password: ";
		cin.getline((*newUser).password, 20);
		// уровень доступа
		cout << "Enter acces level(admin[1]/user[0]): ";
		cin >> (*newUser).accessLevel;

		// проверка по логину в базе учётных записей
		for (UserData* user = users; user < users + *count_user; user++)
		{
			// если логин найден в базе данных
			if (!strcmp((*newUser).login, (*user).login))
			{
				cout << "LOGIN IS BUSSY! PLEASE, RE_ENTER DATA.\nPRESS ANY KEY TO RE-ENTER OR ESC TO EXIT" << endl;

				// символ
				char* c = new char;

				// если нажата esc
				if (*c == (char)27)
				{
					delete c;

					return;
				}

				*flag = true;

				break;
			}
		}

		if (!*flag)
		{
			// шифрование логина 
			Crypt((*newUser).login, 20);

			// запись в файл логина 
			writingToFile((*newUser).login, "Users\\user.data", 20);

			// шифрование пароля
			Crypt((*newUser).password, 20);

			// запись в файл пароля
			writingToFile((*newUser).password, "Users\\user.data", 20);
			
			// шифрование фамилии
			Crypt((*newUser).surname, 20);

			// запись в файл фамилии
			writingToFile((*newUser).surname, "Users\\user.data", 20);

			// шифрование шифрование имени
			Crypt((*newUser).name, 20);

			// запись в файл имени 
			writingToFile((*newUser).name, "Users\\user.data", 20);

			// запись в файл уровня доступа
			writingToFile(&(*newUser).accessLevel, "Users\\user.data", 4);

			cout << "CREATE NEW USER COMPLETE!" << endl;

			delete flag;

			pressAnyKey();

			return;
		}	
	}
}