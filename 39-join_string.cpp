#include <iostream>
#include <vector>

using namespace std;

string JoinStr(vector <string> vec,string delim)
{
    string joinedVec="";
    for (string &i : vec)
    {
        joinedVec+=i+delim;
    }
    return joinedVec.substr(0,joinedVec.length()-delim.length());
}

int main()
{
    vector <string> words={"Hi","Kareem","Alsayd"};
    cout << JoinStr(words," ");
    return 0;
}