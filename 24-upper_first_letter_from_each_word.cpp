#include <iostream>

using namespace std;

string UpperFirstLetters(string sentence)
{
    bool isFirst=true;

    for(int i = 0; i < sentence.length(); i++)
    {
        if (sentence[i]!=' '&&isFirst)
        {
            sentence[i]=toupper(sentence[i]);
        }
        isFirst=(sentence[i]==' '?true:false);
    }
    return sentence;
}

int main()
{
    cout << UpperFirstLetters("  hi   i am    kareem   , free for palstine ");
    return 0;
}