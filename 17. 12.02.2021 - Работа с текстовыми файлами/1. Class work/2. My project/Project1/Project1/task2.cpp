#define _CRT_SECURE_NO_WARNINGS


#include <iostream>

using namespace std;

void task2()
{
	char name[40];
	int num = 1;

	cout << "Enter name file: ";
	cin.getline(name, 40);

	int len = strlen(name);

	name[len++] = '.';
	name[len++] = 't';
	name[len++] = 'x';
	name[len++] = 't';
	name[len++] = 0;

	// чтение текстового файла 
	FILE* file = fopen(name, "r");

	/*// если файл удалось открыть
	if (file != nullptr)
	{
		char buffer[200];
		// пока не достигнут конец файла 
		// feof - конец файла
		while (!feof(file))
		{
			// чтение одной строки из файла
			strcpy(buffer, "");
			fgets(buffer, 200, file);
			cout << buffer;
		}
		fclose(file);
	}
	else cout << "Error" << endl;*/

	// если файл удалось открыть
	if (file != nullptr)
	{
		int buffer;
		// пока не достигнут конец файла 
		// feof - конец файла
		while (!feof(file))
		{
			// чтение одной строки форматированного типа из файла
			fscanf(file, "%d", &buffer);
			cout << buffer << endl;
		}
		fclose(file);
	}
	else cout << "Error" << endl;
}