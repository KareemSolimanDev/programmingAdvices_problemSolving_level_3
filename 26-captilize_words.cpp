#include <iostream>

using namespace std;

string UpperLetters(string sentence)
{

    for(int i = 0; i < sentence.length(); i++)
    {
        sentence[i]=toupper(sentence[i]);
    }
    return sentence;
}

string LowerLetters(string sentence)
{

    for(int i = 0; i < sentence.length(); i++)
    {
            sentence[i]=tolower(sentence[i]);
    }
    return sentence;
}
int main()
{
    cout << "after upper : " << UpperLetters("  hi   i am    kareem   , free for palstine ") << endl;
    cout << "after lower : " << LowerLetters("  HI   I AM    KAREEM   , FREE FOR PALSTINE ") << endl;
    return 0;
}