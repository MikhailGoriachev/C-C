#include <iostream>
#include <conio.h>

using namespace std;

// функция определения числа
int numDeterminal(int a[], int size);

// функция ввода
void enterString(char str[], size_t size);

// функция ввода задания 
int enterTask()
{
    int num;
    while (true)
    {
        cout << endl << "--------------------------------------------" << endl << endl;
        cout << "Enter the task number (0 = exit): ";
        cin >> num;
        cout << endl << "--------------------------------------------" << endl << endl;
        // ---------------------- parameters for entering the task number
        if (num == 0)
            break;
        if (num < 1)
        {
            cout << "Error! Pleace, enter the correct number." << endl << endl;
            continue;
        }
        // --------------------------------------------------------------
        break;
    }

    return num;

}

// вывод одномерного массива
void OutArray(char b[], size_t size);

// вывод двумерного массива
void OutArray(char a[3][4]);

// проверак на корректность символов (задание 6)
bool correctSymbSix(char a[], char b[]);

// вычиление выражения (задание 6)
float computSix(char a[], char b[]);

// перевод цифр в число (задание 6)
int numDeterminalSix(int a[], int size);

// проверка символа (задание 6)
bool detecrSymbSix(char a[], char b[], int k);

// приоритет выполнения (+ - * /)
int opArraySix(int a[], int len);

// сдвиг массива влево (задание 6)
void shiftArraySix(int a[], int j, int len);

// отчистка строки от пробелов (задание 6)
void spaceCleanSix(char a[]);

// перевод цифр в число, после точки (задание 6)
float numDeterminalDotSix(float ar, float ar_num, int j, int f);

void main()
{	
	while (true)
	{
        int num = enterTask();

        if (num == 0)
            break;

        if (num == 1)
        {
            // 1. Функция принимает 3 строки и возвращает true, 
		    // если все они равны, иначе - false

            // объявление функций 

            // функция сравнения трёх строк
            bool comparisonString(char a[], char b[], char c[], size_t size);

            // длина строки
            const size_t size = 40;

            // объявление строк
		    char a[size], b[size], c[size];

            // ввод первой строки
            cout << "Enter string a: ";
            cin.ignore();
            enterString(a, size);

            // ввод второй строки
            cout << "Enter string b: ";
            enterString(b, size);

            // ввод третьей строки
            cout << "Enter string c: ";
            enterString(c, size);

            // результат выполнения функции сравнения
            bool res = comparisonString(a, b, c, size);

            // вывод результата
            if (res)
                cout << "Yes!" << endl;
            else cout << "No!" << endl;
        }
        
        if (num == 2)
        {
            // 2. Функция принимает 2D-массив символов 3x4 и копирует
            // в одномерный массив все символы без повторений
            // Объявление функций 

            // функция ввода двумерного массива 3х4
            void enter2DArray3x4(char a[3][4]);

            // определение повторяющегося символа
            bool repeatSymb(char a[3][4]);

            // заполнение одномерного массива
            void filling1DArray(char a[3][4], char b[], size_t size);

            const int sizeY = 3, sizeX = 4, size = sizeY * sizeX + 1;

            char a[sizeY][sizeX], b[size];

            // ввод двумерного массива
            cout << "Enter array" << endl;
            enter2DArray3x4(a);

            cout << endl;

            // вывод двумерного массива
            OutArray(a);

            cout << endl;

            // заполнение одномерного массива
            filling1DArray(a, b, size);

            cout << "Result" << endl;

            // вывод двумерного массива 
            OutArray(a);

            cout << "1D Array" << endl;

            // вывод одномерного массива
            OutArray(b, size);

            cout << endl;

        }

        if (num == 3)
        {
            // 3. Функция принимает 2 строки и добавляет 2 строку в конец первой в перевёрнутом виде

            // функция переворота строки
            void stringCoup(size_t i, size_t len);

            // функция объёдинения двух строк
            void stringIntegration(char a[], char b[], size_t size, size_t len_b);
            

            const int size = 40;

            char a[size], b[size];



            // ввод первой строки
            cout << "Enter string a: ";
            cin.ignore();
            cin.getline(a, size);

            // ввод второй строки
            cout << "Enter string b: ";
            cin.getline(b, size);

            size_t len_b = strlen(b);

            // объединение двух строк
            stringIntegration(a, b, size, len_b);

            cout << "Result" << endl;

            // вывод строки
            cout << "String a: ";
            OutArray(a, size);



        }

        if (num == 4)
        {
            // 4. Функция принимает строку вида "nnnn op mmm", 
            // где nnnn, mmm - положительные целые числа, op - [+-*/]
            // (пример: 123423 + 2435) и вычисляет значение этого выражения

            // функции 

            // сравнение на коректность с допустимыми символами
            bool correctSymb(char a[], char b[]);

            // коректность ввода
            bool correctString(char a[], char b[]);

            // вычисление выражения 
            float comput(char a[], char b[]);

            // проверка на коректность записи

            const int size = 40, size_cor = 16;

            float res = -1;

            char str[size];

            // допустимые символы 
            char corsymb[size_cor] = " +-*/0123456789";

            // ввод строки
            cout << "Enter string: ";
            enterString(str, size);

            if (correctSymb(str, corsymb))
            {
                if (correctString(str, corsymb))
                {
                    res = comput(str, corsymb);
                }
            }

            cout << endl;

            cout << "Result" << endl;

            cout << endl;

            if (res == -1)
                cout << "Error!" << endl;
            else cout << str << " = " << res << endl;
        }

        if (num == 5)
        {
            // 5. Функция принимает строку и удаляет повторяющиеся 
            // символы из строки (пример: hello world -> helo wrd)

            // функции

            // удаление повторяющихся символов из массива
            void clearRepeatEleArray(char a[], size_t size);

            // функция находит повторяющиеся символы
            void repeatEleArray(char a[], size_t size);

            // сдвиг строки влево
            void shiftArray(char a[], size_t len, size_t k);

            const size_t size = 40;

            char a[size];

            // ввод строки
            cout << "Enter string: ";
            cin.ignore();
            cin.getline(a, size);

            OutArray(a, size);

            cout << endl;

            // очистка массива от повторяющихся элементов
            repeatEleArray(a, size);
            
            cout << "Result" << endl;

            // вывод результата
            OutArray(a, size);


        }

        if (num == 6)
        {
            // задание 6
            void TaskSix();

            TaskSix();
        }
	}

}

