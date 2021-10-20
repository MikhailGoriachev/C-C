#include <iostream>

using namespace std;

int countA(char str[], int count)
{
	if (*str != 0)
	{
		if (*str == 'a')
			count++;
		return countA(++str, count);
	}

	return count;
}

void task3()
{
	// 3. Рекурсивная функция принимает строку и возвращает
	// количество букв 'a'

	// строка 
	char* str = (char*)malloc(sizeof(char) * 40);

	// ввод строки
	cout << "Enter string: ";
	cin.ignore();
	cin.getline(str, 40);

	cout << endl;

	// вызов фунцкии и вывод количетсва букв 'a' в строке
	cout << "Count a: " << countA(str, 0) << endl;

	free(str);
}