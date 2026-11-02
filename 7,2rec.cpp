// Варіант 26
#include <iostream>
#include <iomanip>
#include <time.h>
#include <windows.h>

using namespace std;


void CreateRow(int** a, const int rowNo, const int m, const int Low,const int High, int colNo);
void CreateRows(int** a, const int n, const int m, const int Low, const int High, int rowNo);
void PrintRow(int** a, const int rowNo, const int m, int colNo);
void PrintRows(int** a, const int n, const int m, int rowNo);
int SumAntiDiagonal(int** a, const int n, const int m, int i);

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    srand((unsigned)time(NULL));       

    int n, m;                           // n – кількість рядків, m – кількість стовпців
    cout << "n = "; cin >> n;
    cout << "m = "; cin >> m;
    cout << endl;

    int** a = new int* [n];             // a – масив вказівників на рядки матриці
    for (int i = 0; i < n; i++)
        a[i] = new int[m];

    int Low = -9, High = 9;            
    CreateRows(a, n, m, Low, High, 0);  // формування матриці 

    PrintRows(a, n, m, 0);              

    // результат повертається функцією, виводиться в main
    cout << "Сума елементів побічної діагоналі: " << SumAntiDiagonal(a, n, m, 0) << endl;

    for (int i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

void CreateRow(int** a, const int rowNo, const int m, const int Low,
    const int High, int colNo)
{
    a[rowNo][colNo] = Low + rand() % (High - Low + 1);
    if (colNo < m - 1)                  // ще не весь рядок заповнено
        CreateRow(a, rowNo, m, Low, High, colNo + 1);
}

void CreateRows(int** a, const int n, const int m, const int Low,
    const int High, int rowNo)
{
    CreateRow(a, rowNo, m, Low, High, 0);
    if (rowNo < n - 1)                  // ще не всі рядки заповнено
        CreateRows(a, n, m, Low, High, rowNo + 1);
}

void PrintRow(int** a, const int rowNo, const int m, int colNo)
{
    cout << setw(4) << a[rowNo][colNo]; // кожен елемент займає 4 позиції
    if (colNo < m - 1)
        PrintRow(a, rowNo, m, colNo + 1);
    else
        cout << endl;                   // кінець рядка таблиці
}

void PrintRows(int** a, const int n, const int m, int rowNo)
{
    PrintRow(a, rowNo, m, 0);
    if (rowNo < n - 1)
        PrintRows(a, n, m, rowNo + 1);
    else
        cout << endl;
}

// Елементи побічної діагоналі: a[i][m-1-i], i < min(n, m).
// i – номер поточного рядка; m-1-i – номер стовпчика побічної діагоналі в ньому.
// База рекурсії: рядки або діагональ закінчились – повертаємо 0.
int SumAntiDiagonal(int** a, const int n, const int m, int i)
{
    if (i >= n || i >= m)
        return 0;
    return a[i][m - 1 - i] + SumAntiDiagonal(a, n, m, i + 1);
}