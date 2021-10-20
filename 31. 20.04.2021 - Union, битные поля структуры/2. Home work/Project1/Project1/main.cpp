#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <conio.h>

using namespace std;

// ��������� ������ ��� ����������
struct data_arr
{
	// ����� ������� 
	long sizeArray;

	// ��������� �����
	clock_t start;

	// ����� ����������
	clock_t stop;

	// ����������� �����
	clock_t time;

	// �������� ����������
	char nameSort[20];

	// ���� � ����� � ��������
	char saveArrayPath[_MAX_PATH];
};

// ����� �����
void outLine()
{
	cout << "\n------------------------------------------------------------------------\n\n";
}

// ������� ����� �������
void pressAnyKey()
{
	cout << "PRESS ANY KEY [..]" << endl;

	_getch();
}

// ����� "�����" ���������
void outHeader()
{
	system("cls");

	outLine();

	cout << "SORT ARRAY" << endl;

	outLine();
}

// ����������� �������
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
	// ����� ������ 
	data->start = clock();

	// ���������� ���������
	for (long* arr = array + size - 1; arr > array; arr--, size--)
	{
		for (long* i = array; i < arr; i++)
		{
			// ���� ������� ������� ������ ����������
			if (*i > *(i + 1))
			{
				swap(*i, *(i + 1));
			}
		}
	}

	// ����� ���������
	data->stop = clock();

	// ������ ������� ���������� � ���������
	data->time = data->stop - data->start;
}

// 2. SORT BY SELECTION
void SelectSort(long* array, data_arr* data)
{
	// ����� ������
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

	// ����� ���������
	data->stop = clock();

	// ����� ����������
	data->time = data->stop - data->start;
}

// 3. SORT BY INSERTS
void InsertSort(long* array, data_arr* data)
{
	// ����� ������
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

	// ����� ���������
	data->stop = clock();

	// ����� ����������
	data->time = data->stop - data->start;
}

// 4. QUICK SORT
void QuickSort(long* array, long size)
{
	// ��������� �� �������� ��������
	
	// ��������� 1
	long* i = new long;

	*i = 0;

	// ��������� 2
	long* k = new long;

	*k = size - 1;

	// ����������� �������
	long* centr = new long;

	*centr = array[size>>1];

	// ���������� �������
	do
	{
		// ���� �������� �������� ������� ��������� ������ �������� ������������ ��������
		while (*(array + *i) < *centr)
			++*i;

		// ���� �������� �������� ������� ��������� ������ �������� ������������ ��������
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

	// ����������� ������ �������
	if (*k > 0) QuickSort(array, *k);
	if ( size > *i) QuickSort(array + *i, size - *i);
}

// ���� ���������� 
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

	// ���� ������� �������
	cout << "Enter size array: ";
	cin >> data->sizeArray;

	// ������������ �������� ��������� ������ � ���� ��� ���
	cout << "Save array to file? (Y/N): ";

	// ���� 
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

				// ���� ���� � ����� ���������� ������� 
				cout << "Enter path to save file: ";
				cin.ignore();
				cin.getline(data->saveArrayPath, _MAX_PATH);

				cout << endl;

				// �������� �����
				FILE* saveF = fopen(data->saveArrayPath, "wb");

				// ���� ���� ������ ���������
				if (saveF == nullptr)
				{
					cout << "ERROR CREATE FILE \"" << data->saveArrayPath << "\"" << endl;

					cout << endl;

					continue;
				}

				// �������� �����
				fclose(saveF);

				break;
			}

			break;
		}

		if (*c == 'N' || *c == 'n')
		{
			cout << "No" << endl;

			// ������ ���� �� ���� '-'
			strcpy(data->saveArrayPath, "-");

			break;
		}
	}

	// ������
	*array = new long[data->sizeArray];
	*arrayCpy = new long[data->sizeArray];

	// ���������� ������� ���������� �������
	for (long* arr = *array; arr < *array + data->sizeArray; arr++)
	{
		*arr = rand() % (data->sizeArray + 1);
	}

}

void main()
{
	srand(time(0));

	// ������ �����
	char* c = new char;
	char* cymb = new char;

	// ��������� ������ � ����������
	data_arr* data = new data_arr;

	// �������� ����� ��� ����������
	FILE* file = fopen("./Result.txt", "w");

	// ��������� �� ������ �������
	long** startArray = new long*;

	*startArray = nullptr;

	// ��������� �� ������ ����������
	long** array = new long*;

	*array = nullptr;

	// ���� �������������� ���������� 
	EnterOptions(data, c, startArray, array);


	// ���� ���� ������� ������
	if (file != nullptr)
	{
		// ����
		while (true)
		{
			// ����� ����� ���������
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

			// ���� 
			while (true)
			{
				*cymb = _getch();

				// ���� �������� ����� ������������� ������ ����
				if (*cymb > '0' && *cymb <= '4')
				{
					system("cls");

					outHeader();

					// ����������� ��������� �� ������� ������� � ������ ����������
					CopyArray(*array, *startArray, &data->sizeArray);

					cout << "Sort. Please wait!" << endl;

					// 1. SORT BY BUBBLE
					if (*cymb == '1')
					{
						// �������� ����������
						strcpy(data->nameSort, "SORT BY BUBBLE");

						// ����� ������� ����������
						BubbleSort(*array, data, data->sizeArray);
					}

					// 2. SORT BY SELECTION
					if (*cymb == '2')
					{
						strcpy(data->nameSort, "SORT BY SELECTION");

						// ����� ������� ����������
						SelectSort(*array, data);
					}

					// 3. SORT BY INSERTS
					if (*cymb == '3')
					{
						strcpy(data->nameSort, "SORT BY INSERTS");

						// ����� �������
						InsertSort(*array, data);
					}

					// 4. QUICK SORT
					if (*cymb == '4')
					{
						// ����� ������
						data->start = clock();

						QuickSort(*array, data->sizeArray);

						// ����� ���������
						data->stop = clock();

						// ����� ����������
						data->time = data->stop - data->start;
					}

					// ���� ���� � ����� �� ����� '-', �� ���������� � ���� �������
					if (data->saveArrayPath[0] != '-')
					{
						// �������� ����� � ������ ������������ ������
						FILE* saveFile = fopen(data->saveArrayPath, "r+");

						// ������ ������� � ����
						for (long* arr = *array; arr < *array + data->sizeArray; arr++)
						{
							fprintf(saveFile, "%li\n", *arr);
						}

						// �������� �����
						fclose(saveFile);
					}

					// ���������� ���������� �� ���������� � ���� 
					fprintf(file, "Name sort: ");
					fwrite(data->nameSort, sizeof(char), strlen(data->nameSort), file);
					fprintf(file, "\nSize array: %li\n", data->sizeArray);
					fprintf(file, "Time: %li\n", data->time);
					fprintf(file, "Path result array file: ");
					fwrite(data->saveArrayPath, sizeof(char), strlen(data->saveArrayPath), file);
					fprintf(file, "\n\n");

					system("cls");

					outHeader();

					// ����� ����������
					cout << "RESULT" << endl << endl;

					cout << "Name sort: " << data->nameSort << endl;
					cout << "Size array: " << data->sizeArray << endl;
					cout << "Time: " << data->time << endl;
					cout << "Path result array file: " << data->saveArrayPath << endl;

					// ������� ����� �������
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