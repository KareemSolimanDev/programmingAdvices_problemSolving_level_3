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

string JoinStr(string Arr[],int arrLen,string delim)
{
    string joinedArr="";
    for (int i=0;i < arrLen;i++)
    {
        joinedArr+=Arr[i]+delim;
    }
    return joinedArr.substr(0,joinedArr.length()-delim.length());
}
int main()
{
    vector <string> Vwords={"Hi","Kareem","Alsayd"};
    string Awords[]={"Hi","Kareem","Alsayd"};
    cout << "Vector: " << JoinStr(Vwords," ") << endl;
    cout << "Array: " << JoinStr(Awords,3," ") << endl;
    return 0;
}