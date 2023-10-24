#include <iostream>

using namespace std;

enum enMatchCase{Yes,No};

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



short CountSpacificChar(string sentence,char wantedChar,enMatchCase isMatchCase=enMatchCase::No)
{
    short counter;
    for(char &i : sentence)
    {
            if ((i==tolower(wantedChar)||i==toupper(wantedChar))&&isMatchCase==enMatchCase::Yes)
            {
                counter++;
            }else if(i==wantedChar)
                counter++;
    }
    return counter;
}

int main()
{
    string sentence=ReadString("Enter string to count \n>> ");
    char letter=ReadChar("Enter your wanted character\n>>");

    short countWithoutMatch=CountSpacificChar(sentence,letter);
    short countWithMatch=CountSpacificChar(sentence,letter,enMatchCase::Yes);

    cout << "the letter '" << letter << "' has repeated [" << countWithoutMatch << "] times in this string.\n";
    cout << "letters '" << char(tolower(letter)) << "' and '" << char(toupper(letter)) << "' have repeated [" << countWithMatch << "] times in this string.";

    return 0;
}