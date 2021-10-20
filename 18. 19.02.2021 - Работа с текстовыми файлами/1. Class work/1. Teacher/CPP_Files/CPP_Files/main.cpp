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
/*cout << "Enter file name: ";

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
*/

// 3. Пользователь вводит имя файла, программа копирует во второй файл только найденные числа в первом файле
/*cout << "Enter file name: ";

char inputFilename[40], outputFilename[40];
cout << "Enter input file name: ";
cin >> inputFilename;

cout << "Enter output file name: ";
cin >> outputFilename;

FILE* inputFile = fopen(inputFilename, "r");
FILE* outputFile = fopen(outputFilename, "w");

// если файл удалось открыть
if (inputFile != nullptr && outputFile != nullptr)
{
	// пока не достигнут конец исходного файла
	while (!feof(inputFile))
	{
		// создание буферной строки
		char s[80];

		// чтение одного слова из файла
		fscanf(inputFile, "%79s", s);

		// конвертирование строки в число
		int n = atoi(s);

		// проверка, на то, что считанная строка является числом
		if ((n == 0 && strlen(s) == 1 && s[0] == '0') || n != 0)
		{
			// сохранение числа в результирующий файл
			fprintf(outputFile, "%d\n", n);
		}
	}
	
	fclose(inputFile);
	fclose(outputFile);
}
else cout << "Error opening file!!!" << endl;*/

// 4. Пользователь вводит имя файла, программа копирует его во второй файл, но строки будут в перевёрнум виде:
// первая строка станет последней, вторая - предпоследней и т.д.

/*cout << "Enter file name: ";

char inputFilename[40], outputFilename[40];
cout << "Enter input file name: ";
cin >> inputFilename;

cout << "Enter output file name: ";
cin >> outputFilename;

FILE* inputFile = fopen(inputFilename, "r");
FILE* outputFile = fopen(outputFilename, "w");

// если файл удалось открыть
if (inputFile != nullptr && outputFile != nullptr)
{
	// подсчёт количества строк в файле
	size_t linesNumber = 0;
	// пока не достигнут конец исходного файла
	while (!feof(inputFile))
	{
		// создание буферной строки
		char s[200];

		fgets(s, 199, inputFile);

		linesNumber++;
	}

	// выделение памяти для строк из файла
	char** lines = new char* [linesNumber];

	if (lines != nullptr)
	{
		// переместить указатель в файле
		fseek(inputFile, 0, SEEK_SET);

		// количество считанных строк из файла
		size_t n = 0;
		// пока не достигнут конец исходного файла
		while (!feof(inputFile))
		{
			// создание буферной строки
			char s[200];

			// чтение строки из файла
			fgets(s, 199, inputFile);

			// если строка заканчивается на '\n', то удалить этот символ
			if (s[strlen(s) - 1] == 10)
				s[strlen(s) - 1] = 0;

			// выделение памяти под одну считанную строку
			lines[n] = new char[strlen(s) + 1];

			// копивание строки в массив строк
			strcpy(lines[n++], s);
		}

		// запись в результирующий файл
		for (int i = n-1; i >= 0; i--)
		{
			fputs(lines[i], outputFile);

			if(i != 0)
				fputs("\n", outputFile);
		}

		for (size_t i = 0; i < n; i++)
		{
			delete[] lines[i];
		}

		delete[] lines;
	} else cout << "Memory allocation error!!!" << endl;

	fclose(inputFile);
	fclose(outputFile);
}
else cout << "Error opening file!!!" << endl;*/

// пользователь вводит 2 имени файла, программа копирует из 1 файла во второй только те строки, в
// которых есть гласные буквы

/*char nameFile1[80], nameFile2[80];

char b[40] = "EeYyUuIiOoAa";

cout << "Enter name file 1: ";
cin >> nameFile1;

cout << "Enter name file 2: ";
cin >> nameFile2;

FILE* file1 = fopen(nameFile1, "r");
FILE* file2 = fopen(nameFile2, "w");

while (!feof(file1))
{
	char buffer[200];

	fgets(buffer, 199, file1);

	bool flag = false;

	for (size_t i = 0; i < strlen(buffer); i++)
	{
		flag = false;
		for (size_t k = 0; b[k] != 0; k++)
		{
			if (buffer[i] == b[k])
			{
				flag = true;
				break;
			}
		}
		if (flag)
			break;
	}

	if (flag)
	{
		fputs(buffer, file2);
	}

	strcpy(buffer, "");
}

fclose(file1);
fclose(file2);*/

}
