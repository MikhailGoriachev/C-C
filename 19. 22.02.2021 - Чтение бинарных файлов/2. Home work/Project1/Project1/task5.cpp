#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

void task5()
{
	// 5. ����������� ���������, ������� ���������� ���� �������� 
	// ��� � ���� source.cpp.���������� �� ������� �����
	// ������.������ ������ �� ���������. (+1 � ��������)

	// ��� �����
	char name[40];
	char nameEXE[40];

	// ���� ����� �����
	cout << "Enter name file: ";
	cin.ignore();
	cin.getline(name, 40);

	// ���� ����� .exe ����� 
	cout << "Enter name EXE: ";
	cin.getline(nameEXE, 40);

	// �������� .cpp ����� � ������ ��������� ������ 
	FILE* cpp = fopen(name, "rb");

	// �������� .exe ����� � ������ ��������� ����������
	FILE* exe = fopen(nameEXE, "rb");

	// ���� ����� ������� �������
	if (cpp != nullptr && exe != nullptr)
	{
		// ������� ��������� � ����� cpp � �����
		fseek(cpp, 0, SEEK_END);

		// ����� CPP �����
		long sizeCPP = ftell(cpp);

		// ������� ��������� � ������ exe � �����
		fseek(exe, 0, SEEK_END);

		// ����� ����� cpp + exe
		long sizeEXE = ftell(exe);

		// ������� ��������� � ����� cpp � ������ 
		fseek(cpp, 0, SEEK_SET);

		// ������� ��������� � ���� exe � �����
		fseek(exe, 0, SEEK_SET);

		// ����� 
		char* buffer1 = new char[sizeEXE];

		// ���������� exe ����� � �����
		fread(buffer1, sizeof(char), sizeEXE, exe);

		// �������� exe �����
		fclose(exe);

		// �������� ����� exe � ������ �������� ������
		exe = fopen(nameEXE, "wb");

		fwrite(buffer1, sizeof(char), sizeEXE, exe);

		delete[] buffer1;

		char* buffer2 = new char[sizeCPP];

		// ������ ����� cpp � �����
		fread(buffer2, sizeof(char), sizeCPP, cpp);

		// ������ ������ � ����� ����� exe
		fwrite(buffer2, sizeof(char), sizeCPP, exe);

		// �������� �����
		fclose(exe);

		fclose(cpp);

		cout << "Save" << endl;
	}
	// ���� ����� �� ������� �������
	else cout << "File open error" << endl;
}