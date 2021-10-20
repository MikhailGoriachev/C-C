#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <conio.h>

#include "head.h"

using namespace std;

void main()
{
	srand(time(0));

	// символ ввода
	char* c = new char;
	char* cymb = new char;

	// структура данных о сортировке
	data_arr* data = new data_arr;

	// создание файла для результата
	FILE* file = fopen("./Result.txt", "w");

	// указатель на массив ресурса
	long** startArray = new long*;

	*startArray = nullptr;

	// указатель на массив результата
	long** array = new long*;

	*array = nullptr;

	// ввод первоначальных параметров 
	EnterOptions(data, c, startArray, array);


	// если файл успешно открыт
	if (file != nullptr)
	{
		// меню
		while (true)
		{
			// вывод шапки программы
			outHeader();

			// 1. SORT BY BUBBLE
			cout << "1. SORT BY BUBBLE" << endl;

			// 2. SORT BY SELECTION
			cout << "2. SORT BY SELECTION" << endl;

			// 3. SORT BY INSERTS
			cout << "3. SORT BY INSERTS" << endl;

			// 4. QUICK SORT
			cout << "4. QUICK SORT" << endl;

			// 5. SHELL SORT
			cout << "5. SHELL SORT" << endl;

			// 6. MERGE SORT
			cout << "6. MERGE SORT" << endl;

			// 7. HEAP SORT
			cout << "7. HEAP SORT" << endl;

			cout << "\n\n\nPRESS: EXIT[ESC] RE-ENTER OPTIONS[R]";

			// ввод 
			while (true)
			{
				*cymb = _getch();

				// если введённая цифра соответствует пункту меню
				if (*cymb > '0' && *cymb <= '7')
				{
					system("cls");

					outHeader();

					// копирование элементов из массива ресурса в массив результата
					CopyArray(*array, *startArray, &data->sizeArray);

					// обнуление счётчиков в структуре
					data->comp = 0;
					data->moving = 0;

					cout << "Sort. Please wait!" << endl;

					// 1. SORT BY BUBBLE
					if (*cymb == '1')
					{
						// название сортировки
						strcpy(data->nameSort, "SORT BY BUBBLE");

						// вывов функции сортировки
						BubbleSort(*array, data, data->sizeArray);
					}

					// 2. SORT BY SELECTION
					if (*cymb == '2')
					{
						strcpy(data->nameSort, "SORT BY SELECTION");

						// вызов функции сортировки
						SelectSort(*array, data);
					}

					// 3. SORT BY INSERTS
					if (*cymb == '3')
					{
						strcpy(data->nameSort, "SORT BY INSERTS");

						// вызов функции
						InsertSort(*array, data);
					}

					// 4. QUICK SORT
					if (*cymb == '4')
					{
						strcpy(data->nameSort, "QUICK SORT");

						// время начала
						data->start = clock();

						QuickSort(*array, data->sizeArray, data);

						// время окончания
						data->stop = clock();

						// время выполнения
						data->time = data->stop - data->start;
					}

					// 5. SHELL SORT
					if (*cymb == '5')
					{
						strcpy(data->nameSort, "SHELL SORT");

						// вызов функции
						ShellSort(*array, data);
					}

					// 6. MERGE SORT
					if (*cymb == '6')
					{
						strcpy(data->nameSort, "MERGE SORT");

						data->start = clock();

						// вызов функции
						MergeSort(*array, 0, data->sizeArray - 1, data);

						data->stop = clock();

						data->time = data->stop - data->start;
					}
					
					// 7. HEAP SORT
					if (*cymb == '7')
					{
						strcpy(data->nameSort, "HEAP SORT");

						// вызов функции
						HeapSort(*array, data);
					}


					// если путь к файла не равен '-', то сохранение в файл массива
					if (data->saveArrayPath[0] != '-')
					{
						// открытие файла в режиме расширенного чтения
						FILE* saveFile = fopen(data->saveArrayPath, "r+");

						// запись массива в файл
						for (long* arr = *array; arr < *array + data->sizeArray; arr++)
						{
							fprintf(saveFile, "%li\n", *arr);
						}

						// закрытие файла
						fclose(saveFile);
					}

					// сохранение информации об сортировке в файл 
					fprintf(file, "Name sort: ");
					fwrite(data->nameSort, sizeof(char), strlen(data->nameSort), file);
					fprintf(file, "\nSize array: %li\n", data->sizeArray);
					fprintf(file, "Time: %li\n", data->time);
					fprintf(file, "Path result array file: ");
					fwrite(data->saveArrayPath, sizeof(char), strlen(data->saveArrayPath), file);
					fprintf(file, "\nComparison: %lli", data->comp);
					fprintf(file, "\nMoving: %lli", data->moving);
					fprintf(file, "\n\n");

					system("cls");

					outHeader();

					// вывод информации
					cout << "RESULT" << endl << endl;

					cout << "Name sort: " << data->nameSort << endl;
					cout << "Size array: " << data->sizeArray << endl;
					cout << "Time: " << data->time << endl;
					cout << "Path result array file: " << data->saveArrayPath << endl;
					cout << "Comparison: " << data->comp << endl;
					cout << "Moving: " << data->moving << endl;

					// нажатие любой клавиши
					pressAnyKey();

					break;
				}

				// EXIT [ECS]
				if (*cymb == 27)
				{
					delete c;
					return;
				}

				// RE-ENTER OPTIONS[R]
				if (*cymb == 'r' || *cymb == 'R')
				{
					EnterOptions(data, c, startArray, array);

					break;
				}
			}
		}
	}

	cout << "ERROR CREATE FILE \"Result.txt\"" << endl;
}