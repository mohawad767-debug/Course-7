// Problem #38.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

string Readstring()
{
    string s; cout << "Enter your string: ";
    getline(cin, s);
    return s;

}

string trim_left(string s)
{
    for (int i = 0;i < s.length();i++)
    {
        if (s[i] != ' ')
            return s.substr(i, s.length() - i );
    }


}

string trim_right(string s)
{
    for (int i = s.length()-1;i >= 0;i--)
    {
        if (s[i] != ' ')
            return s.substr(0, i+1);
    }


}

string trim_all(string s)
{
    /*
    
    string b;
    b = trim_left(s);
    b = trim_right(b);
    return b;
    */

    return trim_right((trim_left(s)));

}


int main()
{
    string s = Readstring(); cout << "\n\n";
    
    cout << "string     = " << s << "\n";
    cout << "Trim left  = " << trim_left(s) << "\n";
    cout << "Trim right = " << trim_right(s) << "\n";
    cout << "Trim all   = " << trim_all(s) << "\n";

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
