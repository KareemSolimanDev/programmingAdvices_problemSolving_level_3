#include <iostream>
#include <iomanip>

using namespace std;



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

bool IsPalindromeMatrix(int matrix[3][3],int rows,int cols)
{
    for (short r = 0; r < rows; r++)
    {
        for (short c = 0; c < cols/2; c++)
        {
            if(matrix[r][c]!=matrix[r][cols-1-c])
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    srand(time(0));
    
    // palindrome case
    int matrix[3][3]={
                    {1,0,1},
                    {0,1,0},
                    {0,0,0}};

    // not palindrome case
    // int matrix[3][3]={
    //                 {1,0,1},
    //                 {0,1,0},
    //                 {1,0,0}};



    cout << "The Matrix is : " << endl;
    PrintMatrix(matrix, 3, 3);

    cout << (IsPalindromeMatrix(matrix,3,3)?"Yes,It's a plaindrome matrix.":"No,It's not a plaindrome matrix");


    return 0;
}
