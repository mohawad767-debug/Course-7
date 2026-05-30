// Problem #45.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
using namespace std;

struct stclient {
    string acount_number;
    string pin_code;
    string name;
    string phone;
    int account_balance;


};

stclient Read_data()
{
    stclient client1;
    cout << "Enter account number: "; cin >> client1.acount_number;
    cout << "Enter pincode :"; cin >> client1.pin_code;
    cin.ignore(1, '\n');
    cout << "Enter account name: ";getline(cin, client1.name);
    cout << "Enter phone :"; cin >> client1.phone;
    cout << "Enter Acoount balance :"; cin >> client1.account_balance;

    return client1;






}

string print_st(stclient client,string delimetr)
{
    /*
    
    cout << "\n\nclient record for saving is: \n";
    cout << client.acount_number << delimetr << client.pin_code << delimetr
        << client.name << delimetr << client.phone << delimetr << client.account_balance << "\n";
        */

    string record = "";

    record += client.acount_number + delimetr;
    record+= client.pin_code + delimetr;
    record += client.name + delimetr;
    record += client.phone + delimetr;
    record += to_string(client.account_balance);

    return record;



}


int main()
{
    string s= print_st(Read_data(), "#//");


    cout << "\n\nUser account for saving is:\n ";
    cout << s << "\n";
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
