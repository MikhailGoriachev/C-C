#include <iostream>

using namespace std;

//--------------------------------------------------------------------------------------------

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

// сдвиг массива 
void shiftArray(float a[], int size, int j);

// сдвиг строки
void shift(char a[], int j, int len);

// перевод числа в строку 
int convert(char a[], int len, float num);

// сдвиг строки вправо 
void shiftRight(char a[], int point, int len_1, int len_2);

//--------------------------------------------------------------------------------------------

// задание 5
void task5()
{
    // 6*. Функция принимает строку вида с числами и операторами 
    // [+-*/] вычисляет значение выражения (числа могут дробными)

    char a[200];

    cout << "Enter string: ";
    cin.ignore();
    cin.getline(a, 200);
    //            012345678901234567
    char b[40] = " */+-().0123456789";

    // строка для результата
    char res[200];

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

// проверка на корректность символов -
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

// отчистка строки от пробелов -
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

// проверка на корректность постановки символов -
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

                    // обнуление флага цифр
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

                // СКОБКИ
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

                    if (k == 6)
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
    for (size_t i = 0; a[i] != 0; i++)
    {
        for (size_t k = 1; b[i] != 0; k++)
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

// протокол выполнения выражения -
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
        for (size_t i = bracket[0] + 1, k = 0; i < bracket[1]; i++)
        {
            temp[k++] = a[i];
            if (i + 1 == bracket[1])
                temp[k] = 0;
        }

        // передача в калькулятор и длина числа
        int len_num = calculator(temp, b);

        // если число длиннее 
        if (len_num > len)
        {
            shiftRight(a, bracket[1], len_num, len);
        }

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

// координаты скобок -
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

// вычисление переданной строки и длина числа -
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
    len = convert(a, len, expr[0]);

    // отчиска массива выполняния с оперативной памяти
    //delete[] turn;

    return len;
}

// определение очереди вычисления и координат операторов -
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

// перобразование цифр в число с точкой -
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

// преобразование цифр в число -
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

// функция переноса строки -
void swapChar(char a[], int n, int len)
{
    for (size_t i = n; i < len; i++)
    {
        swap(a[i], a[i + 1]);
    }
}

// сдвиг массива -
void shiftArray(float a[], int size, int j)
{
    for (size_t i = j; i < size; i++)
    {
        swap(a[i], a[i + 1]);
    }

    // уменьшение длины массива
    size--;
}

// сдвиг строки -
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
        for (size_t i = len; i > j; i--)
        {
            swap(a[i], a[i - 1]);
        }
    }
}

// перевод числа в строку -
int convert(char a[], int len, float num)
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

    return strlen(a);
}

// сдвиг строки вправо -
void shiftRight(char a[], int point, int len_1, int len_2)
{
    for (size_t i = strlen(a); i > point; i--)
    {
        swap(a[i], a[i - 1]);
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