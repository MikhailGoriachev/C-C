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

// Пользователь вводит 2 имени файла, программа удаляет из первого файла все цифры и результат записывает во второй файл
/*char nameFile1[80], nameFile2[80];

cout << "Enter name file 1: ";
cin >> nameFile1;

cout << "Enter name file 2: ";
cin >> nameFile2;

FILE* file1 = fopen(nameFile1, "r");
FILE* file2 = fopen(nameFile2, "w");

if (file1 != nullptr && file2 != nullptr)
{
	while (!feof(file1))
	{
		char buffer[200], result[200];

		strcpy(buffer, "");
		fgets(buffer, 199, file1);

		// копирование символов без цифер
		size_t k = 0;
		for (size_t i = 0; buffer[i]!=0; i++)
		{
			if (buffer[i]<'0' || buffer[i]>'9')
			{
				result[k++] = buffer[i];
			}
		}
		result[k] = 0;

		fputs(result, file2);
	}

	fclose(file1);
	fclose(file2);*/

	// Пользователь вводит имя файла, программа удаляет из файла все слова, содержащие любые символы, кроме буквенных и результат записывает в другой файл.
	/*char nameFile1[80], nameFile2[80];

	cout << "Enter name file 1: ";
	cin >> nameFile1;

	cout << "Enter name file 2: ";
	cin >> nameFile2;

	FILE* file1 = fopen(nameFile1, "r");
	FILE* file2 = fopen(nameFile2, "w");

	if (file1 != nullptr && file2 != nullptr)
	{
		while (!feof(file1))
		{
			char word[200];

			fscanf(file1, "%s", word);

			// проверка считанного слова на правильность
			bool isCorrectWord = true;
			for (size_t i = 0; word[i]!=0; i++)
			{
				if (!(word[i] >='a' && word[i] <= 'z' || word[i] >= 'A' && word[i] <= 'Z'))
				{
					isCorrectWord = false;
					break;
				}
			}

			if (isCorrectWord)
			{
				fprintf(file2, "%s\n", word);
			}
		}

		fclose(file1);
		fclose(file2);
	}*/

	/*int a[5];
	for (size_t i = 0; i < 5; i++)
	{
		cin >> a[i];
	}

	cout << "Enter file name: ";

	char filename[40];
	cin >> filename;

	FILE* file = fopen(filename, "wb");

	// если файл удалось открыть
	if (file != nullptr)
	{
		// сохранение всех байтов массива в файл
		fwrite(a, sizeof(int), 5, file);
		fclose(file);

		FILE* file2 = fopen(filename, "rb");

		// если файл удалось открыть
		if (file2 != nullptr)
		{
			int b[5];

			fread(b, sizeof(int), 5, file2);
			fclose(file2);

			for (size_t i = 0; i < 5; i++)
			{
				cout << b[i] << " ";
			}
		}
	}
	else cout << "Error opening file!!!" << endl;*/

	// программа копирует один бинарный файл в другой
	/*char nameFile1[80], nameFile2[80];

	cout << "Enter name file 1: ";
	cin >> nameFile1;

	cout << "Enter name file 2: ";
	cin >> nameFile2;

	FILE* sourceFile = fopen(nameFile1, "rb");
	FILE* destinationFile = fopen(nameFile2, "wb");

	if (sourceFile != nullptr && destinationFile != nullptr)
	{
		// переместить указатель в файле в самый конец
		fseek(sourceFile, 0, SEEK_END);

		long fileSize = ftell(sourceFile);

		// переместить указатель в файле в самое начало файла
		fseek(sourceFile, 0, SEEK_SET);

		// выделить память для хранения всех байт исходного файла
		char* buffer = new char[fileSize];

		if (buffer != nullptr)
		{
			// считать содержимое исходного файла в память
			fread(buffer, sizeof(char), fileSize, sourceFile);

			// считать содержимое исходного файла в память
			fwrite(buffer, sizeof(char), fileSize, destinationFile);

			// освободить память из-под исходного файла
			delete[] buffer;
		}

		fclose(sourceFile);
		fclose(destinationFile);
	}
	else cout << "Error opening file!!!" << endl;*/

	// пользователь вводит имя файла, программа делит его на 2 равные части
	/*char nameFile1[80], destNameFile1[80], destNameFile2[80];

	cout << "Enter source file name: ";
	cin >> nameFile1;
	strcpy(destNameFile1, nameFile1);
	strcat(destNameFile1, ".part1");
	strcpy(destNameFile2, nameFile1);
	strcat(destNameFile2, ".part2");
	FILE* sourceFile = fopen(nameFile1, "rb");
	FILE* destinationFile1 = fopen(destNameFile1, "wb");
	FILE* destinationFile2 = fopen(destNameFile2, "wb");
	if (sourceFile != nullptr && destinationFile1 != nullptr && destinationFile2 != nullptr)
	{
		// переместить указатель в файле в самый конец
		fseek(sourceFile, 0, SEEK_END);
		long fileSize = ftell(sourceFile);
		// переместить указатель в файле в самое начало файла
		fseek(sourceFile, 0, SEEK_SET);
		// выделить память для хранения всех байт исходного файла
		char* buffer = new char[fileSize / 2 + 1];
		if (buffer != nullptr)
		{
			// считать первую половину файла
			fread(buffer, sizeof(char), fileSize / 2, sourceFile);
			// записать первую половину файла
			fwrite(buffer, sizeof(char), fileSize / 2, destinationFile1);

			// считать вторую половину файла
			fread(buffer, sizeof(char), fileSize - fileSize / 2, sourceFile);
			// считать содержимое исходного файла в память
			fwrite(buffer, sizeof(char), fileSize - fileSize / 2, destinationFile2);

			// освободить память из-под исходного файла
			delete[] buffer;
		}
		fclose(sourceFile);
		fclose(destinationFile1);
		fclose(destinationFile2);
	}
	else cout << "Error opening file!!!" << endl;*/
	
	// пользователь вводит 2 имени файла, программа объединяет файлы в один
	/*char nameFile1[80], nameFile2[80], destNameFile[80];

	cout << "Enter source file 1: ";
	cin >> nameFile1;

	cout << "Enter source file 2: ";
	cin >> nameFile2;

	cout << "Enter destination file: ";
	cin >> destNameFile;

	FILE* file1 = fopen(nameFile1, "rb");
	FILE* file2 = fopen(nameFile2, "rb");
	FILE* destinationFile = fopen(destNameFile, "wb");

	if (file1 != nullptr && file2 != nullptr && destinationFile != nullptr)
	{
		// выяснить размер первого файла
		fseek(file1, 0, SEEK_END);
		long fileSize = ftell(file1);
		fseek(file1, 0, SEEK_SET);

		// выделить память для хранения всех байт исходного файла
		char* buffer = new char[fileSize];
		if (buffer != nullptr)
		{
			// считать первую половину файла
			fread(buffer, sizeof(char), fileSize, file1);

			// записать первую половину файла
			fwrite(buffer, sizeof(char), fileSize, destinationFile);

			// освободить память из-под исходного файла
			delete[] buffer;
		}

		// выяснить размер первого файла
		fseek(file2, 0, SEEK_END);
		fileSize = ftell(file2);
		fseek(file2, 0, SEEK_SET);

		// выделить память для хранения всех байт исходного файла
		buffer = new char[fileSize];
		if (buffer != nullptr)
		{
			// считать первую половину файла
			fread(buffer, sizeof(char), fileSize, file2);

			// записать первую половину файла
			fwrite(buffer, sizeof(char), fileSize, destinationFile);

			// освободить память из-под исходного файла
			delete[] buffer;
		}

		fclose(file1);
		fclose(file2);
		fclose(destinationFile);
	}*/

	// программа подсчитывает частотный словарь символов для заданного файла
	char nameFile[80];

	cout << "Enter source file 1: ";
	cin >> nameFile;


	FILE* file1 = fopen(nameFile, "rb");

	if (file1 != nullptr)
	{
		// выяснить размер первого файла
		fseek(file1, 0, SEEK_END);
		long fileSize = ftell(file1);
		fseek(file1, 0, SEEK_SET);

		// выделить память для хранения всех байт исходного файла
		char* buffer = new char[fileSize];
		if (buffer != nullptr)
		{
			// считать первую половину файла
			fread(buffer, sizeof(char), fileSize, file1);

			// формирование частотного словаря
			int letters[26] = { 0 };
			for (size_t i = 0; i < fileSize; i++)
			{
				// если встретился буквенный символ
				if (buffer[i] >= 'a' && buffer[i] <= 'z')
				{
					// увеличить частоту определённой буквы на 1
					letters[buffer[i] - 'a']++;
				}
			}

			for (size_t i = 0; i < 26; i++)
			{
				cout << (char)('a' + i) << ": " << letters[i] << endl;
			}

			// освободить память из-под исходного файла
			delete[] buffer;
		}

		fclose(file1);
	}
}
