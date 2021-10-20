#include <iostream>

using namespace std;

//--------------------------------------------------------------------------------------------

// �������� �� ������������ ��������
bool checkCorrectSymb(char a[], char b[]);

// �������� ������ �� �������� 
void clearSpaceString(char a[]);

// �������� �� ������������ ���������� ��������
bool checkCorrectStagSymb(char a[], char b[]);

// �������� ���������� ��������� 
void protocolCalt(char a[], char b[], char res[]);

// ���������� ������
int bracketChar(char a[], int bracket[]);

// ���������� ���������� ������ � ����� �����
int calculator(char a[], char b[]);

// ����������� ������� ���������� � ��������� ����������
void turn_op(float a[], int size, int turn[]);

// �������������� ���� � ����� � ������ 
void numFractionDot(float num_ex, int a[], int len);

// �������������� ���� � �����
float numFraction(int a[], int len);

// ������� �������� ������
void swapChar(char a[], int n, int len);

// ����� ������� 
void shiftArray(float a[], int size, int j);

// ����� ������
void shift(char a[], int j, int len);

// ������� ����� � ������ 
int convert(char a[], int len, float num);

// ����� ������ ������ 
void shiftRight(char a[], int point, int len_1, int len_2);

//--------------------------------------------------------------------------------------------

// ������� 5
void task5()
{
    // 6*. ������� ��������� ������ ���� � ������� � ����������� 
    // [+-*/] ��������� �������� ��������� (����� ����� ��������)

    char a[200];

    cout << "Enter string: ";
    cin.ignore();
    cin.getline(a, 200);
    //            012345678901234567
    char b[40] = " */+-().0123456789";

    // ������ ��� ����������
    char res[200];

    // �������� �� ���������� ������� 
    if (checkCorrectSymb(a, b))
    {
        // �������� �� ������������ ���������� ��������
        if (checkCorrectStagSymb(a, b))
        {
            protocolCalt(a, b, res);
        }
    }

    cout << res << endl;
}

// �������� �� ������������ �������� -
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

// �������� ������ �� �������� -
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

