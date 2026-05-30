// Problem #35.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

void print_each_word(string s)
{
    string b = "";

    for (int i = 0;i < s.length();i++)
    {
        if (s[i] != ' ')
        {
            b += s[i];
        }
        else
        {
            if (s != "")
            {
                cout << b << "\n";
            }
      
            b = "";

        }


    }




}

void print_each_word2(string S1)
{
    string delim = " "; // delimiter
    short pos = 0;
    string sWord; // define a string variable
    // use find() function to get the position of the delimiters
    while ((pos = S1.find(delim)) != std::string::npos)
    {
        sWord = S1.substr(0, pos); // store the word
        if (sWord != "")
        {
            cout << sWord << endl;
        }
        S1.erase(0, pos + delim.length()); /* erase() until
        positon and move to next word. */
    }
    if (S1 != "")
    {
        cout << S1 << endl; // it print last word of the string.
    }
}


int main()
{

    string s = Readstring();

    cout << "\n\nYour string words: \n";
    print_each_word2(s);
    cout << "\n\n";
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