// функция ввода строки 
void enterString(char str[], size_t size)
{
    cin.ignore();
    cin.getline(str, size);
}
// вывод одномреного массива
void OutArray(char a[], size_t size)
{

    cout << a;

    cout << endl;
}

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////Функции к заданию 1/////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

// функция сравнени трех строк 
bool comparisonString(char a[], char b[], char c[], size_t size)
{
    bool res = true;

    for (size_t i = 0; a[i] != 0 || b[i] != 0 || c[i] != 0; i++)
    {
        if (a[i] != b[i] || a[i] != c[i] || b[i] != c[i])
        {
            res = false;
            break;
        }
    }

    return res;
}

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////Функции к заданию 2/////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

// ввод двумерного массива
void enter2DArray3x4(char a[3][4])
{
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t k = 0; k < 4; k++)
        {
            cout << endl << "Enter element[" << i << "][" << k << "]: ";
            a[i][k] = _getch();
            cout << a[i][k];
        }
        cout << endl;
    }

    cout << endl;
}

// заполнение одномерного массива без повторяющихся символов
void filling1DArray(char a[3][4], char b[], size_t size)
{
    bool repeatSymb(char a[3][4], int j, int p);

    int  j = 0;

    for (int i = 0; i < 3; i++)
    {
        for (int k = 0; k < 4; k++)
        {
            if (repeatSymb(a, i, k))
            {
                b[j++] = a[i][k];
            }
        }
    }

    b[j] = 0;
}

// функция определяет является ли текущий элемент повтрояющимся
bool repeatSymb(char a[3][4], int j, int p)
{
    bool res = true;

    for (int i = j; i >= 0; i--)
    {
        int k = 3;
        if (i == j)
            k = p;
        for (; k >= 0; k--)
        {
            
            if ((i != j || k != p) && a[j][p] == a[i][k])
            {
                res = false;
                return res;
            }
            
            if (i == 0 && k == 0)
                break;
        }
    }

    return res;
}

// вывод двумерного массива
void OutArray(char a[3][4])
{
    cout << "2D Array" << endl;

    for (size_t i = 0; i < 3; i++)
    {
        for (size_t k = 0; k < 4; k++)
        {
            cout << a[i][k] << " ";
        }
        cout << endl;
    }

    cout << endl;
}

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////Функции к заданию 3/////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

