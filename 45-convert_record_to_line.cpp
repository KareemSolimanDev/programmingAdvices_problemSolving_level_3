#include <iostream>

using namespace std;

struct sClient{
    string accountNum,pinCode,name,phone;
    float accountBalance;
};

string ReadString(string msg)
{
    string stringInput;
    cout << msg;
    getline(cin, stringInput);
    return stringInput;
}

sClient ReadClientData()
{
    sClient CliData;
    cout << "\n\t\tPlease enter client data.\n\n";
    CliData.accountNum=ReadString("Enter Account number.\n>> ");
    CliData.pinCode=ReadString("Enter pin code.\n>> ");
    CliData.name=ReadString("Enter the name.\n>> ");
    CliData.phone=ReadString("Enter phone number.\n>> ");
    CliData.accountBalance=0;

    return CliData;
}

string ConvertRecordToLine(sClient cliData,string delim)
{
    string line=cliData.accountNum+delim;
    line+=cliData.pinCode+delim;
    line+=cliData.name+delim;
    line+=cliData.phone+delim;
    line+=to_string(cliData.accountBalance);
    return line;
}
int main()
{
    
    cout << ConvertRecordToLine(ReadClientData(),"#//#");
    return 0;
}