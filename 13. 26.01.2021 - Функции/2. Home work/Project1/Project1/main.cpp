#include <iostream>

using namespace std;

// Функция задача 1. Функция находит минимальное значение трех чисел
int min_f(int a, int b, int c)
{
    int min;

    // если число A или C является минимальным
    if (a <= b)
    {
        if (a <= c)
            min = a;
        else min = c;
    }

    // если число B или C является минималным
    if (b <= a)
    {
        if (b <= c)
            min = b;
        else min = c;
    }

    // функция возвращает минимальное знаачение 
    return min;
}

// Функция задача 2. Находит максимальное значение в двух массивах 
int _max(int a[], size_t size_a, int b[], size_t size_b)
{
    // функция находит максимальное число перого массива 
    int max_a = a[0];
    for (size_t i = 0; i < size_a; i++)
    {
        if (max_a < a[i])
            max_a = a[i];
    }

    // функция находит максимальное число второго массива 
    int max_b = b[0];
    for (size_t i = 0; i < size_b; i++)
    {
        if (max_b < b[i])
            max_b = b[i];
    }

    // максимальое значение в двух массивах по умолчанию равно 
    // максимальному значению первого массива 
    int max = max_a;

    // если максимальное значение второго массива больше, чем
    // максимальное значение первого массива, то это значение 
    // является максимальным
    if (max_b > max_a)
        max = max_b;

    // функция возвращает максимальное значение 
    return max;
}

// Функция задача 3. Определеяет, является ли строка отрицательным 
// дробным числом 
bool factional(char a[], size_t size)
{
    bool res = true;

    // строка нужных символов для проверки
    char b[13] = "-.0123456789";

    // проверка строки
    for (size_t i = 0, dot = 0; a[i] != 0; i++)
    {
        for (size_t k = 0; b[k] != 0; k++)
        {
            // если символ совпадает с сиволом в строке для проверки
            if (a[i] == b[k])
            {
                // если первым сиволом не является минус '-' или если текущий символ является 
                // минусом '-', но при текущий элемент не является первым 
                if (i == 0 && k != 0 || i != 0 && k == 0)
                {
                    res = false;
                    break;
                }

                // счётчик точек
                if (k == 1)
                    dot++;

                // если количество точек больше одной или если вторым сиволом является точка '.' 
                if (dot > 1 || (k == 1 && i == 1))
                {
                    res = false;
                    break;
                }
            }

            // если следующим элементом является 0 (конец строки) и при этом текущий элемент 
            // небыл найден в строке с допустимыми символами
            else if (b[k + 1] == 0)
                res == false;
        }

        // если количество точек является нулем и при этом следующим элементом является 0
        if (dot == 0 && a[i + 1] == 0)
            res = false;

        // если флаг является отрицательным 
        if (res == false)
            break;
    }

    // возвращение результата работа 
    return res;
}

// Функция задача 4. Определяет, равны ли две строки
bool lines_equal(char a[], char b[], size_t size)
{
    bool res = true;

    for (size_t i = 0; a[i] != 0 || b[i] != 0; i++)
    {
        if (a[i] != b[i])
        {
            res = false;
            break;
        }
    }

    return res;
}

// Функция задача 5. Вставляет восклицательные знаки после каждой гласной в строке
bool str_vowels(char a[], size_t size)
{
    // строка нужных символов 
    char b[13] = "AaEeYyUuOoIi";

    bool res = true;
    
    // длина строки 
    int len = strlen(a);

    // цикл текущего элемента строки
    for (size_t i = 0; a[i] != 0; i++)
    {
        // цикл проверки текущего элемента строки с элементами строки нужных символов
        for (size_t k = 0; k < 13; k++)
        {
            // если текущий элемент совпадает с элементом строки для проверки
            if (a[i] == b[k])
            {
                // если максимальная длина строки достигает предела  
                if (len == 38)
                {
                    res = false;
                    break;
                }

                // переменщение последнего элемента строки (0) с следущим элементом строки
                swap(a[len], a[len + 1]);

                // перемещение всех элементов до декущего(без текущего) вправо 
                for (size_t j = len; j != i + 1; j--)
                {
                    swap(a[j], a[j - 1]);
                }

                // следующему элементу от текущего присваивается символ '!'
                a[i + 1] = '!';

                // увеличивание дляны строки на один
                len++;
            }
        }

        // если false то выход из цикла
        if (!res)
            break;
    }

    return res;
}


int main()
{
    while (true)
    {
        int num;
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

        if (num == 1)
        {
            // 1. Функция принимает 3 числа и возвращает минимальное из них

            int a, b, c;

            // ввод первого числа
            cout << "Enter num A: ";
            cin >> a;

            // ввод второго числа 
            cout << "Enter num B: ";
            cin >> b;

            // ввод третьего числа 
            cout << "Enter num C: ";
            cin >> c;

            cout << endl;

            // результат функции присваивается переменной min
            int min = min_f(a, b, c);

            // вывод минимального числа 
            cout << "Minimum number: " << min << endl;
        }

        if (num == 2)
        {
            // 2. Функция принимает 2 массива и находит максимальное значение 
            // в двух массивах

            const int size_a = 5, size_b = 10;

            int a[size_a], b[size_b];

            // ввод первого массива 
            cout << "Enter array A" << endl;

            for (size_t i = 0; i < size_a; i++)
            {
                cout << "a[" << i << "]: ";
                cin >> a[i];
            }

            cout << endl;

            // ввод второго массива
            cout << "Enter array B" << endl;

            for (size_t i = 0; i < size_b; i++)
            {
                cout << "a[" << i << "]: ";
                cin >> b[i];
            }

            cout << endl;

            // функция возвращает максимальное значение 
            int max = _max(a, size_a, b, size_b);

            // вывод максимального значения 
            cout << "Maximum numbar array A and B: " << max << endl;
        }

        if (num == 3)
        {
            // 3. Функция принимает строку и проверяет, является ли эта строка
            // отрицательным дробным числом

            char a[40];

            // ввод строки
            cout << "Enter: ";
            cin.ignore();
            cin.getline(a, 40);

            // получение результата функции
            bool res = factional(a, 40);

            // вывод результата
            if (res)
                cout << "Yes!" << endl;
            else cout << "No!" << endl;
        }

        if (num == 4)
        {
            // 4. Функция  принимает 2 строки и возвращает true, если они 
            // полностью равны, иначе возвращает false

            const size_t size = 40;

            char a[size], b[size];

            // ввод первой строки
            cout << "Enter A: ";
            cin.ignore();
            cin.getline(a, size);

            // ввод второй строки 
            cout << "Enter B: ";
            cin.getline(b, size);

            // вывод результата
            if (lines_equal(a, b, size))
                cout << "Yes!" << endl;
            else cout << "No!" << endl;
        }

        if (num == 5)
        {
            // 5. Функция принимает строку и после каждой гласной буквы 
            // вставляет '!'. "Hello" => "He!llo!"

            char a[40];

            // ввод строки
            cout << "Enter: ";
            cin.ignore();
            cin.getline(a, 40);



            // вывод результата
            cout << "Result" << endl;

            if (!str_vowels(a, 40))
                cout << endl << "To many vowels!" << endl;
            else   cout << a << endl;

        }
    }

    return 0;
}