#include <iostream>
#include <string>
using namespace std;

string ReplaceAllWords(string str,string toReplace,string replaceTo)
{
    short pos=str.find(toReplace);
    while(pos!=string::npos)
    {
        str.replace(pos,toReplace.length(),replaceTo);
        pos=str.find(toReplace);
    }
    return str;
}

int main()
{
    
    cout << ReplaceAllWords("Hi kareem, Hi","Hi","Hello");
    return 0;
}