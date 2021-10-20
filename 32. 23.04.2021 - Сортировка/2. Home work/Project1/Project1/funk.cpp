#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <conio.h>

#include "head.h"

using namespace std;

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

// ввод параметров 
void EnterOptions(data_arr* data, char* c, long** array, long** arrayCpy)
{


	if (*array != nullptr)
	{
		delete[] * array;
	}

	if (*arrayCpy != nullptr)
	{
		delete[] * arrayCpy;
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