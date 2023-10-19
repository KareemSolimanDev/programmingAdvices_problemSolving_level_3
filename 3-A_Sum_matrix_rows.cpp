#include <time.h>
#include <iostream>
#include <iomanip>

using namespace std;

int GetRandomNumberInRange(int start, int end)
{
    return rand() % (end - start + 1) + start;
}

void FillMatrixWithRandomNumbers(int matrix[3][3], short rows, short cols)
{
    for (short r = 0; r < rows; r++)
    {
        for (short c = 0; c < cols; c++)
        {
            matrix[r][c] = GetRandomNumberInRange(1, 100);
        }
    }
}

void PrintMatrix(int matrix[3][3], short rows, short cols)
{
    for (short r = 0; r < rows; r++)
    {
        for (short c = 0; c < cols; c++)
        {
            cout << setw(3) << matrix[r][c] << "  ";
        }
        cout << endl;
    }
}

int SumRow(int matrix[3][3], short row, short cols)
{
    int sum=0;

    for (short c = 0; c < cols; c++)
    {
        sum+=matrix[row][c];
    }

    return sum;
}

void ArraySumRows(int matrix[3][3], short rows, short cols,int arrSum[3])
{

    for (short r = 0; r < rows; r++)
    {
        arrSum[r]=SumRow(matrix,r,cols);
    }

    
}

void PrintArraySumRows(int arrSum[3],int lenght)
{
    for (short i = 0; i < lenght; i++)
    {
        cout << "Sum of row (" << i+1 << ") : " << arrSum[i] << endl;
    }
    
}
int main()
{
    srand(time(0));

    int matrix[3][3];

    FillMatrixWithRandomNumbers(matrix, 3, 3);

    cout << "Thw Matrix ia : " << endl;
    PrintMatrix(matrix, 3, 3);

    int rowsSum[3];
    ArraySumRows(matrix,3,3,rowsSum);

    cout << "rows sum : " << endl;
    PrintArraySumRows(rowsSum,3);

    return 0;
}
