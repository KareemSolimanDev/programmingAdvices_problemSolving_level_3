#include <iostream>

using namespace std;

string ReadString(string msg)
{
    string stringInput;
    cout << msg;
    getline(cin,stringInput);
    return stringInput;
}

bool IsVowel(char ch)
{
    ch=tolower(ch);
    return ch=='a'||ch=='e'||ch=='o'||ch=='u'||ch=='i';
}

void PrintVowelLetters(string sentence)
{
    cout << "vowel letters : ";
    for(char &i : sentence)
    {
            if (IsVowel(i))
            {
                cout << i << "  ";
            }
            
    }

}



int main()
{
    string sentence=ReadString("Enter string to count \n>> ");

    PrintVowelLetters(sentence);
    return 0;
}