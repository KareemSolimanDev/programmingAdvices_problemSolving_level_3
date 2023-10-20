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
bool CheckMatrixIdentity(int matrix[3][3], short rows, short cols)
{
    for (short r = 0; r < rows; r++)
    {
        for (short c = 0; c < cols; c++)
        {
            if(r==c)
            {
                if (matrix[r][c]!=1)
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



    // to check identity case (must be like this)
    int matrix[3][3]={
                    {1,0,0},
                    {0,1,0},
                    {0,0,1}};

    // to check not identity case (add any numbers in array)
    // int matrix[3][3]={
    //                 {0,0,0},
    //                 {0,1,0},
    //                 {0,0,1}};

    cout << "The Matrix is : " << endl;
    PrintMatrix(matrix, 3, 3);

    

    PrintConditionedMsg(CheckMatrixIdentity(matrix,3,3),"Matrix is identity.","Matrix is not identity");

    return 0;
}
