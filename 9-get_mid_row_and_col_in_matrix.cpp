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
            matrix[r][c] = GetRandomNumberInRange(1, 10);
        }
    }
}

void PrintMatrix(int matrix[3][3], short rows, short cols)
{
    for (short r = 0; r < rows; r++)
    {
        for (short c = 0; c < cols; c++)
        {
            printf("%0*d  ",2,matrix[r][c]);
        }
        cout << endl;
    }
}

void PrintArray(int array[], short lenght,string msg)
{
    cout << msg;
    for (short i = 0; i < lenght; i++)
    {
        cout << array[i] << "  ";
    }
    cout << endl;
}

void GetMidRow(int matrix[3][3],int midrow[3], short rows, short cols)
{
    for (short i = 0; i < cols; i++)
    {
        midrow[i]=matrix[rows/2][i];
    }
    
}


void GetMidCol(int matrix[3][3],int midrow[3], short rows, short cols)
{
    for (short i = 0; i < rows; i++)
    {
        midrow[i]=matrix[i][cols/2];
    }
}

int main()
{
    srand(time(0));

    int matrix[3][3];
    int midrow[3];
    int midcol[3];


    FillMatrixWithRandomNumbers(matrix, 3, 3);
    cout << "The Matrix1 is : " << endl;
    PrintMatrix(matrix, 3, 3);

    GetMidRow(matrix,midrow,3,3);
    GetMidCol(matrix,midcol,3,3);

    PrintArray(midrow,3,"middile row in matrix : ");
    PrintArray(midcol,3,"middile col in matrix : ");

    return 0;
}
