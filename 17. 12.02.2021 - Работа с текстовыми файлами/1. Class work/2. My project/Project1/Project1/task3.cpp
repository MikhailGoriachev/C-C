#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

void task3()
{
	// пользователь вводит размеры двумерного массива, программа
	// заполняет массив случайными числами в диапазоне [1, 100]
	// пользователь вводит имя файла, программа сохраняет массив
	// в этом файле
	srand(time(0));

	int sizeY, sizeX;

	cout << "Enter sizeY: ";
	cin >> sizeY;

	cout << "Enter sizeX: ";
	cin >> sizeX;

	cout << endl;

	// двумерный массив
	int** a = new int* [sizeY];

	// заполнение массива
	for (size_t i = 0; i < sizeY; i++)
	{
		a[i] = new int[sizeX];
		// заполнение случайными числами
		for (size_t k = 0; k < sizeX; k++)
		{
			a[i][k] = rand() % 100;
		}
	}

	// вывод массива
	for (size_t i = 0; i < sizeY; i++)
	{
		for (size_t k = 0; k < sizeX; k++)
		{
			cout << a[i][k] << " ";
		}
		cout << endl;
	}

	cout << endl;

	char name_file[40];

	cout << "Enter name file: ";
	cin.ignore();
	cin.getline(name_file, 40);

	// открытие или создание файла
	FILE* file = fopen(name_file, "w");

	fprintf(file, "%d\n%d\n", sizeY, sizeX);

	for (size_t i = 0; i < sizeY; i++)
	{
		for (size_t k = 0; k < sizeX; k++)
		{
			fprintf(file, "%d ", a[i][k]);
		}
		fprintf(file, "\n");
	}
	fclose(file);

	cout << name_file << " " << "save" << endl;

	fclose(file);

	delete[] a;
}