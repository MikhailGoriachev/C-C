#include <iostream>
#include <time.h>


using namespace std;

/*void main()
{
	// функция принимает двумерный массив 3 строки, 
	// 4 столбца и заменяет все нечётные числа
	// на тройки (ввод, замена, вывод)

	void enter2DArr(int a[3][4]);
	void repl(int a[3][4]);
	void print2DArray(int a[3][4]);

	const int sizeY = 3, sizeX = 4;

	int a[sizeY][sizeX];

	cout << "Enter array" << endl;
	enter2DArr(a);

	cout << endl;

	cout << "You array" << endl;
	print2DArray(a);

	cout << endl;

	repl(a);

	cout << "Result" << endl;
	print2DArray(a);
}

void enter2DArr(int a[3][4])
{
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t k = 0; k < 4; k++)
		{
			cout << "Enter element[" << i << "][" << k << "]: ";
			cin >> a[i][k];
		}
		cout << endl;
	}
}

void repl(int a[3][4])
{
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t k = 0; k < 4; k++)
		{
			if (a[i][k] % 2 == 1)
				a[i][k] = 3;
		}
	}
}

void print2DArray(int a[3][4])
{
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t k = 0; k < 4; k++)
		{
			cout << a[i][k] << " ";
		}
		cout << endl;
	}
}*/

void main()
{
	// функция принимает двумерный массив чимволов 3 строки, 3 столбцаи
	// хаотично перемешивает символы (ввод, вывод, перемешивание)

	srand(time(0));

	void enter2DCharArr(char a[3][3]);
	void print2DCharArr(char a[3][3]);
	void repl2DCharArr(char a[3][3]);
	char a[3][3];

	cout << "Enter array" << endl;
	enter2DCharArr(a);

	cout << "You array" << endl;
	print2DCharArr(a);

	cout << endl;

	repl2DCharArr(a);

	cout << "Result" << endl;
	print2DCharArr(a);

}

void enter2DCharArr(char a[3][3])
{
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t k = 0; k < 3; k++)
		{
			cout << "Element [" << i << "][" << k << "]: ";
			cin >> a[i][k];
		}
		cout << endl;
	}
}

void print2DCharArr(char a[3][3])
{
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t k = 0; k < 3; k++)
		{
			cout << a[i][k] << " ";
		}
		cout << endl;
	}
}

void repl2DCharArr(char a[3][3])
{
	int x1, y1, x2, y2;

	for (size_t i = 0; i < 3; i++)
	{
		for (size_t i = 0; i < 3; i++)
		{
			x1 = rand() % 3;
			y1 = rand() % 3;
			x2 = rand() % 3;
			y2 = rand() % 3;

			swap(a[y1][x1], a[y2][x2]);
		}
	}
}
