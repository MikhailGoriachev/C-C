#include <iostream>

using namespace std;

void main() 
{
	/*int a, b, c;

	cout << "Enter a: ";
	cin >> a;
	cout << "Enter b: ";
	cin >> b;
	cout << "Enter c: ";
	cin >> c;

	// если a == b И b == c
	if (a == b && b == c)
	{
		cout << "YES!" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}*/


	// Пользователь вводит четыре числа. Если каждое следующее чмсло в 2 раза больше предыдущего, то программа пишет "YES", иначе "NO"
	/*int a, b, c, d;

	cout << "Enter a: ";
	cin >> a;
	cout << "Enter b: ";
	cin >> b;
	cout << "Enter c: ";
	cin >> c;
	cout << "Enter d: ";
	cin >> d;

	if (b == a * 2 && c == b * 2 && d == c * 2)		
		cout << "YES";
	else
		cout << "NO";*/

		// Пользователь вводит четыре числа. Если одно из чисел меньше отрицательное, то программа пишет "YES", иначе "NO"
	/*int a, b, c;

	cout << "Enter a: ";
	cin >> a;
	cout << "Enter b: ";
	cin >> b;
	cout << "Enter c: ";
	cin >> c;

	if (a < 0 || b < 0 || c < 0)
		cout << "YES";
	else
		cout << "NO"; 
	*/

			//ЦИКЛ FOR

	//Бесконечный цикл
	/*for (;;)
	{
		cout << "YES";
	}*/

	// for  (создание переменной и присваивание ей значения; условия выполнения; действие) 
	/*for (int i = 0; i <= 5; i++)
	{
		cout << i << endl;
	}
	*/

	// краткая операция присваивания a+=2 или a-=2
	// нечетная 
	/*for ( int a = 1; a <= 9; a = a+=2)
	{
		cout << a << endl;
	}
	*/

	/*for (int a = 3; a >= -2; a--)
	{
		cout << a << endl;
	}*/

	/*for (int i = 0; i < 3; i++)
	{
		cout << 1 << endl;
		cout << 0 << endl;
	}*/

	/*for (int i = 0; i <=6; i++)
	{
		if (i==4){}
		else cout << i << endl;
	}*/

	// пользователь вводит 5 чисел и каждое вводимое число прибавляется к сумме  

	/*int sum = 0, a = 0;
	for (int i = 0; i < 5; i++)
	{
		cin >> a;
		sum = sum + a;
	}

	cout << "Sum = " << sum << endl;*/


	// подсчет произведения пяти чисел
	/*int pro =1, a = 0;
	for (int i = 0; i < 4; i++)
	{
		cin >> a;
		if (a > 0)
		pro = pro * a;
	}

	cout << "Pro = " << pro << endl;*/

	// пользователь вводит 5 чисел, программа подсчитывает, сколько из этих чисел 
	// больше 3 и меньше 5 
	
	/*int a = 0, b = 0;
	for (int i = 0; i < 5; i++)
	{
		cout << "Enter num: ";
		cin >> a;
		if (a >= 3 && a <= 5)
		{
			b++;
		}
	}
	cout << b;*/

	// пользователь вводит 5 чисел, программа подсчитывает, количество троей, пятерок
	// и семерок 

	/*int n = 0, a = 0, b = 0, c = 0;
	for (int i = 0; i < 5; i++)
	{
		cout << "Enter num: ";
		cin >> n;
		if (n == 3)
			a++;
		if (n == 5)
			b++;
		if (n == 7)
			c++;
	}
	cout << "3: " << a << endl;
	cout << "5: " << b << endl;
	cout << "7: " << c << endl;*/
	
	// пользователь вводит 5 чисел, программа находит количество четных 
	// и нечетных чисел

	/*int n = 0, even = 0, odd = 0;
	for (int i = 0; i < 5; i++)
	{
		cout << "N: ";
		cin >> n;
		if (n % 2 == 0 && a != 0)
		{
			even++;
		}
		if (n % 2 == 1)
		{
			odd++;
		}
	}
	cout << "Even: " << even << endl;
	cout << "Odd: " << odd << endl;*/
	
	
}