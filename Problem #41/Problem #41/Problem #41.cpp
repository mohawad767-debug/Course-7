// Problem #41.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

string Readstring()
{
    cout << "Enter your string:\n ";
    string s; getline(cin, s);
    return s;

}

vector<string> Split_string(string s,string delimeter)
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

string return_reverse(string s)
{
    vector<string>words;

    string s2 = "";
    words = Split_string(s, " ");

    vector<string>::iterator iter=words.end();

    while (iter != words.begin())
    {
        --iter;
        s2 += *iter + " ";



    }

    s2 = s2.substr(0, s2.length() - 1);

    return s2;



}

int main()
{
    
    string s = Readstring();
    
    cout << return_reverse(s) << "\n";




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
