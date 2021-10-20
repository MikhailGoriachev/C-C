#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

void task1()
{
	// пользователь ввводит 2 имени файла программа копирует 
	// из первого файла во второй, только те строки в которых
	// есть гласные буквы

	char nameFile1[80], nameFile2[80];

	char b[40] = "EeYyUuIiOoAa";

	cout << "Enter name file 1: ";
	cin >> nameFile1;

	cout << "Enter name file 2: ";
	cin >> nameFile2;

	FILE* file1 = fopen(nameFile1, "r");
	FILE* file2 = fopen(nameFile2, "w");

	while (!feof(file1))
	{
		char buffer[200];

		fgets(buffer, 199, file1);

		bool flag = false;

		for (size_t i = 0; i < strlen(buffer); i++)
		{
			flag = false;
			for (size_t k = 0; b[k] != 0; k++)
			{
				if (buffer[i] == b[k])
				{
					flag = true;
					break;
				}
			}
			if (flag)
				break;
		}

		if (flag)
		{
			fputs(buffer, file2);
		}

		strcpy(buffer, "");
	}

	fclose(file1);
	fclose(file2);
}