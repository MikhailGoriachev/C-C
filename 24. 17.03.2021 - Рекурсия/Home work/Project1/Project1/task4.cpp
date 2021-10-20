#include <iostream>

using namespace std;

long sumNumber(char* str)
{
	// если сивол не является концом строки
	if (*str)
	{
		// строка длиной в один жлемент для передачи 
		char c[1];

		// во временную строку заносится символ строки
		c[0] = *str;

		// перевод символа в цифру
		long sum = atoi(c);

		// возвращение присвоенного результата следующий итерации с результатом этой
		return sum += sumNumber(str + 1);
	}

	return 0;
}

void task4()
{
	// 4. Рекурсивная функция принимает строку и вычисляет
	// сумму цифер в этой строке

	// строка
	char* str = new char[40];

	// ввод строки
	cout << "Enter string: " << endl;
	cout << "> ";
	cin.ignore();
	cin.getline(str, 40);

	// суммирование цифер в строке
	cout << "Summer number: " << sumNumber(str) << endl;

	delete[] str;
}