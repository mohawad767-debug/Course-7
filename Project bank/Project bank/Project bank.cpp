// Project bank.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <conio.h>
using namespace std;

const string filename = "Clients.txt";

enum enchoice {
	show_client_list = 1, Add_newclient = 2, Delete_client = 3, Update_client_info = 4,
	findclient = 5,Exit=6


};


struct stclient {
	string Account_Number;
	string Pin_Code;
	string Name;
	string Phone;
	int Balance;

	bool to_ubdate = false;
	bool to_delete = false;

};

vector<string> ReadFromfile(string filename)
{
	vector<string>filelines;

	fstream myfile;

	myfile.open(filename, ios::in);

	if (myfile.is_open())
	{
		string line;

		while (getline(myfile, line))
		{
			filelines.push_back(line);
		}

	}

	myfile.close();

	return filelines;
}
vector<string> split_str(string line, string delimeter)
{
	vector<string> Records;
	int pos = 0;
	string word = "";

	while ((pos = line.find(delimeter)) != string::npos)
	{
		word = line.substr(0, pos);
		if (word != "")
		{
			Records.push_back(word);
		}

		line = line.erase(0, pos + delimeter.length());


	}

	if (line != "")
	{
		Records.push_back(line);
	}

	return Records;


}
stclient Convert_string_into_struct(vector<string> Records)
{
	stclient client;
	client.Account_Number = Records[0];
	client.Pin_Code = Records[1];
	client.Name = Records[2];
	client.Phone = Records[3];
	client.Balance = stoi(Records[4]); return client;

}
vector<stclient> Clients_Data_into_struct()
{
	vector<stclient> clients;


	vector<string> filelines = ReadFromfile(filename);

	for (string& line : filelines)
	{

		clients.push_back(Convert_string_into_struct(split_str(line, "##//#")));

	}


	return clients;



}

void Print_Clients_Data(vector<stclient> clients)
{
	

	cout << "\n\t\t\t\tClient List (" << clients.size() << ") Client(s).\n\n";

	cout << "______________________________________________________";
	cout << "______________________________________________________\n\n";

	cout << left
		<< "| " << setw(15) << "Account Number"
		<< "| " << setw(10) << "Pin Code"
		<< "| " << setw(25) << "Client Name"
		<< "| " << setw(15) << "Phone"
		<< "| " << setw(10) << "Balance" << "|\n";

	cout << "______________________________________________________";
	cout << "______________________________________________________\n\n";

	for (stclient &client : clients)
	{
		cout << left
			<< "| " << setw(15) << client.Account_Number
			<< "| " << setw(10) << client.Pin_Code
			<< "| " << setw(25) << client.Name
			<< "| " << setw(15) << client.Phone
			<< "| " << setw(10) << client.Balance
			<< "|\n";
	}

	cout << "______________________________________________________";
	cout << "______________________________________________________\n\n";



}


bool Client_is_exist(string account_number, vector<stclient> clients)
{

	for (stclient& client : clients)
	{
		if (client.Account_Number == account_number)
		{
			return true;
		}
	}


	return false;

}

void Complet_Data(stclient& client)
{
	cout << "Enter Pin code? "; cin >> client.Pin_Code;
	cin.ignore(1, '\n');
	cout << "Enter Name? "; getline(cin, client.Name);
	cout << "Enter phone? "; cin >> client.Phone;
	cout << "Enter balance? "; cin >> client.Balance;

}

stclient Read_New_Client_Data(vector<stclient> clients)
{
	stclient client;
	cout << "Enter Account number? "; cin >> client.Account_Number;

	while (Client_is_exist(client.Account_Number, clients))
	{
		cout << "Client with account number [" << client.Account_Number
			<< "] is already exists, Enter another Account Number? ";  cin >> client.Account_Number;
	}

	Complet_Data(client);
	return client;



}

string Convert_struct_to_string(stclient client,string delimeter)
{
	string Record = "";
	Record += client.Account_Number + delimeter;
	Record += client.Pin_Code+delimeter;
	Record += client.Name+ delimeter;
	Record += client.Phone + delimeter;
	Record += to_string(client.Balance);

	return Record;





}

vector<string> Convert_Allstructs_to_vectorstring(vector<stclient> clients)
{
	vector<string> filelines;

	for (stclient& client : clients)
	{
		if (client.to_delete == false)
		{
			filelines.push_back(Convert_struct_to_string(client, "##//#"));
		}
		
	}

	return filelines;

}


void Return_Data_to_file(vector<stclient> clients)
{
	vector<string> filelines = Convert_Allstructs_to_vectorstring(clients);

	fstream myfile;
	myfile.open(filename, ios::out);

	if (myfile.is_open())
	{
		for (string& line : filelines)
		{
			myfile << line << "\n";
		}

	}

	myfile.close();


}

void Add_new_client(vector<stclient> &clients)
{

	cout << "________________________________\n";
	cout << "\tAdd new clients screen\n";
	cout << "________________________________\n";
	cout << "Adding New Client: \n\n";

	char c;
	do
	{
		stclient client = Read_New_Client_Data(clients);
		clients.push_back(client);
		Return_Data_to_file(clients);
		cout << "\n\nClient Added successfully, do you want to add more clients? Y/N "; cin >> c;

	} while (c == 'Y' || c == 'y');











}

