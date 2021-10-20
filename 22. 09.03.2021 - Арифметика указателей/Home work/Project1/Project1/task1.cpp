#include <iostream>
#include "head.h"

using namespace std;

void task1()
{
	// 1. Пользователь вводит 2 строки, программа удаляет все вхождения второй строки в первую
	// hello big big world
	//	big
	//
	//	hello   world

	// первая строка
	char* str_a = (char*)malloc(sizeof(char) * 40);

	// вторая строка 
	char* str_b = (char*)malloc(sizeof(char) * 40);

	// ввод первой строки
	cout << "Enter first string: ";
	cin.ignore();
	cin.getline(str_a, 40);

	// ввод второй строки
	cout << "Enter second string: ";
	cin.getline(str_b, 40);

	cout << endl;

	// указатель на длину первой строки
	long* len_a = (long*)malloc(sizeof(long));

	// длина первой строки	
	*len_a = strlen(str_a);

	// длина второй строки
	long* len_b = (long*)malloc(sizeof(long));

	// указатель на длину второй строки
	*len_b = strlen(str_b);

	// если первая строка короче второй
	if (*len_a < *len_b)
	{
		cout << "The first string less than the second string!" << endl;
		return;
	}

	// указатель на количетсво найденных вхождений второй строки в первую
	size_t* count = (size_t*)malloc(sizeof(size_t));

	*count = 0;

	// сканирование первой строки на наличие в ней второй строки
	for (char* p_a = str_a; *(p_a + *len_b - 1) ; p_a++)
	{
		// флаг совпадения элемента
		bool flag = true;

		// сравнения элементов
		for (char* b = str_b, *a = p_a; *b; b++, a++)
		{
			// если элемент не совпадают в первой и второй строке
			if (*a != *b)
			{
				// флаг становится отрицательным
				flag = false;

				// окончание проверки
				break;
			}
		}

		// если флаг положителый, значит вторая строка совпала с первой 
		if (flag)
		{
			// увеличенее счётчика вхождений второй строки в первую
			*count += 1;

			// удаление второй строки из первой	
			// цикл работает до тех пор пока позиция последнего элемента второй строки в первой 
			// не станет равной с текущим элементом 
			for (char* end = p_a + *len_b; p_a < end ; end--)
			{
				// цикл смещения
				// цикл работает, пока текущая поцизия + один элемент не стровняется последним элементом строки
				for (char* a = p_a; a < str_a + *len_a; a++)
				{
					swap(*a, *(a + 1));
				}
				*len_a -= 1;
			}

			// смещение указателя на одну позицию, чтоб после прибавления позиции при следующией
			// итерации цикла позиция указателя была на текущем элементе
			p_a--;
		}
	}

	// вывод результата 
	cout << "Result" << endl;

	cout << endl;

	// вывод первой строки
	cout << str_a << endl;

	cout << endl;

	// вывод количетсва взождений второй строки в первую
	cout << "Count: " << *count << endl;

	// отчистка занятой памяти в куче
	free(len_a);
	free(len_b);
	free(str_a);
	free(str_b);
	free(count);
}