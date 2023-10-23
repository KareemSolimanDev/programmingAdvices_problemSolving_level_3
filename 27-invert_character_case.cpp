#include <iostream>

using namespace std;

char ReadChar(string msg)
{
    char charInput;
    cout << msg;
    cin >> charInput;
    return charInput;
}
char InvertCharCase(char character)
{
    return isupper(character)?tolower(character):toupper(character);
}
int main()
{
    char invertedChar=InvertCharCase(ReadChar("Enter character to invert \n>> "));
    cout << "inverted char : " << invertedChar << endl;
    return 0;
}