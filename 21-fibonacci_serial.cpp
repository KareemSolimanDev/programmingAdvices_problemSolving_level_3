#include <iostream>

using namespace std;

void PrintFiboSerialToLimit(int limit)
{
    int fabNum=1,prev1=0,prev2=1;

    for (int i = 0; i < limit; i++)
    {
        cout << fabNum << "  ";
        fabNum=prev1+prev2;
        prev1=prev2;
        prev2=fabNum;
    }
    
}

int main()
{
    cout << "Fibonacci serial :" ;
    PrintFiboSerialToLimit(10);
    return 0;
}