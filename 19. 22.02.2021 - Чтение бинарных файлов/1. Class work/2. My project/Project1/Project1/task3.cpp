#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

void task3()
{
	char name[40];

	cout << "Enter  name file: ";
	cin >> name;

	FILE* file = fopen(name, "wb");

	cout << "Enter str: " << endl;

	if (file != nullptr)
	{
		cin.ignore();
		while (true)
		{
			char a[40];
			cin.getline(a, 40);

			if (!strcmp(a, "0"))
				break;

			fwrite(a, sizeof(char), 40, file);

			strcpy(a, "");
		}
		fclose(file);

		cout << endl;

		file = fopen(name, "rb");


		if (file != nullptr)
		{
			while (!feof(file))
			{
				char b[40];

				fread(b, sizeof(char), 40, file);

				cout << b << endl;

				strcpy(b, "");
			}

			fclose(file);
		}

		cout << endl;
	}
}