#pragma once

// ��������� ������� 
void task1();
void task2();
void task3();
void task4();
void task5();

// ����� �������

// ������ ������ ���������� ������������� �������
void out2DArray(int** a, int rows, int cols);

// ������� �������� �/��� �������� ����� 
// ����������: 1 - ���� ������, 2 - ���� ��������� 3 - ������ ��������
int detectFile(char name_file[]);

// ������� ���������� ���������� �������
void randomNum(char name_file[]);

// ������� ��������� ��������� ��������
void randomSym(char name_file[]);

// ������� ������ ����������
char* enterDir(char dir[], int*  size);

// ���������� ���������� ������� �� ���� � ��������
void fill2DArrayComb(char name[]);

// ������� �������� ���������� �������
// int
void deleteArr(int** a, int rows, int cols);
// char
void deleteArr(char** a, int rows, int cols);

