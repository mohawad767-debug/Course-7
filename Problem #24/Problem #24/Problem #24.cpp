// Problem #24.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

string Readstring()
{
    string s; cout << "Enter your string: \n";
    getline(cin, s);

    return s;

}


void stringupper(string &s)
{
    bool isfirst = 1;

    for (int i = 0;i < s.length();i++)
    {

        if (s[i] != ' ' && isfirst)
        {
            
            s[i] = toupper(s[i]);
        }


        isfirst = (s[i] == ' ' ? true : false);

    }





}



int main()
{
    string s = Readstring();

   stringupper(s);
   cout << "\nstring after conversion: \n";cout << s << endl;




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
