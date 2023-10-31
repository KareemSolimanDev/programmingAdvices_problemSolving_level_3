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

// reverse words function
vector<string> ReverseWords(vector<string> sentence)
{
    string temp = "";
    short lastIndex = sentence.size() - 1;
    for (int i = 0; i < sentence.size() / 2; i++)
    {
        temp = sentence[i];
        sentence[i] = sentence[lastIndex - i];
        sentence[lastIndex - i] = temp;
    }
    return sentence;
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

// with specifc function to reverse
string ReverseWordsInText(string text, string delim)
{
    return JoinStr(ReverseWords(SplitWords(text, delim)), delim);
}

// with join option (to reverse while join)
string ReverseWordsInText(string text, string delim, bool reverse)
{
    return JoinStr(SplitWords(text, delim), delim, reverse);
}

int main()
{
    string sentence = ReadString("Enter string to reverse \n>> ");
    string delim = ReadString("Enter delimter to cut \n>> ");

    // reversing in specific function
    cout << ReverseWordsInText(sentence, delim) << endl;

    // reversing in join
    cout << ReverseWordsInText(sentence, delim, false) << endl;
    cout << ReverseWordsInText(sentence, delim, true) << endl;

    return 0;
}