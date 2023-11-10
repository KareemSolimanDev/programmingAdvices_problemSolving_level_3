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

void PrintClientsData(vector<sClient> vData)
{
    cout << "\n\t\t\t\t\tClient List (" << vData.size() << ") Client(s).";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
    cout << "| " << left << setw(15) << "Accout Number";
    cout << "| " << left << setw(10) << "Pin Code";
    cout << "| " << left << setw(40) << "Client Name";
    cout << "| " << left << setw(12) << "Phone";
    cout << "| " << left << setw(12) << "Balance";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    for (sClient &Client : vData)
    {
        cout << "| " << setw(15) << left << Client.accountNum;
        cout << "| " << setw(10) << left << Client.pinCode;
        cout << "| " << setw(40) << left << Client.name;
        cout << "| " << setw(12) << left << Client.phone;
        cout << "| " << setw(12) << left << Client.accountBalance;
        cout << endl;
    }
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
}

int main()
{
    const string fileName = "Clients_Data.txt";
    vector<sClient> vData = FormatClientsData(GetClientsDataFromFile(fileName), "#//#");
    PrintClientsData(vData);
    return 0;
}