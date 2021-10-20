#include <iostream>
#include <conio.h>
#include <cstring>

using namespace std;

// функция ввода задания 
int* enterTask()
{
    int num;
    char m[1];

    int* n = &num;

    while (true)
    {
        cout << endl << "--------------------------------------------" << endl << endl;
        cout << "Enter the task number (0 = exit): ";
        do
        {
            m[0] = _getch();
        } while (m[0] < '0' || m[0] > '9');
        num = atoi(m);
        cout << num << endl;
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

    return n;

}

// функция ввода массива
void enterArray(int a[], size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        cout << "Enter element" << "[" << i << "]: ";
        cin >> a[i];
    }
    cout << endl;
}

// функция вывода массива
void outArray(int a[], size_t size)
{
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

// задание 1
void Task1();

// (задание 1) остаток от деления 
int remDivision(int a[], int size, int devis, int remaind);

// (задание 1) заполнение массива нужными элементами
void fillArray(int a[], int b[], size_t size_a, size_t size_b, int divis, int remaind);

// задание 2
void Task2();

// количество НЕ повторяющихся элементов 
int repeatEle2DArr(int a[3][4]);

// заполненение массива без повторяющихся элементов
void fillArrayTwo(int a[3][4], int b[], int size);

// задание 3
void Task3();

// функция подсчитывает количество НЕ повторяющихся символов
int repeatSymString(char a[]);

// заполнение первой строки второй в перевёрнутом виде 
int fillInvertedString(char a[], char b[], size_t size);

// заполнение третьей строки
void fillThirdString(char a[], char c[], size_t size);

// задание 4
void Task4();

// функция заполняет динамичесую строку без повторяющихся символов
void fillNoRepeatString(char a[], char b[]);

// задание 5
void Task5();

// функция по нахождению простых чисел 
bool primeNumber(int a);

// количество простых чисел в массиве
int countPrimeNumber(int a[], size_t size);

// заполнение массива простыми числами
void fillArrayPrimeNumber(int a[], size_t size_a, int b[]);

// задание 6
void Task6();

// проверка на корректность символов
bool checkCorrectSymb(char a[], char b[]);

// отчистка строки от пробелов
void clearSpaceString(char a[]);

// проверка на корректность постановки символов
bool checkCorrectStagSymb(char a[], char b[]);

// протокол выполнения выражения 
void protocolCalt(char a[], char b[], char res[]);

// координаты скобок
int bracketChar(char a[], int bracket[]);

// вычисление переданной строки и длина числа
int calculator(char a[], char b[]);

// определение очереди вычисления и координат операторов
void turn_op(float a[], int size, int turn[]);

// перобразование цифр в число с точкой 
void numFractionDot(float num_ex, int a[], int len);

// преобразование цифр в число
float numFraction(int a[], int len);

// функция переноса строки
void swapChar(char a[], int n, int len);

// перевод число в строку 
void convert(char a[], int len, float num);

// сдвиг строки
void shift(char a[], int j, int len);

// сдвиг массива 
void shiftArray(float a[], int size, int j);

/////////////////////
void main()
{
    for (size_t i = *enterTask(); i != 0; i = *enterTask())
    {
        if (i == 1)
        {
            Task1();
        }

        if (i == 2)
        {
            Task2();
        }

        if (i == 3)
        {
            Task3();
        }

        if (i == 4)
        {
            Task4();
        }

        if (i == 5)
        {
            Task5();
        }

        if (i == 6)
        {
            Task6();
        }

    }
}
/////////////////////

// задание 1
void Task1()
{
    // 1. Пользователь вводит размер массива и сам массив с клавиатуры,
    // программа копирует все чётные элементы во второй динамический массив,
    // а все нечётные элементы в третий динамический массив и выводит их на экран

    int size;

    // ввод длины массива
    cout << "Enter size array: ";
    cin >> size;

    cout << endl;

    // создание динамического массива 
    int* a = new int[size];

    cout << "Enter Array" << endl << endl;

    // ввод массива
    enterArray(a, size);

    // вывод массива
    cout << "Array: ";
    outArray(a, size);

    cout << endl;

    // размер первого массива
    int size_even = remDivision(a, size, 2, 0);

    // создание первого динамического массива
    int* even = new int[size_even];

    // заполнение массива even чётными числами
    fillArray(a, even, size, size_even, 2, 0);

    // размер второго массива
    int size_odd = remDivision(a, size, 2, 1);

    // создание второго динамического массива
    int* odd = new int[size_odd];

    // заполнение массива odd нечётными числами
    fillArray(a, odd, size, size_odd, 2, 1);

    // вывод массива с чётными числами
    if (size_even == 0)
        cout << "No even elements!";
    else
    {
        cout << "Even: ";
        outArray(even, size_even);
    }

    cout << endl;

    // вывод массива с нечётными числами
    if (size_odd == 0)
        cout << "No odd elements!";
    else
    {
        cout << "Odd: ";
        outArray(odd, size_odd);
    }
}

// функция принимает делитель и нужный остаток числа и возаращает 
// количество элементов массива соответсвующих критериям деления 
int remDivision(int a[], int size, int devis, int remaind)
{
    int count = 0;
    for (size_t i = 0; i < size; i++)
    {
        if (a[i] % devis == remaind)
        {
            count++;
        }
    }

    return count;
}

// функция принимает делитель и нужный остаток числа. Заполняет массив нужными числами
void fillArray(int a[], int b[], size_t size_a, size_t size_b, int divis, int remaind)
{
    for (size_t i = 0, k = 0; i < size_a; i++)
    {
        if (a[i] % divis == remaind)
        {
            b[k++] = a[i];
        }
    }
}

// задание 2
void Task2()
{
    // 2. Функция принимает 2D-массив символов 3x4 и копирует в 
    // динамический одномерный массив все символы без повторения
    const int sizeY = 3, sizeX = 4;

    int a[sizeY][sizeX];

    for (size_t i = 0; i < 3; i++)
    {
        for (size_t k = 0; k < 4; k++)
        {
            cout << "Enter element [" << i << "][" << k << "]: ";
            cin >> a[i][k];
        }
        cout << endl;
    }

    cout << endl;

    for (size_t i = 0; i < sizeY; i++)
    {
        for (size_t k = 0; k < sizeX; k++)
        {
            cout << a[i][k] << " ";
        }
        cout << endl;
    }

    cout << endl;

    int size = repeatEle2DArr(a);

    int* b = new int[size];

    fillArrayTwo(a, b, size);

    cout << "Array no repeat: ";
    outArray(b, size);

    cout << endl;
}

// количество повторяющихся элементов 
int repeatEle2DArr(int a[3][4])
{
    int count = 0;
    bool flag = false;

    for (int i = 0; i < 3; i++)
    {
        for (int k = 0; k < 4; k++)
        {
            for (int m = i, n = k; m >= 0; m--)
            {
                if (i == 0 && k == 0)
                    break;
                flag = false;
                for (; n >= 0; n--)
                {
                    if (i == m && k == n)
                        continue;

                    if (a[i][k] == a[m][n] && (m != i || n != k))
                    {
                        flag = true;
                        break;
                    }
                }
                if (flag)
                    break;
                n = 3;
            }
            if (!flag)
            {
                count++;
            }
        }
    }

    return count;
}

// заполненение массива без повторяющихся элементов
void fillArrayTwo(int a[3][4], int b[], int size)
{
    bool flag = false;

    for (int i = 0, j = 0; i < 3; i++)
    {
        for (int k = 0; k < 4; k++)
        {
            flag = false;
            for (int m = i, n = k; m >= 0 && flag == false; m--)
            {
                for (; n >= 0 && flag == false; n--)
                {
                    if (a[i][k] == a[m][n] && (i != m || k != n))
                        flag = true;
                }
                n = 3;
            }
            if (!flag)
                b[j++] = a[i][k];
        }
    }
}

// задание 3
void Task3()
{
    // 3. Функция принимает 2 строки и добавляет 2 строку в конец 
    // первой в перевёрнутом виде и помещает это всё в третью
    // динамическую строку

    char a[40], b[40];

    cout << "Enter first string: ";
    cin.getline(a, 40);

    cout << endl;

    cout << "Enter second string: ";
    cin.getline(b, 40);

    cout << endl;
    int size = fillInvertedString(a, b, 40);
    char* c = new char[size];

    fillThirdString(a, c, size);

    cout << "First string : " << a << endl;
    cout << "Second string: " << b << endl;
    cout << "Third string : " << c << endl;

}

// заполнение первой строки второй в перевёрнутом виде 
int fillInvertedString(char a[], char b[], size_t size)
{
    size_t len_a = strlen(a);
    int len_b = strlen(b);

    for (; len_b >= 0 && len_a < size - 2;)
    {
        a[len_a++] = b[len_b-- - 1];
    }
    a[--len_a] = 0;

    return len_a;
}

// заполнение третьей строки
void fillThirdString(char a[], char c[], size_t size)
{
    size_t i = 0;

    for (; i < size; i++)
    {
        c[i] = a[i];
    }

    c[i] = 0;
}

// задание 4
void Task4()
{
    // 4. Функция принимает строку и удаляет повторяющиеся 
    // символы из строки(пример: hello world->helo wrd)
    // и помещает результат во вторую динамическую строку

    char a[40];

    cout << "Enter string: ";
    cin.getline(a, 40);

    char* b = new char[repeatSymString(a)];

    fillNoRepeatString(a, b);

    cout << endl;

    cout << "String NO repeat elements: " << b << endl;

}

// функция подсчитывает количество НЕ повторяющихся символов
int repeatSymString(char a[])
{
    int count = 0;

    bool flag = false;
    for (size_t i = 0; i < a[i] != 0; i++)
    {
        flag = false;
        for (int k = i; k >= 0; k--)
        {
            if (i != 0 && i != k && a[i] == a[k])
            {
                flag = true;
                break;
            }
        }
        if (!flag)
            count++;
    }

    return count;
}

// функция заполняет динамичесую строку без повторяющихся символов
void fillNoRepeatString(char a[], char b[])
{
    size_t j = 0;

    for (size_t i = 0; a[i] != 0; i++)
    {
        bool flag = false;
        for (int k = i; k >= 0; k--)
        {
            if (a[i] == a[k] && i != k)
            {
                flag = true;
                break;
            }
        }
        if (!flag)
        {
            b[j++] = a[i];
        }
    }

    b[j] = 0;
}

// задание 5
void Task5()
{
    // 5. Пользователь вводит размер массива и сам массив с 
    // клавиатуры, программа копирует все простые числа во второй
    // динамический массив и выводит его на экран

    int size_a = 0;

    // ввод размера массива
    cout << "Enter size array: ";
    cin >> size_a;

    // создание первого динамического массива указанной пользователем длины
    int* a = new int[size_a];

    cout << endl;

    // ввод массива
    cout << "Enter array:" << endl << endl;
    enterArray(a, size_a);

    // вывод первого массива
    cout << "You array: ";
    outArray(a, size_a);

    cout << endl;

    // вычисление длины для второго массива
    int size_b = countPrimeNumber(a, size_a);

    // создание второго динамического массива
    int* b = new int[size_b];

    // заполнение второго массива простыми числами из первого массива
    fillArrayPrimeNumber(a, size_a, b);

    // вывод второго массива на экран
    cout << "Array prime number: ";
    outArray(b, size_b);

}

// функция по нахождению простых чисел 
bool primeNumber(int a)
{
    if (a == 2)
        return true;

    if (a < 2)
        return false;

    for (size_t i = 2; i < a / 2 + 1; i++)
    {
        if (a % i == 0)
        {
            return false;
        }
    }

    return true;
}

// количество простых чисел в массиве
int countPrimeNumber(int a[], size_t size)
{
    int count = 0;

    for (size_t i = 0; i < size; i++)
    {
        if (primeNumber(a[i]))
        {
            count++;
        }
    }

    return count;
}

// заполнение массива простыми числами
void fillArrayPrimeNumber(int a[], size_t size_a, int b[])
{
    for (size_t i = 0, k = 0; i < size_a; i++)
    {
        if (primeNumber(a[i]))
        {
            b[k++] = a[i];
        }
    }
}

// задание 6
void Task6()
{
    // 6*. Функция принимает строку вида с числами и операторами 
    // [+-*/] вычисляет значение выражения (числа могут дробными)

    char a[40];

    cout << "Enter string: ";
    cin.getline(a, 40);
    //            012345678901234567
    char b[40] = " */+-().0123456789";

    // строка для результата
    char res[40];

    // проверка на допустимые символы 
    if (checkCorrectSymb(a, b))
    {
        // проверка на корректность постановки символов
        if (checkCorrectStagSymb(a, b))
        {
            protocolCalt(a, b, res);
        }
    }

    cout << res << endl;
}

// проверка на корректность символов
bool checkCorrectSymb(char a[], char b[])
{
    for (size_t i = 0; a[i] != 0; i++)
    {
        bool flag = false;
        for (size_t k = 0; k < b[k] != 0; k++)
        {
            if (a[i] == b[k])
            {
                flag = true;
                break;
            }
        }
        if (!flag)
            return false;
    }

    return true;
}

// отчистка строки от пробелов
void clearSpaceString(char a[])
{
    for (size_t i = 0; a[i] != 0;)
    {
        if (a[i] == ' ')
        {
            for (size_t k = i; a[k - 1] != 0; k++)
            {
                swap(a[k], a[k + 1]);
            }

            continue;
        }

        i++;
    }
}

// проверка на корректность постановки символов
bool checkCorrectStagSymb(char a[], char b[])
{
    // оператор 
    bool op = false;

    // точка
    bool dot = false;

    // флаг пробелов
    bool space = false;

    // флаг того что цифр ещё небыло в строке
    bool num = false;

    // показатель цифр
    bool bracketOp = false;

    // счётчик открывающих скобок
    int open = 0;

    // счётчик закрывающих скобок 
    int close = 0;


    // проверка на числа и пробелы
    for (size_t i = 0; i < a[i] != 0; i++)
    {
        for (size_t k = 0; k < b[k] != 0; k++)
        {
            if (a[i] == b[k])
            {
                // ПРОБЕЛ
                if (k == 0)
                {
                    // если в строке ещё небыло цифр
                    if (!num)
                        break;
                    space = true;
                    break;
                }

                // ОПЕРАТОР
                if (k >= 1 && k <= 4)
                {
                    // если оператор идет подряд за оператором
                    if (op)
                        return false;

                    // флаг оператора
                    op = true;

                    // флаг точки обнуляется
                    dot = false;

                    // обнеление флага цифр
                    num = false;

                    // обнуление пробела
                    space = false;
                    break;
                }

                // ЦИФРЫ
                if (k >= 8 && k <= 17)
                {
                    // если после цифр уже был пробел и небыло оператора
                    if (space)
                        return false;

                    num = true;

                    // флаг оператора обнуляется
                    op = false;

                    break;
                }

                if (k == 5 || k == 6)
                {
                    // если это открывающая скобка 
                    if (k == 5)
                    {
                        // флаг оператора
                        op = false;

                        // флаг точки обнуляется
                        dot = false;

                        // обнеление флага цифр
                        num = false;

                        // обнуление пробела
                        space = false;
                    }
                }
            }
        }
    }

    
    // отчистка строки от пробелов 
    clearSpaceString(a);



    // оператор 
    op = false;

    // точка
    dot = false;

    // флаг того что цифр ещё небыло в строке
    num = false;

    // показатель цифр
    bracketOp = false;

    // счётчик открывающих скобок
    open = 0;

    // счётчик закрывающих скобок 
    close = 0;


    // текущий символ
    for (size_t i = 0; i < a[i] != 0; i++)
    {
        for (size_t k = 1; k < b[i] != 0; k++)
        {
            // если текущий символ первой строки совпадает с текущим массивом второй строки
            if (a[i] == b[k])
            {
                // ОПЕРАТОР
                if (k >= 1 && k <= 4)
                {
                    if (i == 0 && a[i + 1] == '(')
                        break;

                    // если оператор стоит первым
                    if (i == 0)
                        return false;

                    // если оператор идет подряд за оператором
                    if (op)
                        return false;

                    // флаг оператора
                    op = true;

                    // флаг точки обнуляется
                    dot = false;

                    break;
                }

                // ЦИФРЫ
                if (k >= 8 && k <= 17)
                {
                    num = true;

                    if (open > 0)
                        bracketOp = true;

                    // флаг оператора обнуляется
                    op = false;

                    break;
                }

                // ТОЧКА 
                if (k == 7)
                {
                    // если точка является первым символом в строке
                    if (i == 0)
                        return false;

                    // если точка уже была после оператора 
                    if (dot)
                        return false;

                    // если следующий символ после точки не является цифрой 
                    if (a[i + 1] < '0' && a[i + 1] > '9')
                        return false;

                    // если предыдущий символ не является цифрой 
                    if (a[i - 1] < '0' && a[i + 1] > '9')
                        return false;

                    // флаг точки
                    dot = true;

                    break;
                }

                // СКОБКИ 
                if (k == 5 || k == 6)
                {
                    // если это открывающая скобка 
                    if (k == 5)
                    {
                        // счётчик открытия скобок 
                        open++;

                        // если скобка является первой в строке
                        if (i == 0)
                            break;
                            
                        // флаг точки обнуляется
                        dot = false;

                        // показатель цифр в скобках
                        bracketOp = false;

                        // если перед скобкой небыло оператора, но в строке уже были цифры
                        if (!op && num && a[i - 1] != '(')
                            return false;

                        // флаг оператора
                        op = false;
                    }

                    // если это закрывающая скобка
                    if (k == 6)
                    {
                        // счётчик закрытия скобок
                        close++;

                        // если показатель цифр false и при этом это последняя закрывающая
                        if (!bracketOp)
                            return false;

                        // если закрывающих скобок больше, чем открывающих
                        if (open == 0)
                            return false;

                        if (open == close)
                            open = close = 0;

                    }

                    break;
                }
            }

        }
    }



    // если количество открывающих и закрывающих скобок не сошлось
    if (!open == 0)
        return false;

    return true;
}

// протокол выполнения выражения 
void protocolCalt(char a[], char b[], char res[])
{
    // массив для выражения 
    float expr[40];

    // координаты скобок
    int bracket[2];
    
    // длина строки выражения
    //int len = strlen(a);

    // длина масива скобок  
    int brlen = 0;

    // длина чисел в скобке
    int len = 1;

    // ход выполнения 
    for (size_t i = 0, flag = 0; flag == 0; i++)
    {
        // строка для отправки выражения
        char temp[40];

        // длина скобок и их координаты
        len = bracketChar(a, bracket);


        // если скобки существуют
        if (len == 0)
        {            
            // параметры скобок расширяются на всю длину выражения
            bracket[0] = -1;
            len = strlen(a);
            bracket[1] = len;

            // если скобок больше нет, то выхож при следущей итерации цикла
            flag = 1;
        }

        // заполнение массива текущими элементами для передачи в калькулятор
        for (size_t i = bracket[0] + 1 , k = 0; i < bracket[1]; i++)
        {
            temp[k++] = a[i];
            if (i + 1 == bracket[1])
                temp[k] = 0;
        }

        // передача в калькулятор и длина числа
        int len_num = calculator(temp, b);

        
        // длина ввода резултата
        int len_in = 0;

        // полседний элемент результата        
        int i_in = bracket[0];

        // вписывание результата
        for (size_t k = 0; temp[k] != 0; i_in++, k++)
        {
            a[i_in] = temp[k];
            len_in++;
        }

        len = strlen(a);

        for (size_t i = i_in; i <= bracket[1]; i++)
        {
            shift(a, i_in, len--);
        }

        a[len] = 0;

        // сдвиг влево, если длина результата меньше, чем длина скобок или вправо
        // если длина больше, чем длина скобок
        // shift(a, bracket[0], len); 

        

        if (flag == 1)
        {
            for (size_t i = 0; i < temp[i - 1] != 0; i++)
            {
                res[i] = temp[i];
            }
            return;
        }
    }
}

// координаты скобок
int bracketChar(char a[], int bracket[])
{
    // обнуление координат
    bracket[0] = 0;
    bracket[1] = 0;

    // координаты скобок
    for (size_t i = 0; a[i] != 0; i++)
    {
        if (a[i] == '(')
        {
            bracket[0] = i;
        }

        if (a[i] == ')')
        {
            bracket[1] = i;
            break;
        }
    }

    // длина скобок 
    return bracket[1] - bracket[0];
}

// вычисление переданной строки и длина числа
int calculator(char a[], char b[])
{
    // массив для сборки текущего числа и цифр
    int numeral[40];

    // массив общего выражения 
    float expr[40];

    // показатель точки
    bool dot = false;

    // счётчик операторов
    int op = 0;

    // длина массива
    int size = 0;

    

    // перевод выражения из строки в числовой массив
    for (size_t i = 0, j = 0; a[i] != 0; i++)
    {
        // цифра
        int figure = 0;
        for (size_t k = 1; b[k] != 0; k++)
        {     
            if (k > 8)
            {
                figure++;
            }

            // если символы совпали
            if (a[i] == b[k])
            {
                // ОПЕРАТОР
                if (k >= 1 && k <= 4)
                {
                    // счётчик оператора
                    op++;

                    // оператор в массив
                    expr[size++] = k;

                    // сброс показателя точки
                    dot = false;

                    break;
                }

                // ТОЧКА
                if (k == 7)
                {   
                    // флаг точки
                    dot = true;

                    break;
                }

                // ЦИФРЫ
                if (k >= 8 && k <= 17)
                {
                    // заполнение массива с цифрами 
                    numeral[j++] = figure;

                    // если цифра является в числе последней перед оператором или точкой 
                    // или это последняя цифра в выражении
                    if ((a[i + 1] >= b[1] && a[i + 1] <= b[4]) || (a[i + 1] == '.') || a[i + 1] == 0)
                    {
                        // заполнение массива с выражением

                        // если цифры после точки  
                        if (dot)
                        {
                            size--;
                            numFractionDot(expr[size], numeral, j);
                            size++;
                        }
                        // если до точки
                        else                         
                            expr[size++] = numFraction(numeral, j);

                        j = 0;

                        break;
                    }
                }
            }
        }
    }

    // очередь выполнения 
    int* turn = new int[op];

    // определение очереди вычисления и координат операторов
    turn_op(expr, size, turn);

    // вычисление выражения 
    for (size_t i = 0; i < op; i++)
    {
        // координаты текущего операнда
        int k = turn[i];

        // бинарные операции
        if (expr[k] == 1)
        {
            expr[k - 1] *= expr[k + 1];
        }

        if (expr[k] == 2)
        {
            expr[k - 1] /= expr[k + 1];
        }

        if (expr[k] == 3)
        {
            expr[k - 1] += expr[k + 1];
        }

        if (expr[k] == 4)
        {
            expr[k - 1] -= expr[k + 1];
        }

        // сдвиг влево на два символа
        shiftArray(expr, size, turn[i]);
        shiftArray(expr, size, turn[i]);
    }

    // длина строки
    int len = 0;

    // преобразование результата в строку
    convert(a, len, expr[0]);

    // отчиска массива выполняния с оперативной памяти
    //delete[] turn;

    return len;
}

// определение очереди вычисления и координат операторов
void turn_op(float a[], int size, int turn[])
{
    for (size_t i = 1, k = 2, w = 0, n = 0; w < 2; i += 2, k += 2, w++)
    {
        for (int j = 1; j < size; j += 2)
        {
            if (a[j] == i || a[j] == k)
                turn[n++] = j;
        }
    }
}

// перобразование цифр в число с точкой 
void numFractionDot(float num_ex, int a[], int len)
{
    float num = 0;

    int n = 0;


    for (size_t i = 0; i < len; i++)
    {
        n = a[i];
        if (i < len - 1)
        {
            for (size_t k = 0; k < len - 1 - i; k++)
            {
                n *= 10;
            }
        }

        num += n;
    }

    // создания числа с точкой
    for (size_t i = 0; ; i++)
    {
        if (num >= 1)
            num /= 10;
    }

    num_ex += num;
}

// преобразование цифр в число
float numFraction(int a[], int len)
{
    float num = 0;

    int n = 0;

    
    for (size_t i = 0; i < len; i++)
    {
        n = a[i];
        if (i < len - 1)
        {
            for (size_t k = 0; k < len - 1 - i; k++)
            {
                n *= 10;
            }
        }

        num += n;
    }

    return num;
}

// функция переноса строки
void swapChar(char a[], int n, int len)
{
    for (size_t i = n; i < len; i++)
    {
        swap(a[i], a[i + 1]);
    }
}

// сдвиг массива 
void shiftArray(float a[], int size, int j)
{
    for (size_t i = j; i < size; i++)
    {
        swap(a[i], a[i + 1]);
    }

    // уменьшение длины массива
    size--;
}

// сдвиг строки
void shift(char a[], int j, int len)
{
    // если длина положительная то сдвиг влево, если отрицательная, то сдвиг вправо
    if (len > 0)
    {
        for (size_t i = j; i < len; i++)
        {
            swap(a[i], a[i + 1]);
        }
    }
    if (len < 0)
    {
        len *= -1;
        for (size_t i = len; i > j ; i--)
        {
            swap(a[i], a[i - 1]);
        }
    }
}

// перевод числа в строку 
void convert(char a[], int len, float num)
{
    // счётик символов после точки
    int n = 0;

    // точки
    bool dot = false;

    // число становится целым
    for (; ; n++)
    {
        if (num != (int)num)
        {
            num *= 10;
            dot = true;
        }
        else break;
    }

    char temp[40];

    // перевод числа в строку
    _itoa_s(num, temp, 10);

    // длина строки
    int len_a = 0;

    // заполнение строки
    for (size_t i = 0; temp[i - 1] != 0; i++)
    {
        a[i] = temp[i];
        len_a++;
    }

    // расставление точек
    if (dot)
    {
        for (size_t i = len_a; i > n; i--)
        {
            swap(a[i], a[i - 1]);
        }


        // окончание строки
        a[++len_a] = 0;

        // подставка точки
        a[n] = '.';
    }
}

// перевод цифр в число
/*int numDeterminalSix(float a[], int size)
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
}*/