#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

long countSentence(char* buff, long size);

void writeNewBuff(char* a, char* b, long size_a, long size_b);

void task7()
{
	// пользователь вводит имя файла программа обрабатывает таким 
	// образом что каждое предложение оказывается на новой строке (?!.)
		// имя файла
	char* name = (char*)malloc(sizeof(char) * 40);

	// ввод имени файла
	cout << "Enter file name: ";
	cin.ignore();
	cin.getline(name, 40);

	cout << endl;

	// открытие исходного файла 
	FILE* file = fopen(name, "rb");

	// если файл успешно открыт
	if (file != nullptr)
	{
		//ввод имени результирующего файла
		cout << "Enter name result file: ";
		cin.getline(name, 40);

		// указатель файла в конец
		fseek(file, 0, SEEK_END);

		// длина файла
		long size = ftell(file);

		// указатель в файле в начало
		fseek(file, 0, SEEK_SET);

		// буфер для файла
		char* buff = (char*)malloc(sizeof(char) * size);

		// считывание в буфер файла
		fread(buff, sizeof(char), size, file);

		// закрытие исходного файла
		fclose(file);

		// новая длина буфера
		long new_size = countSentence(buff, size);

		// новый буфер
		char* new_buff = (char*)malloc(sizeof(char) * size);

		// заполнение нового буфера измененным сожержанием первого буфера
		writeNewBuff(buff, new_buff, size, new_size);

		// открытие нового файла
		file = fopen(name, "wb");

		// запись в новый файл
		fwrite(new_buff, sizeof(char), new_size, file);

		// закрытие файла
		fclose(file);

		cout << "File save" << endl;

	}
	// если файл не удалось открыть
	else cout << "Error! File NOT found" << endl;


}

long countSentence(char* buff, long size)
{
	long* new_size = (long*)malloc(sizeof(long));

	*new_size = size;

	for (char* buffer = buff; buffer < buff + size; buffer++)
	{
		if (*buffer == '.' && *(buffer + 1) != '.')
			++*new_size;
		if (*buffer == '\n')
			--* new_size;
	}

	size = *new_size;

	free(new_size);

	return size;
}

void writeNewBuff(char* a, char* b, long size_a, long size_b)
{
	bool dot = false;

	long size = 0;

	for (char* aa = a, *bb = b; aa < a + size_a; aa++)
	{
		if (*aa == '\n')
			continue;

		if (*aa == '.' && *(aa - 1) != '.')
		{
			for (char* p_b = bb + 1; p_b > bb - size; p_b--)
			{
				swap(*p_b, *(p_b - 1));
			}

			*(bb - size) = '\n';

			size = -1;

			bb++;
		}

		size++;

		*bb = *aa;
		bb++;
	}
}