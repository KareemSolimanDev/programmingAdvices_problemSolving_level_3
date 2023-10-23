#include <iostream>

using namespace std;

string ReadString(string msg)
{
    string stringInput;
    cout << msg;
    getline(cin,stringInput);
    return stringInput;
}



short CountUpperCase(string sentence)
{
    short counter;
    for(char &i : sentence)
    {
            if (isupper(i))
            {
                counter++;
            }
            
    }
    return counter;
}

short CountLowerCase(string sentence)
{
    short counter;
    for(char &i : sentence)
    {
            if (islower(i))
            {
                counter++;
            }
            
    }
    return counter;
}

int main()
{
    string sentence=ReadString("Enter string to count \n>> ");
    cout << "string size : " << sentence.length() << endl;
    cout << "Upper letters count : " << CountUpperCase(sentence) << endl;
    cout << "Lower letters count : " << CountLowerCase(sentence) << endl;
    return 0;
}