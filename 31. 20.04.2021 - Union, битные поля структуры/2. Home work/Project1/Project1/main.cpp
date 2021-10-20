#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <conio.h>

using namespace std;

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

	// название сортировки
	char nameSort[20];

	// путь к файлу с массивом
	char saveArrayPath[_MAX_PATH];
};

// вывод линии
void outLine()
{
	cout << "\n------------------------------------------------------------------------\n\n";
}

// нажатие любой клавиши
void pressAnyKey()
{
	cout << "PRESS ANY KEY [..]" << endl;

	_getch();
}

// вывод "шапки" программы
void outHeader()
{
	system("cls");

	outLine();

	cout << "SORT ARRAY" << endl;

	outLine();
}

// копирование массива
void CopyArray(long* destination, long* source, long* size)
{
	for (long* dest = destination, *sour = source; dest < destination + *size; dest++, sour++)
	{
		*dest = *sour;
	}
}

// 1. SORT BY BUBBLE
void BubbleSort(long* array, data_arr* data, long size)
{
	// время начала 
	data->start = clock();

	// сортировка пузырьком
	for (long* arr = array + size - 1; arr > array; arr--, size--)
	{
		for (long* i = array; i < arr; i++)
		{
			// если текущий элемент больше следующего
			if (*i > *(i + 1))
			{
				swap(*i, *(i + 1));
			}
		}
	}

	// время окончания
	data->stop = clock();

	// запись времени выполнения в структуру
	data->time = data->stop - data->start;
}

// 2. SORT BY SELECTION
void SelectSort(long* array, data_arr* data)
{
	// время начала
	data->start = clock();

	for (long* arr = array; arr < array + data->sizeArray - 1; arr++)
	{
		for (long* i = arr; i < array + data->sizeArray; i++)
		{
			if (*i < *arr)
			{
				for (long* k = i + 1; k < array + data->sizeArray; k++)
				{
					if (*k < *i)
					{
						i = k;
					}
				}

				swap(*arr, *i);

				break;
			}
		}
	}

	// время окончания
	data->stop = clock();

	// время выполнения
	data->time = data->stop - data->start;
}

// 3. SORT BY INSERTS
void InsertSort(long* array, data_arr* data)
{
	// время начала
	data->start = clock();

	long* tmp = new long;

	long* k;

	for (long* i = array; i < array + data->sizeArray; i++)
	{
		*tmp = *i;

		for (k = i - 1; k >= array && *k > *tmp; k--)
		{
			//swap(*k, *(k + 1));
			*(k + 1) = *k;
		}

		*(k + 1) = *tmp;
	}

	// время окончания
	data->stop = clock();

	// время выполнения
	data->time = data->stop - data->start;
}

// 4. QUICK SORT
void QuickSort(long* array, long size)
{
	// указатели на исходных позициях
	
	// указатель 1
	long* i = new long;

	*i = 0;

	// указатель 2
	long* k = new long;

	*k = size - 1;

	// центральный элемент
	long* centr = new long;

	*centr = array[size>>1];

	// разделение массива
	do
	{
		// пока значение элемента первого указателя меньше значения центрального элемента
		while (*(array + *i) < *centr)
			++*i;

		// пока значение элемента второго указателя больше значения центрального элемента
		while (*(array + *k) > *centr)
			--*k;

		if (*i <= *k)
		{
			swap(*(array + *i), *(array + *k));

			++*i;
			--*k;
		}

	} while (*i <= *k);

	//delete centr;

	// рекурсивные вызовы функции
	if (*k > 0) QuickSort(array, *k);
	if ( size > *i) QuickSort(array + *i, size - *i);
}

// ввод параметров 
void EnterOptions(data_arr* data, char* c, long** array, long** arrayCpy)
{


	if (*array != nullptr)
	{
		delete[] *array;
	}

	if (*arrayCpy != nullptr)
	{
		delete[] *arrayCpy;
	}

	outHeader();

	// ввод размера массива
	cout << "Enter size array: ";
	cin >> data->sizeArray;

	// пользователь выбирает сохранять массив в файл или нет
	cout << "Save array to file? (Y/N): ";

	// ввод 
	while (true)
	{
		*c = _getch();

		// Yes
		if (*c == 'Y' || *c == 'y')
		{
			cout << "Yes" << endl;

			cout << endl;

			while (true)
			{

				// ввод пути к файлу сохранения массива 
				cout << "Enter path to save file: ";
				cin.ignore();
				cin.getline(data->saveArrayPath, _MAX_PATH);

				cout << endl;

				// открытие файла
				FILE* saveF = fopen(data->saveArrayPath, "wb");

				// если файл открыт неуспешно
				if (saveF == nullptr)
				{
					cout << "ERROR CREATE FILE \"" << data->saveArrayPath << "\"" << endl;

					cout << endl;

					continue;
				}

				// закрытие файла
				fclose(saveF);

				break;
			}

			break;
		}

		if (*c == 'N' || *c == 'n')
		{
			cout << "No" << endl;

			// замена пути на знак '-'
			strcpy(data->saveArrayPath, "-");

			break;
		}
	}

	// массив
	*array = new long[data->sizeArray];
	*arrayCpy = new long[data->sizeArray];

	// заполнение массива случайными числами
	for (long* arr = *array; arr < *array + data->sizeArray; arr++)
	{
		*arr = rand() % (data->sizeArray + 1);
	}

}

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

			cout << "\n\n\nPRESS: EXIT[ESC] RE-ENTER OPTIONS[R]";

			// ввод 
			while (true)
			{
				*cymb = _getch();

				// если введённая цифра соответствует пункту меню
				if (*cymb > '0' && *cymb <= '4')
				{
					system("cls");

					outHeader();

					// копирование элементов из массива ресурса в массив результата
					CopyArray(*array, *startArray, &data->sizeArray);

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
						// время начала
						data->start = clock();

						QuickSort(*array, data->sizeArray);

						// время окончания
						data->stop = clock();

						// время выполнения
						data->time = data->stop - data->start;
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
					fprintf(file, "\n\n");

					system("cls");

					outHeader();

					// вывод информации
					cout << "RESULT" << endl << endl;

					cout << "Name sort: " << data->nameSort << endl;
					cout << "Size array: " << data->sizeArray << endl;
					cout << "Time: " << data->time << endl;
					cout << "Path result array file: " << data->saveArrayPath << endl;

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