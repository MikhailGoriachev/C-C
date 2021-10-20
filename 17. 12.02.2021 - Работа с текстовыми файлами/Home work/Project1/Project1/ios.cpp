#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

// функция вывода двумерного динамического массива
void out2DArray(int** a, int rows, int cols)
{
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t k = 0; k < cols; k++)
		{
			cout << a[i][k] << " ";
		}
		cout << endl;
	}
}

// функция выбора директории
char* enterDir(char dir[], int* size)
{
	cout << "Enter directory: ";
	cin.ignore();
	cin.getline(dir, *size);

	int len = strlen(dir);

	*size -= len;

	return &dir[len];
}

// проверка на наличие файла 
/*void detectFile(char name[])
{
	FILE* file = fopen(name, "r");

	if (file == 0)
	{
		char* a = new char[40];
		cout << "File not found. Create file? (Yes/No): ";
		// проверка введенного ответа
		while (true)
		{
			cin.getline(a, 40);
			if (strcmp(a, "Yes") == 0)
				break;
			// если ответ отрицательный, то программа завершается
			if (strcmp(a, "No") == 0)
			{
				cout << endl;
				cout << "Exit" << endl;
				return;
			}
			// если ввод некорректный то пользователь вводит ответ, пока не введет правильно
			cout << "Error! Enter Yes or No: ";
		}

		// создание файла 
		file = fopen(name, "w");
		fclose(file);
		cout << name << " save" << endl;
		
		delete[] a;
	}
	fclose(file);
}*/

// заполнение двумерного массива из цифр и симовлов
void fill2DArrayComb(char name[])
{
	srand(time(0));

	int rows, cols;

	FILE* file = fopen(name, "w");
	
	cout << "Enter rows: ";
	cin >> rows;

	cout << "Enter cols: ";
	cin >> cols;

	for (size_t i = 0; i < rows; i++)
	{
		for (size_t k = 0; k < cols; k++)
		{
			char sym = rand() % ((int)'z' - (int)'0' + 1) + (int)'0';
			fprintf(file, "%c ", sym);
		}
		fprintf(file, "\n");
	}

	fclose(file);
}

// фукнция удаления двумерного массива
// int
void deleteArr(int** a, int rows, int cols)
{
	for (size_t i = 0; i < rows; i++)
	{
		delete[] a[i];
	}

	delete[] a;
}
// char
void deleteArr(char** a, int rows, int cols)
{
	for (size_t i = 0; i < rows; i++)
	{
		delete[] a[i];
	}

	delete[] a;
}

// функция проверки и/или создания файла
int detectFile(char name_file[])
{
	FILE* file = fopen(name_file, "r");

	if (file == 0)
	{
		char a[40];
		cout << "File not found! Create a new file? (Yes/No): ";
		cin.ignore();
		cin.getline(a, 40);

		while (true)
		{
			if (!strcmp(a, "Yes"))
				break;
			if (!strcmp(a, "No"))
				return 3;
			cout << "Enter correct answer: ";
			cin.getline(a, 40);
		}

		file = fopen(name_file, "w");
		fclose(file);
		return 1;
	}
	fclose(file);
	return 0;
}

// функция заполнения случайными числами
void randomNum(char name_file[])
{
	srand(time(0));
	int rows, cols;

	cout << endl;

	cout << "Enter rows: ";
	cin >> rows;

	cout << endl;

	cout << "Enter cols: ";
	cin >> cols;

	cout << endl;

	int** a = new int* [rows];

	FILE* file = fopen(name_file, "w");

	for (size_t i = 0; i < rows; i++)
	{
		a[i] = new int[cols];
		for (size_t k = 0; k < cols; k++)
		{
			a[i][k] = rand() % 89 + 10;
			fprintf(file, "%d ", a[i][k]);
		}
		fprintf(file, "\n");
	}

	deleteArr(a, rows, cols);

	fclose(file);
}

// фукнция запонения случаными сиволами
void randomSym(char name_file[])
{
	char b[53] = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";

	srand(time(0));

	int rows, cols;

	cout << endl;

	cout << "Enter rows: ";
	cin >> rows;

	cout << endl;

	cout << "Enter cols: ";
	cin >> cols;

	cout << endl;

	FILE* file = fopen(name_file, "w");

	char** a = new char* [rows];
	for (size_t i = 0; i < rows; i++)
	{
		a[i] = new char[cols];
		for (size_t k = 0; k < cols; k++)
		{
			a[i][k] = b[rand() % 52];
			fprintf(file, "%c ", a[i][k]);
		}
		fprintf(file, "\n");
	}

	deleteArr(a, rows, cols);

	fclose(file);
}