// переворот строки
int stringCoup(size_t i , size_t len)
{
    int k = len - 1 - i;

    return k;
}

// объединение строк
void stringIntegration(char a[], char b[], size_t size, size_t len_b)
{
    size_t len = strlen(a);

    size_t i = len;

    for (int k = 0; k < len_b; i++, k++)
    {
        if (i == 39)
        {
            a[i] = 0;
            cout << "Error! Overflow string!" << endl;
            break;
        }

        a[i] = b[stringCoup(k, len_b)];
    }

    a[i] = 0;
}

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////Функции к заданию 4/////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

// проверка на корректность введённых символов
bool correctSymb(char a[], char b[])
{
    bool flag = false;

    for (size_t i = 0; a[i] != 0; i++)
    {
        flag = false;

        for (size_t k = 0; b[k] != 0; k++)
        {
            if (a[i] == b[k])
            {
                flag = true;
                break;
            }
        }
        if (!flag)
        {
            return flag;
        }
    }

    return flag;
}

// проверка на корректность постановки символов
bool correctString(char a[], char b[])
{        
    bool space = true;
    bool symb = true;
    bool flag = false;
    bool op = false;

    for (size_t i = 0; a[i] != 0; i++)
    {
        flag = false;
        for (size_t k = 0; b[k] != 0; k++)
        {
            if (a[i] == b[k])
            {

                if (k > 0 && k < 5 && (symb == true || op == true))
                {
                    break;
                }

                if (k > 4 && k < 15 && symb == false && space == false)
                {
                    break;
                }

                if (k > 4 && k < 15)
                {
                    symb = false;
                    flag = true;
                }

                if (k == 0 && symb == false)
                {
                    space = false;
                    flag = true;
                }

                if (k > 0 && k < 5)
                {
                    symb = true;
                    space = true;
                    flag = true;
                    op = true;
                }
                
                if (k == 0)
                {
                    flag = true;
                    break;
                }

                break;
            }
        }

        if (!flag)
            return flag;
    }

    if (op == false)
        flag = false;

    return flag;
}

// объединение цифр в число
int numDeterminal(int a[], int size)
{
    int num = 0;

    int n = 0;

    for (size_t i = 0; i < size; i++)
    {
        n = a[i];
        if (i < size - 1)
        {
            for (size_t k = 0; k < size - 1 - i; k++)
            {
                n *= 10;
            }
        }
        
        num += n;
    }

    return num;
}

// вычисление выражения 
float comput(char a[], char b[]) 
{
    float res = 0;

    int ar_a[40];
    int ar_b[40];

    bool op = false;
    int id_op = 0;


    int len = 0;

    int j = 0;
    int m = 0;

    for (size_t i = 0; a[i] != 0; i++)
    {
        for (size_t k = 0, n = 0; b[k] != 0; k++)
        {
            if (k > 5)
                n++;

            if (a[i] == b[k] && k > 0 && k < 5)
            {
                op = true;

                id_op = k;

                continue;
            }

            if (a[i] == b[k])
            {
                if (k > 5 && k < 15)
                {
                    if (op == false)
                    {
                        ar_a[j++] = n;

                    }
                    else
                    {
                        ar_b[m++] = n;
                    }
                }
            }
        }
    }

    float a_num = numDeterminal(ar_a, j);
    float b_num = numDeterminal(ar_b, m);

    if (id_op == 1)
        res = a_num + b_num;
    if (id_op == 2)
        res = a_num - b_num;
    if (id_op == 3)
        res = a_num * b_num;
    if (id_op == 4)
        res = a_num / b_num;

    return res;
}

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////Функции к заданию 5/////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

// сдвиг массива влево
void shiftArray(char a[], size_t len, size_t k)
{
    for (size_t i = k; i < len; i++)
    {
        swap(a[i], a[i + 1]);
    }
}

// функция находит повторяющиеся элеметны 
void repeatEleArray(char a[], size_t size)
{
    size_t len = strlen(a);

    for (size_t i = 0; i < len; i++)
    {
        for (int k = i - 1; k >= 0; k--)
        {
            if (i == 0)
            {
                break;
            }

            if (a[i] == a[k])
            {
                shiftArray(a, len, i);
                i--; 
                len--;
                break;
            }
        }
    }
}

