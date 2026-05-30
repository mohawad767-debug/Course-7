// Problem #46.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;


struct stclient {

    string account_number;
    string pin_code;
    string name;
    string phone;
    int balance;

};

string ReadString()
{
    string s;
    cout << "Enter your string: \n"; getline(cin, s);
    return s;

}

vector<string> split_str(string s, string delimeter)
{
   
    vector<string> words;
    

    short pos = 0;
    string sWord; 
 
    while ((pos = s.find(delimeter)) != std::string::npos)
    {
        sWord = s.substr(0, pos); 
        if (sWord != "")
        {
            words.push_back(sWord);
           
        }
        s.erase(0, pos + delimeter.length()); 
    }
    if (s != "")
    {
        words.push_back(s);
    }
    return words;
  
}


void Fillstruct(vector<string> words,stclient &client)
{
    client.account_number = words[0];
    client.pin_code = words[1];
    client.name = words[2];
    client.phone = words[3];
    client.balance = stoi(words[4]);


}

void Print_str(stclient& client)
{
    cout << "\n\nthe following is the extracted record:\n";
    cout << "Account number  : " << client.account_number << "\n";
    cout << "Pin code        : " << client.pin_code << "\n";
    cout << "Name            : " << client.name << "\n";
    cout << "phone           : " << client.phone << "\n";
    cout << "Balance         : " << client.balance << "\n";

    cout << "\n\n";


}



int main()
{

    string s = ReadString();

    stclient client;
    Fillstruct(split_str(s, "#//#"), client);
    Print_str(client);


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
