#include <iostream>

using namespace std;

string ReadString(string msg)
{
    string stringInput;
    cout << msg;
    getline(cin, stringInput);
    return stringInput;
}

string RemovePunctSigns(string str)
{
    for (short i = 0; i < str.length(); i++)
    {
        if (ispunct(str[i]))
        {
            str[i]=char(0);
        }
        
    }
    return str;
}


int main()
{
    string sentence = ReadString("Enter string \n>> ");
    cout << "Original : " << sentence << endl;
    cout << "After removing : " << RemovePunctSigns(sentence) << endl;
    return 0;
}