#include <iostream>
#include "myio.h"

using namespace std;

// принимает массив и символ, подсчитывает, сколько раз символ встечается в массиве
size_t check2DCharArray(char a[3][4], char ch)
{
	int n = 0;
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t k = 0; k < 4; k++)
		{
			if (a[i][k] == ch)
				n++;
			if (n > 1)
				return 2;
		}
	}
	return n;
}

// печать одномерного массива
void printArray(char a[], size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

// Функция принимает число и возвращает "перевёрнутое" число: 123 = > 321
unsigned int numberReverse(unsigned int num)
{
	unsigned int result = 0;
	while (num > 0)
	{
		int delta = num % 10;
		num = num / 10;
		result = result*10 + delta;
	}
	return result;
}

void main()
{
	/*
	int a;
	a = 3;

	// вывести адрес переменной a
	cout << &a << endl;

	// создать указатель и поместить в него адрес переменной a
	int* p = &a;

	// вывести адрес, который хранится в указателе p
	cout << p << endl;

	// вывести значение, на которое указывает указатель
	cout << *p << endl;

	// объявить массив (константный указатель на 0 ячейку массива)
	int b[5] = { 1, 2, 3, 4, 5 };
	cout << b[0] << endl;

	// вывод адреса массива
	cout << b << endl;

	// объявить указатель p2 и поместить в него адрес массива b
	int* p2 = b;

	// изменение массива b через указатель p2
	p2[0] = 12;
	
	for (size_t i = 0; i < 5; i++)
	{
		cout << b[i] << " ";
	}
	cout << endl;

	// помещение в указатель p2 адреса, взятого из указателя p
	p2 = p;

	// работа с динамическим массивом
	cout << "Enter size of array: ";
	int arrSize;
	cin >> arrSize;

	float* arr = new float[arrSize];

	for (size_t i = 0; i < arrSize; i++)
	{
		arr[i] = i + 1;
		cout << arr[i] << " ";
	}
	cout << endl;

	delete[] arr;*/

	// 2. Функция принимает 2D-массив символов 3x4 и копирует в динамический одномерный массив 
	// все символы без повторений

	/*char letters[3][4];

	// ввод двумерного массива
	enter2DCharArray(letters);

	// подсчёт количества неповторяющихся элементов
	size_t counter = 0;
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t k = 0; k < 4; k++)
		{
			if (check2DCharArray(letters, letters[i][k]) == 1)
				counter++;
		}
	}

	// печать двумерного массива
	print2DCharArray(letters);

	char* letters2 = new char[counter];

	// копирование неповторяющихся элементов в одномерный массив
	size_t n = 0;
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t k = 0; k < 4; k++)
		{
			if (check2DCharArray(letters, letters[i][k]) < 2)
				letters2[n++] = letters[i][k];
		}
	}

	// печать результата
	printArray(letters2, counter);

	delete[] letters2;*/

	// 3. Функция принимает 2 строки и добавляет 2 строку в конец первой в перевёрнутом виде и помещает это всё в третью
	//	динамическую строку

	/*char s[40], s2[40];

	cout << "Enter first string: ";
	cin >> s;

	cout << "Enter second string: ";
	cin >> s2;

	// длина первой строки
	size_t length = strlen(s);

	// длина второй строки
	size_t length2 = strlen(s2);

	// выделение памяти по результат
	char* s3 = new char[length + length2 + 1];

	// копирование первой строки
	strcpy(s3, s);

	// копирование перевёрнутой второй строки
	int k = length;
	for (int i = length2-1; i>=0; i--)
	{
		s3[k++] = s2[i];
	}
	s3[length + length2] = 0;

	cout << "Result: " << s3 << endl;

	// освобождение памяти
	delete[] s3;*/

	// Функция принимает число и возвращает "перевёрнутое" число: 123 => 321
	/*int num;
	cin >> num;
	cout << numberReverse(num) << endl;*/

	// ДВУМЕРНЫЕ ДИНАМИЧЕСКИЕ МАССИВЫ
	/*size_t rows = 3;
	size_t cols = 4;

	cout << "Enter rows number: ";
	cin >> rows;

	cout << "Enter cols number: ";
	cin >> cols;

	int** a = new int* [rows];

	for (size_t i = 0; i < rows; i++)
	{
		a[i] = new int[cols];
	}

	enter2DArray(a, cols, rows);

	print2DArray(a, cols, rows);

	for (size_t i = 0; i < rows; i++)
	{
		delete[] a[i];
	}

	delete[] a;*/

	// двумерный динамический массив с различной длиной строк
	size_t rows = 3;

	cout << "Enter rows number: ";
	cin >> rows;

	int** a = new int* [rows];

	for (size_t i = 0; i < rows; i++)
	{
		a[i] = new int[i+1];

		for (size_t k = 0; k < i+1; k++)
		{
			a[i][k] = i + k + 1;
		}
	}

	for (size_t i = 0; i < rows; i++)
	{
		for (size_t k = 0; k < i + 1; k++)
		{
			cout << a[i][k] << " ";
		}
		cout << endl;
	}

	for (size_t i = 0; i < rows; i++)
	{
		delete[] a[i];
	}

	delete[] a;
}