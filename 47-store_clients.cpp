#include <iostream>
#include <fstream>

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

void StoreDataToFile(string fileName,string Data)
{
    fstream myFile;
    myFile.open(fileName,ios::app);
    myFile << Data << endl;
    myFile.close();
}


bool IsContinue(string msg,string passCase)
{
    string ans;
    cout << msg << endl;
    cin  >> ans;
    cin.ignore();
    return ans == passCase;
}

void AddClients(string fileName)
{
    do
    {
        system("cls");
        string Data=ConvertRecordToLine(ReadClientData(),"#//#");
        StoreDataToFile(fileName,Data);
    } while (IsContinue("Do you want to add anothr client. (y/n)","y"));
    
}

int main()
{
    const string fileName="Clients_Data.txt";
    AddClients(fileName);
    return 0;
}