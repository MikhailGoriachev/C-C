#pragma once

// заголовки заданий 
void task1();
void task2();
void task3();
void task4();
void task5();

// общие функции

// фунция вывода двумерного динамического массива
void out2DArray(int** a, int rows, int cols);

// функция проверки и/или создания файла 
// возвращает: 1 - файл создан, 2 - файл сущесвует 3 - отмена создания
int detectFile(char name_file[]);

// функция заполнения случайными числами
void randomNum(char name_file[]);

// фукнция запонения случаными сиволами
void randomSym(char name_file[]);

// функция выбора директории
char* enterDir(char dir[], int*  size);

// заполнение двумерного массива из цифр и симовлов
void fill2DArrayComb(char name[]);

// фукнция удаления двумерного массива
// int
void deleteArr(int** a, int rows, int cols);
// char
void deleteArr(char** a, int rows, int cols);

