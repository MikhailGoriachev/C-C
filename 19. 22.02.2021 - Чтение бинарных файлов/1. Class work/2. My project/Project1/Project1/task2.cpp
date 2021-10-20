#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

void task2()
{
	int a[5];
	
	for (size_t i = 0; i < 5; i++)
	{
		cin >> a[i];
	}

	char filename[40];

	cout << "Enter file name: ";
	cin >> filename;

	FILE* file = fopen(filename, "wb");

	if (file != nullptr)
	{
		// сохранение всех байтов массива в файл
		fwrite(a, sizeof(long int), 5, file);
		fclose(file);

		// sizeof - возвращает размер типа в байтах

		FILE* file2 = fopen(filename, "rb");

		if (file2 != nullptr)
		{
			int b[5];

			fread(b, sizeof(long int), 5, file2);
			fclose(file2);

			for (size_t i = 0; i < 5; i++)
			{
				cout << b[i] << " ";
			}

			cout << endl;
		}
	}
}