#include <iostream>
#include <conio.h>
#include <cstring>

using namespace std;

// ������� ����� ������� 
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

// ������� ����� �������
void enterArray(int a[], size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        cout << "Enter element" << "[" << i << "]: ";
        cin >> a[i];
    }
    cout << endl;
}

// ������� ������ �������
void outArray(int a[], size_t size)
{
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

// ������� 1
void Task1();

// (������� 1) ������� �� ������� 
int remDivision(int a[], int size, int devis, int remaind);

// (������� 1) ���������� ������� ������� ����������
void fillArray(int a[], int b[], size_t size_a, size_t size_b, int divis, int remaind);

// ������� 2
void Task2();

// ���������� �� ������������� ��������� 
int repeatEle2DArr(int a[3][4]);

// ������������ ������� ��� ������������� ���������
void fillArrayTwo(int a[3][4], int b[], int size);

// ������� 3
void Task3();

// ������� ������������ ���������� �� ������������� ��������
int repeatSymString(char a[]);

// ���������� ������ ������ ������ � ����������� ���� 
int fillInvertedString(char a[], char b[], size_t size);

// ���������� ������� ������
void fillThirdString(char a[], char c[], size_t size);

// ������� 4
void Task4();

// ������� ��������� ����������� ������ ��� ������������� ��������
void fillNoRepeatString(char a[], char b[]);

// ������� 5
void Task5();

// ������� �� ���������� ������� ����� 
bool primeNumber(int a);

// ���������� ������� ����� � �������
int countPrimeNumber(int a[], size_t size);

// ���������� ������� �������� �������
void fillArrayPrimeNumber(int a[], size_t size_a, int b[]);

// ������� 6
void Task6();

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

// ������� ����� � ������ 
void convert(char a[], int len, float num);

// ����� ������
void shift(char a[], int j, int len);

// ����� ������� 
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

// ������� 1
void Task1()
{
    // 1. ������������ ������ ������ ������� � ��� ������ � ����������,
    // ��������� �������� ��� ������ �������� �� ������ ������������ ������,
    // � ��� �������� �������� � ������ ������������ ������ � ������� �� �� �����

    int size;

    // ���� ����� �������
    cout << "Enter size array: ";
    cin >> size;

    cout << endl;

    // �������� ������������� ������� 
    int* a = new int[size];

    cout << "Enter Array" << endl << endl;

    // ���� �������
    enterArray(a, size);

    // ����� �������
    cout << "Array: ";
    outArray(a, size);

    cout << endl;

    // ������ ������� �������
    int size_even = remDivision(a, size, 2, 0);

    // �������� ������� ������������� �������
    int* even = new int[size_even];

    // ���������� ������� even ������� �������
    fillArray(a, even, size, size_even, 2, 0);

    // ������ ������� �������
    int size_odd = remDivision(a, size, 2, 1);

    // �������� ������� ������������� �������
    int* odd = new int[size_odd];

    // ���������� ������� odd ��������� �������
    fillArray(a, odd, size, size_odd, 2, 1);

    // ����� ������� � ������� �������
    if (size_even == 0)
        cout << "No even elements!";
    else
    {
        cout << "Even: ";
        outArray(even, size_even);
    }

    cout << endl;

    // ����� ������� � ��������� �������
    if (size_odd == 0)
        cout << "No odd elements!";
    else
    {
        cout << "Odd: ";
        outArray(odd, size_odd);
    }
}

// ������� ��������� �������� � ������ ������� ����� � ���������� 
// ���������� ��������� ������� �������������� ��������� ������� 
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

// ������� ��������� �������� � ������ ������� �����. ��������� ������ ������� �������
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

// ������� 2
void Task2()
{
    // 2. ������� ��������� 2D-������ �������� 3x4 � �������� � 
    // ������������ ���������� ������ ��� ������� ��� ����������
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

// ���������� ������������� ��������� 
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

// ������������ ������� ��� ������������� ���������
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

// ������� 3
void Task3()
{
    // 3. ������� ��������� 2 ������ � ��������� 2 ������ � ����� 
    // ������ � ����������� ���� � �������� ��� �� � ������
    // ������������ ������

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

// ���������� ������ ������ ������ � ����������� ���� 
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

// ���������� ������� ������
void fillThirdString(char a[], char c[], size_t size)
{
    size_t i = 0;

    for (; i < size; i++)
    {
        c[i] = a[i];
    }

    c[i] = 0;
}

// ������� 4
void Task4()
{
    // 4. ������� ��������� ������ � ������� ������������� 
    // ������� �� ������(������: hello world->helo wrd)
    // � �������� ��������� �� ������ ������������ ������

    char a[40];

    cout << "Enter string: ";
    cin.getline(a, 40);

    char* b = new char[repeatSymString(a)];

    fillNoRepeatString(a, b);

    cout << endl;

    cout << "String NO repeat elements: " << b << endl;

}

// ������� ������������ ���������� �� ������������� ��������
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

// ������� ��������� ����������� ������ ��� ������������� ��������
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

// ������� 5
void Task5()
{
    // 5. ������������ ������ ������ ������� � ��� ������ � 
    // ����������, ��������� �������� ��� ������� ����� �� ������
    // ������������ ������ � ������� ��� �� �����

    int size_a = 0;

    // ���� ������� �������
    cout << "Enter size array: ";
    cin >> size_a;

    // �������� ������� ������������� ������� ��������� ������������� �����
    int* a = new int[size_a];

    cout << endl;

    // ���� �������
    cout << "Enter array:" << endl << endl;
    enterArray(a, size_a);

    // ����� ������� �������
    cout << "You array: ";
    outArray(a, size_a);

    cout << endl;

    // ���������� ����� ��� ������� �������
    int size_b = countPrimeNumber(a, size_a);

    // �������� ������� ������������� �������
    int* b = new int[size_b];

    // ���������� ������� ������� �������� ������� �� ������� �������
    fillArrayPrimeNumber(a, size_a, b);

    // ����� ������� ������� �� �����
    cout << "Array prime number: ";
    outArray(b, size_b);

}

// ������� �� ���������� ������� ����� 
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

// ���������� ������� ����� � �������
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

// ���������� ������� �������� �������
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

// ������� 6
void Task6()
{
    // 6*. ������� ��������� ������ ���� � ������� � ����������� 
    // [+-*/] ��������� �������� ��������� (����� ����� ��������)

    char a[40];

    cout << "Enter string: ";
    cin.getline(a, 40);
    //            012345678901234567
    char b[40] = " */+-().0123456789";

    // ������ ��� ����������
    char res[40];

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

// �������� �� ������������ ��������
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

// �������� ������ �� ��������
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

// �������� �� ������������ ���������� ��������
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
    for (size_t i = 0; i < a[i] != 0; i++)
    {
        for (size_t k = 1; k < b[i] != 0; k++)
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

// �������� ���������� ��������� 
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
        for (size_t i = bracket[0] + 1 , k = 0; i < bracket[1]; i++)
        {
            temp[k++] = a[i];
            if (i + 1 == bracket[1])
                temp[k] = 0;
        }

        // �������� � ����������� � ����� �����
        int len_num = calculator(temp, b);

        
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

// ���������� ������
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

// ���������� ���������� ������ � ����� �����
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
    convert(a, len, expr[0]);

    // ������� ������� ���������� � ����������� ������
    //delete[] turn;

    return len;
}

// ����������� ������� ���������� � ��������� ����������
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

// �������������� ���� � ����� � ������ 
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

// �������������� ���� � �����
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

// ������� �������� ������
void swapChar(char a[], int n, int len)
{
    for (size_t i = n; i < len; i++)
    {
        swap(a[i], a[i + 1]);
    }
}

// ����� ������� 
void shiftArray(float a[], int size, int j)
{
    for (size_t i = j; i < size; i++)
    {
        swap(a[i], a[i + 1]);
    }

    // ���������� ����� �������
    size--;
}

// ����� ������
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
        for (size_t i = len; i > j ; i--)
        {
            swap(a[i], a[i - 1]);
        }
    }
}

// ������� ����� � ������ 
void convert(char a[], int len, float num)
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