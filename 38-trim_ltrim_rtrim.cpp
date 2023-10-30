#include <iostream>
using namespace std;

string ReadString(string msg)
{
    string stringInput;
    cout << msg;
    getline(cin, stringInput);
    return stringInput;
}


string Ltrim(string sentence)
{
    while(sentence[0]==' ')
    {
        sentence.erase(0,1);
    }
    return sentence;
}


string Rtrim(string sentence)
{
    int lastIndex=sentence.length()-1;
    while(sentence[lastIndex]==' ')
    {
        sentence.erase(lastIndex,lastIndex+1);
        lastIndex=sentence.length()-1;
    }
    return sentence;
}

string Trim(string sentence)
{
    return Rtrim(Ltrim(sentence));
}

int main()
{
    string sentence = ReadString("Enter string to count \n>> ");
    string s="fejfj";
    cout <<"After Left Trim:" <<  Ltrim(sentence) << "|" << endl;
    cout <<"After Right Trim :" <<  Rtrim(sentence) << "|" << endl;
    cout <<"After Trim :" <<  Trim(sentence) << "|" << endl;

    return 0;
}