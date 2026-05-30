// Problem #49.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include<iomanip>
using namespace std;

const string filename = "Clientfile2";

struct stclient {
    string account_number;
    string pincode;
    string name;
    string phone;
    int balance;

};

stclient Fill_struct(vector<string> data)
{

    stclient client;

    client.account_number = data[0];
    client.pincode = data[1];
    client.name = data[2];
    client.phone = data[3];
    client.balance = stoi(data[4]);

    return client;



}

vector <string> Split_str(string s, string delimeter)
{
    vector<string> words;
    int pos = 0;
    string word = "";

    while ((pos = s.find(delimeter)) != string::npos)
    {

        word = s.substr(0, pos);
        if (word != "")
        {
            words.push_back(word);

        }

        s = s.erase(0, pos + delimeter.length());


    }

    if (s != "")
    {
        words.push_back(s);
    }

    return words;


}

vector<string> Read_from_file(string file_name)
{
    vector<string> Records;

    fstream myfile;
    myfile.open(filename, ios::in);

    if (myfile.is_open())
    {
        string line;

        while (getline(myfile, line))
        {
            Records.push_back(line);



        }


        myfile.close();

    }



    return Records;


}

void PrintClientRecord(stclient Client)
{
    cout << "| " << setw(15) << left << Client.account_number;
    cout << "| " << setw(10) << left << Client.pincode;
    cout << "| " << setw(40) << left << Client.name;
    cout << "| " << setw(12) << left << Client.phone;
    cout << "| " << setw(12) << left << Client.balance;
}


void PrintAllClientsData(vector <stclient> vClients)
{
    cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ")"
        << " Client(s).";
    cout <<
        "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
    cout << "| " << left << setw(15) << "Accout Number";
    cout << "| " << left << setw(10) << "Pin Code";
    cout << "| " << left << setw(40) << "Client Name";
    cout << "| " << left << setw(12) << "Phone";
    cout << "| " << left << setw(12) << "Balance";
    cout <<
        "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
    for (stclient Client : vClients)
    {
        PrintClientRecord(Client);
        cout << endl;
    }
    cout <<
        "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
}

vector<stclient> All_Data()
{
    vector<stclient> clients;

    vector<string> Records = Read_from_file(filename);

    for (int i = 0;i < Records.size();i++)
    {

        stclient client = Fill_struct(Split_str(Records[i], "#//#"));
        clients.push_back(client);



    }


    return clients;

}

void Print_result(vector<stclient> clients,string accountum)
{
    for (int i = 0;i < clients.size();i++)
    {
        if (clients[i].account_number == accountum)
        {
            cout << "\n\nthe following is the client details: \n\n";
            cout << "Account number: " << clients[i].account_number << "\n";
            cout << "Pin code: " << clients[i].pincode << "\n";
            cout << "Name: " << clients[i].name << "\n";
            cout << "phone: " << clients[i].phone << "\n";
            cout << "Balance: " << clients[i].balance << "\n";
          
            return;

        }


    }

    cout << "\n\nClient with account number " << accountum << " not found\n";

}


bool Check_account(string account_num, stclient& clientx)
{

    vector <stclient> clients = All_Data();

    for (stclient client : clients)
    {
        if (client.account_number == account_num)
        {
            clientx = client;
            return 1;

        }


    }

    return 0;


}

void print_client_Data(stclient client)
{
    cout <<"\naccount number: "<< client.account_number << "\n";
    cout <<"Pin code: "<< client.pincode << "\n";
    cout <<"Name: "<< client.name << "\n";
    cout <<"phone: "<< client.phone << "\n";
    cout << "account balance: "<<client.balance << "\n";


}

int main()
{
    stclient client;

    cout << "Enter account number: "; string c; cin >> c;

   


    if (Check_account(c, client))
    {
        cout << "\n\nClinet data\n";
        print_client_Data(client);
        cout << "\n\n";



    }
    else
    {
        cout << "\n\nclient with account number " << c << " is not found\n\n";
    }
   




}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
