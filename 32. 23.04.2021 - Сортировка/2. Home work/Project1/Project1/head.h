#pragma once

#include <iostream>

// структура данных для сортировки
struct data_arr
{
	// длина массива 
	long sizeArray;

	// начальное время
	clock_t start;

	// время оконочания
	clock_t stop;

	// затраченное время
	clock_t time;

	// количество сравниваний
	long long comp;

	// количество перемещений
	long long moving;

	// название сортировки
	char nameSort[20];

	// путь к файлу с массивом
	char saveArrayPath[_MAX_PATH];
};

// вывод линии
void outLine();

// нажатие любой клавиши
void pressAnyKey();

// вывод "шапки" программы
void outHeader();

// копирование массива
void CopyArray(long* destination, long* source, long* size);

// ввод параметров 
void EnterOptions(data_arr* data, char* c, long** array, long** arrayCpy);

// 1. SORT BY BUBBLE
void BubbleSort(long* array, data_arr* data, long size);

// 2. SORT BY SELECTION
void SelectSort(long* array, data_arr* data);

// 3. SORT BY INSERTS
void InsertSort(long* array, data_arr* data);

// 4. QUICK SORT
void QuickSort(long* array, long size, data_arr* data);

// 5. SORT BY SHELL
void ShellSort(long* a, data_arr* data);

// 6. MergeSort
void MergeSort(long* arr, long leftBorder, long rightBorder, data_arr* data);

// 7. HEAP SORT
void HeapSort(long* arr, data_arr* data);
