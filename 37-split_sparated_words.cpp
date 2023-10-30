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


vector <string> SplitWords(string sentence, string delim)
{
    vector <string> words={};
    string word="";
    sentence += delim;
    short delimPos = 0;
    

    while((delimPos=sentence.find(delim))!=string::npos)
    {
        word=sentence.substr(0,delimPos);
        if (word!="")
        {
            words.push_back(word);
        }
        sentence.erase(0,delimPos+delim.length());
    }
    return words;
}

void PrintVector(vector <string> vec)
{
    for (string &i : vec)
    {
        cout << i << endl;
    }
    
}

int main()
{
    string sentence = ReadString("Enter string to count \n>> ");
    string delim=ReadString("Enter delimter to cut \n>> ");
    vector <string> vecWords= SplitWords(sentence,delim);
    cout << "Tokens : " << vecWords.size() << endl;
    PrintVector(vecWords);
    return 0;
}