// �������� �� ������������ ���������� �������� -
bool checkCorrectStagSymb(char a[], char b[])
{
    // �������� 
    bool op = false;

    // �����
    bool dot = false;

    // ���� ��������
    bool space = false;

    // ���� ���� ��� ���� ��� ������ � ������
    bool num = false;

    // ���������� ����
    bool bracketOp = false;

    // ������� ����������� ������
    int open = 0;

    // ������� ����������� ������ 
    int close = 0;


    // �������� �� ����� � �������
    for (size_t i = 0; i < a[i] != 0; i++)
    {
        for (size_t k = 0; k < b[k] != 0; k++)
        {
            if (a[i] == b[k])
            {
                // ������
                if (k == 0)
                {
                    // ���� � ������ ��� ������ ����
                    if (!num)
                        break;
                    space = true;
                    break;
                }

                // ��������
                if (k >= 1 && k <= 4)
                {
                    // ���� �������� ���� ������ �� ����������
                    if (op)
                        return false;

                    // ���� ���������
                    op = true;

                    // ���� ����� ����������
                    dot = false;

                    // ��������� ����� ����
                    num = false;

                    // ��������� �������
                    space = false;
                    break;
                }

                // �����
                if (k >= 8 && k <= 17)
                {
                    // ���� ����� ���� ��� ��� ������ � ������ ���������
                    if (space)
                        return false;

                    num = true;

                    // ���� ��������� ����������
                    op = false;

                    break;
                }

                // ������
                if (k == 5 || k == 6)
                {
                    // ���� ��� ����������� ������ 
                    if (k == 5)
                    {
                        // ���� ���������
                        op = false;

                        // ���� ����� ����������
                        dot = false;

                        // ��������� ����� ����
                        num = false;

                        // ��������� �������
                        space = false;
                    }

                    if (k == 6)
                    {
                        // ���� ���������
                        op = false;

                        // ���� ����� ����������
                        dot = false;

                        // ��������� ����� ����
                        num = false;

                        // ��������� �������
                        space = false;
                    }
                }
            }
        }
    }


    // �������� ������ �� �������� 
    clearSpaceString(a);



    // �������� 
    op = false;

    // �����
    dot = false;

    // ���� ���� ��� ���� ��� ������ � ������
    num = false;

    // ���������� ����
    bracketOp = false;

    // ������� ����������� ������
    open = 0;

    // ������� ����������� ������ 
    close = 0;


    // ������� ������
    for (size_t i = 0; a[i] != 0; i++)
    {
        for (size_t k = 1; b[i] != 0; k++)
        {
            // ���� ������� ������ ������ ������ ��������� � ������� �������� ������ ������
            if (a[i] == b[k])
            {
                // ��������
                if (k >= 1 && k <= 4)
                {
                    if (i == 0 && a[i + 1] == '(')
                        break;

                    // ���� �������� ����� ������
                    if (i == 0)
                        return false;

                    // ���� �������� ���� ������ �� ����������
                    if (op)
                        return false;

                    // ���� ���������
                    op = true;

                    // ���� ����� ����������
                    dot = false;

                    break;
                }

                // �����
                if (k >= 8 && k <= 17)
                {
                    num = true;

                    if (open > 0)
                        bracketOp = true;

                    // ���� ��������� ����������
                    op = false;

                    break;
                }

                // ����� 
                if (k == 7)
                {
                    // ���� ����� �������� ������ �������� � ������
                    if (i == 0)
                        return false;

                    // ���� ����� ��� ���� ����� ��������� 
                    if (dot)
                        return false;

                    // ���� ��������� ������ ����� ����� �� �������� ������ 
                    if (a[i + 1] < '0' && a[i + 1] > '9')
                        return false;

                    // ���� ���������� ������ �� �������� ������ 
                    if (a[i - 1] < '0' && a[i + 1] > '9')
                        return false;

                    // ���� �����
                    dot = true;

                    break;
                }

                // ������ 
                if (k == 5 || k == 6)
                {
                    // ���� ��� ����������� ������ 
                    if (k == 5)
                    {
                        // ������� �������� ������ 
                        open++;

                        // ���� ������ �������� ������ � ������
                        if (i == 0)
                            break;

                        // ���� ����� ����������
                        dot = false;

                        // ���������� ���� � �������
                        bracketOp = false;

                        // ���� ����� ������� ������ ���������, �� � ������ ��� ���� �����
                        if (!op && num && a[i - 1] != '(')
                            return false;

                        // ���� ���������
                        op = false;
                    }

                    // ���� ��� ����������� ������
                    if (k == 6)
                    {
                        // ������� �������� ������
                        close++;

                        // ���� ���������� ���� false � ��� ���� ��� ��������� �����������
                        if (!bracketOp)
                            return false;

                        // ���� ����������� ������ ������, ��� �����������
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



    // ���� ���������� ����������� � ����������� ������ �� �������
    if (!open == 0)
        return false;

    return true;
}

// �������� ���������� ��������� -
void protocolCalt(char a[], char b[], char res[])
{
    // ������ ��� ��������� 
    float expr[40];

    // ���������� ������
    int bracket[2];

    // ����� ������ ���������
    //int len = strlen(a);

    // ����� ������ ������  
    int brlen = 0;

    // ����� ����� � ������
    int len = 1;

    // ��� ���������� 
    for (size_t i = 0, flag = 0; flag == 0; i++)
    {
        // ������ ��� �������� ���������
        char temp[40];

        // ����� ������ � �� ����������
        len = bracketChar(a, bracket);


        // ���� ������ ����������
        if (len == 0)
        {
            // ��������� ������ ����������� �� ��� ����� ���������
            bracket[0] = -1;
            len = strlen(a);
            bracket[1] = len;

            // ���� ������ ������ ���, �� ����� ��� �������� �������� �����
            flag = 1;
        }


        // ���������� ������� �������� ���������� ��� �������� � �����������
        for (size_t i = bracket[0] + 1, k = 0; i < bracket[1]; i++)
        {
            temp[k++] = a[i];
            if (i + 1 == bracket[1])
                temp[k] = 0;
        }

        // �������� � ����������� � ����� �����
        int len_num = calculator(temp, b);

        // ���� ����� ������� 
        if (len_num > len)
        {
            shiftRight(a, bracket[1], len_num, len);
        }

        // ����� ����� ���������
        int len_in = 0;

        // ��������� ������� ����������        
        int i_in = bracket[0];

        // ���������� ����������
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

        // ����� �����, ���� ����� ���������� ������, ��� ����� ������ ��� ������
        // ���� ����� ������, ��� ����� ������
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

// ���������� ������ -
int bracketChar(char a[], int bracket[])
{
    // ��������� ���������
    bracket[0] = 0;
    bracket[1] = 0;

    // ���������� ������
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

    // ����� ������ 
    return bracket[1] - bracket[0];
}

// ���������� ���������� ������ � ����� ����� -
int calculator(char a[], char b[])
{
    // ������ ��� ������ �������� ����� � ����
    int numeral[40];

    // ������ ������ ��������� 
    float expr[40];

    // ���������� �����
    bool dot = false;

    // ������� ����������
    int op = 0;

    // ����� �������
    int size = 0;



    // ������� ��������� �� ������ � �������� ������
    for (size_t i = 0, j = 0; a[i] != 0; i++)
    {
        // �����
        int figure = 0;
        for (size_t k = 1; b[k] != 0; k++)
        {
            if (k > 8)
            {
                figure++;
            }

            // ���� ������� �������
            if (a[i] == b[k])
            {
                // ��������
                if (k >= 1 && k <= 4)
                {
                    // ������� ���������
                    op++;

                    // �������� � ������
                    expr[size++] = k;

                    // ����� ���������� �����
                    dot = false;

                    break;
                }

                // �����
                if (k == 7)
                {
                    // ���� �����
                    dot = true;

                    break;
                }

                // �����
                if (k >= 8 && k <= 17)
                {
                    // ���������� ������� � ������� 
                    numeral[j++] = figure;

                    // ���� ����� �������� � ����� ��������� ����� ���������� ��� ������ 
                    // ��� ��� ��������� ����� � ���������
                    if ((a[i + 1] >= b[1] && a[i + 1] <= b[4]) || (a[i + 1] == '.') || a[i + 1] == 0)
                    {
                        // ���������� ������� � ����������

                        // ���� ����� ����� �����  
                        if (dot)
                        {
                            size--;
                            numFractionDot(expr[size], numeral, j);
                            size++;
                        }
                        // ���� �� �����
                        else
                            expr[size++] = numFraction(numeral, j);

                        j = 0;

                        break;
                    }
                }
            }
        }
    }

    // ������� ���������� 
    int* turn = new int[op];

    // ����������� ������� ���������� � ��������� ����������
    turn_op(expr, size, turn);

    // ���������� ��������� 
    for (size_t i = 0; i < op; i++)
    {
        // ���������� �������� ��������
        int k = turn[i];

        // �������� ��������
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

        // ����� ����� �� ��� �������
        shiftArray(expr, size, turn[i]);
        shiftArray(expr, size, turn[i]);
    }

    // ����� ������
    int len = 0;

    // �������������� ���������� � ������
    len = convert(a, len, expr[0]);

    // ������� ������� ���������� � ����������� ������
    //delete[] turn;

    return len;
}

// ����������� ������� ���������� � ��������� ���������� -
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

// �������������� ���� � ����� � ������ -
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

    // �������� ����� � ������
    for (size_t i = 0; ; i++)
    {
        if (num >= 1)
            num /= 10;
    }

    num_ex += num;
}

// �������������� ���� � ����� -
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

// ������� �������� ������ -
void swapChar(char a[], int n, int len)
{
    for (size_t i = n; i < len; i++)
    {
        swap(a[i], a[i + 1]);
    }
}

// ����� ������� -
void shiftArray(float a[], int size, int j)
{
    for (size_t i = j; i < size; i++)
    {
        swap(a[i], a[i + 1]);
    }

    // ���������� ����� �������
    size--;
}

// ����� ������ -
void shift(char a[], int j, int len)
{
    // ���� ����� ������������� �� ����� �����, ���� �������������, �� ����� ������
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

// ������� ����� � ������ -
int convert(char a[], int len, float num)
{
    // ������ �������� ����� �����
    int n = 0;

    // �����
    bool dot = false;

    // ����� ���������� �����
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

    // ������� ����� � ������
    _itoa_s(num, temp, 10);

    // ����� ������
    int len_a = 0;

    // ���������� ������
    for (size_t i = 0; temp[i - 1] != 0; i++)
    {
        a[i] = temp[i];
        len_a++;
    }

    // ������������ �����
    if (dot)
    {
        for (size_t i = len_a; i > n; i--)
        {
            swap(a[i], a[i - 1]);
        }


        // ��������� ������
        a[++len_a] = 0;

        // ��������� �����
        a[n] = '.';
    }

    return strlen(a);
}

// ����� ������ ������ -
void shiftRight(char a[], int point, int len_1, int len_2)
{
    for (size_t i = strlen(a); i > point; i--)
    {
        swap(a[i], a[i - 1]);
    }
}

// ������� ���� � �����
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