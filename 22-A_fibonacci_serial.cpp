#include <iostream>

using namespace std;

void PrintFiboSerialToLimit(int limit,int prev1,int prev2)
{
        if (limit >0)
        {
            int fabNum=prev1+prev2;
            prev2=prev1;
            prev1=fabNum;
            cout << fabNum << "  ";
            PrintFiboSerialToLimit(limit-1,prev1,prev2);
            
        }
        
    
}

int main()
{
    cout << "Fibonacci serial :" ;
    PrintFiboSerialToLimit(10,0,1);
    return 0;
}