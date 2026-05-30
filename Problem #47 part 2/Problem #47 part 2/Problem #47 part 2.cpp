// Problem #47 part 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct stclient {
    string account_number;
    string pincode;
    string name;
    string phone;
    int balance;

};

stclient Read_Data()
{
    stclient client;

    cout << "Enter account number: "; getline(cin >> ws, client.account_number);
    cout << "Enter pincode: "; getline(cin, client.pincode);
    cout << "Enter name: ";getline(cin, client.name);
    cout << "Enter phone: ";getline(cin, client.phone);
    cout << "Enter account balance: ";cin >> client.balance;

    return client;


        




}

string Convert_to_record( stclient client,string delimeter)
{
    string record = "";

    record += client.account_number + delimeter;
    record += client.pincode + delimeter;
    record += client.name + delimeter;
    record += client.phone + delimeter;
    record += to_string(client.balance);

    return record;



}


void Add_string_to_file(string file_name,string record)
{
    fstream myfile;
    myfile.open(file_name, ios::out | ios::app);
 
        if (myfile.is_open())
        {
            myfile << record << "\n";
            myfile.close();




        }




}

void Add_client()
{


    stclient client=Read_Data();
    Add_string_to_file("Clientfile", Convert_to_record(client, "#//#"));




}



void Add_All()
{
    char x;

    do
    {
        system("cls");
        cout << "Adding new client\n\n";
        Add_client();
        cout << "\n\nclient added succefully.  Do you want to add more? ";
        cin >> x;

    } while (toupper(x) == 'Y');





}


int main()
{
    Add_All();
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
