// Problem #06.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <stdio.h>
#include <vector>
using namespace std;

void Read_Rows_Cols(int* R, int* C)
{
    cout << "Enter the numer of rows: ";
    cin >> *R;

    cout << "Enter thw number of columns: ";
    cin >> *C;


}

int** two_dimnench_arr(int R, int C)
{


    int** arr = new int* [R];

    for (int i = 0;i < R;i++)
    {
        arr[i] = new int[C];
    }

    return arr;




}

void Fillarr(int** arr, int R, int C)
{
    int c = 1;

    for (int i = 0;i < R;i++)
    {

        for (int j = 0;j < C;j++)
        {
            arr[i][j] = c;
            c++;
        }
    }



}

void Printarr(int** arr, int R, int C)
{
    for (int i = 0;i < R;i++)
    {

        for (int j = 0;j < C;j++)
        {
          
            cout << arr[i][j] << "\t";
        }

        cout << "\n";
    }

}

int main()
{
    int R, C;
    Read_Rows_Cols(&R, &C);
    int** arr = two_dimnench_arr(R, C);
    Fillarr(arr, R, C);
    Printarr(arr, R, C);







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
