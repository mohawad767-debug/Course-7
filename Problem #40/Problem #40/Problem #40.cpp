// Problem #40.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector <string> Readvector()
{
    vector<string> words;
    int n;
    cout << "Enter yhe numer of names: ";
    cin >> n;

    string s;

    for (int i = 0;i < n;i++)
    {
        cout << "Enter name " << i + 1 << " : ";
        cin >> s;

        words.push_back(s);



    }
    return words;


}

string* Create_arr(int length)
{
    string* x = new string[length];
    return x;



}

void Readarr(string* arr, int length)
{

    for (int i = 0;i < length;i++)
    {
        cout << "Enter name " << i + 1 << " : ";
        cin >> arr[i];
    }
}




string Join_string(vector<string> words, string delimeter)
{
    /*

    string s = "";
    for (int i = 0;i < words.size() - 1;i++)
    {
        s += words[i];
        s += delimeter;

    }
    s += words[words.size() - 1];


    return s;

    */

    string S1 = "";

    for (string& b : words)
    {
        S1 = S1 + b + delimeter;

    }

    return S1.substr(0, S1.length() - delimeter.length());


}

string Join_string(string* namesarr, int length, string delimeter)
{
    string S;
    for (int i = 0;i < length-1;i++)
    {
        S = S + namesarr[i] + delimeter;

    }
    S += namesarr[length - 1];

    return S;


}

int main()
{
    cout << "enter the number of names: ";
    int n; cin >> n;

    string* arr = Create_arr(n);
    Readarr(arr, n);

    cout << "\n\n" << Join_string(arr, n, "|||") << "\n";



   

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