void Mark_Updated_struct(stclient& client, vector<stclient>& clients)
{

	for (stclient& x : clients)
	{
		if (client.Account_Number == x.Account_Number)
		{
			x.to_ubdate = true;
			client = x;
				


		}

	}


}


void Fill_Deleted_struct(stclient& client, vector<stclient>& clients)
{

	for (stclient& x : clients)
	{
		if (client.Account_Number == x.Account_Number)
		{
			x.to_delete = true;
			client = x;



		}
	}



}

void Print_struct_Data(stclient client)
{

	cout << "\n\nThe following are the clients details: ";
	cout << "\n________________________________\n";
	cout << "Account number: " << client.Account_Number << "\n";
	cout << "Pin code      : " << client.Pin_Code << "\n";
	cout << "Name          : " << client.Name << "\n";
	cout << "Phone         : " << client.Phone << "\n";
	cout << "Account balance: " << client.Balance << "\n";
	cout << "________________________________\n";
}

void Refresh_Vector(vector<stclient>& clients)
{
	clients.clear();

	clients = Clients_Data_into_struct();


}

void delete_Client(vector<stclient>& clients)
{
	cout << "________________________________\n";
	cout << "\tDelete Client Screen\n";
	cout << "________________________________\n";

	stclient client;
	cout << "\nPlease, Enter Account Number? "; cin >> client.Account_Number;

	if (!Client_is_exist(client.Account_Number, clients))
	{
		cout << "\nClient with account number (" << client.Account_Number << ") is not found!\n";
	}
	else
	{
		Fill_Deleted_struct(client, clients);
		Print_struct_Data(client);
		cout << "\n\nAre you sure you want to delete this client? y/n ? "; char ans; cin >> ans;

		if (ans == 'Y'||ans=='y')
		{
			Return_Data_to_file(clients);
			cout << "\n\nClient Deleted successfully\n\n";
			Refresh_Vector(clients);

		}


	}




}


void Update_struct(stclient& client, vector<stclient> &clients)
{
	Complet_Data(client);

	for (stclient& x : clients)
	{
		if (x.to_ubdate == true)
		{
			x = client;
		}

	}

	

}

void Update_Client(vector <stclient>& clients)
{
	cout << "________________________________\n";
	cout << "\tUpdate Client Info Screen\n";
	cout << "________________________________\n";

	stclient client;
	cout << "\nPlease, Enter Account Number? "; cin >> client.Account_Number;

	if (!Client_is_exist(client.Account_Number, clients))
	{
		cout << "\nClient with account number (" << client.Account_Number << ") is not found!\n";
	}
	else
	{
		Mark_Updated_struct(client, clients);
		Print_struct_Data(client);
		cout << "\n\nAre you sure you want to update this client? y/n ? "; char ans; cin >> ans;

		if (ans == 'Y'||ans=='y')
		{
			cout << "\n\n";
			Update_struct(client, clients);
			Return_Data_to_file(clients);
			cout << "\n\nClient updated successfuly\n";

		}

	}



}

void find_selected_one(stclient& client, vector<stclient> clients)
{

	for (stclient& x : clients)
	{
		if (client.Account_Number == x.Account_Number)
		{
			client = x;
		}


	}



}

void find_client(vector<stclient> clients)
{
	cout << "________________________________\n";
	cout << "\tFind Client Screen\n";
	cout << "________________________________\n";

	stclient client;
	cout << "\nPlease, Enter Account Number? "; cin >> client.Account_Number;

	if (!Client_is_exist(client.Account_Number, clients))
	{
		cout << "\nClient with account number (" << client.Account_Number << ") is not found!\n";
	}
	else
	{
		find_selected_one(client, clients);
		cout << "\n\n";
		Print_struct_Data(client);

	}



}

void Ending_program_screen()
{

	cout << "________________________________________________________\n";
	cout << "\t\tEnd program\n";
	cout << "________________________________________________________\n";


}
void Show_main_menu()
{
		
		cout << "========================================================\n";
		cout << "\t\tMain Menue Screen\n";
		cout << "========================================================\n";
		cout << "\t[1] Show Client List.\n";
		cout << "\t[2] Add New Client.\n";
		cout << "\t[3] Delete Client.\n";
		cout << "\t[4] Update Client Info\n";
		cout << "\t[5] Find Client\n";
		cout << "\t[6] Exit\n";
		cout << "========================================================\n";
}

void Back_message()
{

	cout << "\n\nPress any key to back to main menue....\n"; _getch();
	system("cls");

}

void Program()
{
	int n;

	do
	{

		Show_main_menu();
		vector<stclient> clients = Clients_Data_into_struct();
		cout << "Choose what do you want to do [1 to 6]? ";  cin >> n; 	enchoice player = (enchoice)n;
		system("cls");
		switch (player)
		{
		case enchoice::show_client_list:
		{
		
			Print_Clients_Data(clients);
			Back_message();
			break;
			


		}
		case enchoice::Add_newclient:
		{
			Add_new_client(clients);
			Back_message();
			break;

		}

		case enchoice::Delete_client:
		{
			delete_Client(clients);
			Back_message();
			break;

		}
		case enchoice::Update_client_info:
		{
			Update_Client(clients);
			Back_message();
			break;


		}
		case enchoice::findclient:
		{
			find_client(clients);
			Back_message();
			break;


		}
		case enchoice::Exit:
		{


			Ending_program_screen();
		}



		}
	
	} while (n > 0 && n < 6);

	return;




}





int main()
{
	Program();
	




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
