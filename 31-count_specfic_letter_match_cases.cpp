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
    getline(cin, stringInput);
    return stringInput;
}

short CountSpacificChar(string sentence, char wantedChar, bool CaseSensitive = true)
{
    short counter;
    for (char &i : sentence)
    {

        if (CaseSensitive)
        {
            if (i == wantedChar)
            {
                counter++;
            }
        }
        else
        {
            if (tolower(i) == tolower(wantedChar))
                counter++;
        }
    }

    return counter;
}

int main()
{
    string sentence = ReadString("Enter string to count \n>> ");
    char letter = ReadChar("Enter your wanted character\n>>");

    short countWithCaseSensitive = CountSpacificChar(sentence, letter);
    short countWithoutCaseSensitive = CountSpacificChar(sentence, letter, false);

    cout << "the letter '" << letter << "' has repeated [" << countWithCaseSensitive << "] times in this string.\n";
    cout << "letters '" << char(tolower(letter)) << "' and '" << char(toupper(letter)) << "' have repeated [" << countWithoutCaseSensitive << "] times in this string.";

    return 0;
}