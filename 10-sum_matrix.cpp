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
int SumMatrix(int matrix[3][3], short rows, short cols)
{
    int sum=0;

    for (short r = 0; r < rows; r++)
    {
        for (short c = 0; c < cols; c++)
        {
            sum+=matrix[r][c];
        }
        
    }

    return sum;
}

int main()
{
    srand(time(0));

    int matrix[3][3];

    FillMatrixWithRandomNumbers(matrix, 3, 3);

    cout << "The Matrix is : " << endl;
    PrintMatrix(matrix, 3, 3);

    cout << "Matrixs sum : " << SumMatrix(matrix,3,3) << endl;

    return 0;
}
