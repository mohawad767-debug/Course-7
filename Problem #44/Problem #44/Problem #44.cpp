// Problem #44.cpp : This file contains the 'main' function. Program execution begins and ends there.
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


string Remove_punct(string s)
{
    string s2 = "";
    for (int i = 0;i < s.length();i++)
    {
        if (!ispunct(s[i]))
        {
            s2 += s[i];
           
        }
    }
    return s2;
}


int main()
{
    string s = Readstring();

    cout << "\n\nstring after removing punctuation: \n";
    cout << Remove_punct(s) << "\n";
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
