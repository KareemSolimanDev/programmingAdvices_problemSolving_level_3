#include <iostream>
#include <vector>

using namespace std;

struct sClient{
    string accountNum,pinCode,name,phone;
    float accountBalance;
};

vector <string> SplitWords(string sentence, string delim)
{
    vector <string> words={};
    string word="";
    sentence += delim;
    short delimPos = 0;
    

    while((delimPos=sentence.find(delim))!=string::npos)
    {
        word=sentence.substr(0,delimPos);
        if (word!="")
        {
            words.push_back(word);
        }
        sentence.erase(0,delimPos+delim.length());
    }
    return words;
}




sClient ConvertLineToRecord(string line,string delim)
{
    vector<string> vSplitedRecord=SplitWords(line,delim);
    sClient record;
    record.accountNum=vSplitedRecord[0];
    record.pinCode=vSplitedRecord[1];
    record.name=vSplitedRecord[2];
    record.phone=vSplitedRecord[3];
    record.accountBalance=stof(vSplitedRecord[4]);
    return record;
}
int main()
{
    string line="a1#//#22332#//#kareem#//#323455664#//#500.4";
    sClient Client=ConvertLineToRecord(line,"#//#");
    cout << Client.accountNum << endl;
    cout << Client.pinCode << endl;
    cout << Client.name << endl;
    cout << Client.phone << endl;
    cout << Client.accountBalance << endl;

    return 0;
}