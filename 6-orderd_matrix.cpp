#include <iostream>

using namespace std;

void FillMatrixWithOrderedNumbers(int matrix[3][3], short rows, short cols)
{
    int counter = 0;
    for (short r = 0; r < rows; r++)
    {
        for (short c = 0; c < cols; c++)
        {
            matrix[r][c] = ++counter;
        }
    }
}

void PrintMatrix(int matrix[3][3], short rows, short cols)
{
    for (short r = 0; r < rows; r++)
    {
        for (short c = 0; c < cols; c++)
        {
            cout << matrix[r][c] << "  ";
        }
        cout << endl;
    }
}

int main()
{

    int matrix[3][3];

    FillMatrixWithOrderedNumbers(matrix, 3, 3);

    cout << "The Matrix is : " << endl;
    PrintMatrix(matrix, 3, 3);

    return 0;
}
