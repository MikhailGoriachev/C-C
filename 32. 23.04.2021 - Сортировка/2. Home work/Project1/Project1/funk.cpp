#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <conio.h>

#include "head.h"

using namespace std;

// ����� �����
void outLine()
{
	cout << "\n------------------------------------------------------------------------\n\n";
}

// ������� ����� �������
void pressAnyKey()
{
	cout << "PRESS ANY KEY [..]" << endl;

	_getch();
}

// ����� "�����" ���������
void outHeader()
{
	system("cls");

	outLine();

	cout << "SORT ARRAY" << endl;

	outLine();
}

// ����������� �������
void CopyArray(long* destination, long* source, long* size)
{
	for (long* dest = destination, *sour = source; dest < destination + *size; dest++, sour++)
	{
		*dest = *sour;
	}
}

// ���� ���������� 
void EnterOptions(data_arr* data, char* c, long** array, long** arrayCpy)
{


	if (*array != nullptr)
	{
		delete[] * array;
	}

	if (*arrayCpy != nullptr)
	{
		delete[] * arrayCpy;
	}

	outHeader();

	// ���� ������� �������
	cout << "Enter size array: ";
	cin >> data->sizeArray;

	// ������������ �������� ��������� ������ � ���� ��� ���
	cout << "Save array to file? (Y/N): ";

	// ���� 
	while (true)
	{
		*c = _getch();

		// Yes
		if (*c == 'Y' || *c == 'y')
		{
			cout << "Yes" << endl;

			cout << endl;

			while (true)
			{

				// ���� ���� � ����� ���������� ������� 
				cout << "Enter path to save file: ";
				cin.ignore();
				cin.getline(data->saveArrayPath, _MAX_PATH);

				cout << endl;

				// �������� �����
				FILE* saveF = fopen(data->saveArrayPath, "wb");

				// ���� ���� ������ ���������
				if (saveF == nullptr)
				{
					cout << "ERROR CREATE FILE \"" << data->saveArrayPath << "\"" << endl;

					cout << endl;

					continue;
				}

				// �������� �����
				fclose(saveF);

				break;
			}

			break;
		}

		if (*c == 'N' || *c == 'n')
		{
			cout << "No" << endl;

			// ������ ���� �� ���� '-'
			strcpy(data->saveArrayPath, "-");

			break;
		}
	}

	// ������
	*array = new long[data->sizeArray];
	*arrayCpy = new long[data->sizeArray];

	// ���������� ������� ���������� �������
	for (long* arr = *array; arr < *array + data->sizeArray; arr++)
	{
		*arr = rand() % (data->sizeArray + 1);
	}

}