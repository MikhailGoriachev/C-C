#include <iostream>

using namespace std;

// ������� ������ 1. ������� ������� ����������� �������� ���� �����
int min_f(int a, int b, int c)
{
    int min;

    // ���� ����� A ��� C �������� �����������
    if (a <= b)
    {
        if (a <= c)
            min = a;
        else min = c;
    }

    // ���� ����� B ��� C �������� ����������
    if (b <= a)
    {
        if (b <= c)
            min = b;
        else min = c;
    }

    // ������� ���������� ����������� ��������� 
    return min;
}

// ������� ������ 2. ������� ������������ �������� � ���� �������� 
int _max(int a[], size_t size_a, int b[], size_t size_b)
{
    // ������� ������� ������������ ����� ������ ������� 
    int max_a = a[0];
    for (size_t i = 0; i < size_a; i++)
    {
        if (max_a < a[i])
            max_a = a[i];
    }

    // ������� ������� ������������ ����� ������� ������� 
    int max_b = b[0];
    for (size_t i = 0; i < size_b; i++)
    {
        if (max_b < b[i])
            max_b = b[i];
    }

    // ����������� �������� � ���� �������� �� ��������� ����� 
    // ������������� �������� ������� ������� 
    int max = max_a;

    // ���� ������������ �������� ������� ������� ������, ���
    // ������������ �������� ������� �������, �� ��� �������� 
    // �������� ������������
    if (max_b > max_a)
        max = max_b;

    // ������� ���������� ������������ �������� 
    return max;
}

// ������� ������ 3. �����������, �������� �� ������ ������������� 
// ������� ������ 
bool factional(char a[], size_t size)
{
    bool res = true;

    // ������ ������ �������� ��� ��������
    char b[13] = "-.0123456789";

    // �������� ������
    for (size_t i = 0, dot = 0; a[i] != 0; i++)
    {
        for (size_t k = 0; b[k] != 0; k++)
        {
            // ���� ������ ��������� � ������� � ������ ��� ��������
            if (a[i] == b[k])
            {
                // ���� ������ ������� �� �������� ����� '-' ��� ���� ������� ������ �������� 
                // ������� '-', �� ��� ������� ������� �� �������� ������ 
                if (i == 0 && k != 0 || i != 0 && k == 0)
                {
                    res = false;
                    break;
                }

                // ������� �����
                if (k == 1)
                    dot++;

                // ���� ���������� ����� ������ ����� ��� ���� ������ ������� �������� ����� '.' 
                if (dot > 1 || (k == 1 && i == 1))
                {
                    res = false;
                    break;
                }
            }

            // ���� ��������� ��������� �������� 0 (����� ������) � ��� ���� ������� ������� 
            // ����� ������ � ������ � ����������� ���������
            else if (b[k + 1] == 0)
                res == false;
        }

        // ���� ���������� ����� �������� ����� � ��� ���� ��������� ��������� �������� 0
        if (dot == 0 && a[i + 1] == 0)
            res = false;

        // ���� ���� �������� ������������� 
        if (res == false)
            break;
    }

    // ����������� ���������� ������ 
    return res;
}

// ������� ������ 4. ����������, ����� �� ��� ������
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

// ������� ������ 5. ��������� ��������������� ����� ����� ������ ������� � ������
bool str_vowels(char a[], size_t size)
{
    // ������ ������ �������� 
    char b[13] = "AaEeYyUuOoIi";

    bool res = true;
    
    // ����� ������ 
    int len = strlen(a);

    // ���� �������� �������� ������
    for (size_t i = 0; a[i] != 0; i++)
    {
        // ���� �������� �������� �������� ������ � ���������� ������ ������ ��������
        for (size_t k = 0; k < 13; k++)
        {
            // ���� ������� ������� ��������� � ��������� ������ ��� ��������
            if (a[i] == b[k])
            {
                // ���� ������������ ����� ������ ��������� �������  
                if (len == 38)
                {
                    res = false;
                    break;
                }

                // ������������ ���������� �������� ������ (0) � �������� ��������� ������
                swap(a[len], a[len + 1]);

                // ����������� ���� ��������� �� ��������(��� ��������) ������ 
                for (size_t j = len; j != i + 1; j--)
                {
                    swap(a[j], a[j - 1]);
                }

                // ���������� �������� �� �������� ������������� ������ '!'
                a[i + 1] = '!';

                // ������������ ����� ������ �� ����
                len++;
            }
        }

        // ���� false �� ����� �� �����
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
            // 1. ������� ��������� 3 ����� � ���������� ����������� �� ���

            int a, b, c;

            // ���� ������� �����
            cout << "Enter num A: ";
            cin >> a;

            // ���� ������� ����� 
            cout << "Enter num B: ";
            cin >> b;

            // ���� �������� ����� 
            cout << "Enter num C: ";
            cin >> c;

            cout << endl;

            // ��������� ������� ������������� ���������� min
            int min = min_f(a, b, c);

            // ����� ������������ ����� 
            cout << "Minimum number: " << min << endl;
        }

        if (num == 2)
        {
            // 2. ������� ��������� 2 ������� � ������� ������������ �������� 
            // � ���� ��������

            const int size_a = 5, size_b = 10;

            int a[size_a], b[size_b];

            // ���� ������� ������� 
            cout << "Enter array A" << endl;

            for (size_t i = 0; i < size_a; i++)
            {
                cout << "a[" << i << "]: ";
                cin >> a[i];
            }

            cout << endl;

            // ���� ������� �������
            cout << "Enter array B" << endl;

            for (size_t i = 0; i < size_b; i++)
            {
                cout << "a[" << i << "]: ";
                cin >> b[i];
            }

            cout << endl;

            // ������� ���������� ������������ �������� 
            int max = _max(a, size_a, b, size_b);

            // ����� ������������� �������� 
            cout << "Maximum numbar array A and B: " << max << endl;
        }

        if (num == 3)
        {
            // 3. ������� ��������� ������ � ���������, �������� �� ��� ������
            // ������������� ������� ������

            char a[40];

            // ���� ������
            cout << "Enter: ";
            cin.ignore();
            cin.getline(a, 40);

            // ��������� ���������� �������
            bool res = factional(a, 40);

            // ����� ����������
            if (res)
                cout << "Yes!" << endl;
            else cout << "No!" << endl;
        }

        if (num == 4)
        {
            // 4. �������  ��������� 2 ������ � ���������� true, ���� ��� 
            // ��������� �����, ����� ���������� false

            const size_t size = 40;

            char a[size], b[size];

            // ���� ������ ������
            cout << "Enter A: ";
            cin.ignore();
            cin.getline(a, size);

            // ���� ������ ������ 
            cout << "Enter B: ";
            cin.getline(b, size);

            // ����� ����������
            if (lines_equal(a, b, size))
                cout << "Yes!" << endl;
            else cout << "No!" << endl;
        }

        if (num == 5)
        {
            // 5. ������� ��������� ������ � ����� ������ ������� ����� 
            // ��������� '!'. "Hello" => "He!llo!"

            char a[40];

            // ���� ������
            cout << "Enter: ";
            cin.ignore();
            cin.getline(a, 40);



            // ����� ����������
            cout << "Result" << endl;

            if (!str_vowels(a, 40))
                cout << endl << "To many vowels!" << endl;
            else   cout << a << endl;

        }
    }

    return 0;
}