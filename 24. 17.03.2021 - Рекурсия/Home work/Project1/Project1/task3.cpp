#include <iostream>

using namespace std;

// количество гласных в строке
long vowelsStr(char* str)
{
	// все гласные
	char a[] = "EeYyUuOoAa";

	// количество гласных
	long count = 0;
	
	// проверка на гласную
	for (char* c = a; *c; c++)
	{
		if (*str == *c)
		{
			count++;
		}
	}

	// до тех пор пока сивол не является нулём
	if (*(str + 1))
	{
		count += vowelsStr(str + 1);
	}

	// возвращение
	return count;

}

// сравнение количества гласных в строках
bool cmpVowelsCount(char** str, int rows, long count)
{
	// длина текущей строки
	count = vowelsStr(*str);

	long count_n = vowelsStr(*(str + 1));

	// если количетсво гласных в текущей строке не совпадает с количеством в прошлой строке
	if (rows > 1 && (count < count_n || count > count_n))
	{
		return false;
	}

	if (rows > 2)
	{
		if (!cmpVowelsCount(str + 1, rows - 1, 0))
			return false;
	}

	return true;
}

void task3()
{
	// 3. Рекурсивная функция принимает 2 строки и выясняет,
	// одинаковое ли у них количетво гласных букв.
	
	// количество строк
	int* rows = new int;

	// ввод количетсва строк
	cout << "Enter number rows: ";
	cin >> *rows;

	cin.ignore();

	// двумерный массив под количетсву строк
	char** str = new char*[*rows];

	// указатель на двумерный массив
	char** rows_s = str;

	// ввод строк
	for (int num = 1, *n = &num; rows_s < str + *rows; rows_s++, ++*n)
	{
		// создание строки
		*rows_s = new char[40];

		// ввод строки
		cout << "Enter " << *n << " string" << endl;
		cout << "> ";
		cin.getline(*rows_s, 40);
	}

	// функция выясняет равное ли количетсво гласных букв в строках
	if (!cmpVowelsCount(str, *rows, 0))
		cout << "No!" << endl;
	else cout << "Yes!" << endl;

	rows_s = str;

	// отчистка памяти от строк двумерного массива
	for (; rows_s < str + *rows; rows_s++)
	{
		delete[] rows_s;
	}

	delete[] str;
	delete rows;

}