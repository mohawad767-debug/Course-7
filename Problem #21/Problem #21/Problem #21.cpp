// Problem #21.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<algorithm>
#include <iomanip>
using namespace std;

void fibonaci(int n)
{
	int num1 = 0, num2 = 1,  num3 = 0;
	cout << num2 << " ";
	for (int i = 1;i < n;i++)
	{
		num3 = num1 + num2;
		num1 = num2;
		num2 = num3;

		cout << num3 << " ";

	}
	cout << "\n\n";
}

int main()
{
   
	fibonaci(20);


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
