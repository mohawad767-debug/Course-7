// pROBLEM #29.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

enum Whattocount{Small=1,Capital=2,All=3
};


string Reads()
{
    string s; cout << "Enter your string\n";
    getline(cin, s);
    return s;

    
}

int stringlength(string s)
{
    return s.length();

}

int Capletters(string s)
{
    int c = 0;
    for (int i = 0;i < s.length();i++)
    {
        if (isupper(s[i]))
            c++;
        

        
    }
    return c;


}

int Smallletters(string s)
{
    int c = 0;
    for (int i = 0;i < s.length();i++)
    {
        if (islower(s[i]))
            c++;



    }
    return c;
}

int Countstring(string s, Whattocount abouts)
{
    if (abouts == Whattocount::All)
        return s.length();

    int c = 0;
    for (int i = 0;i < s.length();i++)
    {
        if (islower(s[i])&&abouts==Whattocount::Small)
            c++;

        if (isupper(s[i])&&abouts == Whattocount::Capital)
            c++;




    }
    return c;




}



int main()
{
    /*
   
    string s = Reads();
    cout << "\n\nstring length: " << stringlength(s) << "\n";
    cout << "Capital letters count: " << Capletters(s) << "\n";
    cout << "Small letters count: " << Smallletters(s) << "\n";
     */
    string s = Reads();
    cout << "\n\nstring length: " << Countstring(s,Whattocount::All) << "\n";
    cout << "Capital letters count: " << Countstring(s, Whattocount::Capital) << "\n";
    cout << "Small letters count: " << Countstring(s, Whattocount::Small) << "\n";
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
