#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

struct sClient
{
    string accountNum, pinCode, name, phone;
    float accountBalance;
};

string ReadString(string msg)
{
    string stringInput;
    cout << msg;
    getline(cin, stringInput);
    return stringInput;
}

vector<string> SplitWords(string sentence, string delim)
{
    vector<string> words = {};
    string word = "";
    sentence += delim;
    short delimPos = 0;

    while ((delimPos = sentence.find(delim)) != string::npos)
    {
        word = sentence.substr(0, delimPos);
        if (word != "")
        {
            words.push_back(word);
        }
        sentence.erase(0, delimPos + delim.length());
    }
    return words;
}

sClient ConvertLineToRecord(string line, string delim)
{
    vector<string> vSplitedRecord = SplitWords(line, delim);
    sClient record;
    record.accountNum = vSplitedRecord[0];
    record.pinCode = vSplitedRecord[1];
    record.name = vSplitedRecord[2];
    record.phone = vSplitedRecord[3];
    record.accountBalance = stof(vSplitedRecord[4]);
    return record;
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

vector<string> GetClientsDataFromFile(string fileName)
{
    fstream File;
    string Data;
    vector<string> vData;
    File.open(fileName, ios::in);
    while (getline(File, Data))
    {
        vData.push_back(Data);
    }
    File.close();
    return vData;
}

vector<sClient> FormatClientsData(vector<string> vData, string delim)
{
    sClient formatedData;
    vector<sClient> vFormatedData;
    for (string &i : vData)
    {
        formatedData = ConvertLineToRecord(i, delim);
        vFormatedData.push_back(formatedData);
    }
    return vFormatedData;
}

short FindClientData(vector<sClient> vData,string accountNum)
{
    short DataIndex=-1;
    for (short client=0; client < vData.size() ;client++)
    {
        if (vData[client].accountNum==accountNum)
        {
            DataIndex = client;
            break;
        }
        
    }
    return DataIndex;
}

void PrintClientData(sClient Data)
{
    cout << "\t\t\t\t______Client Data______\n\n";
    cout << "Accout Number   : " << Data.accountNum << "\n" ;
    cout << "Pin Code        : " << Data.pinCode << "\n" ;
    cout << "Client Name     : " << Data.name << "\n" ;
    cout << "Phone           : " << Data.phone << "\n" ;
    cout << "Account Balance : " << Data.accountBalance << endl ;
}

void PrintResult(vector<sClient> vData,short ClientIndex)
{
    

    if(ClientIndex!=-1)
    {
        PrintClientData(vData[ClientIndex]);
    }else{
        cout << "Oops , Client is not here" << endl;
    }
    
}

bool IsContinue(string msg,string passCase)
{
    string ans;
    cout << msg;
    cin  >> ans;
    cin.ignore();
    return ans == passCase;
}

void UpdateFileData(string fileName,vector<string> newData)
{
    fstream File;
    File.open(fileName,ios::out);
    
    for (string &line : newData)
    {
        File << line << endl;
    }
    File.close();

}

vector<string> ConvertRecordsToLines(vector<sClient> Data,string delim)
{
    vector<string> strData;
    
    for (sClient &client : Data)
    {
        strData.push_back(ConvertRecordToLine(client,delim));
    }
    return strData;

}
sClient UpdateClientData()
{
    sClient CliData;
    cout << "\n\t\tPlease enter new client data.\n\n";
    CliData.pinCode=ReadString("Enter new pin code.\n>> ");
    CliData.name=ReadString("Enter the new name.\n>> ");
    CliData.phone=ReadString("Enter new phone number.\n>> ");
    CliData.accountBalance=stof(ReadString("Enter new balance.\n>> "));

    return CliData;
}
void UpdateRecordFromVector(vector<sClient> &vec,short RecordIndex)
{
    sClient newRecord=UpdateClientData();
    newRecord.accountNum=vec[RecordIndex].accountNum;
    vec[RecordIndex]=newRecord;
}

int main()
{
    const string fileName = "Clients_Data.txt";
    string accountNum=ReadString("Enter Accout Number to update\n>> ");

    vector<sClient> vData=FormatClientsData(GetClientsDataFromFile(fileName),"#//#");
    short ClientIndex=FindClientData(vData,accountNum);

    PrintResult(vData,ClientIndex);
    if (ClientIndex!=-1)
    {
        bool continueupdateProcess=IsContinue("Are you sure to update this client. (y/n)\n>> ","y");
        if (continueupdateProcess)
        {
            UpdateRecordFromVector(vData,ClientIndex);
            UpdateFileData(fileName,ConvertRecordsToLines(vData,"#//#"));
            cout << "Client updated successfully" << endl;
        }
        
    }
    
    return 0;
}