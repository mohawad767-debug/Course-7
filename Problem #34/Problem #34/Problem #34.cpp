// Problem #34.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

string Readstring()
{
    string s; cout << "Enter yuor string: \n";
    getline(cin, s);

    return s;

}

bool is_vowel(char c)
{


    char vowels[10] = { 'a','e','i','o','u','A','E','I','O','U' };

    for (int i = 0;i < 10;i++)
    {
        if (c == vowels[i])
        {
            return 1;
        }
    }

    return 0;


}

void printvowels(string s)
{
    int counter = 0;

    for (int i = 0;i < s.length();i++)
    {
        if (is_vowel(s[i]))
        {
            cout << s[i] << "   ";
        }

    }

  




}

int main()
{
    string s = Readstring();

    cout << "\n\nVowels in the string : ";
    printvowels(s);
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
