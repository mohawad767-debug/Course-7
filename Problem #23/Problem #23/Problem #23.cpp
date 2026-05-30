// Problem #23.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

void prints(string s)
{
    cout << s[0] << endl;
    for (int i = 0;i < s.length();i++)
    {
        if (s[i] == ' ')
        {
            cout << s[i + 1] << endl;
        }


    }


}

string Readstring()
{
    cout << "Enter your string: ";
    string s; getline(cin, s);
    return s;

}

void printfirstletter(string s)
{
    bool isfirst = 1;

    for (int i = 0;i < s.length();i++)
    {

        if (s[i] != ' ' && isfirst)
        {
            cout << s[i] << endl;

        }


        isfirst = (s[i] == ' ' ? true : false);

    }





}



int main()
{
    string s = Readstring();

    printfirstletter(s);




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
