#include <iostream>

using namespace std;

char ReadChar(string msg)
{
    char charInput;
    cout << msg;
    cin >> charInput;
    return charInput;
}

string ReadString(string msg)
{
    string stringInput;
    cout << msg;
    getline(cin,stringInput);
    return stringInput;
}



short CountSpacificChar(string sentence,char wantedChar)
{
    short counter;
    for(char &i : sentence)
    {
            if (i==wantedChar)
            {
                counter++;
            }
            
    }
    return counter;
}

int main()
{
    string sentence=ReadString("Enter string to count \n>> ");
    short count=CountSpacificChar(sentence,ReadChar("Enter your wanted character\n>>"));
    cout << "letter has repeated [" << count << "] times in this string.";
    return 0;
}