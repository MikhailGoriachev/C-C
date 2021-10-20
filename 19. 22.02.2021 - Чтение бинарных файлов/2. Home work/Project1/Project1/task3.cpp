#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

void task3()
{
	// 3. Пользователь вводит 2 имени файла, программа объединяет их в один файл

	// имена первого и второго файла
	char name1[40], name2[40], name3[40];

	// ввод имени первого файла
	cout << "Enter first file name: ";
	cin.ignore();
	cin.getline(name1, 40);

	cout << endl;

	// ввод имени второго файла
	cout << "Enter second file name: ";
	cin.getline(name2, 40);

	cout << endl;

	// ввод имени файла для сохранения
	cout << "Enter save file name: ";
	cin.getline(name3, 40);

	cout << endl;

	// открытие первого и второго файла в режиме битного чтения
	FILE* file1 = fopen(name1, "rb");
	FILE* file2 = fopen(name2, "rb");

	// открытие файла для сохранения в режиме битной записи 
	FILE* save = fopen(name3, "wb");

	// если все файлы удалось открыть
	if (file1 != nullptr && file2 != nullptr && save != nullptr)
	{
		// указатель в первом файле устанавливается в конец
		fseek(file1, 0, SEEK_END);

		// указатель во втором файле устанавливается в конец
		fseek(file2, 0, SEEK_END);

		// длина первого файла
		long size1 = ftell(file1);

		// длина второго файла
		long size2 = ftell(file2);

		// указатель в первом файле устанавливается в начало 
		fseek(file1, 0, SEEK_SET);

		// указатель во втором файле устанавливается в начало
		fseek(file2, 0, SEEK_SET);

		// длина буфера
		size_t size = size1;

		// если длина второго файла больше длины первого файла
		if (size2 > size1)
			size = size2;

		// буфер 
		char* buffer = new char[size];

		// считываение первого файла в буфер
		fread(buffer, sizeof(char), size1, file1);

		// файл для сохранения заполняется содержимым буфера 
		fwrite(buffer, sizeof(char), size1, save);

		// отчистка буфера 
		strcpy(buffer, "");

		// считыаение второго файла в буфер
		fread(buffer, sizeof(char), size2, file2);

		// файл для сохранения заполняется содержимым буфера
		fwrite(buffer, sizeof(char), size2, save);

		// закрытие первого файла
		fclose(file1);

		// закрытие второго файла
		fclose(file2);

		// закрытие файла для сохранения
		fclose(save);

		cout << "Save" << endl;
	}

	// если файл(ы) не удалось открыть
	else cout << "Error opening file!" << endl;
}