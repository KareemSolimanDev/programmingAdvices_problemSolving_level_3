#include <iostream>

using namespace std;

string ReadString(string msg)
{
    string stringInput;
    cout << msg;
    getline(cin,stringInput);
    return stringInput;
}


void PrintSpratedWords(string sentence)
{
    string word="";
    sentence+=" ";
    for(char &i : sentence)
    {
        
            if (i==' ')
            {
                cout << word << "\n";
                word="";
            }else{
                word+=i;
            }
            
    }

}



int main()
{
    string sentence=ReadString("Enter string to count \n>> ");

    PrintSpratedWords(sentence);
    return 0;
}