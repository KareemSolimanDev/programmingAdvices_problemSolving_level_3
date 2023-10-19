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
int SumCol(int matrix[3][3], short rows, short col)
{
    int sum=0;

    for (short r = 0; r < rows; r++)
    {
        sum+=matrix[r][col];
    }

    return sum;
}
void PrintSumcols(int matrix[3][3], short rows,short cols)
{
    

    for (short c = 0; c < cols; c++)
    {
        cout << "Sum of col (" << c+1 << ") : " << SumCol(matrix,rows,c) << endl;
    }


}
int main()
{
    srand(time(0));

    int matrix[3][3];

    FillMatrixWithRandomNumbers(matrix, 3, 3);

    cout << "The Matrix is : " << endl;
    PrintMatrix(matrix, 3, 3);

    cout << "cols sum : " << endl;
    PrintSumcols(matrix,3,3);

    return 0;
}
