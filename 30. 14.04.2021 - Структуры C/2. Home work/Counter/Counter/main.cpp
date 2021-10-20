#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <conio.h>
#include <io.h>

using namespace std;

struct count_t
{
	unsigned int countCPP;
	unsigned int countH;
	unsigned long countCymbol;
	unsigned long countLine;
};

// �������� ������� ����� ������� 
void pressAnyKey()
{
	cout << "\n\n\nPRESS ANY KEY [..]" << endl;

	_getch();
}


// ����� �����
void outline()
{
	cout << "\n---------------------------------------------------------------------------\n\n";
}

// ���������� ���������� .cpp, .h
bool expr(char* name, count_t* count)
{
	for (char* n = name + strlen(name); n > name; n--)
	{
		if (*n == '.')
		{
			if (!strcmp(n, ".cpp"))
			{
				count->countCPP++;

				return true;
			}

			else if (!strcmp(n, ".h"))
			{
				count->countH++;

				return true;
			}

			return false;
		}
	}

	return false;
}

void counter(char* path, count_t* count)
{
	// ���������� ����� � ����
	strcat(path, "\\");

	// ��������� �� ������ ����� ����� � ����
	char* name = path + strlen(path);

	// ���������� ����� ��� �������� ������ 
	strcpy(name, "*");

	// ������ ������
	_finddata_t list;

	// ��������� �� ������ � �������� ���
	long pointer = _findfirst(path, &list);

	if (pointer == -1)
	{
		cout << "ERROR CREATE LIST!" << endl;

		pressAnyKey();

		return;
	}

	// ������������ ������
	do
	{
		// ���� ��� ����� � ��������� "." ��� ".."
		if (!strcmp(list.name, ".") || !strcmp(list.name, ".."))
		{
			continue;
		}

		// ���������� ����� ����� � ����
		strcpy(name, list.name);

		// ���� ��� �����
		if (list.attrib & _A_SUBDIR)
		{
			// ������ ����������� �������
			counter(path, count);

			continue;
		}

		// ���� ��� ����
		if (expr(name, count))
		{
			cout << list.name << "     ";

			// �������� ����� � ������ ������
			FILE* file = fopen(path, "r");

			// ���� ���� ������� ������
			if (file != nullptr)
			{
				// ������ �����
				cout << list.size << endl;

				// ����� ��� �����
				char* buffer = new char[list.size + 1];

				// ���������� �����
				fread(buffer, sizeof(char), list.size, file);

				long size = list.size;

				for (char* b = buffer; b < buffer + size; b++)
				{
					if (*b == '\n')
					{
						count->countLine++;

						size--;
					}
					else count->countCymbol++;
				}

				count->countLine++;
				// ���������� �����
			/*	while (!feof(file))
				{
					// ���������� ������
					fgets(buffer, list.size + 1, file);

//					if (strcmp(buffer, ""))
		//			{
						// ���������� �������� �����
						count->countLine++;

						// ���������� �������� ��������
						count->countCymbol += strlen(buffer);
//					}
					// �������� ������
					strcpy(buffer, "");
				}*/

				// �������� �����
				fclose(file);

				// �������� ������
				delete[] buffer;
			}
			else cout << "ERROR" << endl;
		}

	} while (!_findnext(pointer, &list));

	// �������� ������
	_findclose(pointer);
}

void main()
{
	// ������������ ����� ����� �����, ��������� ������������ 
	// ������� �����, �������� �� ���� ������ .cpp, .h
	// � ���� ����� � � ���������.

	outline();

	cout << "COUNTER" << endl;

	outline();

	// ���� � �����
	char* path = new char[_MAX_PATH];

	// ���� �� ���������
	strcpy(path, ".");

	// ������ ����� 
	char* c = new char;

	// �����: ������� ��� ��� ������� ������� ����
	cout << "Enter path / default path(1/2): ";

	// ���� 
	while (true)
	{
		*c = _getch();

		// Enter path 1
		if (*c == '1')
		{
			cout << "1" << endl;

			// ���� ����
			cout << "Enter path: ";
			cin.getline(path, _MAX_PATH);

			break;
		}

		// Default path 2
		if (*c == '2')
		{
			cout << "2" << endl;

			break;
		}
	}

	system("cls");

	outline();

	cout << "COUNTER" << endl;

	outline();

	// ��������� ���������
	count_t* count = new count_t;

	// ��������� ���������
	count->countCPP = 0;
	count->countCymbol = 0;
	count->countH = 0;
	count->countLine = 0;

	// ������ ������� ��������
	counter(path, count);

	pressAnyKey();

	system("cls");

	outline();

	cout << "COUNTER" << endl;

	outline();

	// ����� ����������
	cout << "RESULT" << endl;
	cout << "All files .cpp and .h: " << count->countCPP + count->countH << endl;
	cout << "Count .cpp files: " << count->countCPP << endl;
	cout << "Count .h files: " << count->countH << endl;

	cout << endl;

	cout << "Count lines: " << count->countLine << endl;
	cout << "Count cumbols: " << count->countCymbol << endl;

	pressAnyKey();

}