// Problem #08.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;


int Randomnum(int from, int to)
{
    return rand() % (to - from + 1) + from;

}

void Read_Rows_Cols(int *R, int *C)
{
    cout << "Enter the number of rows: ";
    cin >> *R;

    cout << "Enter the number of columns: ";
    cin >> *C;


}

int** create2d(int R, int C)
{
    int** arr = new int*[R];

    for (int i = 0;i < R;i++)
    {
        arr[i] = new int[C];

    }


    return arr;



}

void fillarr(int **arr,int R, int C)
{
    for (int i = 0;i < R;i++)
    {
        for (int j = 0;j < C;j++)
        {
            arr[i][j] = Randomnum(1, 100);
            
        }




    }

}

void multiply(int** arr1, int** arr2, int** arr3, int R, int C)
{
    for (int i = 0;i < R;i++)
    {

        for (int j = 0;j < C;j++)
        {

            arr3[i][j] = arr1[i][j] * arr2[i][j];

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
    srand((unsigned)time(NULL));

    int R, C;
    Read_Rows_Cols(&R, &C);
   
    int** arr1 = create2d(R, C);  int** arr2 = create2d(R, C);  int** arr3 = create2d(R, C);

    fillarr(arr1, R, C);  fillarr(arr2, R, C);
    multiply(arr1, arr2, arr3, R, C);

    cout << "\nMatrix 1\n";Printarr(arr1, R, C);
    cout << "\nMatrix 2\n";Printarr(arr2, R, C);
    cout << "\nMatrix 3\n";Printarr(arr3, R, C);



    
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
