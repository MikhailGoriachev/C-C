#include <iostream>
// для ввода строки
#include <conio.h>
using namespace std;

void main()
{
	// перебрать все символы строки и вывести их на экран
	/*char s[40];

	cin >> s;


	// длина строки
	size_t len = 0;
	for (size_t i = 0; s[i] != 0; i++)
	{
		cout << s[i] << endl;
		len++;
	}

	cout << "String size = " << len << endl;*/

	// пользователь вводит строку программа заменяет 
	// все гласные буквы на !

	/*char s[40];

	// ввод строки
	cin >> s;

	// вывод строки
	for (size_t i = 0; s[i] != 0; i++)
	{
		cout << s[i] << " ";
	}

	// проверка значений строки
	for (size_t i = 0; s[i] != 0; i++)
	{
		switch (s[i])
		{
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
			case 'y':
				s[i] = '!';
		} 

	}

	cout << endl;

	// вывод строки
	for (size_t i = 0; s[i] != 0 ; i++)
	{
		cout << s[i] << " ";
	}*/

	// пользователь показывает коды символов
	/*while (true)
	{
		char ch = _getch(); //_getch возвращает значение нажатой клавиши
		cout << ch << " code: " << (int)ch << endl; // (int) - приведение к типу int 
	}*/

	// программа вводит коды символов и выводит сами символы (выход по ESC)
	/*while (true)
	{
		int code;
		cin >> code;
		cout << "Code: " << code << " Symbol: " << (char)code << endl;

		// выход по ESC
		if (code == 27)
			break;
	}*/

	// пользователь вводит строку, если в строке все символы одинаковые
	// программа выводит YES, иначе она выводит '0'
	/*char s[40];

	cin >> s;

	bool flag = true;
	for (size_t i = 1; s[i] != 0; i++)
	{
		if (s[i] != s[0])
		{
			cout << "Letters are not equal" << endl;
			flag = false;
			break;
		}
	}

	if (flag)
		cout << "All letters are equal" << endl;*/

	// пользователь вводит строку, программа меняет мастами первый и последний 
	// символы строки
	/*char str[40];

	cin >> str;

	for (size_t i = 0; str[i] != 0; i++)
	{
		cout << str[i] << " ";
	}

	cout << endl;

	int len = 0;
	for (size_t i = 0; str[i] != 0; i++)
	{
		len++;
	}

	int temp = str[0];
	str[0] = str[len - 1];
	str[len - 1] = temp;
	
	for (size_t i = 0; str[i] != 0; i++)
	{
		cout << str[i] << " ";
	}*/

	// пользователь вводит строку, программа "переворачивает" её и 
	// выводит на экран
	/*char str[40];

	cin >> str;

	// вычисление длинны строки с помощью strlen()
	size_t len = strlen(str);

	// второй вариант
	// int len = 0;
	// for (size_t i = 0; str[i] != 0; i++)
	// {
	// 	len++;
	// }

	for (size_t i = 0, k = len - 1; i < len / 2; i++, k--)
	{
		char temp = str[i];
		str[i] = str[k];
		str[k] = temp;
	}

	// вывод строки
	cout << str << endl;*/

	// пользователь вводит 2 строки, программа определяет, равны ли они
	// посимвольно
	/*char str1[40], str2[40];

	cin >> str1 >> str2;

	bool flag = true;

	for (size_t i = 0; str1[i] != 0 || str2[i] != 0; i++)
	{
		if (str1[i] != str2[i])
		{
			flag = false;
			break;
		}
	}


	if (flag)
		cout << "YES" << endl;
	else cout << "NO"; */




}