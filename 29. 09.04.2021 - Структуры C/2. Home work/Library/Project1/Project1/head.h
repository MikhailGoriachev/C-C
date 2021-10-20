#pragma once

// ��������� ������� ������ ������������
// ������� �������: 0 - �������, 1 - �������������
struct UserData
{
	char login[20];
	char password[20];
	char surname[20];
	char name[20];
	int accessLevel;
};

// ��������� ����������
struct CryptKey
{
	// ����
	char a[250];

	// ������� �������
	char b[250];
};

// ��������� �����
struct book_t
{
	//  - ����� �����
	char number[20];
	//  - �������� �����
	char name[40];
	//  - ���� �����
	char genre[20];
	//  - ��� ������
	char FIO[60];
	//  - ��� �������
	int dateCreate;
	//  - ����
	int price;
};

// �������� ������� ����� �������
void pressAnyKey();

// ����� �����
void outline();

// ���� � �������; mode == 0 - ���� � �������, mode == 1 - ���������� ��������������, mode == 2 - �����;
UserData* login(int* mode);

// �������� ����� ����������
CryptKey* loadingKey();

// �������� ������� ������ �������������
UserData* loadingUserData(int* count_users, CryptKey** key);

// ������������ �����������
void deCrypt(char* str, unsigned long size);

// ���������� �����������
void Crypt(char* str, unsigned long size);

// ����������� � ����
int writingToFile(void* buffer, const char nameFile[], unsigned int countByte);

// �������� �� �����
int deleteToFile(char* buffer, const char nameFile[], unsigned int countByte);

// �������� ������������
void createUser(UserData* users, int* count_user, CryptKey** key);

// ����
void menu(int* mode);

// �������� ������ � ������
book_t* loadingDataBooks(int** countBooks);

// 1. �������� ���� ����
book_t* AllBooks(int** countBooks);

// ����� ����� � ������
void SearchBook(book_t* books, book_t* searcBook, int* countBook);

// 2. ����� �����
void SearchBook(book_t* books, int* countBook);

// 4. ���������� �����
book_t* AddBook(book_t* books, int** countBooks);

// �������� ����� � �����; flag - 1 ����������, 2 ��������������, 3 ��� ����������;
void CpyBook(char* pathSource, char* pathDestination, int flag);

// 3. �������� �����
void DownloadBook(book_t* books, int** countBooks);

// ����� �������� �����
void DownloadBook(book_t* book);

// 5. �������� ����� 
book_t* DeleteBook(book_t* books, int** countBooks);

// ����� �������� 
book_t* DeleteBook(book_t* books, book_t book_p, int** countBooks);