#include <iostream>

using namespace std;

string ReadString(string msg)
{
    string stringInput;
    cout << msg;
    getline(cin,stringInput);
    return stringInput;
}

char InvertCharCase(char character)
{
    return isupper(character)?tolower(character):toupper(character);
}

string InvertStringCase(string sentence)
{

    for(int i = 0; i < sentence.length(); i++)
    {
            sentence[i]=InvertCharCase(sentence[i]);
    }
    return sentence;
}

int main()
{
    string invertedChar=InvertStringCase(ReadString("Enter character to invert \n>> "));
    cout << "inverted string : " << invertedChar << endl;
    return 0;
}