#include <iostream>
#include <conio.h>

using namespace std;

// ������� ����������� �����
int numDeterminal(int a[], int size);

// ������� �����
void enterString(char str[], size_t size);

// ������� ����� ������� 
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

// ����� ����������� �������
void OutArray(char b[], size_t size);

// ����� ���������� �������
void OutArray(char a[3][4]);

// �������� �� ������������ �������� (������� 6)
bool correctSymbSix(char a[], char b[]);

// ��������� ��������� (������� 6)
float computSix(char a[], char b[]);

// ������� ���� � ����� (������� 6)
int numDeterminalSix(int a[], int size);

// �������� ������� (������� 6)
bool detecrSymbSix(char a[], char b[], int k);

// ��������� ���������� (+ - * /)
int opArraySix(int a[], int len);

// ����� ������� ����� (������� 6)
void shiftArraySix(int a[], int j, int len);

// �������� ������ �� �������� (������� 6)
void spaceCleanSix(char a[]);

// ������� ���� � �����, ����� ����� (������� 6)
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
            // 1. ������� ��������� 3 ������ � ���������� true, 
		    // ���� ��� ��� �����, ����� - false

            // ���������� ������� 

            // ������� ��������� ��� �����
            bool comparisonString(char a[], char b[], char c[], size_t size);

            // ����� ������
            const size_t size = 40;

            // ���������� �����
		    char a[size], b[size], c[size];

            // ���� ������ ������
            cout << "Enter string a: ";
            cin.ignore();
            enterString(a, size);

            // ���� ������ ������
            cout << "Enter string b: ";
            enterString(b, size);

            // ���� ������� ������
            cout << "Enter string c: ";
            enterString(c, size);

            // ��������� ���������� ������� ���������
            bool res = comparisonString(a, b, c, size);

            // ����� ����������
            if (res)
                cout << "Yes!" << endl;
            else cout << "No!" << endl;
        }
        
        if (num == 2)
        {
            // 2. ������� ��������� 2D-������ �������� 3x4 � ��������
            // � ���������� ������ ��� ������� ��� ����������
            // ���������� ������� 

            // ������� ����� ���������� ������� 3�4
            void enter2DArray3x4(char a[3][4]);

            // ����������� �������������� �������
            bool repeatSymb(char a[3][4]);

            // ���������� ����������� �������
            void filling1DArray(char a[3][4], char b[], size_t size);

            const int sizeY = 3, sizeX = 4, size = sizeY * sizeX + 1;

            char a[sizeY][sizeX], b[size];

            // ���� ���������� �������
            cout << "Enter array" << endl;
            enter2DArray3x4(a);

            cout << endl;

            // ����� ���������� �������
            OutArray(a);

            cout << endl;

            // ���������� ����������� �������
            filling1DArray(a, b, size);

            cout << "Result" << endl;

            // ����� ���������� ������� 
            OutArray(a);

            cout << "1D Array" << endl;

            // ����� ����������� �������
            OutArray(b, size);

            cout << endl;

        }

        if (num == 3)
        {
            // 3. ������� ��������� 2 ������ � ��������� 2 ������ � ����� ������ � ����������� ����

            // ������� ���������� ������
            void stringCoup(size_t i, size_t len);

            // ������� ����������� ���� �����
            void stringIntegration(char a[], char b[], size_t size, size_t len_b);
            

            const int size = 40;

            char a[size], b[size];



            // ���� ������ ������
            cout << "Enter string a: ";
            cin.ignore();
            cin.getline(a, size);

            // ���� ������ ������
            cout << "Enter string b: ";
            cin.getline(b, size);

            size_t len_b = strlen(b);

            // ����������� ���� �����
            stringIntegration(a, b, size, len_b);

            cout << "Result" << endl;

            // ����� ������
            cout << "String a: ";
            OutArray(a, size);



        }

        if (num == 4)
        {
            // 4. ������� ��������� ������ ���� "nnnn op mmm", 
            // ��� nnnn, mmm - ������������� ����� �����, op - [+-*/]
            // (������: 123423 + 2435) � ��������� �������� ����� ���������

            // ������� 

            // ��������� �� ����������� � ����������� ���������
            bool correctSymb(char a[], char b[]);

            // ����������� �����
            bool correctString(char a[], char b[]);

            // ���������� ��������� 
            float comput(char a[], char b[]);

            // �������� �� ����������� ������

            const int size = 40, size_cor = 16;

            float res = -1;

            char str[size];

            // ���������� ������� 
            char corsymb[size_cor] = " +-*/0123456789";

            // ���� ������
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
            // 5. ������� ��������� ������ � ������� ������������� 
            // ������� �� ������ (������: hello world -> helo wrd)

            // �������

            // �������� ������������� �������� �� �������
            void clearRepeatEleArray(char a[], size_t size);

            // ������� ������� ������������� �������
            void repeatEleArray(char a[], size_t size);

            // ����� ������ �����
            void shiftArray(char a[], size_t len, size_t k);

            const size_t size = 40;

            char a[size];

            // ���� ������
            cout << "Enter string: ";
            cin.ignore();
            cin.getline(a, size);

            OutArray(a, size);

            cout << endl;

            // ������� ������� �� ������������� ���������
            repeatEleArray(a, size);
            
            cout << "Result" << endl;

            // ����� ����������
            OutArray(a, size);


        }

        if (num == 6)
        {
            // ������� 6
            void TaskSix();

            TaskSix();
        }
	}

}

