#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

void task4()
{
	char name_file[40];

	cout << "Enter name file: ";
	cin >> name_file;

	FILE* file = fopen(name_file, "r");

	cout << endl;

	int sizeY = 0;
	int sizeX = 0;


	// чтение размеров массива
	fscanf(file, "%d", &sizeY);
	fscanf(file, "%d", &sizeX);

	cout << "SizeY: " << sizeY << endl;
	cout << "SizeX: " << sizeX << endl;

	cout << endl;

	int** a = new int* [sizeY];

	for (size_t i = 0; i < sizeY; i++)
	{
		a[i] = new int[sizeX];
		int num;
		for (size_t k = 0; k < sizeX; k++)
		{
			fscanf(file, "%d", &num);
			a[i][k] = num;
		}
	}

	fclose(file);

	for (size_t i = 0; i < sizeY; i++)
	{
		for (size_t k = 0; k < sizeX; k++)
		{
			cout << a[i][k] << " ";
		}
		cout << endl;
	}

	delete[] a;
}