// очистка строки от повторяющихся элементов
void clearRepeatEleArray(char a[], size_t size)
{
    repeatEleArray(a, size);
}

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////Функции к заданию 6/////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

// тело задания 6
void TaskSix()
{
    // 6 * .Функция принимает строку вида с числами и операторами[+-*/ ]
    // вычисляет значение выражения(числа могут дробными)        ПОЛИЗ

    const int size = 40;

    char a[size];
    char b[size] = " */+-0123456789.";

    cout << "Enter string: ";
    cin.ignore();
    cin.getline(a, size);

    

    float res = 0.0;

    // проверка на коректность символов 
    if (correctSymb(a, b))
    {
        if (correctSymbSix(a, b))
        {
            res = computSix(a, b);
        }
        
    }

    cout << res << endl;
}

// проверка символа 
bool detecrSymbSix(char a[], char b[], int k)
{
    bool res = false;

    for (size_t i = 0; i < 5; i++)
    {
        if (a[k] == b[15])
        {
            return true;
        }
        if (a[k] == b[i])
        {
            res = true;
            return res;
        }
    }

    return res;
}

// перевод цифр в число
int numDeterminalSix(float a[], int size)
{
    float num = 0;

    float n = 0;

    for (size_t i = 0; i < size; i++)
    {
        n = a[i];
        if (i < size - 1)
        {
            for (size_t k = 0; k < size - 1 - i; k++)
            {
                n *= 10;
            }
        }

        num += n;
    }

    return num;
}

// приоритет выполнения (* / + -)
int opArraySix(float a[], int len)
{
    for (size_t i = 1, j = 2; i < 7; i += 2, j += 2)
    {
        for (size_t k = 1; k < len; k += 2)
        {
            if (a[k] == i || a[k] == j)
            {
                return k;
            }

        }
    }

    

    return 0;
}

// сдвиг массива влево
void shiftArraySix(float a[], int j, int len)
{
    for (size_t i = j; i < len; i++)
    {
        swap(a[i], a[i + 1]);
    }
}

// отчиска строки от пробелов 
void spaceCleanSix(char a[])
{
    for (size_t i = 0; a[i] != 0; i++)
    {
        if (a[i] == ' ')
        {
            for (size_t k = i; a[k - 1] != 0; k++)
            {
                swap(a[k], a[k + 1]);
            }
            i--;
        }
    }
}

// перевод цифр в число после точки
float numDeterminalDotSix(float ar[], float ar_num[], int j, int f)
{
    float res = 0;

    float num = 0;

    float n = 0;

    for (size_t i = 0; i < j; i++)
    {
        n = ar[i];
        if (i < j - 1)
        {
            for (size_t k = 0; k < j - 1 - i; k++)
            {
                n *= 10;
            }
        }

        num += n;

        
    }

    for (size_t w = 0; w < j; w++)
    {
        num /= 10;
    }
    
    ar_num[f] += num;

    return res;
}

