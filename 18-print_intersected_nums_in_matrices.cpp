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
bool IsNumInMatrix(int matrix[3][3], short rows, short cols,int numToCheck)
{

    for (short r = 0; r < rows; r++)
    {
        for (short c = 0; c < cols; c++)
        {
            if(numToCheck==matrix[r][c])
            {
                return true;
            }
        }
        
    }

    return false;
}

void PrintIntersectedNumsInMatrices(int matrix[3][3],int matrix1[3][3], short rows, short cols)
{
    cout << "Intersected nums : ";
    for (short r = 0; r < rows; r++)
    {
        for (short c = 0; c < cols; c++)
        {
            if(IsNumInMatrix(matrix1,3,3,matrix[r][c]))
            {
                cout << matrix[r][c] << "  ";
            }
        }
        
    }
}

int main()
{
    srand(time(0));

    int matrix[3][3];
    int matrix1[3][3];

    FillMatrixWithRandomNumbers(matrix, 3, 3);

    cout << "The Matrix is : " << endl;
    PrintMatrix(matrix, 3, 3);

    FillMatrixWithRandomNumbers(matrix1, 3, 3);

    cout << "The Matrix1 is : " << endl;
    PrintMatrix(matrix1, 3, 3);

    PrintIntersectedNumsInMatrices(matrix,matrix1,3,3);

    return 0;
}
