#include <iostream>

using namespace std;

template <typename T>
T add(T a, T b)
{
	return a + b;
}

void main()
{
	cout << "result = " << add(3, 5) << endl;
	cout << "result = " << add(3.425234, 5.254543) << endl;
	cout << "result = " << add(3.43434452234455f, 5.2232344343f) << endl;
}