// вычисление выражения (задание 6)
float computSix(char a[], char b[])
{
    /*// отчистка строки от пробелов
    spaceCleanSix(a);

    int len = strlen(a);

    int count_op = 0;
    bool op = false;
    int id_op = 0;

    int ar[40];
    int ar_num[40];

    int j = 0;
    int f = 0;

    // числа 

    int temp_res = 0;
    int temp_a = 0;
    int temp_b = 0;

    for (size_t i = 0; a[i] != 0; i++)
    {
        for (size_t k = 0, n = 0; b[k] != 0; k++)
        {
            if (k > 5)
                n++;

            // оператор
            if (a[i] == b[k] && k > 0 && k < 5)
            {
                op = true;

                count_op++;

                ar_num[f++] = k;
                break;
            }

            // цифры
            if (a[i] == b[k])
            {
                if (k > 5 && k < 15)
                {
                    ar[j++] = n;
                    if (detecrSymbSix(a, b, i + 1) || a[i + 1] == 0)
                    {
                        ar_num[f++] = (numDeterminalSix(ar, j));
                        j = 0;
                    }
                }
                break;
            }
    }
    */
    float res = 0.0;

    float ar[40];
    float ar_num[40];

    float answer[40];

    int count_op = 0;
    bool op = false;
    int id_op = 0;


    int len = 0;

    int j = 0;
    int f = 0;

    bool dot = false;

    for (size_t i = 0; a[i] != 0; i++)
    {
        for (size_t k = 0, n = 0; b[k] != 0; k++)
        {
            if (k > 5)
                n++;

            // оператор
            if (a[i] == b[k] && k > 0 && k < 5)
            {
                dot = false;

                op = true;

                count_op++;

                ar_num[f++] = k;
                break;
            }

            // точка 
            if (k == 15)
            {
                f--;
                dot = true;
                continue;
            }

            // цифры
            if (a[i] == b[k])
            {
                if (dot == true)
                {
                    ar[j++] = n;

                    if (detecrSymbSix(a, b, i + 1))
                    {
                        ar_num[f++] += (numDeterminalDotSix(ar, ar_num, j, f));
                        j = 0;
                    }
                    break;
                }

                if (k > 4 && k < 15)
                {
                    ar[j++] = n;
                    if (detecrSymbSix(a, b, i+1) || a[i+1] == 0)
                    {
                        ar_num[f] = 0;
                        ar_num[f++] = (numDeterminalSix(ar, j));
                        j = 0;
                    }
                }
                break;
            }
        }
    }

    cout << endl;

    // вывод выражения на экран
    for (size_t i = 0; i < f; i++)
    {
        if (i % 2 == 1)
        {
            if (ar_num[i] == 1)            
                cout << "*";            
            if (ar_num[i] == 2)
                cout << "/";
            if (ar_num[i] == 3)
                cout << "+";
            if (ar_num[i] == 4)
                cout << "-";
            cout << " ";
            continue;
        }
        cout << ar_num[i] << " ";
    }

    cout << "= ";

    // арифметические функции
    for (size_t i = 0;;)
    {
        i = opArraySix(ar_num, f);

        if (i == 0)
            break;

        if (ar_num[i] == 1)
        {
            ar_num[i - 1] *= ar_num[i + 1];
        }

        if (ar_num[i] == 2)
        {
            ar_num[i - 1] /= ar_num[i + 1];
        }

        if (ar_num[i] == 3)
        {
            ar_num[i - 1] += ar_num[i + 1];
        }

        if (ar_num[i] == 4)
        {
            ar_num[i - 1] -= ar_num[i + 1];
        }

        // сдвиг массива влево
        shiftArraySix(ar_num, i, f);
        shiftArraySix(ar_num, i, f);

        f -= 2;
    }


    res = ar_num[0];
    return res;
}

// проверка на корректность вида выражения 
bool correctSymbSix(char a[], char b[])
{
    // пробелы
    bool space = true;
    // цифры
    bool symb = true;
    // флаг правильности
    bool flag = false;
    // оператор 
    bool op = false;
    // точка
    bool dot = false;

    // проверка на правильность постановки выражения 
    for (size_t i = 0; a[i] != 0; i++)
    {
        flag = false;
        for (size_t k = 0; b[k] != 0; k++)
        {
            if (a[i] == b[k])
            {
                // если точка уже была введена, а оператора еще ныбыло, либо перед точкой нет цифр
                if (k == 15 && (dot == true || symb == true))
                {
                    break;
                }

                // точка
                if (k == 15)
                {
                    dot = true;
                    flag = true;
                }

                // если это */+- и при этом флаг цифр ещё небыло вообще или цифр небыло после прошлого оператора
                if (k > 0 && k < 5 && symb == true)
                {
                    break;
                }

                // если цифры и при этом цифры уже были введены и пробел после цифр стоял
                if (k > 4 && k < 15 && symb == false && space == false)
                {
                    break;
                }

                // цифры
                if (k > 4 && k < 15)
                {
                    symb = false;
                    flag = true;
                }

                // если пробел и при этом цифры уже вводились
                if (k == 0 && symb == false)
                {
                    space = false;
                    flag = true;
                }

                // если это оператор
                if (k > 0 && k < 5)
                {
                    symb = true;
                    space = true;
                    flag = true;
                    op = true;
                    dot = false;

                    // если предыдущем символом является точка
                    if (a[i - 1] == b[15])
                    {
                        flag = false;
                        break;
                    }
                }

                // если пробел
                if (k == 0)
                {
                    flag = true;

                    // если предыдущий символ является точкой 
                    if (a[i - 1] == b[15])
                    {
                        flag = false;
                        break;
                    }

                    break;
                }

                break;
            }
        }

        if (!flag)
            return flag;
    }

    if (op == false)
        flag = false;

    return flag;
}
