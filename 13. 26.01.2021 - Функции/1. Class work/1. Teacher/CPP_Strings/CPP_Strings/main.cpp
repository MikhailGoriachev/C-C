﻿#include <iostream>
#include <conio.h>

using namespace std;

void main()
{
	/*char str[40];
	str[0] = 'H';
	str[1] = 'e';
	str[2] = 'l';
	str[3] = 'l';
	str[4] = 'o';
	str[5] = 0;*/

	//char str[40] = {'H', 'e', 'l', 'l', 'o'};

	/*char str[40] = "Hello";
	char str2[40];

	// вычисление длины строки
	cout << strlen(str) << endl;

	// копирование строки str в str2
	strcpy_s(str2, str);

	cin >> str;
	cin >> str2;

	//cout << strcmp(str, str2) << endl;

	// сравнение строк
	if (strcmp(str, str2) == 0)
		cout << "Strings are equal" << endl;
	else cout << "not equal";
	
	cout << str2 << endl;

	cout << str << endl;*/

	// перебрать все символы строки и вывести их на экран
	/*char s[40];
	cin >> s;

	size_t len = 0;
	for (size_t i = 0; s[i]!=0; i++)
	{
		cout << s[i] << endl;
		len++;
	}
	cout << "String size = " << len << endl;*/

	// пользователь вводит строку, программа заменяет все гласные буквы на '!'
	/*char s[40];
	cin >> s;

	for (size_t i = 0; s[i] != 0; i++)
	{
		if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'y' || s[i] == 'u')
			s[i] = '!';
	}

	cout << s << endl;*/

	// программа показывает коды символов
	/*while (true)
	{
		char ch = _getch();
		cout << ch << " code: " << (int)ch << endl;
	}*/

	// программа вводит коды символов и выводит сами символы (выход по ESC)
	/*while (true)
	{
		int code;
		cin >> code;
		cout << "Code: " << " Symbol: " << (char)code << endl;

		if (code == 27)
			break;
	}*/

	// пользователь вводит строку, если в строке все символы одинаковые, программа выводит 'YES',
	// иначе она выводит 'No'
	/*char s[40];
	cin >> s;

	bool flag = true;
	for (size_t i = 0; s[i]!=0; i++)
	{
		if (s[i] != s[0])
		{
			cout << "Letters are not equal!" << endl;
			flag = false;
			break;
		}
	}
	if (flag)
		cout << "All letters are equal" << endl;*/

	// пользователь вводит строку, программа меняет местами первый и последний символы строки.
	/*char s[40];
	cin >> s;

	size_t len = 0;
	for (size_t i = 0; s[i] != 0; i++)
	{
		len++;
	}

	char temp = s[0];
	s[0] = s[len - 1];
	s[len - 1] = temp;

	cout << s << endl;*/

	// пользователь вводит строку, программа "переворачивает" её и выводит на экран
	/*char s[40];
	cin >> s;
	size_t len = strlen(s);

	for (size_t i = 0; i<len/2; i++)
	{
		char temp = s[i];
		s[i] = s[len - 1 - i];
		s[len - 1 - i] = temp;
	}

	cout << s << endl;*/

	// пользователь вводит 2 строки, программа определяет, равны ли они посимвольно
	/*char s[40], s2[40];
	cin >> s >> s2;

	bool equal = true;
	for (size_t i = 0; s[i]!=0 || s2[i]!=0; i++)
	{
		if (s[i] != s2[i])
		{
			equal = false;
			break;
		}
	}

	if (equal)
		cout << "Strings are equal" << endl;
	else cout << "Strings are NOT equal" << endl;*/

	// ДЗ. Задача 5. Пользователь вводит строку, программа определяет, является ли она числом
	// с плавающей запятой
	
	/*char s[40];
	cin >> s;

	// признак того, что точка уже найдена в строке
	bool isPointUsed = false;

	// признак того, что число правильное
	bool isNumberCorrect = true;

	if (s[0] == '+' || s[0] == '-' || s[0] >= '0' && s[0] <= '9' || s[0] == '.')
	{
		// если встретилась точка - запомнить это
		if (s[0] == '.')
			isPointUsed = true;

		for (size_t i = 1; s[i] != 0; i++)
		{
			// если в текущем символе обнаружена не цифра или там не точка при неиспользованной точке, то число НЕ правильное
			if ((s[i] != '.' || isPointUsed) && (s[i] < '0' || s[i] > '9'))
			{
				isNumberCorrect = false;
				break;
			}

			// если встретилась точка - запомнить это
			if (s[i] == '.')
				isPointUsed = true;
		}
	}
	else isNumberCorrect = false;
	
	if (isNumberCorrect)
		cout << "String is a number!" << endl;
	else
		cout << "String is NOT a number!" << endl;*/

	// пользователь вводит 2 строки, программа дописывает вторую строку в конец первой и выводит первую
	// строку на экран

	/*char s[40], s2[40];

	cout << "Enter first string:";
	cin.getline(s, 40);

	cout << "Enter second string:";
	cin.getline(s2, 40);

	size_t size = strlen(s);

	size_t i = 0;
	for (; s2[i]!=0; i++)
	{
		s[i + size] = s2[i];
	}
	s[size + i] = 0;

	cout << s << endl;*/

	// пользователь вводит строку, программа удаляет первый символ строки и выводит её на экран
	/*char s[40];

	cout << "Enter string:";
	cin.getline(s, 40);

	for (size_t i = 0; s[i]!=0; i++)
	{
		s[i] = s[i + 1];
	}

	cout << s << endl;*/

	// пользователь вводит строку, программа удаляет все гласные буквы из строки и выводит её на экран
	/*char s[40];

	cout << "Enter string:";
	cin.getline(s, 40);

	// цикл по символам строки
	for (size_t i = 0; s[i]!=0; i++)
	{
		if (s[i] == 'a' || s[i] == 'o' || s[i] == 'i' || s[i] == 'u' || s[i] == 'y' || s[i] == 'e')
		{
			// цикл для сдвига влево и удаления гласной буквы
			for (size_t k = i; s[k] != 0; k++)
			{
				s[k] = s[k + 1];
			}
			i--;
		}
	}

	cout << s << endl;*/

	// пользователь вводит строку, программа удаляет первую половину строки и выводит её на экран
	/*char s[40];

	cout << "Enter string:";
	cin.getline(s, 40);

	size_t n = strlen(s) / 2;

	size_t k = 0;

	for (size_t i = n; s[i]!=0; i++, k++)
	{
		s[k] = s[i];
	}

	s[k] = 0;

	cout << s << endl;*/

	// пользователь вводит строку, программа переворачивает её и выводит на экран
	/*char s[40];

	cout << "Enter string:";
	cin.getline(s, 40);

	size_t size = strlen(s);

	for (size_t i = 0; i < size/2; i++)
	{
		char temp = s[i];
		s[i] = s[size - i - 1];
		s[size - i - 1] = temp;
	}

	cout << s << endl;*/

	// пользователь вводит строку, программа удаляет все цифры и выводит строку на экран
	char s[40];

	cout << "Enter string:";
	cin.getline(s, 40);

	// цикл по символам строки
	for (size_t i = 0; s[i] != 0; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			// цикл для сдвига влево и удаления гласной буквы
			for (size_t k = i; s[k] != 0; k++)
			{
				s[k] = s[k + 1];
			}
			i--;
		}
	}

	cout << s << endl;
}