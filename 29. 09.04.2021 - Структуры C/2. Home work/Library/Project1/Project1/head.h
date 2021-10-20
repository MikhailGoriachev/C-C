#pragma once

// структура учётных данных пользователя
// уровень доступа: 0 - обычный, 1 - администрация
struct UserData
{
	char login[20];
	char password[20];
	char surname[20];
	char name[20];
	int accessLevel;
};

// структура шифрования
struct CryptKey
{
	// шифр
	char a[250];

	// рельные символы
	char b[250];
};

// структура книги
struct book_t
{
	//  - номер книги
	char number[20];
	//  - название книги
	char name[40];
	//  - жанр книги
	char genre[20];
	//  - ФИО автора
	char FIO[60];
	//  - год выпуска
	int dateCreate;
	//  - цена
	int price;
};

// ожидание нажатия любой клавиши
void pressAnyKey();

// вывод линии
void outline();

// вход в аккаунт; mode == 0 - вход в аккаунт, mode == 1 - управление пользователями, mode == 2 - выход;
UserData* login(int* mode);

// загрузка ключа шифрования
CryptKey* loadingKey();

// загрузка учётных данных пользователей
UserData* loadingUserData(int* count_users, CryptKey** key);

// дешифрование содержимого
void deCrypt(char* str, unsigned long size);

// шифрование содержимого
void Crypt(char* str, unsigned long size);

// дописывание в файл
int writingToFile(void* buffer, const char nameFile[], unsigned int countByte);

// удаление из файла
int deleteToFile(char* buffer, const char nameFile[], unsigned int countByte);

// создание пользователя
void createUser(UserData* users, int* count_user, CryptKey** key);

// меню
void menu(int* mode);

// загрузка данных о книгах
book_t* loadingDataBooks(int** countBooks);

// 1. Просмотр всех книг
book_t* AllBooks(int** countBooks);

// поиск книги в списке
void SearchBook(book_t* books, book_t* searcBook, int* countBook);

// 2. Найти книгу
void SearchBook(book_t* books, int* countBook);

// 4. Добавление книги
book_t* AddBook(book_t* books, int** countBooks);

// загрузка книги в папку; flag - 1 шифрование, 2 расшифарование, 3 без шифрования;
void CpyBook(char* pathSource, char* pathDestination, int flag);

// 3. Загрузка книги
void DownloadBook(book_t* books, int** countBooks);

// тихая загрузка книги
void DownloadBook(book_t* book);

// 5. Удаление книги 
book_t* DeleteBook(book_t* books, int** countBooks);

// тихое удаление 
book_t* DeleteBook(book_t* books, book_t book_p, int** countBooks);