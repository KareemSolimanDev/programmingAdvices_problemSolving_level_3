#include <iostream>
#include <fstream>

using namespace std;

struct sClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
};

sClient ReadNewClient()
{
    sClient Client;
    cout << "Enter Account Number? ";

    // to solve cin with getline problem
    // getline(cin ##( >> ws )###, Client.AccountNumber);

    getline(cin, Client.AccountNumber);
    cout << "Enter PinCode? ";
    getline(cin, Client.PinCode);
    cout << "Enter Name? ";
    getline(cin, Client.Name);
    cout << "Enter Phone? ";
    getline(cin, Client.Phone);
    cout << "Enter AccountBalance? ";
    cin >> Client.AccountBalance;

    return Client;
}

string ConvertRecordToLine(sClient Client, string Seperator = "#//#")
{
    string stClientRecord = "";
    stClientRecord = Client.AccountNumber + Seperator;
    stClientRecord += Client.PinCode + Seperator;
    stClientRecord += Client.Name + Seperator;
    stClientRecord += Client.Phone + Seperator;
    stClientRecord += to_string(Client.AccountBalance);

    return stClientRecord;
}
void AddDtataToFile(string fileName,string Data)
{
    fstream DataFile;
    DataFile.open(fileName,ios::out | ios::app);
    DataFile << Data << endl;
    DataFile.close();
}
void AddClients()
{
    sClient Client;
    char con = 'Y';
    do
    {

        system("cls");
        cout << "\nPlease Enter Client Data: \n\n" << endl;
        Client = ReadNewClient();

        AddDtataToFile("Client_Data.txt",ConvertRecordToLine(Client));
        cout << "\nClient Record Saving succesfully \n";
        cout << "Do you want to add another client data y/n \n>> ";
        cin >> con;
        cin.ignore();
    } while (tolower(con) == 'y');

}

int main()
{


    AddClients();

    return 0;
}