// ������� ����� ������ 
void enterString(char str[], size_t size)
{
    cin.ignore();
    cin.getline(str, size);
}
// ����� ����������� �������
void OutArray(char a[], size_t size)
{

    cout << a;

    cout << endl;
}

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////������� � ������� 1/////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

// ������� �������� ���� ����� 
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
////////////////////////////////������� � ������� 2/////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

// ���� ���������� �������
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

// ���������� ����������� ������� ��� ������������� ��������
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

// ������� ���������� �������� �� ������� ������� �������������
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

// ����� ���������� �������
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
////////////////////////////////������� � ������� 3/////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

// ��������� ������
int stringCoup(size_t i , size_t len)
{
    int k = len - 1 - i;

    return k;
}

// ����������� �����
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
////////////////////////////////������� � ������� 4/////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

// �������� �� ������������ �������� ��������
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

// �������� �� ������������ ���������� ��������
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

// ����������� ���� � �����
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

// ���������� ��������� 
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
////////////////////////////////������� � ������� 5/////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

// ����� ������� �����
void shiftArray(char a[], size_t len, size_t k)
{
    for (size_t i = k; i < len; i++)
    {
        swap(a[i], a[i + 1]);
    }
}

// ������� ������� ������������� �������� 
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

// ������� ������ �� ������������� ���������
void clearRepeatEleArray(char a[], size_t size)
{
    repeatEleArray(a, size);
}

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////������� � ������� 6/////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

// ���� ������� 6
void TaskSix()
{
    // 6 * .������� ��������� ������ ���� � ������� � �����������[+-*/ ]
    // ��������� �������� ���������(����� ����� ��������)        �����

    const int size = 40;

    char a[size];
    char b[size] = " */+-0123456789.";

    cout << "Enter string: ";
    cin.ignore();
    cin.getline(a, size);

    

    float res = 0.0;

    // �������� �� ����������� �������� 
    if (correctSymb(a, b))
    {
        if (correctSymbSix(a, b))
        {
            res = computSix(a, b);
        }
        
    }

    cout << res << endl;
}

// �������� ������� 
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

// ������� ���� � �����
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

// ��������� ���������� (* / + -)
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

// ����� ������� �����
void shiftArraySix(float a[], int j, int len)
{
    for (size_t i = j; i < len; i++)
    {
        swap(a[i], a[i + 1]);
    }
}

// ������� ������ �� �������� 
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

// ������� ���� � ����� ����� �����
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

// ���������� ��������� (������� 6)
float computSix(char a[], char b[])
{
    /*// �������� ������ �� ��������
    spaceCleanSix(a);

    int len = strlen(a);

    int count_op = 0;
    bool op = false;
    int id_op = 0;

    int ar[40];
    int ar_num[40];

    int j = 0;
    int f = 0;

    // ����� 

    int temp_res = 0;
    int temp_a = 0;
    int temp_b = 0;

    for (size_t i = 0; a[i] != 0; i++)
    {
        for (size_t k = 0, n = 0; b[k] != 0; k++)
        {
            if (k > 5)
                n++;

            // ��������
            if (a[i] == b[k] && k > 0 && k < 5)
            {
                op = true;

                count_op++;

                ar_num[f++] = k;
                break;
            }

            // �����
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

            // ��������
            if (a[i] == b[k] && k > 0 && k < 5)
            {
                dot = false;

                op = true;

                count_op++;

                ar_num[f++] = k;
                break;
            }

            // ����� 
            if (k == 15)
            {
                f--;
                dot = true;
                continue;
            }

            // �����
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

    // ����� ��������� �� �����
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

    // �������������� �������
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

        // ����� ������� �����
        shiftArraySix(ar_num, i, f);
        shiftArraySix(ar_num, i, f);

        f -= 2;
    }


    res = ar_num[0];
    return res;
}

// �������� �� ������������ ���� ��������� 
bool correctSymbSix(char a[], char b[])
{
    // �������
    bool space = true;
    // �����
    bool symb = true;
    // ���� ������������
    bool flag = false;
    // �������� 
    bool op = false;
    // �����
    bool dot = false;

    // �������� �� ������������ ���������� ��������� 
    for (size_t i = 0; a[i] != 0; i++)
    {
        flag = false;
        for (size_t k = 0; b[k] != 0; k++)
        {
            if (a[i] == b[k])
            {
                // ���� ����� ��� ���� �������, � ��������� ��� ������, ���� ����� ������ ��� ����
                if (k == 15 && (dot == true || symb == true))
                {
                    break;
                }

                // �����
                if (k == 15)
                {
                    dot = true;
                    flag = true;
                }

                // ���� ��� */+- � ��� ���� ���� ���� ��� ������ ������ ��� ���� ������ ����� �������� ���������
                if (k > 0 && k < 5 && symb == true)
                {
                    break;
                }

                // ���� ����� � ��� ���� ����� ��� ���� ������� � ������ ����� ���� �����
                if (k > 4 && k < 15 && symb == false && space == false)
                {
                    break;
                }

                // �����
                if (k > 4 && k < 15)
                {
                    symb = false;
                    flag = true;
                }

                // ���� ������ � ��� ���� ����� ��� ���������
                if (k == 0 && symb == false)
                {
                    space = false;
                    flag = true;
                }

                // ���� ��� ��������
                if (k > 0 && k < 5)
                {
                    symb = true;
                    space = true;
                    flag = true;
                    op = true;
                    dot = false;

                    // ���� ���������� �������� �������� �����
                    if (a[i - 1] == b[15])
                    {
                        flag = false;
                        break;
                    }
                }

                // ���� ������
                if (k == 0)
                {
                    flag = true;

                    // ���� ���������� ������ �������� ������ 
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
