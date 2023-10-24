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

short CountVowelLetters(string sentence)
{
    short counter=0;
    for(char &i : sentence)
    {
            if (IsVowel(i))
            {
                counter++;
            }
            
    }
    return counter;
}



int main()
{
    string sentence=ReadString("Enter string to count \n>> ");
    cout << "vowel letters count : " << CountVowelLetters(sentence) << endl;
    return 0;
}