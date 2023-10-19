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

bool isSumMatrixEqual(int matrix1[3][3],int matrix2[3][3], short rows, short cols)
{
    return SumMatrix(matrix1,rows,cols)==SumMatrix(matrix2,rows,cols); 
    
}
void PrintConditionedMsg(bool condition,string Succesmsg,string Failmsg)
{
    if(condition)
    {
        cout << Succesmsg << endl;
    }else{
        cout << Failmsg << endl;
    }
}
int main()
{
    srand(time(0));

    int matrix1[3][3];
    int matrix2[3][3];

    FillMatrixWithRandomNumbers(matrix1, 3, 3);
    cout << "The Matrix is : " << endl;
    PrintMatrix(matrix1, 3, 3);

    FillMatrixWithRandomNumbers(matrix2, 3, 3);
    cout << "The Matrix is : " << endl;
    PrintMatrix(matrix2, 3, 3);

    PrintConditionedMsg(isSumMatrixEqual(matrix1,matrix2,3,3),"Matices are Equal.","Matices are not Equal.");

    return 0;
}
