#include <time.h>
#include <iostream>
#include <iomanip>

using namespace std;

int ReadPositiveNumber(string msg)
{
    int Num=0;
    do
    {
        cout << msg << endl << ">> ";
        cin >> Num;

    } while (Num<=0);

    return Num;
}

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

int main()
{
    srand(time(0));

    int matrix[3][3];

    FillMatrixWithRandomNumbers(matrix, 3, 3);

    cout << "The Matrix is : " << endl;
    PrintMatrix(matrix, 3, 3);

    int userNum=ReadPositiveNumber("Please enter number to search?");
    

    cout << (IsNumInMatrix(matrix,3,3,userNum)?"Number is here.":"Number isn't here.") << endl;

    return 0;
}
