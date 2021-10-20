#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "header.h"

using namespace std;

void task1()
{
	srand(time(0));

	// 1. Пользователь вводит имя файла, программа считывает из 
	// файла двумерный массив чисел и выводит на эран.

	// имя файла 
	int size = 40;
	char* name_file = new char[size];

	char* p_name = enterDir(name_file, &size);

	cout << endl;

	// ввода имени файла
	cout << "Enter file name: ";
	cin.getline(p_name, size);

	cout << endl;

	// проверка на то существует ли файл
	FILE* file = fopen(name_file, "r");

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

		delete[] a;

		// создание файла 
		file = fopen(name_file, "w");

		cout << endl;

		cout << "Create Array" << endl;

		cout << endl;
		// срздание массива
		int rows, cols;

		cout << "Enter rows: ";
		cin >> rows;

		cout << "Enter cols: ";
		cin >> cols;

		int** arr = new int* [rows];

		// заполнеиние двумерного массива случайными числами
		for (size_t i = 0; i < rows; i++)
		{
			arr[i] = new int[cols];
			for (size_t k = 0; k < cols; k++)
			{
				arr[i][k] = rand() % 89 + 10;
			}
		}

		cout << endl;

		cout << "Filling file..." << endl;

		cout << endl;

		// в файле указываются размеры двумерного массива
		fprintf(file, "%d \n", rows);
		fprintf(file, "%d \n", cols);

		// заполнение файла элементами двумерного массива

		for (size_t i = 0; i < rows; i++)
		{
			for (size_t k = 0; k < cols; k++)
			{
				fprintf(file, "%d ", arr[i][k]);
			}
			fprintf(file, "\n");
		}
		
		deleteArr(arr, rows, cols);

		cout << "Completed file filling" << endl << endl;

		cout << "Save " << name_file << endl << endl;

		fclose(file);

		file = fopen(name_file, "r");
	}

	cout << "Loading " << name_file << "... " << endl;

	// размеры двумерного массива
	int rows, cols;

	// считывание размеров двумерного массива
	fscanf(file, "%d", &rows);
	fscanf(file, "%d", &cols);

	// запонение массива элементами с файла
	int** arr = new int* [rows];

	for (size_t i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
		for (size_t k = 0; k < cols; k++)
		{
			fscanf(file, "%d", &arr[i][k]);
		}
	}

	cout << endl;

	// вывод двумерного динамического массива
	out2DArray(arr, rows, cols);

	deleteArr(arr, rows, cols);

	delete[] name_file;

	cout << endl;

	// закрытие файла
	fclose(file);
}