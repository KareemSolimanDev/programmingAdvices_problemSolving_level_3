#include <iostream>

using namespace std;

string lowerFirstLetters(string sentence)
{
    bool isFirst=true;

    for(int i = 0; i < sentence.length(); i++)
    {
        if (sentence[i]!=' '&&isFirst)
        {
            sentence[i]=tolower(sentence[i]);
        }
        isFirst=(sentence[i]==' '?true:false);
    }
    return sentence;
}

int main()
{
    cout << lowerFirstLetters("  Hi   I am    Kareem   , Free For Palstine ");
    return 0;
}