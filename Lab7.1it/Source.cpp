#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High);
void Print(int** a, const int rowCount, const int colCount);
void Sort(int** a, const int rowCount, const int colCount);
void Change(int** a, const int row1, const int row2, const int colCount);
void Calc(int** a, const int rowCount, const int colCount, int& S, int& k);

int main()
{
    srand((unsigned)time(NULL));
    int Low = -8;
    int High = 42;
    int rowCount = 8;
    int colCount = 7;
    int** a = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        a[i] = new int[colCount];

    Create(a, rowCount, colCount, Low, High);
    Print(a, rowCount, colCount);

    Sort(a, rowCount, colCount);
    Print(a, rowCount, colCount);

    int S, k;
    Calc(a, rowCount, colCount, S, k);

    // Виведення результатів
    cout << "S = " << S << endl;
    cout << "k = " << k << endl;

    Print(a, rowCount, colCount);

    for (int i = 0; i < rowCount; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High)
{
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            a[i][j] = Low + rand() % (High - Low + 1);  
}

void Print(int** a, const int rowCount, const int colCount)
{
    cout << endl;
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
            cout << setw(4) << a[i][j];  
        cout << endl;
    }
    cout << endl;
}

void Sort(int** a, const int rowCount, const int colCount)
{
    bool swapped;
    do {
        swapped = false;
        for (int i = 0; i < rowCount - 1; i++) {
            if (a[i][0] < a[i + 1][0]) {
                Change(a, i, i + 1, colCount);
                swapped = true;
            }
            else if (a[i][0] == a[i + 1][0] && a[i][1] < a[i + 1][1]) {
                Change(a, i, i + 1, colCount);
                swapped = true;
            }
            else if (a[i][0] == a[i + 1][0] && a[i][1] == a[i + 1][1] && a[i][2] > a[i + 1][2]) {
                Change(a, i, i + 1, colCount);
                swapped = true;
            }
        }
    } while (swapped); 
}

void Change(int** a, const int row1, const int row2, const int colCount)
{
    for (int j = 0; j < colCount; j++)
    {
        int tmp = a[row1][j];
        a[row1][j] = a[row2][j];
        a[row2][j] = tmp;
    }
}

void Calc(int** a, const int rowCount, const int colCount, int& S, int& k)
{
    S = 0;
    k = 0;
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
        {
            if (a[i][j] > 0 && (a[i][j] % 2 != 0))  
            {
                S += a[i][j];
                k++;
                a[i][j] = 0; 
            }
        }
    }
}
