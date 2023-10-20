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
bool CheckMatrixScalar(int matrix[3][3], short rows, short cols)
{
    for (short r = 0; r < rows; r++)
    {
        for (short c = 0; c < cols; c++)
        {
            if(r==c)
            {
                if (matrix[r][c]!=matrix[0][0])
                {
                    return false;
                }
                

            }else{

                if (matrix[r][c]!=0)
                {
                    return false;
                }
            }
        }
    }
    return true;

}


int main()
{
    srand(time(0));



    // to check scalar case (must be like this)
    int matrix[3][3]={
                    {2,0,0},
                    {0,2,0},
                    {0,0,2}};

    // to check not scalar case (add any numbers in array)
    // int matrix[3][3]={
    //                 {2,0,0},
    //                 {0,1,0},
    //                 {0,0,2}};

    cout << "The Matrix is : " << endl;
    PrintMatrix(matrix, 3, 3);

    

    cout << (CheckMatrixScalar(matrix,3,3)?"Matrix is scalar.":"Matrix is not scalar");

    return 0;
}
