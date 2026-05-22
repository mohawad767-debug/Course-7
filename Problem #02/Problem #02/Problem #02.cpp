// Problem #02.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <stdio.h>
using namespace std;

void Read_Rows_Columns(int* R, int* C)
{
    cout << "Enter the number of Rows: ";
    cin >> *R;

    cout << "Enter the number of Columns: ";
    cin >> *C;



}

int** create_2d_arr(int R, int C)
{
    int** arr = new int* [R];

    for (int i = 0;i < R;i++)
    {
        arr[i] = new int[C];

    }
    return arr;


}

int Randomnum(int from, int to)
{

    return rand() % (to - from + 1) + from;

}

void Fillarr(int** arr, int R, int C)
{
    for (int i = 0;i < R;i++)
    {

        for (int j = 0;j < C;j++)
        {
            arr[i][j] = Randomnum(1, 100);

        }


    }



}

void Printarr(int** arr, int R, int C)
{


    for (int i = 0;i < R;i++)
    {

        for (int j = 0;j < C;j++)
        {
            cout << setw(3) << arr[i][j] << "\t";

        }

        cout << "\n";
    }



}

void Print_Sum_of_each_Row(int** arr, int R, int C)
{
    int sum = 0;

    for (int i = 0;i < R;i++)
    {
        sum = 0;
        for (int j = 0;j < C;j++)
        {

            sum += arr[i][j];


        }

        cout <<"Row " << i + 1 << " sum = " << sum << "\n";
    }



}

void Deletearr(int** arr, int R)
{

    for (int i = 0;i < R;i++)
    {
        delete[]arr[i];
    }

    delete arr;



}





int main()
{
    srand((unsigned)time(NULL));

    int R, C;
    Read_Rows_Columns(&R, &C);
    int** arr = create_2d_arr(R, C);
    Fillarr(arr, R, C);

    cout << "\n\nThe following is a " << R << "*" << C << " Random array:\n";
    Printarr(arr, R, C);

    cout << "\n\nThe following are the sum of each Row in the array: \n";
    Print_Sum_of_each_Row(arr, R, C);
    Deletearr(arr, R);

















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
