#include <iostream>

using namespace std;

string ReadString(string msg)
{
    string stringInput;
    cout << msg;
    getline(cin, stringInput);
    return stringInput;
}


short CountSpratedWords(string sentence, string delim)
{
    string word = "";
    sentence += delim;
    short delimPos = 0;
    short counter=0;

    while((delimPos=sentence.find(delim))!=string::npos)
    {
        word=sentence.substr(0,delimPos);
        if (word!="")
        {
            counter++;
        }
        sentence.erase(0,delimPos+delim.length());
    }
    return counter;
}



int main()
{
    string sentence = ReadString("Enter string to count \n>> ");
    string delim=ReadString("Enter delimter to cut \n>> ");
    cout << "The count of words : " << CountSpratedWords(sentence, delim);
    return 0;
}