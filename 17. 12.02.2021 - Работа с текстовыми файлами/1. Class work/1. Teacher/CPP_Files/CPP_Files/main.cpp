#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <time.h>

using namespace std;

void main()
{
	//puts("Hello world");
	//printf("My name is %s, I'm %d years old.", "Dima", 43);

	// открытие текстового файла для записи
	/*FILE* file = fopen("mytext.txt", "w");

	fputs("Hello world!\n", file);
	fprintf(file, "My name is %s, I'm %d years old.\nend.", "Dima", 43);

	// закрытие файла
	fclose(file);*/

	// пользователь вводит имя файла и числа, пока не введёт 0.
	// все числа, кроме 0, сохраняются в файл в столбик.
	/*cout << "Enter file name: ";

	char filename[40];
	cin >> filename;

	FILE* file = fopen(filename, "w");

	int num = 0;
	do
	{
		cin >> num;
		if (num != 0)
			fprintf(file, "%d\n", num);
	} while (num != 0);

	// закрытие файла
	fclose(file);*/

	// чтение текстового файла
	/*cout << "Enter file name: ";

	char filename[40];
	cin >> filename;

	FILE* file = fopen(filename, "r");

	// если файл удалось открыть
	if (file != nullptr)
	{
		char buffer[200];

		// пока не достигнут конец файла
		while (!feof(file))
		{
			// чтение одной строки из файла
			strcpy(buffer, "");
			fgets(buffer, 200, file);
			cout << buffer;
		}
		fclose(file);
	}
	else cout << "Error opening file!!!" << endl;*/

	// чтение файла с числами
	/*cout << "Enter file name: ";

	char filename[40];
	cin >> filename;

	FILE* file = fopen(filename, "r");

	// если файл удалось открыть
	if (file != nullptr)
	{
		int buffer;

		// пока не достигнут конец файла
		while (!feof(file))
		{
			// чтение одной форматированной строки из файла
			fscanf(file, "%d", &buffer);
			cout << buffer << endl;
		}
		fclose(file);
	}
	else cout << "Error opening file!!!" << endl;*/

	// пользователь вводит размеры двумерного массива, программа заполняет массив
	// случайными числами в диапазоне [1, 100]. пользователь вводит имя файла,
	// программ сохраняет массив там.

	/*srand(time(0));

	int rows = 0, cols = 0;
	cout << "Enter number of rows: ";
	cin >> rows;
	cout << "Enter number of cols: ";
	cin >> cols;

	int** arr = new int* [rows];

	for (size_t i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
		for (size_t k = 0; k < cols; k++)
		{
			arr[i][k] = rand() % 101;
		}
	}

	cout << "Enter file name: ";

	char filename[40];
	cin >> filename;

	FILE* file = fopen(filename, "w");

	// запись размеров в файл
	fprintf(file, "%d\n", rows);
	// запись размеров в файл
	fprintf(file, "%d\n", cols);

	// если файл удалось открыть
	if (file != nullptr)
	{
		for (size_t i = 0; i < rows; i++)
		{
			for (size_t k = 0; k < cols; k++)
			{
				fprintf(file, "%d ", arr[i][k]);
			}
			fprintf(file, "\n");
		}
		fclose(file);
	}
	else cout << "Error opening file!!!" << endl;

	delete[] arr;*/

// чтение матрицы из файла
cout << "Enter file name: ";

char filename[40];
cin >> filename;

FILE* file = fopen(filename, "r");

// если файл удалось открыть
if (file != nullptr)
{
	int rows = 0, cols = 0;

	// чтение размеров массива
	fscanf(file, "%d", &rows);
	fscanf(file, "%d", &cols);

	cout << rows << endl << cols << endl;

	
	fclose(file);
}
else cout << "Error opening file!!!" << endl;
}
