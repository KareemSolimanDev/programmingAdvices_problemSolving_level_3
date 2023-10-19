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


void Multiply2Matrices(int matrix1[3][3],int matrix2[3][3],int Mmatrix[3][3], short rows, short cols)
{
    for (short r = 0; r < rows; r++)
    {
        for (short c = 0; c < cols; c++)
        {
            Mmatrix[r][c]=matrix1[r][c]*matrix2[r][c];
        }
    }
}

int main()
{
    srand(time(0));

    int matrix1[3][3];
    int matrix2[3][3];
    int Mmatrix[3][3];

    FillMatrixWithRandomNumbers(matrix1, 3, 3);
    cout << "The Matrix1 is : " << endl;
    PrintMatrix(matrix1, 3, 3);


    FillMatrixWithRandomNumbers(matrix2, 3, 3);
    cout << "The Matrix2 is : " << endl;
    PrintMatrix(matrix2, 3, 3);

    cout << "The Multiplaied Matrix is : " << endl;
    Multiply2Matrices(matrix1,matrix2,Mmatrix,3,3);
    PrintMatrix(Mmatrix, 3, 3);
    

    return 0;
}
