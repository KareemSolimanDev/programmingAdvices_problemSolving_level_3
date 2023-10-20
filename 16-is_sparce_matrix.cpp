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
            matrix[r][c] = GetRandomNumberInRange(0, 1);
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
int CountNumInMatrix(int matrix[3][3], short rows, short cols,int numToCheck)
{
    short count=0;
    for (short r = 0; r < rows; r++)
    {
        for (short c = 0; c < cols; c++)
        {
            if(numToCheck==matrix[r][c])
            {
                count++;
            }
        }
        
    }

    return count;
}

bool IsSparseMatrix(int matrix[3][3], short rows, short cols)
{
    return CountNumInMatrix(matrix,rows,cols,0)>=((rows*cols)/2+1);
}

int main()
{
    srand(time(0));

    int matrix[3][3];

    FillMatrixWithRandomNumbers(matrix, 3, 3);

    cout << "The Matrix is : " << endl;
    PrintMatrix(matrix, 3, 3);

    

    cout << (IsSparseMatrix(matrix,3,3)?"Yes , It's sparse matrix.":"No , It's not sparse matrix.");

    return 0;
}
