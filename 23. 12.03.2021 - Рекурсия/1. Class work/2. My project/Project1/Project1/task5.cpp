#include <iostream>

using namespace std;

int Sum(int x)
{
	int result = x;
	if (x >= 1)
		result = result + Sum(x - 1);

	return result;
}

void task5()
{
	cout << Sum(3) << endl;
	cout << "End." << endl;
}