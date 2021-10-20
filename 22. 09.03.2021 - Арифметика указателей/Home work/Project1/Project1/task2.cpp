#include <iostream>
#include "head.h"

using namespace std;

void task2()
{
	// 2. Пользователь вводит 3 строки, программа заменяет все вхождения второй строки в первую
	// hello big big world
	//	big
	//	small
	//
	//	hello small small world

	// первая строка 
	char* str_a = (char*)malloc(sizeof(char) * 80);

	// вторая строка 
	char* str_b = (char*)malloc(sizeof(char) * 80);

	// третья строка 
	char* str_c = (char*)malloc(sizeof(char) * 80);

	// ввод первой строки 
	cout << "Enter first string: ";
	cin.ignore();
	cin.getline(str_a, 80);

	// ввод второй строки
	cout << "Enter secong string: ";
	cin.getline(str_b, 80);

	// ввод третьей строки
	cout << "Enter tird string: ";
	cin.getline(str_c, 80);

	cout << endl;

	// длина первой строки
	long* len_a = (long*)malloc(sizeof(long));

	*len_a = strlen(str_a);

	// длина второй строки
	long* len_b = (long*)malloc(sizeof(long));

	*len_b = strlen(str_b);

	// длина третьей строки
	long* len_c = (long*)malloc(sizeof(long));

	*len_c = strlen(str_c);

	// если первая строка пуста
	if (*len_a == 0)
	{
		cout << "Error! The first line is empty" << endl;
		return;
	}

	// если первая строка короче второй 
	if (*len_a < *len_b)
	{
		cout << "Error! The first string less than the second string!" << endl;
		return;
	}

	// если вторая строка имеет значение '\0'
	if (*str_b == 0)
	{
		cout << "Error! The secong line is '\\0'" << endl;
		return;
	}
	

	// счётчик количества вхождений второй строки в первую
	long* count = (long*)malloc(sizeof(long));

	*count = 0;

	// сканирование первой строки
	for (char* poz_a = str_a; *(poz_a + *len_b - 1); poz_a++)
	{
		// флаг равности элементов
		bool flag = true;

		// указатель для начальной позиции в первой строке
		char* a = poz_a;

		// проверка строк по элементно 
		for (char* b = str_b; *b; b++, a++)
		{
			// если элементы не равны
			if (*a != *b)
			{
				// флаг равенства 
				flag = false;

				// выход из текущей проверки
				break;
			}
		}

		// если сторки равны
		if (flag)
		{
			// увеличения значения счётчика
			*count += 1;

			// если вторая строка и третья различны по длине
			// 
			// если вторая строка короче третьей
			if (*len_b < *len_c)
			{
				// смещение вправо на разницу между второй и третьей строкой
				// смещение будет происходить, пока позиция указателя окончания второй строки 
				// в первой не достигнет окончание будущей третьей строки в первом файле

				a = poz_a + *len_b + 1;

				for (; a <= poz_a + *len_c; a++)
				{
					// смещение вправо
					for (char* a_a = str_a + *len_a; a_a >= a; a_a--)
					{
						swap(*a_a, *(a_a - 1));
					}

					// увеличение длины первой строки
					*len_a += 1;

					*(str_a + *len_a) = 0;
				}
			}

			// если вторая строка длинее, чем третья
			if (*len_b > *len_c)
			{
				// смещение влево на разницу между третьей и второй строкой 
				// смещение будет происходить до тех пор, пока поцизия временного 
				// указателя в первой строке не станет равен текущему указателю в 
				// строке + длина третьей сторки
				a = poz_a + *len_b - 1;

				for (; a >= poz_a + *len_c; a--)
				{
					// смещение влево
					for (char* a_a = a, * end = str_a + *len_a; a_a <= end; a_a++)
					{
						swap(*a_a, *(a_a + 1));
					}

					*len_a -= 1;
				}
			}
			
			// заполнение приготовленного места третьей строкой
			// выполняется до тех пор пока указатель в третьей строке 
			// не окажется на элементе с 0
			for (char* c = str_c; *c; c++, poz_a++)
			{
				*poz_a = *c;
			}

			// если текущий указатель первой строки равен указателю на первый элемент
			// строки и при этом элемент является 0
			if (poz_a == str_a && *poz_a == 0)
				break;

			// уменьшение указателя в первой строке на один, чтоб при 
			// следующей итерации цикла, после перемещения указателя 
			// на одну ячейку указатель указывал на следующий элемент строки
			poz_a--;

			
		}
	}

	// вывод результата
	cout << "Result" << endl;
	cout << endl;
	cout << "First string: " << str_a << endl;
	cout << endl;
	cout << "Count: " << *count << endl;

	// отчитска выделенной оперативной памяти
	free(str_a);
	free(str_b);
	free(str_c);
	free(len_a);
	free(len_b);
	free(len_c);
	free(count);
}