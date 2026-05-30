// Problem #51.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include<fstream>
using namespace std;

const string filename = "Clientfile2";

struct stclient {
    string account_num;
    string pin_code;
    string name;
    string phone;
    int balance;

    bool to_update = false;

};

stclient Fillclient(vector<string> record)
{
    stclient x;
    x.account_num = record[0];
    x.pin_code = record[1];
    x.name = record[2];
    x.phone = record[3];
    x.balance = stoi(record[4]);

    return x;



}

vector<string> Split_str(string s,string delimeter)
{
    vector<string> Records;
    int pos = 0;
    string word = "";

    while ((pos = s.find(delimeter)) != string::npos)
    {

        word = s.substr(0, pos);
        Records.push_back(word);

        s = s.erase(0, pos + delimeter.length());


    }

    if (s != "")
    {
        Records.push_back(s);
    }
 
    return Records;


}


vector <string> Read_Records()
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

    }


    return Records;

}

vector <stclient> Convert_filelines_into_structure()
{
    vector<stclient> clients;

    vector<string> Records = Read_Records();

    for (string& s : Records)
    {
        clients.push_back(Fillclient(Split_str(s, "#//#")));

    }

    return clients;



}

string Read_account_num()
{

    string s; cout << "Enter account number: ";
    cin >> s;
    return s;

}

bool find_Selected_client(vector<stclient> &clients,string account_num,stclient &client)
{
    for (stclient& x : clients)
    {
        if (x.account_num == account_num)
        {
            x.to_update = 1;
            client = x;

            return 1;

        }


    }
    
    return 0;

}

void Print_struct(stclient x)
{

    cout << "\n\nThe following are the client material: \n\n";
    cout << "Account number: " << x.account_num << "\n";
    cout << "Pin code: " << x.pin_code << "\n";
    cout << "Name: " << x.name << "\n";
    cout << "Phone: " << x.phone << "\n";
    cout << "Balance: "<<x.balance << "\n";
    


}

void ubdate_Client_Data(vector<stclient> &x)
{
    for (stclient &client : x)
    {
        if (client.to_update == true)
        {

            cout << "\n\nEnter picode: "; cin >> client.pin_code;
            cin.ignore(1, '\n');
            cout << "Enter name: "; getline(cin, client.name);
            cout << "Enter phone: "; cin >> client.phone;
            cout << "Enter account balance: ";cin >> client.balance;





        }




    }

}


string conactenate_struct(stclient client, string delimeter)
{

    string Record;

    Record += client.account_num + delimeter;
    Record += client.pin_code + delimeter;
    Record += client.name + delimeter;
    Record += client.phone + delimeter;
    Record += to_string(client.balance);

    return Record;





}

void put_strings_in_file(vector<string> Records)
{
    fstream myfile;
    myfile.open(filename, ios::out);
    if(myfile.is_open())
    {
        for (string& s : Records)
        {

            myfile << s << "\n";

        }



    }
  




}


void Return_tofile(vector<stclient> clients)
{
    vector<string> Record;

    for (stclient& client : clients)
    {
        Record.push_back(conactenate_struct(client, "#//#"));
    }

    put_strings_in_file(Record);

}

void Update_Client(vector<stclient> &Allclients, string account_number)
{
    stclient client;

    if (find_Selected_client(Allclients, account_number, client))
    {
        Print_struct(client);
        char c; cout << "\nDo you want to ubdate client data: "; cin >> c;

        if (toupper(c) == 'Y')
        {
            ubdate_Client_Data(Allclients);
            cout << "\nClient ubdated successfuly\n";
            Return_tofile(Allclients);

        }



    }
    else
    {
        cout << "\n\nClient with account number " << account_number << " is not found\n\n";
    }



}


int main()
{
    vector<stclient> clients = Convert_filelines_into_structure();
    string account_num = Read_account_num();


    Update_Client(clients, account_num);




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
