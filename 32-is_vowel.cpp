#include <iostream>

using namespace std;

char ReadChar(string msg)
{
    char charInput;
    cout << msg;
    cin >> charInput;
    return charInput;
}

bool IsVowel(char ch)
{
    ch=tolower(ch);
    return ch=='a'||ch=='e'||ch=='o'||ch=='u'||ch=='i';
}

int main()
{
    char ch=ReadChar("Enter character to check.\n>> ");
    cout << (IsVowel(ch)?"Yes , It's vowel letter.":"No , It's not vowel letter.");

    return 0;
}