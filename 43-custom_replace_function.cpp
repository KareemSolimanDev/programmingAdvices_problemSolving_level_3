#include <iostream>
#include <vector>
using namespace std;

string ReadString(string msg)
{
    string stringInput;
    cout << msg;
    getline(cin, stringInput);
    return stringInput;
}

vector<string> SplitWords(string sentence, string delim)
{
    vector<string> words = {};
    string word = "";
    sentence += delim;
    short delimPos = 0;

    while ((delimPos = sentence.find(delim)) != string::npos)
    {
        word = sentence.substr(0, delimPos);
        if (word != "")
        {
            words.push_back(word);
        }
        sentence.erase(0, delimPos + delim.length());
    }
    return words;
}

// with option to reverse
string JoinStr(vector<string> vec, string delim, bool reverse = false)
{

    string joinedVec = "";

    if (reverse)
    {
        vector<string>::iterator iter = vec.end();
        while (iter != vec.begin())
        {
            --iter;
            joinedVec += *iter + delim;
        }
    }
    else
    {

        vector<string>::iterator iter = vec.begin();
        while (iter != vec.end())
        {
            joinedVec += *iter + delim;
            ++iter;
        }
    }

    return joinedVec.substr(0, joinedVec.length() - delim.length());
}

string LowerAllString(string S1)
{
    for (short i = 0; i < S1.length(); i++)
    {
        S1[i] = tolower(S1[i]);
    }
    return S1;
}

string ReplaceWords(string str, string toReplace, string replaceTo, bool matchCase = true)
{
    vector<string> vString=SplitWords(str," ");
    for (string &i : vString)
    {

        if (matchCase)
        {
            if (i == toReplace)
            {
                i = replaceTo;
            }
        }
        else
        {
            if (LowerAllString(i) == LowerAllString(toReplace))
            {
                i = replaceTo;
            }
        }
    }
    return JoinStr(vString," ");
}

int main()
{
    string sentence = ReadString("Enter string \n>> ");
    string toReplace = ReadString("Enter word that you want to replace \n>> ");
    string replaceTo = ReadString("Enter word that you want replace to it \n>> ");

    cout << "Replace with match case : " << ReplaceWords(sentence,toReplace,replaceTo) << endl;
    cout << "Replace without match case : " << ReplaceWords(sentence,toReplace,replaceTo,false) << endl;

    return 0;
}