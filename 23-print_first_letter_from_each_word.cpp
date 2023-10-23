#include <iostream>

using namespace std;

void PrintFirstLetters(string sentence)
{
    bool isFirst=true;
    for(int i = 0; i < sentence.length(); i++)
    {
        if (sentence[i]!=' '&&isFirst)
        {
            cout << sentence[i] << endl;
        }
        isFirst=(sentence[i]==' '?true:false);
    }
    
}

int main()
{
    PrintFirstLetters("  hi   i am    kareem   , free for palstine ");
    return 0;
}