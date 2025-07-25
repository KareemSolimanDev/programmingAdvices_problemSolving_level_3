#include <iostream>

using namespace std;

string ReadString(string msg)
{
    string stringInput;
    cout << msg;
    getline(cin, stringInput);
    return stringInput;
}


void PrintSpratedWords(string sentence, string delim)
{
    string word = "";
    sentence += delim;
    short delimPos = 0;

    while((delimPos=sentence.find(delim))!=string::npos)
    {
        word=sentence.substr(0,delimPos);
        if (word!="")
        {
            cout << word << endl;
        }
        sentence.erase(0,delimPos+delim.length());
    }

}



int main()
{
    string sentence = ReadString("Enter string to count \n>> ");
    string delim=ReadString("Enter delimter to cut \n>> ");
    PrintSpratedWords(sentence, delim);
    return 0;
}