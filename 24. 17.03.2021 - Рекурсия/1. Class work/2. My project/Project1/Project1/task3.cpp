#include <iostream>

using namespace std;

// сравнение строк: первой и второй перевёрнутой
bool cmpString(char* a, char* b, size_t len)
{
	if (*a == *(b + len - 1) && *a != 0)
	{
		if (cmpString(a + 1, b, len - 1))
		{
			return true;
		}
		else return false;
	}
	if (*a == 0)
		return true;

	return false;

}

void task3()
{
	// функция принимает две строки и сравнивает первую с перевёрнутой второй

	// первая строка
	char* a = (char*)malloc(sizeof(char) * 40);

	// вторая строка
	char* b = (char*)malloc(sizeof(char) * 40);

	// ввод первой строки
	cout << "Enter first string: ";
	cin.ignore();
	cin.getline(a, 40);

	// ввод второй строки
	cout << "Enter secong string: ";
	cin.getline(b, 40);

	// длина второй строки
	size_t len = strlen(b);

	// сравнение строк: первой и второй перевёрнутой
	if (cmpString(a, b, len))
	{
		cout << "Yes" << endl;
	}
	else cout << "No" << endl;
}